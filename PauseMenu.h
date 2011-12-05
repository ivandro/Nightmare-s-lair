#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "cg/cg.h"
#include "MainMenu.h"
#include "MyCamera.h"
#include "MyFPSCamera.h"
#include "DebugCamera.h"
#include "MyController.h"
#include "MyLight.h"
#include "MyQuadric.h"
#include "MyScene.h"
#include "MyTeapot.h"
#include "MyTexturedBox.h"
#include "MainCharacter.h"
#include "MyWorld.h"
#include "Key.h"
#include "Heart.h"
#include "Cloud.h"
#include "CloudRemanant.h"
#include "Observer.h"
#include "StringWorld.h"
#include "GrassWorld.h"
#include "Rabbit.h"
#include "Munition.h"
#include "GroundMunition.h"
#include "TextureBank.h"
#include "GrassTagFileConverter.h"
#include "MyApp.h"

namespace example {

	#define KEY_RESUME 'r'
	#define KEY_ESCAPE 27

	class PauseMenu: 
		public cg::Entity,
		public cg::IKeyboardEventListener,
		public cg::IDrawListener{
	
	private:
		cg::Application *m_application;
		cg::Vector2i _pauseBitsSize, _resumeBitsSize, _resumeSelectedBitsSize, _exitBitsSize, _exitSelectedBitsSize;
		BYTE *pauseBits, *resumeBits, *resumeSelectedBits, *exitBits, *exitSelectedBits;
		ResourceLoader *resourceLoader;
		cg::Vector2i _winSize;
		bool resumeSelected, exitSelected;

	public:

		PauseMenu( std::string id );
		~PauseMenu();
		void init();
        void onKeyPressed(unsigned char key);
        void onSpecialKeyPressed(int key);
		void draw();
		void disableEntities();
		void enableEntities();

		void resumeGame();
		void endCurrentGame();
		void exitGame();

	};

}

#endif