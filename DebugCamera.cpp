#include "DebugCamera.h"

namespace example {

    DebugCamera::DebugCamera( std::string id ) : Entity(id) {
	}
    DebugCamera::~DebugCamera() {
	}
    void DebugCamera::init() {
		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		_winSize.set(win.width,win.height);
		_up.set(0,1,0);
		_front.set(1,0,0);
		_right.set(0,0,1);
		_isDebugMode = false;

		_physics.setPosition(3,1.01,-3);
		_physics.setAngularVelocity(1000);
		_physics.setLinearVelocity(100); 
		
    }
    void DebugCamera::draw() {

		if(_isDebugMode){
			/*cg::Vector3d _position = _physics.getPosition();
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(80,_winSize[0]/(double)_winSize[1],1.0,100.0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(_position[0],_position[1]+2.5,_position[2],_position[0]-3,
_position[1],_position[2],_up[0],_up[1],_up[2]);*/

		//	glutSetCursor( GLUT_CURSOR_CROSSHAIR );
			glutWarpPointer( _winSize[ 0 ] / 2.0, _winSize[ 1 ] / 2.0);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(80,_winSize[0]/(double)_winSize[1], 1.0, 100.0 );
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			cg::Vector3d _position = _physics.getPosition();
			GLdouble eyeX = _position[ 0 ];
			GLdouble eyeY = _position[ 1 ] + 2.5;
			GLdouble eyeZ = _position[ 2 ];
			
			GLdouble initialXOrientation = 90.0;
			GLdouble initialYOrientation = 29.0;
			
			_physics.cameraRotation( initialXOrientation, 0.0, 1.0, 0.0 );
			_physics.cameraRotation( initialYOrientation, 0.0, 0.0, 1.0 );
			
			_physics.cameraRotation( _physics.getCameraRotationY(), 0.0, 0.0, 1.0 );
			_physics.cameraRotation( -_physics.getCameraRotationX(), 0.0, 1.0, 0.0 );

			_physics.cameraTranslation( eyeX, eyeY, eyeZ );

			cg::Vector3d *newFront = new cg::Vector3d( cos( _physics.getCameraRotationX() * degreeToRadianus ), 0.0, sin( _physics.getCameraRotationX() * degreeToRadianus ) );
			cg::Vector3d *newRight = new cg::Vector3d( -sin( _physics.getCameraRotationX() * degreeToRadianus ), 0.0, cos( _physics.getCameraRotationX() * degreeToRadianus ) );

			
			_physics.setFront ( *newFront );
			_physics.setRight( *newRight );

		}
		/*else{
			glutSetCursor( GLUT_CURSOR_INHERIT );
		}*/
    }

	void DebugCamera::onReshape(int width, int height) {
		_winSize.set(width,height);
	}

	void DebugCamera::toggleDebugMode() {
		_isDebugMode = !_isDebugMode;
	}

	bool DebugCamera::isActive(){
		return _isDebugMode;
	}


	void DebugCamera::update(unsigned long elapsed_millis) {
		if(_isDebugMode){
			if(cg::KeyBuffer::instance()->isKeyDown('w')) {
				_physics.goAhead();		
			}
			if(cg::KeyBuffer::instance()->isKeyDown('s')) {
				_physics.goBack();	
			}
			if(cg::KeyBuffer::instance()->isKeyDown('a')) {
				_physics.strafeLeft();
			}
			if(cg::KeyBuffer::instance()->isKeyDown('d')) {
				_physics.strafeRight();
			}
			
			double elapsed_seconds = elapsed_millis / (double)10000;
			_physics.step(elapsed_seconds);		
			_physics.applyTransforms();
		}
	}

	void DebugCamera::onMousePassiveMotion( int x, int y ) {
		onMouseMotion( x, y );		
	}

	void DebugCamera::onMouseMotion( int x, int y ) {
		_physics.calculateCameraRotationVector( x, y, _winSize );
	}

}
