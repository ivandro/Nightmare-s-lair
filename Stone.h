#ifndef Stone_H
#define Stone_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"

namespace example {

	class Stone : public cg::Entity,
		public cg::IDrawListener 
	{
	private:
		MyPhysics _physics;
		GLUquadricObj *_SphereObj, *_TorusObj;
		int _modelSphere, _modelTorus;
		int _materialDL;
		void makeSphere();
		void makeTorus();
		void makeSphereModel();
		void makeTorusModel();
		void makeMaterial();
	public:
		Stone(std::string id);
		~Stone();
		void init();
		void draw();
	};

}

#endif