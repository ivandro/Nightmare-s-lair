#ifndef GRASS_WORLD_H
#define GRASS_WORLD_H
#include "World.h"
#include "GrassFloor.h"
#include "GrassWall.h"
#include "Cloud.h"
#include "CloudRemanant.h"
#include "GrassLamp.h"
#include "GrassDecoration.h"
#include "GrassDoor.h"
#include "cg/cg.h"

namespace example {

	class GrassWorld : public World{
	private:
		int _grassCount, _wallCount, _lampCount, _decoCount;
		bool _player, _door;

	public:
		GrassWorld();
		~GrassWorld();
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