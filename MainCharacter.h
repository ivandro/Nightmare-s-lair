#ifndef BOX_H
#define BOX_H

#include "cg/cg.h"
#include "MyPhysics.h"
#include "MyFPSCamera.h"
#include "MaterialBank.h"

#define PI 3.198
#define degreeToRadianus ( 2 * PI ) / 360

namespace example {
	class MainCharacter : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener,
		public cg::IMouseEventListener
	{
	private:
		int _modelDL;
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

		

	public:
		MyPhysics _physics;

		MainCharacter(std::string id);
		~MainCharacter();

        void init();
        void update(unsigned long elapsed_millis);
		void onMousePassiveMotion(int x, int y);
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

	};
}

#endif