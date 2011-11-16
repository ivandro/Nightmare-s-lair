#include "StringWorld.h"

namespace example{
	
	StringWorld::StringWorld(){}
	StringWorld::~StringWorld(){}

	void StringWorld::createFloor(int x,int y,float blocksize){
		std::cout << " "; //Simpler is best
		if(x ==_width-1)
			std::cout << std::endl;
	}
	void StringWorld::createWall(int x,int y,float blocksize){
		std::cout << "#"; 
		if(x ==_width-1)
			std::cout << std::endl;
	} 
	void StringWorld::createDecoration(int x,int y,float blocksize){
		std::cout << "D";
	}
	void StringWorld::createLamp(int x,int y,float blocksize){
		std::cout << "L";
	}
	void StringWorld::createEnemy(int x,int y,float blocksize){
		std::cout << "§"; // Amorphous enemy
	}
	void StringWorld::createObstacle(int x,int y,float blocksize){
		std::cout << "0"; 
	}
	void StringWorld::createKey(int x,int y,float blocksize){
		std::cout << "K";
	}
	void StringWorld::createPowerUp(int x,int y,float blocksize){
		std::cout << "^"; // Powering UP
	}
	void StringWorld::createDoor(int x,int y,float blocksize){
		std::cout << "@"; //@ looks like a gate
	}
	void StringWorld::createPlayer(int x,int y,float clocksize){
		std::cout << "*"; // Your the star of this show
	}
}