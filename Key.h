#ifndef KEY_H
#define KEY_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"

namespace example {

	class Key : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener 
	{
	private:
		MyPhysics _physics;
		GLUquadricObj *_cylinderObj, *_TorusObj;
		int _modelCylinder, _modelTorus, _modelHead;
		int _materialDL;
		void makeCylinder();
		void makeTorus();
		void makeCylinderModel();
		void makeTorusModel();
		void drawCube();
		void makeHead();
		void makeMaterial();
	public:
		Key(std::string id);
		~Key();
		void init();
		void update(unsigned long elapsed_millis);
		void draw();
	};

}

#endif