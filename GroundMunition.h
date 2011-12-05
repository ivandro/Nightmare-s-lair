#ifndef GroundMunition_H
#define GroundMunition_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"

namespace example {

	class GroundMunition : public cg::Entity,
				public cg::IUpdateListener,
				public cg::IDrawListener 
	{
	private:
		MyPhysics _physics;
		GLUquadricObj *_sphereObj;
		int _modelGroundMunition;
		int _materialDL;
		void makeSphere();
		void makeGroundMunitionModel();
		void makeMaterial();
		float _rotateFace;
		int rotatefaceMod;

		cg::Vector2f _pos;
		float _blocksize;

	public:
		GroundMunition(int x, int y, float blocksize, std::string id);
		~GroundMunition();
		void update(unsigned long elapsed_millis);
		void init();
		void draw();
	};

}

#endif