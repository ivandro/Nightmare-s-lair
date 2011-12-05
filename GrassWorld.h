#ifndef GRASS_WORLD_H
#define GRASS_WORLD_H
#include "World.h"
#include "GrassFloor.h"
#include "GrassWall.h"
#include "GrassLamp.h"
#include "GrassDecoration.h"
#include "GrassDoor.h"
#include "Spike.h"
#include "Rabbit.h"
#include "Key.h"
#include "cg/cg.h"


namespace example {

	class GrassWorld : public World{
	private:

	public:
		GrassWorld();
		~GrassWorld();
		
		 Floor * createFloor(int x,int y,float blocksize, std::string id); //WHITE
		 Wall * createWall(int x,int y,float blocksize, std::string id);  //BLACK
		 Decoration * createDecoration(int x,int y,float blocksize, std::string id); //GREEN
		 Lamp * createLamp(int x,int y,float blocksize, std::string id); //YELLOW
		 Enemy * createEnemy(int x,int y,float blocksize, std::string id);  //RED
		 Obstacle * createObstacle(int x,int y,float blocksize, std::string id); //GREY
		 Key * createKey(int x,int y,float blocksize, std::string id);  //MAGENTA
		 Powerup * createPowerUp(int x,int y,float blocksize, std::string id); //BLUE
		 Door *createDoor(int x,int y,float blocksize, std::string id); //BROWN
		 MainCharacter *createPlayer(int x,int y,float clocksize, std::string id); //CYAN


	};


}
#endif