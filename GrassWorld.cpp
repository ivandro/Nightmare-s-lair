#include "GrassWorld.h"
#include <vector>

namespace example {
	
	GrassWorld::GrassWorld(){
		_floorCount = 0;
		_wallCount=0;
		_decoCount=0;
		_obstacleCount=0;
		_enemyCount=0;
		_lampCount=0;
		_keyCount=0;
		_powerupCount = 0;
		_player = false;
		_door = false;

	}
	GrassWorld::~GrassWorld(){}
	
	Floor * GrassWorld::createFloor(int x,int y,float blocksize, std::string id){
		return new GrassFloor(x,y,blocksize,id);
	}

	Wall * GrassWorld::createWall(int x,int y,float blocksize, std::string id){
		return new GrassWall(x,y,blocksize,id);
	} 

	Decoration * GrassWorld::createDecoration(int x,int y,float blocksize, std::string id){
		return new GrassDecoration(x,y,blocksize,id);
	}

	Lamp * GrassWorld::createLamp(int x,int y,float blocksize, std::string id){
		return new GrassLamp(x,y,blocksize,id);
	}

	
	Enemy * GrassWorld::createEnemy(int x,int y,float blocksize, std::string id){
		return new Rabbit(x,y,blocksize,id);
	}
	Obstacle * GrassWorld::createObstacle(int x,int y,float blocksize, std::string id){
		return new Spike(x,y,blocksize,id);
	}

	Key * GrassWorld::createKey(int x,int y,float blocksize, std::string id){
		return new Key(x,y,blocksize,id);
	}

	Powerup * GrassWorld::createPowerUp(int x,int y,float blocksize,std::string id){
		return NULL;
	}
	Door * GrassWorld::createDoor(int x,int y,float blocksize, std::string id){
			return new GrassDoor(x,y,blocksize,id);
			cg::Registry::instance()->add(_doorEnt);
	}
	MainCharacter * GrassWorld::createPlayer(int x,int y,float blocksize, std::string id){
		return NULL;
	}


}