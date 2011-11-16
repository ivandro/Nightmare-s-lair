#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "FreeImage.h"
namespace example {

	class World {
	protected:

		int _height,_width;

	private :
		
		FIBITMAP * _file;
		
		virtual void createFloor(int x,int y,float blocksize) =0; //WHITE
		virtual void createWall(int x,int y,float blocksize) =0;  //BLACK
		virtual void createDecoration(int x,int y,float blocksize) =0; //GREEN
		virtual void createLamp(int x,int y,float blocksize) =0; //YELLOW
		virtual void createEnemy(int x,int y,float blocksize) =0;  //RED
		virtual void createObstacle(int x,int y,float blocksize) =0; //GREY
		virtual void createKey(int x,int y,float blocksize) =0;  //MAGENTA
		virtual void createPowerUp(int x,int y,float blocksize) =0; //BLUE
		virtual void createDoor(int x,int y,float blocksize) =0; //BROWN
		virtual void createPlayer(int x,int y,float clocksize) =0; //CYAN

		public :

		World();
		~World();
		void generateWorld(char * file, float sizeblock);
		void loadFile(char * file);
	};

}

#endif