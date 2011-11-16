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

#include "MyApp.h"

namespace example {

	MyApp::MyApp() {
		_windowInfo.caption = "Nightmare's Lair";				        
		_windowInfo.x = 550;
		_windowInfo.y = 0;
		_windowInfo.width = 800; 
		_windowInfo.height = 600; 
	}
	MyApp::~MyApp() {
	}
	void MyApp::createEntities() {

		addEntity( new MyScene( "Scene" ) );
		addEntity( new MyFPSCamera( "FPSCamera" ) );
		addEntity( new MyCamera( "Camera" ) );
		addEntity( new DebugCamera( "DebugCamera" ) );	
		addEntity( new MyLight( "Sun" ) );
		addEntity( new MyController( "Controller" ) );
		addEntity( new TextureBank( "TextureBank" ) );
		addEntity( new MyWorld( "World" ) );
		addEntity( new MainCharacter( "MainCharacter" ) );
		addEntity( new Heart( "Heart" ) );
		addEntity( new Key( "Key" ) );
		addEntity( new Stone( "Stone" ) );
		addEntity(new Rabbit("rabbit"));
		addEntity(new Munition("munition"));
		addEntity(new GroundMunition("groundmunition"));
		addEntity( new Observer( "Observer" ) );
		
	}
	void MyApp::createViews() {
	
		cg::View* v = createView( "view" );
		v->linkEntityAtEnd( "Scene" );
		v->linkEntityAtEnd( "FPSCamera" ); 
		v->linkEntityAtEnd( "Camera" ); 
		v->linkEntityAtEnd( "DebugCamera" ); 
		v->linkEntityAtEnd( "Sun" );
		v->linkEntityAtEnd( "World" ); 
		v->linkEntityAtEnd( "Heart" );
		v->linkEntityAtEnd( "Key" );
		v->linkEntityAtEnd( "Stone" );
		v->linkEntityAtEnd("rabbit");
	//	v->linkEntityAtEnd("munition");
		v->linkEntityAtEnd("groundmunition");
		v->linkEntityAtEnd( "MainCharacter" );
		v->linkEntityAtEnd( "Controller" );
		v->linkEntityAtEnd( "Observer" );	
		example::World *world = new example::GrassWorld();
		world->generateWorld("Images\\WorldMap\\Map.bmp",5.0f);
	}


}