#include "Powerup.h"

namespace example {

	
	Powerup::Powerup(std::string id) : cg::Entity(id) {
	
	}
	Powerup::Powerup(Heart *heart, GroundMunition *gmunition, std::string id) : cg::Entity(id) {
		_name = id;
		_heart = heart;
		_gmunition = gmunition;		
		_catched = false;
		_heart->state.disable();
		_gmunition->state.disable();
		_timestamp = -1;
	}
	Powerup::~Powerup() {
	}

	void Powerup::init() {
			
	}

	
	void Powerup::activePowerup(){ //deve ser chamada sempre que o user apanhar powerup, apos timer!
				
		//comparar e vier qual é o powerup, aceder-lhe pelo
		//registo e colocá-lo no local.. desactivar o outro
		
		//random
		int x = rand() % 2;

		switch(x){
			case 0:  //activa Heart, desactiva GroundMunition
				_heartActive = true; 
				_heart->state.enable();
				_gmunition->state.disable();
	
				break;

			case 1:  //activa GroundMunition, desactiva Heart
				_heartActive = false; 
				_heart->state.disable();
				_gmunition->state.enable();
				break; 

			default: std::cout << "error!!!" << std::endl;
		}
		
	}	

	void Powerup::update(unsigned long elapsed_millis) {		
		/*if(_catched) { //ERRADO!!!
			PowerupManager *pum = (PowerupManager*)cg::Registry::instance()->get("PowerupManager");
			pum->powerupCatched(_name);
			_catched = false; //colocado a true qd e' apanhado, na altura das colisoes
		}*/
	}

	//chamada pelo powerup (heart ou municao) quando ha colisao
	void Powerup::setCatched(bool catched){_catched = catched;}
	
	void Powerup::setTimestamp(int timestamp){_timestamp = timestamp;}
	
	int Powerup::getTimestamp(){return _timestamp;}
}