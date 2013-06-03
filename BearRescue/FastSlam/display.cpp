#include "display.h" 

using namespace cv;

display_CLASS::display_CLASS(){
	map.create(HEIGHT, WIDTH, CV_8UC3);

	//dislay
	windowName = "oknoZobrazeni";
	zoom = 100;
	shiftX = 0;
	shiftY = 0;

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
	int key = waitKey(80);
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
	circle(map,particle,2,Scalar(0,0,255));

	int pointNarrowX = pointX + 5*cos(State.angle);
	int pointNarrowY = fixHeight(HEIGHT,(State.position.y)*zoom - shiftY + 5*sin(State.angle));
	Point narrow(pointNarrowX,pointNarrowY);
	line(map,particle,narrow,Scalar(0,0,255));
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
