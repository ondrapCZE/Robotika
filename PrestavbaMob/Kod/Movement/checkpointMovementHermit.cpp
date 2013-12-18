#include "checkpointMovementHermit.hpp"
#include <iostream>

void checkpointMovementHermit::moveToCheckpoints() {
	while(true){
		Checkpoint checkpoint;
		if(checkpointsQueue.tryPop(checkpoint)){
			std::cout << checkpoint.position.x << "," << checkpoint.position.y << std::endl;
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


checkpointMovementHermit::checkpointMovementHermit(BasicDifferencialChassis* chassis) : chassis(chassis) {
	moveToCheckpointsThread = std::move(std::thread(&checkpointMovementHermit::moveToCheckpoints,this));
}

void checkpointMovementHermit::addCheckpoint(const Checkpoint& checkpoint){
	checkpointsQueue.push(checkpoint);
}

void checkpointMovementHermit::addCheckpoint(const std::vector<Checkpoint>& checkpoints){
	for(auto element : checkpoints){
		checkpointsQueue.push(element);
	}
}

State checkpointMovementHermit::getActualState(){
	return chassis->getState();
}

void checkpointMovementHermit::clearCheckpoints(){
	checkpointsQueue.clear();
}