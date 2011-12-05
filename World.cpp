#include "World.h"

namespace example {

	World::World(){
		_file = NULL;
		_width=0;
		_height=0;
		_bCM = new BlockCollisionsManager();
		_bxCM = new BoxCollisionManager();
		_puM = new PowerupManager("PowerupManager");
		cg::Registry::instance()->add(_puM);
		
	}

	void World::loadFile(char * file){
		_file = FreeImage_Load(FIF_BMP, file, BMP_DEFAULT);
		if (!_file) 
			std::cout<<"Critical ERROR://Unable to load Map!"<<std::endl;
		else{
			_file = FreeImage_ConvertTo24Bits(_file);

			_width = FreeImage_GetWidth(_file);
			_height = FreeImage_GetHeight(_file);
		}
	}

	World::~World(){}

	void World::populateWorld(){

		cg::View* view = (cg::View*)cg::Registry::instance()->get("view");
		if(view){
			for(int i = 0; i < _lampCount; i++){	//Creates ordered Scene graph
				Lamp * lmp = _lamps[i];
				view->linkEntityAtEnd(lmp->getId());
			}
			for(int i = 0; i < _floorCount; i++){ 
				Floor * gf = _floors[i];
				view->linkEntityAtEnd(gf->getId());
			}
			for(int i = 0; i < _wallCount; i++){
				Wall * wall = _walls[i];
				view->linkEntityAtEnd(wall->getId());
			}

			view->linkEntityAtEnd(_doorEnt->getId());

			for(int i = 0; i < _obstacleCount; i++){
				Obstacle * obs = _obstacles[i];
				view->linkEntityAtEnd(obs->getId());
			}
			for(int i = 0; i < _decoCount; i++){
				Decoration * deco = _decorations[i];
				view->linkEntityAtEnd(deco->getId());
			}
			for(int i = 0; i < _keyCount; i++){
				Key * key = _keys[i];
				view->linkEntityAtEnd(key->getId());
			}
			for(int i = 0; i < _powerupCount; i++){
				Heart * h = _hearts[i];
				GroundMunition * gm = _gMunitions[i];
				Powerup * pu = _powerups[i];
				view->linkEntityAtEnd(h->getId());
				view->linkEntityAtEnd(gm->getId());
				view->linkEntityAtEnd(pu->getId());
			}

			for(int i = 0; i < _enemyCount; i++){
				Enemy * en = _enemies[i];
				view->linkEntityAtEnd(en->getId());
			}

						
			view->linkEntityAtEnd(_cloud->getId());
			view->linkEntityAtEnd(_cloudRem->getId());
			view->linkEntityAtEnd(_playerEnt->getId());
			view->linkEntityAtEnd(_sun->getId());
			view->linkEntityAtEnd(_puM->getId());
		}
	}

	
	void World::generateWorld(char * file, float sizeblock) {
		loadFile(file);

		unsigned pitch = FreeImage_GetPitch(_file);
		RGBQUAD * pixel;
			
		if((FreeImage_GetBPP(_file) == 24)) {
			int keyCount=0;
			for(int y = (int)_height-1; y >= 0 ; y--) { // int for left to right top to bottom reading of the file
					for(unsigned x = 0; x < _width; x++) {
						pixel = new RGBQUAD();

						FreeImage_GetPixelColor(_file,x,y,pixel);
							
						int red = (int)pixel->rgbRed;
						int green = (int)pixel->rgbGreen;
						int blue = (int)pixel->rgbBlue;
							
						if(red == 0 && green == 0 && blue == 0) //ifs start by most probable to least
							generateWall(x,y,sizeblock);
						else if(red == 255 && green == 255 && blue == 255)
							generateFloor(x,y,sizeblock);
						else if(red ==128 && green ==128 && blue == 128)
							generateObstacle(x,y,sizeblock);
						else if(red == 0 && green == 255 && blue == 0)
							generateDecoration(x,y,sizeblock);
						else if(red == 0 && green == 0 && blue == 255)
							generatePowerUp(x,y,sizeblock);
						else if(red == 255 && green == 255 && blue == 0)
							generateLamp(x,y,sizeblock);
						else if(red== 255 && green == 0 && blue == 0)
							generateEnemy(x,y,sizeblock);
						else if(red==255 && green == 0 && blue ==255)
							generateKey(x,y,sizeblock);
						else if(red == 128 && green ==0 && blue ==0)
							generateDoor(x,y,sizeblock);
						else
							generatePlayer(x,y,sizeblock);
					}
			}
		}
	}

	void World::generateFloor(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Floor" << _floorCount;
		Floor * f = createFloor(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(f);
		_floorCount++;
		_floors.push_back(f);

		_bCM->addCollisionCondition(x,y,false);
	}
	void World::generateWall(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Wall" << _wallCount;
		Wall * wall = createWall(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(wall);
		_wallCount++;
		_walls.push_back(wall);
		
		_bCM->addCollisionCondition(x,y,true);

		HUD *hud = (HUD*)cg::Registry::instance()->get("HUD"); //passar para World.cpp
		hud->addMapCoordinates(x, y);
	} 
	void World::generateDecoration(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Decoration" << _decoCount;
		Decoration * deco = createDecoration(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(deco);
		_decoCount++;
		_decorations.push_back(deco);

		generateFloor(x,y,blocksize); //also generates collision
		_bxCM->addStatic(deco);
	}
	void World::generateLamp(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Lamp" << _lampCount;
		Lamp * gl = createLamp(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(gl);
		_lampCount++;
		_lamps.push_back(gl);

		generateFloor(x,y,blocksize); //also generates collision
		_bxCM->addStatic(gl);
	}
	void World::generateEnemy(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Enemy" << _obstacleCount;
		Enemy * en = createEnemy(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(en);
		_enemyCount++;
		_enemies.push_back(en);
		
		generateFloor(x,y,blocksize); //also generates collision
		_bxCM->addMovable(en);

	}	
	
	void World::generateObstacle(int x,int y,float blocksize){
		std::stringstream sstm;
		sstm << "Obstacle" << _obstacleCount;
		Obstacle * obs = createObstacle(x,y,blocksize,sstm.str());
		cg::Registry::instance()->add(obs);
		_obstacleCount++;
		_obstacles.push_back(obs);
		
		generateFloor(x,y,blocksize); //also generates collision
		_bxCM->addStatic(obs);

	
	}
	void World::generateKey(int x,int y,float blocksize){
		if(_keyCount<3){	
			std::stringstream sstm;
			sstm << "Key" << _keyCount;
			Key * key = createKey(x,y,blocksize,sstm.str());
			cg::Registry::instance()->add(key);
			_keyCount++;
			_keys.push_back(key);
		
			generateFloor(x,y,blocksize); //also generates collision

			_bxCM->addStatic(key);

		} else 	std::cout << "There can only be THREE... Keys";
				//exception
	}
	void World::generatePowerUp(int x,int y,float blocksize){
		std::stringstream sstm, sstmh, sstmgm;
	
		//criar Heart
		sstmh << "Heart" << _powerupCount;
		Heart *heart = new Heart(x,y,blocksize,sstmh.str());
		cg::Registry::instance()->add(heart);
		_hearts.push_back(heart);
	
		//cria GroundMunition
		sstmgm << "GroundMunition" << _powerupCount;
		GroundMunition *gmunition = new GroundMunition(x,y,blocksize,sstmgm.str());
		cg::Registry::instance()->add(gmunition);
		_gMunitions.push_back(gmunition);

		//cria Powerup
		sstm << "PowerUp" << _powerupCount;
		Powerup *pu = new Powerup(heart,gmunition,sstm.str());
		cg::Registry::instance()->add(pu);
		_powerups.push_back(pu);

		_puM->addCoordinates(x,y, pu);
		_powerupCount++;


		generateFloor(x,y,blocksize);

		_bCM->addCollisionCondition(x,y,false);
		//_bxCM->addStatic(key);
	}
	void World::generateDoor(int x,int y,float blocksize){
		if(!_door){
			_door = !_door;
			_doorEnt = createDoor(x,y,blocksize,"Door");
			cg::Registry::instance()->add(_doorEnt);

			_bCM->addCollisionCondition(x,y,true);
			_bxCM->addStatic(_doorEnt);
		} else
			std::cout << "There can only be ONE... Door of Nightmare's";
			//exception
	}
	void World::generatePlayer(int x,int y,float blocksize){
		if(!_player){
			_player = !_player;


			_cloud = new Cloud(x,y,blocksize,"Nuvem");
			_cloudRem = new CloudRemanant(blocksize,"ResidualCloud");
			_playerEnt = new MainCharacter(x,y,blocksize,"MainCharacter",_bCM,_bxCM);
			_sun = new MyLight("Sun",blocksize);

			cg::Registry::instance()->add(_sun);
			cg::Registry::instance()->add(_cloud);
			cg::Registry::instance()->add(_cloudRem);
			cg::Registry::instance()->add(_playerEnt);

			generateFloor(x,y,blocksize); //also generates collision

			_bxCM->addMovable(_playerEnt);


		} else {
			std::cout << "There can only be ONE... Player";
			//exception
		}


	}



}
