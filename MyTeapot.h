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

#ifndef MY_TEABOX_H
#define MY_TEABOX_H

#include <string>
#include "cg/cg.h"
#include "MyPhysics.h"
#include "MaterialBank.h"
namespace example {

	class MyTeapot : public cg::Entity,
		public cg::IDrawListener,
		public cg::IUpdateListener
	{
	private:
		int _modelDL;
		void makeModel();

		int _materialDL;
		void makeMaterial();

		MyPhysics _physics;

		bool _debugMode;

	public:
		MyTeapot(std::string id);
		~MyTeapot();
		
		void init();
		void update(unsigned long elapsed_millis);
		void draw();

		void toggleDebugMode();
	};
}

#endif