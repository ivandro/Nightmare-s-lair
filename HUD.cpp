#include "HUD.h"


namespace example {

	HUD::HUD( std::string id ) : cg::Entity( id ) {
	}
	HUD::~HUD() {
	}
	void HUD::init() {
		
		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		height = win.height;
		width = win.width;

		_position.set(0,0);		
		_characterPosition.set(650, 150); //to change
		deltaPixel = 8;
	}
	
	void HUD::update(unsigned long elapsed_millis) {

		MainCharacter *maincharacter = (MainCharacter*)cg::Registry::instance()->get("MainCharacter");
		_LifeCount = maincharacter->getNLifes();
		_MunitionCount = maincharacter->getNMunitions();
		//_KeyCount = maincharacter->getNKeys(); TO DO
		cg::Vector2d charPos = maincharacter->getCharPos();

		_characterPosition[0] = charPos[0];
		_characterPosition[1] = charPos[1];

	}

	void HUD::drawOverlay() {
		drawInformation();			
		drawMunitionIcon();
		drawHeartIcon();
		drawKeyIcon();
		drawMiniMap();
		drawCrosshair();
		drawCharacterPosition();
	}


	void HUD::draw(){		
	}

	void HUD::drawInformation(){
		glColor3f(0.3f,0.3f,0.3f);
		cg::Util::instance()->drawBitmapString("Press [ESC] to exit.",10,66);
		cg::Util::instance()->drawBitmapString("Press [F1] to dump registry to logfile.",10,52);
		cg::Util::instance()->drawBitmapString("Press [F2] to toggle debug mode.",10,38);
		cg::Util::instance()->drawBitmapString("Press [F3] to see FPS view.",10,24);
		cg::Util::instance()->drawBitmapString("Press [MOUSE LEFT] to rotate and [MOUSE RIGHT] to roll camera.",10,10);
	}

	void HUD::drawMunitionIcon(){
		std::stringstream sstm;
		sstm << "Numero de municoes: " << _MunitionCount; 
		
		glColor3f(1.0f,1.0f,1.0f);
		cg::Util::instance()->drawBitmapString(sstm.str(),10,590);
	}

	void HUD::drawHeartIcon(){
		/*
		_modelHeartIcon = glGenLists(1);
		assert(_modelHeartIcon != 0);
		
		glNewList(_modelHeartIcon,GL_COMPILE);

		glPushMatrix();
			glColor3f(0.3f,0.3f,0.3f);
			glBegin(GL_QUADS);
				glVertex2f(0, 0);
				glVertex2f(1, 0);
				glVertex2f(1, 1);
				glVertex2f(0, 1);
			glEnd();
				
		glPopMatrix();	

		glEndList();*/

		std::stringstream sstm;
		sstm << "Numero de vidas: " << _LifeCount; 
		
		glColor3f(1.0f,1.0f,1.0f);
		cg::Util::instance()->drawBitmapString(sstm.str(),10,576);
	}

	void HUD::drawKeyIcon(){
		std::stringstream sstm;
		sstm << "Numero de chaves: " ;//<< _KeyCount << "/3"; 
		
		glColor3f(1.0f,1.0f,1.0f);
		cg::Util::instance()->drawBitmapString(sstm.str(),10,561);
	}

	void HUD::drawMiniMap(){

	//fundo cinza
	/*for(int i = 0; i <= 240; i++){
		
		for(int j = 585; j <= width; j++){ //	cena super inificiente
			
				glColor3f(0.5f,0.5f,0.5f);
				cg::Util::instance()->drawBitmapString("0",j,i);
			}
		}*/

		int h=210;

		//mapa
		for(int i = 25; i >= 0; i--, h= h-deltaPixel){
			for(int j = 25; j >= 0; j--){
				if(mapcoordinates[j][i] == 1){
					glColor3f(1.0f,1.0f,1.0f);
					cg::Util::instance()->drawBitmapString("X",width-10-j*deltaPixel,h-i);				
				}		
			
			}
		}

	}

	void HUD::drawCrosshair(){

		for(int i = height/2-deltaPixel*2; i <= height/2+deltaPixel*2; i++){
			glColor3f(1.0f,1.0f,1.0f);
			cg::Util::instance()->drawBitmapString(".",width/2,i);
		}
		for(int j = width/2-deltaPixel*2; j <= width/2+deltaPixel*2; j++){
			glColor3f(1.0f,1.0f,1.0f);
			cg::Util::instance()->drawBitmapString(".",j,height/2);
		}
	}

	void HUD::drawCharacterPosition(){
		int x = _characterPosition[0];
		int y = _characterPosition[1];
		glColor3f(0.0f,0.0f,1.0f);
		//cg::Util::instance()->drawBitmapString("#",590+y*deltaPixel,230-x);
		cg::Util::instance()->drawBitmapString("#",width-10-x*deltaPixel,y*deltaPixel);

	}

	void HUD::addMapCoordinates(int x, int y){
		mapcoordinates[x][y] = 1;
	}

}