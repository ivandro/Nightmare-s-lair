// This file is an example for CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho

#include "MyController.h"

namespace example {

	MyController::MyController( std::string id ) : cg::Entity( id ) {
	}
	MyController::~MyController() {
	}
	void MyController::init() {
		
		textureBank = (TextureBank *) cg::Registry::instance()->get( "TextureBank" );
		tagFileBitmapConverter = new NightTagFileConverter();
		textureBankSave = new std::map< TextureTags, GLint >();

	}
	void MyController::onKeyPressed( unsigned char key ) {

	if( key == 'c' ) {
			
			textureBank->changeConverter( &tagFileBitmapConverter, &textureBankSave );
		
		}
		else if ( key == KEY_PAUSE || key == KEY_ESCAPE ) {
			
			
			cg::Registry *registry = cg::Registry::instance();
			PauseMenu *pauseMenu;
			if ( pauseMenu = ( PauseMenu *)registry->get( "Pause Menu" ) ) {

				pauseMenu->init();
				pauseMenu->state.enable();

			}
			else {

				pauseMenu = new PauseMenu( "Pause Menu" );
				registry->add( pauseMenu );
				pauseMenu->init();
				cg::View *v = ( cg::View* )registry->get( "view" );
				v->linkEntityAtEnd( "Pause Menu" );

			}

			pauseMenu->disableEntities();

		}

	}
	void MyController::onKeyReleased(unsigned char key) {
	}
	void MyController::onSpecialKeyPressed(int key) {
	}
	void MyController::onSpecialKeyReleased(int key) {
        if (key == GLUT_KEY_F1) {
			cg::Manager::instance()->getApp()->dump();
        }
        if (key == GLUT_KEY_F2) {
			Observer *observer= (Observer*)cg::Registry::instance()->get("Observer");
			observer->toggleObjects();
			observer->activeDebug();

		}
		 if (key == GLUT_KEY_F3) {
			  
			Observer *observer= (Observer*)cg::Registry::instance()->get("Observer");
					 
			DebugCamera *debugcamera = (DebugCamera*)cg::Registry::instance()->get("DebugCamera");
			if(!debugcamera->isActive()) {
				MyFPSCamera *fpscamera = (MyFPSCamera*)cg::Registry::instance()->get("FPSCamera");
				MyCamera *camera = (MyCamera*)cg::Registry::instance()->get("Camera");
			
				MainCharacter *obj = (MainCharacter*)cg::Registry::instance()->get("MainCharacter");
				Cloud *cl = (Cloud*)cg::Registry::instance()->get("Nuvem");
			
				cl->togglemovable();
				obj->togglemovable();
				observer->toggleCameras();
				/*	if(camera){
					camera->toggleTopMode();			
				}
				if(fpscamera){
					fpscamera->toggleFPSMode();			
				}
				*/

			
			}
		 }
	}

}