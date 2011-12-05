#ifndef MY_DEBUG_CAMERA_H
#define MY_DEBUG_CAMERA_H

#include <string>
#include "cg/cg.h"
#include "MyPhysics.h"
#include "MyFPSCamera.h"

#define PI 3.198
#define degreeToRadianus ( 2 * PI ) / 360
namespace example {

    class DebugCamera : public cg::Entity, 
		public cg::IDrawListener,
		public cg::IReshapeEventListener,
		public cg::IUpdateListener,
		public cg::IMouseEventListener
	{
    private:
		cg::Vector2d _winSize;
		cg::Vector3d _up,_front,_right;
		bool _isDebugMode;

    public:	
		MyPhysics _physics;
		DebugCamera( std::string id );
        virtual ~DebugCamera();
        void init();
        void draw();
        void onReshape(int width, int height);
		void toggleDebugMode();
		bool isActive();
		void setPosition(cg::Vector3d position);
		void update(unsigned long elapsed_millis);

		void onMousePassiveMotion(int x, int y);
		void onMouseMotion(int x, int y);

	};
}

#endif
