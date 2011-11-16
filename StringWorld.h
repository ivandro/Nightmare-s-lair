#ifndef STRING_WORLD_H
#define STRING_WORLD_H

#include "World.h"

namespace example {
	class StringWorld : public World {
	public:
		StringWorld();
		~StringWorld();
		void createFloor(int x,int y,float blocksize);
		void createWall(int x,int y,float blocksize); 
		void createDecoration(int x,int y,float blocksize);
		void createLamp(int x,int y,float blocksize);
		void createEnemy(int x,int y,float blocksize);
		void createObstacle(int x,int y,float blocksize);
		void createKey(int x,int y,float blocksize);
		void createPowerUp(int x,int y,float blocksize);
		void createDoor(int x,int y,float blocksize);
		void createPlayer(int x,int y,float clocksize);


	};

}
#endif