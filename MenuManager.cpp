#include "MenuManager.h"

namespace example {
	
	MenuManager::MenuManager( std::string id, MenuTypes menuType ): cg::Entity( id ), actualMenuMode( menuType ){

	}
	
	MenuManager::~MenuManager() {}
	
	void MenuManager::init() {
	
		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		_winSize.set(win.width,win.height);

	}


	// draw listener Methods
	

	void MenuManager::draw(  ) { 
	
		std::cout << "ivandro sabes bem" << std::endl;
		if ( actualMenuMode == NONE_MENU ) {

			// menu draw is disabled

		}
		else {//if ( actualMenuMode == BEGIN_MENU ) {
			// adequerir informação sobre imagem

			//textureBank.loadImage( TEXTURE_WALL );
			FREE_IMAGE_FORMAT fileFormat = FreeImage_GetFileType( "Images\\Wall\\dirtyWall\\grass.tga", 0 );
			FIBITMAP *fiWall = FreeImage_Load( fileFormat, "somefile", 0);
			fiWall = FreeImage_ConvertTo32Bits( fiWall );
			if ( fiWall != NULL ) {
				int width = FreeImage_GetWidth( fiWall );
				_winSize[ 0 ] = FreeImage_GetWidth( fiWall );
				int height =  FreeImage_GetHeight( fiWall );
				_winSize[ 1 ] = FreeImage_GetHeight( fiWall );

				BYTE *bits = new BYTE[ width * height * 4 ];

				BYTE *pixels = (BYTE *)FreeImage_GetBits( fiWall );

				for(int pix=0; pix < _winSize[ 0 ] * _winSize[ 1 ]; pix++) {

					bits[ pix*4 + 0 ] = pixels[ pix*4 + 2 ];
					bits[ pix * 4 + 1 ] = pixels[ pix * 4 + 1 ];
					bits[ pix * 4 + 2 ] = pixels[ pix * 4 + 0 ];
					bits[ pix* 4 + 3 ] = pixels[ pix * 4  + 3 ];

				}


		
				// draw begin of the game menu
				glClearColor( 0.0, 0.0, 0.0, 0.0 );
				glShadeModel( GL_FLAT );
				glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
				glClear( GL_COLOR_BUFFER_BIT );
				glRasterPos2i( 0, 0 );
				glDrawPixels( ( int )_winSize[ 0 ], ( int )_winSize[ 1 ], GL_RGBA, GL_UNSIGNED_BYTE, bits );
				glFlush();
			
			}
		}/*
		else if ( actualMenuMode == END_MENU ) {

			// draw end of the game menu
			glRasterPos2i( 0, 0 );

		}
		else if ( actualMenuMode == PAUSE_MENU ) {

			// draw pause menu
			glRasterPos2i( 0, 0 );

		}
		else {

			// menu mode not recognized

		}
	*/
	}

	

	// Miscellaneous


	void MenuManager::setMenu( MenuTypes menuType ) {
	
		std::cout << "Menu type now is " << menuType << std::endl;
		actualMenuMode = menuType;
	
	}

	bool MenuManager::inMenu() {
		
		if ( actualMenuMode == NONE_MENU ) {

			return false;

		}
		else {
			
			return true;

		}
	
	}

	bool MenuManager::inMenu( MenuTypes menuType ) {
	
		if ( actualMenuMode == menuType ) {

			return true;

		}
		else {

			return false;

		}
	
	}
	
}