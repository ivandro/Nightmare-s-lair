#ifndef MUNITION_H
#define MUNITION_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"
#include "MyBox.h" //to change

namespace example {

	class Munition : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener
	{
	private:
		MyPhysics _physics;
		GLUquadricObj *_sphereObj;
		int _modelMunition;
		int _materialDL;
		void makeSphere();
		void makeMunitionModel();
		void makeMaterial();
		bool _disappear;

	public:
		Munition(std::string id);
		~Munition();
		void init();
		void update(unsigned long elapsed_millis);
		void draw();

		void attack();
		void reborn();
	};

}

#endif