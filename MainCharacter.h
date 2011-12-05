#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H


#include "cg/cg.h"
#include "MyPhysics.h"
#include "MyFPSCamera.h"
#include "BlockCollisionsManager.h"
#include "Cloud.h"
#include "MaterialBank.h"
#include "BoxEntity.h"
#include "BoxCollisionManager.h"
#include "MyLight.h"
#include "MunitionManager.h"
#include "Door.h"

#define PI 3.198
#define degreeToRadianus ( 2 * PI ) / 360

namespace example {
	class MainCharacter : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener,
		public cg::IMouseEventListener,
		public BoxEntity
	{
	private:
		int _modelDL;
		BlockCollisionsManager * _CM;
		BoxCollisionManager *_BM;
		cg::Vector3d m_lastMousePosition;
		cg::Vector3d _lastposition;
		bool _movable, _isDebug;
		float rotRightArm;
		float rotRightLeg;
		float rotLeftArm;
		float rotLeftLeg;
		bool movingRightUp;
		bool movingRightForward;
		bool movingLeftUp;
		bool movingLeftForward;
		float _blocksize;
		int _x,_y;
		int _LifeCount, _MunitionCount,_keyCount;
		MunitionManager *munitionManager;
		bool munitionRecharged;
		double munitionRechargeTime;

	
	public:
		MyPhysics _physics;

		MainCharacter(int x, int y, float blocksize, std::string id, BlockCollisionsManager * cm, BoxCollisionManager *bm);
		~MainCharacter();

        void init();
        void update(unsigned long elapsed_millis);
		void onMousePassiveMotion(int x, int y);
		void onMouse(int button, int state, int x, int y);

		void drawMainCharacter();
        void draw();
		void togglemovable();
		void toggleDebugMode();

		void fpsTransformationBegin();
		void fpsTransformationEnd();
		
		void moveRightArm();
		void moveRightLeg();
		void moveLeftArm();
		void moveLeftLeg();
		void checkColisions(cg::Vector3d oldPos, cg::Vector3d newPos);
		void rechargeMunition( double seconds );
		void initializeMunitionRecharge( double seconds );
		int getNLifes();
		int getNMunitions();
		cg::Vector2d getCharPos();

	};
}

#endif