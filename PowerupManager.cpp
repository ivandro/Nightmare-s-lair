#include "PowerupManager.h"

namespace example {

	PowerupManager::PowerupManager(std::string id) : cg::Entity(id) {
	}
	PowerupManager::~PowerupManager() {
	}

	void PowerupManager::init() {
		_nVidas = 3;
		_nMunition = 3;
	}


	void PowerupManager::update(unsigned long elapsed_millis) {		
	
	}

}