#include "World.h"

namespace example {

	World::World(){
		_file = NULL;
		_width=0;
		_height=0;
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
							createWall(x,y,sizeblock);
						else if(red == 255 && green == 255 && blue == 255)
							createFloor(x,y,sizeblock);
						else if(red ==128 && green ==128 && blue == 128)
							createObstacle(x,y,sizeblock);
						else if(red == 0 && green == 255 && blue == 0)
							createDecoration(x,y,sizeblock);
						else if(red == 0 && green == 0 && blue == 255)
							createPowerUp(x,y,sizeblock);
						else if(red == 255 && green == 255 && blue == 0)
							createLamp(x,y,sizeblock);
						else if(red== 255 && green == 0 && blue == 0)
							createEnemy(x,y,sizeblock);
						else if(red==255 && green == 0 && blue ==255)
							createKey(x,y,sizeblock);
						else if(red == 128 && green ==0 && blue ==0)
							createDoor(x,y,sizeblock);
						else
							createPlayer(x,y,sizeblock);
					}
			}
		}
	}

}
