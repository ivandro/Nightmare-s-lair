#include "GrassWorld.h"

namespace example {
	
	GrassWorld::GrassWorld(){
		_grassCount = 0;
		_wallCount=0;
		_decoCount=0;
		_player = false;
		_door = false;
	}
	GrassWorld::~GrassWorld(){}

	void GrassWorld::createFloor(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Floor" << _grassCount;
		cg::Registry::instance()->add(new GrassFloor(x,y,blocksize,sstm.str()));
		_grassCount++;
		cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
		if(view)
			view->linkEntityAtEnd(sstm.str());
	}
	void GrassWorld::createWall(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Wall" << _wallCount;
		cg::Registry::instance()->add(new GrassWall(x,y,blocksize,sstm.str()));
		_wallCount++;
		cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
		if(view)
			view->linkEntityAtEnd(sstm.str());
	} 
	void GrassWorld::createDecoration(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Decoration" << _decoCount;
		cg::Registry::instance()->add(new GrassDecoration(x,y,blocksize,sstm.str()));
		_decoCount++;
		cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
		if(view)
			view->linkEntityAtEnd(sstm.str());
		createFloor(x,y,blocksize);
	}
	void GrassWorld::createLamp(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Lamp" << _lampCount;
		cg::Registry::instance()->add(new GrassLamp(x,y,blocksize,sstm.str()));
		_lampCount++;
		cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
		if(view)
			view->linkEntityAtEnd(sstm.str());
		createFloor(x,y,blocksize);
	}
	void GrassWorld::createEnemy(int x,int y,float blocksize){
	}
	void GrassWorld::createObstacle(int x,int y,float blocksize){
	}
	void GrassWorld::createKey(int x,int y,float blocksize){
	}
	void GrassWorld::createPowerUp(int x,int y,float blocksize){
	}
	void GrassWorld::createDoor(int x,int y,float blocksize){
		if(!_door){
			_door = !_door;
			
			cg::Registry::instance()->add(new GrassDoor(x,y,blocksize,"GrassDoor"));
			cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
			if(view)
				view->linkEntityAtEnd("GrassDoor");
		} else
			std::cout << "There can only be ONE... Door of Nightmare's";
			//exception

	}
	void GrassWorld::createPlayer(int x,int y,float blocksize){
		if(!_player){
			_player = !_player;
			cg::Registry::instance()->add(new Cloud(x,y,blocksize,"Nuvem"));
			cg::Registry::instance()->add(new CloudRemanant(blocksize,"ResidualCloud"));

			cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
			if(view)
				view->linkEntityAtEnd("Nuvem");
				view->linkEntityAtEnd("ResidualCloud");
		} else {
			std::cout << "There can only be ONE... Player";
			//exception
		}
		createFloor(x,y,blocksize);
	}


}