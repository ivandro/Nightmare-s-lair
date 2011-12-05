#include "PowerupManager.h"

namespace example {

	//PowerupManager::PowerupManager(std::string id)  {
	PowerupManager::PowerupManager(std::string id) : cg::Entity(id) {		

	}
	PowerupManager::~PowerupManager() {
	}

	void PowerupManager::init() {

	}

	void PowerupManager::addCoordinates(int x, int y, Powerup *powerup){
		std::stringstream sstm;
		sstm << x << '|' << y;
		coordinates[sstm.str()] = powerup;
	}
	

	void PowerupManager::update(unsigned long elapsed_millis) {		
		
		StringPowerUp::iterator itr;
	
		for(itr = coordinates.begin(); itr != coordinates.end(); itr++){
			
			Powerup* powerup = itr->second;
			if(powerup->getTimestamp() == -1) 
				;//he does nothing!
			else if(powerup->getTimestamp() == 0) powerup->activePowerup(); //new random
			else{ 
				int actualtimestamp;
				actualtimestamp = powerup->getTimestamp();
				powerup->setTimestamp(actualtimestamp--);			
			}
		}		
	}


	void PowerupManager::powerupCatched(std::string name){
		//parsing do nome, ve numero do powerup e altera no timer respectivo
	
	/*	std::stringstream sstm;
		sstm << name[7];

		int i = atoi(sstm.str().c_str());
		timearray[i] = 20;*/

		//vai buscar o powerup e faz setTimestamp

	}
}