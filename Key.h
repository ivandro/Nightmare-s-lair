#ifndef KEY_H
#define KEY_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"
#include "BoxEntity.h"

namespace example {

	class Key : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener,
		public BoxEntity
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
		cg::Vector2f _pos;
		float _blocksize;
		float _rotateFace;
		double _angle;
		int rotatefaceMod, faceMod;

	public:
		Key(int x, int y, float blocksize, std::string id);
		~Key();
		void init();
		void update(unsigned long elapsed_millis);
		void draw();
		void playerCollision();
	};

}

#endif