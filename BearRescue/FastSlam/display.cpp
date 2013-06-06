#include "display.h" 

using namespace cv;

display_CLASS::display_CLASS(){
	map.create(HEIGHT, WIDTH, CV_8UC3);

	//dislay
	windowName = "oknoZobrazeni";
	zoom = 200;
	shiftX = -20;
	shiftY = -20;

	MULTI_STEP = (float) 1;
	SHIFT_X_STEP = 10;

#ifdef _MSC_VER
	SHIFT_Y_STEP = 10;
#else
	SHIFT_Y_STEP = -10;
#endif

	//video.open("mapa.avi",CV_FOURCC_PROMPT,10,Size(WIDTH,HEIGHT),true);
}

int display_CLASS::fixHeight(int MaxHeight,int Height){
#ifdef _MSC_VER
	return MaxHeight - Height;
#else
	return Height;
#endif
}

void display_CLASS::displayMap(){
	cvNamedWindow(windowName.c_str(),CV_WINDOW_AUTOSIZE);

	imshow(windowName.c_str(),map);
	int key = waitKey(-1);
	if(key == -1)
		return;

	int ascii = (char) key;
	double r;

	switch(ascii){
		case '+':
			r = (zoom + MULTI_STEP) / zoom;
			zoom += MULTI_STEP;
			shiftX = (int)(r * (WIDTH / 2.0 + shiftX) - WIDTH / 2.0);
			shiftY = (int)(r * (HEIGHT / 2.0 + shiftY) - HEIGHT / 2.0);
			break;
		case '-':
			if(zoom > MULTI_STEP){
				r = (zoom - MULTI_STEP) / zoom;
				zoom -= MULTI_STEP;
				shiftX = (int)(r * (WIDTH / 2.0 + shiftX) - WIDTH / 2.0);
				shiftY = (int)(r * (HEIGHT / 2.0 + shiftY) - HEIGHT / 2.0);
			}
			break;
		case 27:
			exit(0);
		case 'w':
			shiftY += SHIFT_Y_STEP;
			break;
		case 's':
			shiftY -= SHIFT_Y_STEP;
			break;
		case 'a':
			shiftX -= SHIFT_X_STEP;
			break;
		case 'd':
			shiftX += SHIFT_X_STEP;
			break;
		default:
			break;
	}


	//imwrite("./Test/test.jpg",map);
	//video << map;
}

void display_CLASS::writeMostProbState(const state_STR &State){
	int pointX = (State.position.x)*zoom - shiftX;
	int pointY = fixHeight(HEIGHT,(State.position.y)*zoom - shiftY);
	Point particle(pointX,pointY);
	circle(map,particle,0.14*zoom,Scalar(0,0,255));

	int pointNarrowX = pointX + 5*cos(State.angle);
	int pointNarrowY = fixHeight(HEIGHT,(State.position.y)*zoom - shiftY + 5*sin(State.angle));
	Point narrow(pointNarrowX,pointNarrowY);
	line(map,particle,narrow,Scalar(0,0,255));
}

void display_CLASS::writeLaserScan(std::vector<double> laserScan, const state_STR &State){
	position_STR sickPosition(State.position);
	sickPosition.x += 0.1487*cos(State.angle - 0.738);
	sickPosition.y += 0.1487*sin(State.angle - 0.738);
	double angle = State.angle + M_PI_2 + M_PI_4;
	for(std::vector<double>::iterator measure = laserScan.begin(); measure != laserScan.end(); ++measure){
		int pointX = sickPosition.x * zoom - shiftX;
		int pointY = fixHeight(HEIGHT, sickPosition.y * zoom - shiftY);
		Point begin(pointX,pointY);
		pointX += cos(angle)*(*measure) * zoom;

		#ifdef _MSC_VER
			pointY -= sin(angle)*(*measure) * zoom;
		#else
			pointY += sin(angle)*(*measure) * zoom;
		#endif

		Point end(pointX,pointY);
		line(map,begin,end,Scalar(0,200,0));

		angle -= M_PI / 180.0;
	}
}

void display_CLASS::writeIntersection(vm::VectorMap* vectorMap, const state_STR &state){
	State sickPosition(state.position.x,state.position.y,state.angle);
	sickPosition.x += 0.1487*cos(state.angle - 0.738);
	sickPosition.y += 0.1487*sin(state.angle - 0.738);
	sickPosition.angle += M_PI_2 + M_PI_4;

	for(int i=0; i<272 ;++i){
		for(vm::wallIt wall = vectorMap->getWallsItBegin(); wall != vectorMap->getWallsItEnd(); ++wall){
			vm::Point intersection = vectorMap->getIntersection((*wall),sickPosition);
			//printf("Intersection [%f,%f]\n", intersection.x, intersection.y);
			intersection.x = intersection.x * zoom - shiftX;
			intersection.y = fixHeight(HEIGHT, intersection.y * zoom - shiftY);
			line(map,cv::Point(intersection.x,intersection.y),cv::Point(intersection.x+1,intersection.y+1),cv::Scalar(255,0,0),1);
		}
		sickPosition.angle -= M_PI / 180.0;
	}
}

void display_CLASS::writeParticle(const vector<struct particle_STR> &Particles){
	for(vector<struct particle_STR>::const_iterator particle = Particles.begin(); particle < Particles.end(); ++particle){
		int pointX = (particle->state.position.x)*zoom - shiftX;
		int pointY = fixHeight(HEIGHT,(particle->state.position.y)*zoom - shiftY);
		Point particlePoint(pointX,pointY);

		circle(map,particlePoint,2,Scalar(255,0,0));
		int pointNarrowX = pointX + 5*cos(particle->state.angle);
		int pointNarrowY = fixHeight(HEIGHT,(particle->state.position.y)*zoom - shiftY + 5*sin(particle->state.angle));
		Point narrow(pointNarrowX,pointNarrowY);

		line(map,particlePoint,narrow,Scalar(255,0,0));
	} 
}

void display_CLASS::writeMap(vm::VectorMap* VectorMap){	
	map.setTo(Scalar(255,255,255));

	for(vm::wallIt wall = VectorMap->getWallsItBegin(); wall != VectorMap->getWallsItEnd(); ++wall){
		int pointX = wall->begin.x * zoom - shiftX;
		int pointY = fixHeight(HEIGHT, wall->begin.y * zoom - shiftY);
		Point begin(pointX,pointY);
		pointX = wall->end.x * zoom - shiftX;
		pointY = fixHeight(HEIGHT, wall->end.y * zoom - shiftY);
		Point end(pointX,pointY);
		line(map, begin, end, Scalar(0,0,0));
	}
}
