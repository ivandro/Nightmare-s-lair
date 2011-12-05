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

#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H

#include "cg/cg.h"
#include "MyLight.h"
#include "MyTeapot.h"
#include "MyCamera.h"
#include "DebugCamera.h"
#include "MyFPSCamera.h"
#include "MainCharacter.h"
#include "Cloud.h"
#include "MyLight.h"
#include "Observer.h"
#include "TextureBank.h"
#include "NightTagFileConverter.h"
#include "PauseMenu.h"

namespace example {

	#define KEY_ESCAPE 27
	#define KEY_PAUSE 'p'

	class MyController : public cg::Entity,
		public cg::IKeyboardEventListener,
		public cg::IDrawListener
	{
	private:
		
			TextureBank *textureBank;
			TagFileBitmapConverter *tagFileBitmapConverter;
			std::map< TextureTags, GLint > *textureBankSave;

	public:
		MyController( std::string id );
		~MyController();
		void init();
        void onKeyPressed(unsigned char key);
        void onKeyReleased(unsigned char key);
        void onSpecialKeyPressed(int key);
        void onSpecialKeyReleased(int key);
	};
}

#endif