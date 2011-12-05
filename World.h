#ifndef WORLD_NORM_H
#define WORLD_NORM_H



#include <iostream>
#include "FreeImage.h"
#include "Floor.h"
#include "Wall.h"
#include "Cloud.h"
#include "CloudRemanant.h"
#include "Lamp.h"
#include "Decoration.h"
#include "Door.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Key.h"
#include "MainCharacter.h"
#include "BlockCollisionsManager.h"
#include "BoxCollisionManager.h"
#include "MyLight.h"
#include "PowerupManager.h"
#include "HUD.h"

namespace example {

	class World {
	protected:
		int _height,_width;
		int _floorCount, _wallCount, _lampCount, _decoCount,
			_obstacleCount, _enemyCount, _keyCount, _powerupCount;
		bool _player, _door;
		std::vector<Floor *> _floors;
		std::vector<Wall *> _walls;
		std::vector<Decoration *> _decorations;
		std::vector<Lamp *> _lamps;
		std::vector<Enemy *> _enemies;
		std::vector<Obstacle *> _obstacles;
		std::vector<Key *> _keys;
		std::vector<Powerup *> _powerups;
		std::vector<Heart *> _hearts;
		std::vector<GroundMunition *> _gMunitions;
		Door * _doorEnt;
		Cloud * _cloud;
		CloudRemanant * _cloudRem;
		BlockCollisionsManager * _bCM;
		BoxCollisionManager * _bxCM;
		PowerupManager * _puM;
		MainCharacter * _playerEnt;
		MyLight * _sun;

	private :
		
		FIBITMAP * _file;
		
		virtual Floor * createFloor(int x,int y,float blocksize, std::string id) =0; //WHITE
		virtual Wall * createWall(int x,int y,float blocksize, std::string id) =0;  //BLACK
		virtual Decoration * createDecoration(int x,int y,float blocksize, std::string id) =0; //GREEN
		virtual Lamp * createLamp(int x,int y,float blocksize, std::string id) =0; //YELLOW
		virtual Enemy * createEnemy(int x,int y,float blocksize, std::string id) =0;  //RED
		virtual Obstacle * createObstacle(int x,int y,float blocksize, std::string id) =0; //GREY
		virtual Key * createKey(int x,int y,float blocksize, std::string id) =0;  //MAGENTA
		virtual Powerup * createPowerUp(int x,int y,float blocksize, std::string id) =0; //BLUE
		virtual Door *createDoor(int x,int y,float blocksize, std::string id) =0; //BROWN
		virtual MainCharacter *createPlayer(int x,int y,float clocksize, std::string id) =0; //CYAN

		void generateFloor(int x,int y,float blocksize);
		void generateWall(int x,int y,float blocksize);  
		void generateDecoration(int x,int y,float blocksize); 
		void generateLamp(int x,int y,float blocksize); 
		void generateEnemy(int x,int y,float blocksize); 
		void generateObstacle(int x,int y,float blocksize); 
		void generateKey(int x,int y,float blocksize); 
		void generatePowerUp(int x,int y,float blocksize); 
		void generateDoor(int x,int y,float blocksize);
		void generatePlayer(int x,int y,float clocksize); 


		public :

		World();
		~World();
		void populateWorld() ;
		void generateWorld(char * file, float sizeblock);
		void loadFile(char * file);
	};

}

#endif