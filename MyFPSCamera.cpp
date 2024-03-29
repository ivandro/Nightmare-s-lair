// This file is an example for CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho

#include "MyFPSCamera.h"

namespace example {

    MyFPSCamera::MyFPSCamera( std::string id ) : Entity( id ) {
				glutSetCursor(GLUT_CURSOR_NONE );
	}
    MyFPSCamera::~MyFPSCamera() {
	}
    void MyFPSCamera::init() {
		cg::tWindowInfo win = cg::Manager::instance()->getApp()->getWindowInfo();
		_winSize.set(win.width,win.height);
		_orientation.setRotationDeg(0,cg::Vector3d::ny);
		_up.set(0,1,0);
		_front.set(1,0,0);
		_right.set(0,0,1);
		_isRoll = false;
		_isFPSMode = true;
		_isFirst = true;
		_position.set(0,0,0);
    }

	/*
	**	name: draw
	**	description: draw the world in first person view 
	**  detailed description: 
	**		camera movement: move the rest of the world in the oposite direction of the camera to give the ilusion that the camera as moved
	**		save camera modelview disposition: save the earlier modelview matrix, allowing objects that don't want to move with the rest of the 
	**	  world, making the ilusion that they are following the camera 
	*/
    void MyFPSCamera::draw() {
		
		if( _isFPSMode ) {

			_isFirst = false;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(80,_winSize[0]/(double)_winSize[1], 0.25, 100.0 );
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			GLdouble eyeX = _position[ 0 ];
			GLdouble eyeY = _position[ 1 ] + 2.5; // 2.5 makes the camera a little above from the player object
			GLdouble eyeZ = _position[ 2 ];
			
			GLdouble initialXOrientation = 90.0;
			GLdouble initialYOrientation = 29.0;
			
			// unchanged matrix 

			
			fpsCameraPhysics.cameraRotation( initialXOrientation, 0.0, 1.0, 0.0 );
			fpsCameraPhysics.cameraRotation( initialYOrientation, 0.0, 0.0, 1.0 );
			glPushMatrix();
			
			fpsCameraPhysics.cameraTranslation( eyeX, eyeY, eyeZ );

			// save unchanged modelView matrix
			glGetDoublev( GL_MODELVIEW_MATRIX, unchangedModelViewMatrix );

			glPopMatrix();

			// pensava que o produto de rota��es fosse comutativo, mas por alguma raz�o se mudar a ordem destes dois metodos
			// o movimento da camera fica todo errado

			fpsCameraPhysics.cameraRotation( fpsCameraPhysics.getCameraRotationY(), 0.0, 0.0, 1.0 );
			fpsCameraPhysics.cameraRotation( -fpsCameraPhysics.getCameraRotationX(), 0.0, 1.0, 0.0 );

			fpsCameraPhysics.cameraTranslation( eyeX, eyeY, eyeZ );
			
		}
		else {
		
			// do nothing!

		}

    }
	
	void MyFPSCamera::onReshape(int width, int height) {
		_winSize.set(width,height);
	}

	void MyFPSCamera::toggleFPSMode() {
		_isFPSMode = !_isFPSMode;
		
		if ( _isFPSMode ) {

			
			glutSetCursor( GLUT_CURSOR_NONE  );

		}
		else {

			glutSetCursor( GLUT_CURSOR_INHERIT );

		}
	}


	bool MyFPSCamera::isActive(){
		return _isFPSMode;
	}

	void MyFPSCamera::setPosition(cg::Vector3d position){
		_position.set(position);
	}
	
	void MyFPSCamera::onMousePassiveMotion( int x, int y ) {

		onMouseMotion( x, y );
		
	}
	
	void MyFPSCamera::update( unsigned long ellapsedMilis ) {
		
		glutWarpPointer( _winSize[ 0 ] / 2.0, _winSize[ 1 ] / 2.0);

	}

	/*
	** name: onMouseMotion
	** description: make the camera look at where the mouse is pointing
	** parameters:
	**		x - x mouse position
	**		y - y mouse position
	*/

	void MyFPSCamera::onMouseMotion( int x, int y ) {
		
		fpsCameraPhysics.calculateCameraRotationVector( x, y, _winSize );

	}

	GLdouble* MyFPSCamera::getUnchangedMVMatrix() {

		return &unchangedModelViewMatrix[ 0 ];
		
	}

	/*
	** name: getRotationX
	** description: fps camera rotation in the horizontal ( y axis but is the x that changes)
	** return: the x rotation
	*/

	GLdouble MyFPSCamera::getRotationX() {

		return fpsCameraPhysics.getCameraRotationX();

	}

	/*
	** name: isFPSMode
	** description: sees if the actual camera showing is the FPS
	** return: answer to the question " we are at the fps camera right now? "
	*/

	bool MyFPSCamera::isFPSMode() {

		return _isFPSMode;
}
	cg::Vector3d MyFPSCamera::getPosition(){
		return _position;
	}

}
