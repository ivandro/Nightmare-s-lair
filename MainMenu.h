#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "cg/cg.h"
#include "ResourceLoader.h"
#include "MyCamera.h"
#include "MyFPSCamera.h"
#include "DebugCamera.h"
#include "MyController.h"
#include "MyScene.h"
#include "Observer.h"
#include "StringWorld.h"
#include "GrassWorld.h"
#include "MunitionManager.h"
#include "TextureBank.h"
#include "GrassTagFileConverter.h"


namespace example {

	#define KEY_START  's'
	#define KEY_ESCAPE 27
	#define KEY_ENTER 13

	#define NUMBER_OF_IMAGES 3

	class MainMenu: 
		public cg::Entity,
		public cg::IKeyboardEventListener,
		public cg::IDrawListener,
		public cg::IUpdateListener{
	
	private:
		cg::Application *m_application;
		ResourceLoader *resourceLoader;
		std::string imagePaths[ NUMBER_OF_IMAGES ];
		int actualImage;
		unsigned long imageTime;
		int width;
		int height;
		BYTE *bits;
		BYTE *titleBits, *playBits, *playSelectedBits, *exitBits, *exitSelectedBits, *imageBits;
		cg::Vector2d _titleBitsSize, _playBitsSize, _playSelectedBitsSize, _exitBitsSize, _exitSelectedBitsSize, _imageBitsSize;
		cg::Vector2d _winSize;
		bool playSelected, exitSelected;

	public:

		MainMenu( std::string id, cg::Application *application );
		~MainMenu();
		void init();
        void onKeyPressed(unsigned char key);
        void onSpecialKeyPressed(int key);
		void draw();
		void createEntities();
		void createViews();
		void update( unsigned long ellapsedMilis );

	public:

		void startGame();
		void exitGame();

	};

}

#endif