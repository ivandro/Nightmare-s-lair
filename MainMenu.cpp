#include "MainMenu.h"

namespace example {

	MainMenu::MainMenu( std::string id, cg::Application *application ) : cg::Entity( id ), m_application( application ),
		playSelected( true ), exitSelected( false ) {
	
		imagePaths[ 0 ] = "Images\\Menu\\Image1.png";
		imagePaths[ 1 ] = "Images\\Menu\\Image2.png";
		imagePaths[ 2 ] = "Images\\Menu\\Image3.png";
		actualImage = 0;
		imageTime = 0;
	
	}

	MainMenu::~MainMenu() {}

	void MainMenu::init() {

		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		_winSize.set(win.width,win.height);
	
		resourceLoader = new ResourceLoader();
		
		glShadeModel( GL_SMOOTH );

		imageBits = resourceLoader->loadImage( imagePaths[ actualImage ] );
		_imageBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_imageBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		titleBits = resourceLoader->loadImage( "Images\\Menu\\MenuTitle2.png" );
		_titleBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_titleBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		
		playBits = resourceLoader->loadImage( "Images\\Menu\\Play1.png" );
		_playBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_playBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		
		playSelectedBits = resourceLoader->loadImage( "Images\\Menu\\Play1Selected.png" );
		_playSelectedBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_playSelectedBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		
		exitBits = resourceLoader->loadImage( "Images\\Menu\\Exit1.png" );
		_exitBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_exitBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		
		exitSelectedBits = resourceLoader->loadImage( "Images\\Menu\\Exit1Selected.png" );
		_exitSelectedBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
		_exitSelectedBitsSize[ 1 ] = resourceLoader->getLastImageHeight();
		
		
		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	
	}

	void MainMenu::onKeyPressed( unsigned char key ) {

		if ( key == KEY_START ) {

			startGame();

		}
		else if ( key == KEY_ESCAPE ) {

			exitGame();

		}
		else if ( key == KEY_ENTER || key == 'e') {

			if ( playSelected ) {

				startGame();

			}
			else {

				exitGame();

			}
			

		}

	}

	void MainMenu::startGame() {
		
		// disable MainMenu
		this->state.disable();
		std::cout << "[MainMenu.ccp-startGame]:Main Menu disable " << std::endl;
		
		createEntities();
		createViews();
		
		cg::Registry::instance()->init();

	}

	void MainMenu::exitGame() {

			cg::Manager::instance()->shutdownApp();

	}

	void MainMenu::createEntities() {

		cg::Registry *registry = cg::Registry::instance();
		registry->add( new MyScene( "Scene" ) );
		registry->add( new MyFPSCamera( "FPSCamera" ) );
		registry->add( new MyCamera( "Camera" ) );
		registry->add( new DebugCamera( "DebugCamera" ) );	
		registry->add( new TextureBank( "TextureBank", new GrassTagFileConverter() ) );
		registry->add( new MyController( "Controller" ) );
		registry->add( new MunitionManager( "munition manager",  3 ) );
		registry->add( new Observer( "Observer" ) );
		registry->add( new HUD( "HUD" ) );

	}
	void MainMenu::createViews() {
	
		
		cg::Registry *registry = cg::Registry::instance();
		cg::View *v = ( cg::View* )registry->get( "view" );

		v->linkEntityAtEnd( "Scene" );
		v->linkEntityAtEnd( "FPSCamera" );
		v->linkEntityAtEnd( "Camera" );
		v->linkEntityAtEnd( "DebugCamera" );	
		v->linkEntityAtEnd( "TextureBank");
		v->linkEntityAtEnd( "Controller" );
		v->linkEntityAtEnd( "munition manager");
		v->linkEntityAtEnd( "Observer" );
		v->linkEntityAtEnd( "HUD" );

		example::World *world = new example::GrassWorld();
		world->generateWorld("Images\\WorldMap\\Map.bmp",5.0f);
		world->populateWorld();
		
	}

	void MainMenu::onSpecialKeyPressed(int key) {
	
		if ( key == GLUT_KEY_UP || key == GLUT_KEY_DOWN ) {

			if ( playSelected ) {

				playSelected = false;
				exitSelected = true;

			}
			else {

				playSelected = true;
				exitSelected = false;
			
			}

		}

	}

	
	void MainMenu::update( unsigned long ellapsedMilis ) {

		imageTime += ellapsedMilis;

		if ( imageTime > 3000 ) {
			
			imageTime = 0;
			actualImage = ( actualImage + 1 ) % NUMBER_OF_IMAGES;
			imageBits = resourceLoader->loadImage( imagePaths[ actualImage ] );
			_imageBitsSize[ 0 ] = resourceLoader->getLastImageWidth();
			_imageBitsSize[ 1 ] = resourceLoader->getLastImageHeight();

		}

	}
	
	void MainMenu::draw() {
		
		glClearColor( 0.0f, 1.0f, 1.0f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		glRasterPos2i( 100, 450 );
		glDrawPixels( ( GLsizei )_titleBitsSize[ 0 ], ( GLsizei )_titleBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, titleBits );
		
		if ( playSelected ) {
			glRasterPos2i( 10, 270 );
			glDrawPixels( ( GLsizei )_playSelectedBitsSize[ 0 ], ( GLsizei )_playSelectedBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, playSelectedBits );
		}
		else {

			
			glRasterPos2i( 10, 270 );
			glDrawPixels( ( GLsizei )_playBitsSize[ 0 ], ( GLsizei )_playBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, playBits );

		}

		if ( exitSelected ) {
			
			glRasterPos2i( 10, 200 );
			glDrawPixels( ( GLsizei )_exitSelectedBitsSize[ 0 ], ( GLsizei )_exitSelectedBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, exitSelectedBits );
		
		}
		else {

			glRasterPos2i( 10, 200 );
			glDrawPixels( ( GLsizei )_exitBitsSize[ 0 ], ( GLsizei )_exitBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, exitBits );

		}

		
		glRasterPos2i( ( ( GLint )_winSize[ 0 ] - 10 ) / 2, 150 );
		glDrawPixels( ( GLsizei)_imageBitsSize[ 0 ], ( GLsizei )_imageBitsSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, imageBits );

		glFlush();

		
		cg::Util::instance()->drawBitmapString("Press [ESC] to exit.",10,10);
		cg::Util::instance()->drawBitmapString("Press [s] to start game.",10,30);

	}

}