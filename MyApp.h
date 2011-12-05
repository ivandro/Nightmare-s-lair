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

#ifndef MY_APP_H
#define MY_APP_H

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
#include "Cloud.h"
#include "CloudRemanant.h"
#include "Observer.h"
#include "StringWorld.h"
#include "GrassWorld.h"
#include "Munition.h"
#include "TextureBank.h"
#include "GrassTagFileConverter.h"
#include "MenuManager.h"
#include "HUD.h"

namespace example {

	class MyApp : public cg::Application {
	public:
		MyApp();
		~MyApp();
		void createEntities();
		void createViews();
	};
}

#endif