#ifndef MUNITION_H
#define MUNITION_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"
#include "MunitionObserver.h"
//#include "MyBox.h" //to change

namespace example {

	class Munition : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener
	{
	private:
		MunitionObserver *munitionObserver;
		std::string id;
		MyPhysics _physics;
		GLUquadricObj *_sphereObj;
		int _modelMunition;
		int _materialDL;
		void makeSphere();
		void makeMunitionModel();
		void makeMaterial();
		bool isActive, _disappear;
		double timer;
		double timeToLive;
		bool flying;

	public:
		Munition(std::string id);
		Munition( std::string i, MunitionObserver *munitionObserver );
		~Munition();
		void setMunitionObserver( MunitionObserver *munitionObserver );
		void init();
		void update(unsigned long elapsed_millis);
		void draw();

		void shoot();

		void setPosition( cg::Vector3d position );
		void setOrientation( cg::Vector3d up, cg::Vector3d front, cg::Vector3d right );
		void Collision();
		void setTimer( double seconds );
		bool currentlyActive();

	private:
		void actualizeTimer( double timePassed );
		void initTimer();
		void endTimer();
		bool isEndTimer();
		void fly();		// munition fly animation
	
	};

}

#endif