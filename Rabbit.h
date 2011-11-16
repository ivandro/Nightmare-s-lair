#ifndef RABBIT_H
#define RABBIT_H

#include "cg/cg.h"
#include "MyPhysics.h"
#include "MaterialBank.h"

namespace example {
	class Rabbit : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener
	{
	private:
		int _modelEar, _modelBody, _modelFoot;
		bool _isDebug;
		void drawCube();
		void makeEar();
		void makeBody();
		void makeFoot();
		void makeMaterial();
		int _materialDL;
		bool _animationflag;
		float _timer;

		double _angle;
		float _rotateFace;
		int faceMod, rotatefaceMod;

	public:		
		MyPhysics _physics;

		Rabbit(std::string id);
		~Rabbit();

        void init();
        void update(unsigned long elapsed_millis);
        void draw();
		void toggleDebugMode();
	//	void timeRemanant();

	};
}

#endif