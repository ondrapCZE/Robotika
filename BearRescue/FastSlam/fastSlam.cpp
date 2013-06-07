#include "fastSlam.h"
#include "display.h"

#include "readFile.h"
#include <stdint.h>
#include <limits>


FastSLAM_CLASS::FastSLAM_CLASS(){
	init(20);
	lastState.x = numeric_limits<double>::max();
	probState = getMostProbabilisticState();
}

double FastSLAM_CLASS::normAngle(double Angle){
	while(Angle > M_PI)
		Angle -= 2*M_PI;

	while(Angle < -M_PI)
		Angle += 2*M_PI;

	return Angle;
}

double FastSLAM_CLASS::randn_notrig(double mu, double sigma){
        static bool deviateAvailable=false;        //        flag
        static double storedDeviate;                        //        deviate from previous calculation
        double polar, rsquared, var1, var2;
        
        //        If no deviate has been stored, the polar Box-Muller transformation is 
        //        performed, producing two independent normally-distributed random
        //        deviates.  One is stored for the next round, and one is returned.
        if (!deviateAvailable) {
                
                //        choose pairs of uniformly distributed deviates, discarding those 
                //        that don't fall within the unit circle
                do {
						var1=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
                        var2=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
                        rsquared=var1*var1+var2*var2;
                } while ( rsquared>=1.0 || rsquared == 0.0);
                
                //        calculate polar tranformation for each deviate
                polar=sqrt(-2.0*log(rsquared)/rsquared);
                
                //        store first deviate and set flag
                storedDeviate=var1*polar;
                deviateAvailable=true;
                
                //        return second deviate
                return var2*polar*sigma + mu;
        }
        
        //        If a deviate is available from a previous call to this function, it is
        //        returned, and the flag is set to false.
        else{
                deviateAvailable=false;
                return storedDeviate*sigma + mu;
        }
}

double FastSLAM_CLASS::gausianDistribution(double Diference, double Dispersion){
	double dispersionSquare = pow(Dispersion,2);
	double fraction = 1/sqrt(2*M_PI*dispersionSquare);
	double distance = pow(Diference,2);
	double multi = pow(M_E,-(distance/(2*dispersionSquare)));
	return fraction*multi;
}

double FastSLAM_CLASS::resample(int Count){
	if(Count <= 0) Count = 100; 
	vector<particle_STR> newParticles;

	double sume = 0;
	for(vector<particle_STR>::const_iterator particle = particles.begin(); particle != particles.end(); ++particle){
		sume+= particle->weight;
	}

	double shift = sume/Count;
	double start = shift*(rand()/(double)RAND_MAX);
	double countWeight = 0;
	int index = 0;
	
	// avrige sum
	weightSlow = weightSlow + 0.1*(sume/(double)particles.size() - weightSlow);

	for(vector<particle_STR>::iterator particle = particles.begin(); particle != particles.end(); ++particle){
		countWeight += particle->weight;
		while(countWeight > (shift*index + start)){
			newParticles.push_back(*particle);
			newParticles[index++].weight = 1;
		}
	}

	particles = newParticles;
	// TODO: linux lock
	probState = calculateMostProbabilisticState();

	return sume/(double)particles.size();
}

void FastSLAM_CLASS::weightParticlesFromSick(double StartAngle, double MaxScanLength, std::vector<double> data){
	for(vector<particle_STR>::iterator particle = particles.begin(); particle != particles.end(); ++particle){
		double angle = StartAngle;
		for(int i=0; i<data.size(); ++i){

			angle -= M_PI / 180.0;
		}
	}
}

void FastSLAM_CLASS::init(int Count){
	particles.clear();
	for(int i = 0; i < Count; ++i){	
		State state(0.2,0.2,M_PI/2.0);
		particle_STR particle(state);

		particles.push_back(particle);		
	}
}

State FastSLAM_CLASS::calculateMostProbabilisticState(){
	State probPosition(0,0,0);
	double weight = 0;

	for(vector<struct particle_STR>::const_iterator particle = particles.begin(); particle < particles.end(); ++particle){
		probPosition.x += particle->weight * particle->state.x;
		probPosition.y += particle->weight * particle->state.y;
		probPosition.angle += particle->weight * particle->state.angle;

		weight += particle->weight;
	}
	
	probPosition.x /= weight;
	probPosition.y /= weight;
	probPosition.angle = normAngle(probPosition.angle/weight);

	printf("ProbState [%f,%f,%f] \n",probPosition.x,probPosition.y,probPosition.angle );

	return probPosition;
}

State FastSLAM_CLASS::getMostProbabilisticState(){
	// TODO: linux lock
	return probState;
}

void FastSLAM_CLASS::move(State State){
	if(lastState.x == numeric_limits<double>::max()){
		lastState = State;
		return;
	}

	double shiftX = State.x - lastState.x;
	double shiftY = State.y - lastState.y;
	double length = _hypot(shiftX,shiftY);

	if(length == 0){
		move(State.angle - lastState.angle,(State.angle - lastState.angle)/100.0);	
	}else{
		double gama = asin(shiftY/length);

		if(shiftX < 0){
			gama = M_PI - gama;
		}

		/*uint8_t test = (shiftY < 0) << 1 | (shiftX < 0);

		switch(test){
			case 1:
				gama = M_PI - gama;
				break;
			case 2:
				gama = 2*M_PI + gama;
				break;
			case 3:
				gama = M_PI - gama;
				break;
			default:
				break;
		}*/
		
		double alpha = gama - lastState.angle;
		double beta =  State.angle - gama;

		cout << "a: " << alpha << " l: " << length << " b: " << beta << endl;
		move(alpha, 0, length, 0, beta, 0);
		//move(alpha, alpha / 100.0, length, length / 100.0, beta, beta / 100.0);
	}

	lastState = State;
}

void FastSLAM_CLASS::move(double Alpha, double AlphaVar, double Length, double LengthVar, double Beta, double BetaVar){
	for(vector<particle_STR>::iterator particle = particles.begin(); particle != particles.end(); ++particle){
		particle->state.angle += randn_notrig(Alpha, AlphaVar);
		double length = randn_notrig(Length,LengthVar);
		particle->state.x += cos(particle->state.angle)*length;
		particle->state.y += sin(particle->state.angle)*length;
		particle->state.angle += randn_notrig(Beta, BetaVar);

		particle->state.angle = normAngle(particle->state.angle);
	}

	// TODO: linux lock
	probState = calculateMostProbabilisticState();
}

int main(){
	
	
	FastSLAM_CLASS fastSlam;
	vm::VectorMap* map = fastSlam.getVectorMap();

	// add wall to map
	map->addWall(vm::Wall(vm::Point(0,0), vm::Point(1.4,0)));
	map->addWall(vm::Wall(vm::Point(0,0), vm::Point(0,2.8)));
	map->addWall(vm::Wall(vm::Point(0,2.8), vm::Point(1.4,2.8)));
	map->addWall(vm::Wall(vm::Point(1.4,0), vm::Point(1.4,2.8)));
	map->addWall(vm::Wall(vm::Point(0,1.4), vm::Point(0.9,1.4)));
	map->addWall(vm::Wall(vm::Point(0.9,0.7), vm::Point(0.9,1.4)));
	map->addWall(vm::Wall(vm::Point(0.4,0), vm::Point(0.4,0.7)));
	
	readDataFromFile_CLASS test(&fastSlam);
	test.startReadFromFile("log1.out");

	return 0;
}