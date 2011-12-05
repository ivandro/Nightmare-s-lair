#include "PauseMenu.h"

namespace example {

	PauseMenu::PauseMenu( std::string id ) : cg::Entity( id ), resumeSelected( true ), exitSelected( false ) {}

	PauseMenu::~PauseMenu() {
	}

	void PauseMenu::init() {

		std::cout << "Pause in init " << std::endl;
	
		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		_winSize.set(win.width,win.height);
	
		resourceLoader = new ResourceLoader();
		
		glShadeModel( GL_FLAT );

		pauseBits = resourceLoader->loadImage( "Images\\Menu\\Pause.png" );
		_pauseBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_pauseBitsSize[ 1 ] = resourceLoader->getLastImageHeight();
		
		resumeBits = resourceLoader->loadImage( "Images\\Menu\\Resume1.png" );
		_resumeBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_resumeBitsSize[ 1 ] = resourceLoader->getLastImageHeight();
		
		resumeSelectedBits = resourceLoader->loadImage( "Images\\Menu\\Resume1Selected.png" );
		_resumeSelectedBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_resumeSelectedBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		exitBits = resourceLoader->loadImage( "Images\\Menu\\Exit1.png" );
		_exitBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_exitBitsSize[ 1 ] = resourceLoader->getLastImageHeight();
		
		exitSelectedBits = resourceLoader->loadImage( "Images\\Menu\\Exit1Selected.png" );
		_exitSelectedBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_exitSelectedBitsSize[ 1 ] = resourceLoader->getLastImageHeight();
		
		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	
	}

	void PauseMenu::resumeGame() {
		
		// disable PauseMenu
		this->state.disable();
		
		// colocar de novo informação
		enableEntities();
		
	}

	void PauseMenu::endCurrentGame() {
		
		// TO DO
		// disable PauseMenu
		/*MainMenu *mainMenu = ( MainMenu * )cg::Registry::instance()->get( "Main Menu" );
		cg::Registry *registry = cg::Registry::instance();
		registry->remove( "Main Menu" );
		registry->remove( "Pause Menu" );

		mainMenu->state.enable();
		mainMenu->init();
		registry->add( mainMenu );
		*/
	}

	void PauseMenu::exitGame() {

		cg::Manager::instance()->shutdownApp();

	}

	void PauseMenu::onKeyPressed( unsigned char key ) {
		
		if ( key == KEY_RESUME ) {

				resumeGame();

		}
		else if ( key == KEY_ENTER || key == 'e') {

			if ( resumeSelected ) {

				resumeGame();

			}
			else {

				exitGame();

			}
		
		}
		
	}


	void PauseMenu::disableEntities() {

		cg::Registry *registry = cg::Registry::instance();
		registry->get( "Scene" )->state.disable();
		registry->get( "FPSCamera" )->state.disable();
		registry->get( "Camera" )->state.disable();
		registry->get( "DebugCamera" )->state.disable();	
		registry->get( "TextureBank" )->state.disable();
		registry->get( "Sun" )->state.disable();
		registry->get( "Controller" )->state.disable();
		registry->get( "World" )->state.disable();
		registry->get( "MainCharacter" )->state.disable();
		registry->get( "Heart" )->state.disable();
		registry->get( "Stone" )->state.disable();
		registry->get( "rabbit")->state.disable();
		registry->get( "munition")->state.disable();
		registry->get( "groundmunition")->state.disable();
		registry->get( "Observer" )->state.disable();
		
	}
	void PauseMenu::enableEntities() {
		
		cg::Registry *registry = cg::Registry::instance();
		registry->get( "Scene" )->state.enable();
		registry->get( "FPSCamera" )->state.enable();
		registry->get( "Camera" )->state.enable();
		registry->get( "DebugCamera" )->state.enable();	
		registry->get( "TextureBank" )->state.enable();
		registry->get( "Sun" )->state.enable();
		registry->get( "Controller" )->state.enable();
		registry->get( "World" )->state.enable();
		registry->get( "MainCharacter" )->state.enable();
		registry->get( "Heart" )->state.enable();
		registry->get( "Stone" )->state.enable();
		registry->get( "rabbit")->state.enable();
		registry->get( "munition")->state.enable();
		registry->get( "groundmunition")->state.enable();
		registry->get( "Observer" )->state.enable();
		
	}
	
	void PauseMenu::onSpecialKeyPressed(int key) {
	
		if ( key == GLUT_KEY_UP || key == GLUT_KEY_DOWN ) {

			if ( resumeSelected ) {

				resumeSelected = false;
				exitSelected = true;

			}
			else {

				resumeSelected = true;
				exitSelected = false;
			
			}

		}
	
	}
	
	void PauseMenu::draw() {

		glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		glRasterPos2i( ( _winSize[ 0 ] - _pauseBitsSize[ 0 ] ) / 2, 450 );
		glDrawPixels( ( GLsizei )_pauseBitsSize[ 0 ], ( GLsizei )_pauseBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, pauseBits );

		
		if ( resumeSelected ) {

			glRasterPos2i( ( _winSize[ 0 ] - _resumeSelectedBitsSize[ 0 ] ) / 2, 300 );
			glDrawPixels( ( GLsizei )_resumeSelectedBitsSize[ 0 ], ( GLsizei )_resumeSelectedBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, resumeSelectedBits );

		}
		else {

			glRasterPos2i( ( _winSize[ 0 ] - _resumeBitsSize[ 0 ] ) / 2, 300 );
			glDrawPixels( ( GLsizei )_resumeBitsSize[ 0 ], ( GLsizei )_resumeBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, resumeBits );

		}
		
		if ( exitSelected ) {

			glRasterPos2i( ( _winSize[ 0 ] - _exitSelectedBitsSize[ 0 ] ) / 2, 200 );
			glDrawPixels( ( GLsizei )_exitSelectedBitsSize[ 0 ], ( GLsizei )_exitSelectedBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, exitSelectedBits );

		}
		else {

			glRasterPos2i( ( _winSize[ 0 ] - _exitBitsSize[ 0 ] ) / 2, 200 );
			glDrawPixels( ( GLsizei )_exitBitsSize[ 0 ], ( GLsizei )_exitBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, exitBits );

		}

		cg::Util::instance()->drawBitmapString("Press [R] to resume game.",10, 10 );
		cg::Util::instance()->drawBitmapString("Press [ESCAPE] to exit game.",10, 20 );

	}

}