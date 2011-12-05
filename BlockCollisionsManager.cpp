#include "BlockCollisionsManager.h"

namespace example {

	BlockCollisionsManager::BlockCollisionsManager(){
	}

	BlockCollisionsManager::~BlockCollisionsManager(){}

	void BlockCollisionsManager::addCollisionCondition(int x, int y, bool val){
		std::stringstream sstm;
		sstm << "" << x  << "|" << y;
		_allowedMap[sstm.str()] = val;
	}

	bool BlockCollisionsManager::checkCollision(int x, int y){
		std::stringstream sstm;
		sstm << "" << x  << "|" << y;
		return _allowedMap[sstm.str()];
	}

	


}