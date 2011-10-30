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

    MyFPSCamera::MyFPSCamera() : Entity("FPSCamera"), xRotation( 0.0 ), yRotation( 0.0 ) {
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

			glutSetCursor( GLUT_CURSOR_CROSSHAIR );
			glutWarpPointer( _winSize[ 0 ] / 2, _winSize[ 1 ] / 2);

			_isFirst = false;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(80,_winSize[0]/(double)_winSize[1], 1.0, 100.0 );
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			GLdouble eyeX = _position[ 0 ];
			GLdouble eyeY = _position[ 1 ] + 2.5; // 2.5 makes the camera a little above from the player object
			GLdouble eyeZ = _position[ 2 ];
			
			GLdouble initialYOrientation = -90.0;
			GLdouble initialXOrientation = -29.0;
			
			// unchanged matrix 
			glPushMatrix();
			
			
			glRotated( initialYOrientation, 0.0, 1.0, 0.0 );
			glRotated( initialXOrientation , 0.0, 0.0, 1.0 );
			glTranslated( -eyeX, -eyeY, -eyeZ );

			// save unchanged modelView matrix
			glGetDoublev( GL_MODELVIEW_MATRIX, unchangedModelViewMatrix );

			glPopMatrix();

			// move the world such that look the camera is looking to the mouse position
			glRotated( initialYOrientation , 0.0, 1.0, 0.0 );
			glRotated( -yRotation, 0.0, 0.0, 1.0 );
			glRotated( initialXOrientation , 0.0, 0.0, 1.0 );
			glRotated( xRotation, 0.0, 1.0, 0.0 );
			// move the camera to eyeX
			glTranslated( -eyeX, -eyeY, -eyeZ );
			
		}
		else {
		
			glutSetCursor( GLUT_CURSOR_INHERIT );

		}

    }
	
	void MyFPSCamera::onReshape(int width, int height) {
		_winSize.set(width,height);
	}

	void MyFPSCamera::toggleFPSMode() {
		_isFPSMode = !_isFPSMode;
	}


	void MyFPSCamera::setPosition(cg::Vector3d position){
		_position.set(position);
	}
	
	void MyFPSCamera::onMousePassiveMotion( int x, int y ) {

		onMouseMotion( x, y );
		
	}

	/*
	** name: onMouseMotion
	** description: make the camera look at where the mouse is pointing
	** parameters:
	**		x - x mouse position
	**		y - y mouse position
	*/

	void MyFPSCamera::onMouseMotion( int x, int y ) {

		// calculate the diference of the  x mouse position and the middle of the window
	
		GLdouble xMiddleWindowPos = ( GLdouble )_winSize[ 0 ] / 2.0;
		GLdouble xDiff = x - xMiddleWindowPos;
		
		// multiply that diference by the x degree of rotation
	
		GLdouble xDegreeOfRotation = 360.0 / ( GLdouble )_winSize[ 0 ];
		if ( xDiff > 0 ) {

			xRotation += xDegreeOfRotation * 4;// * xDiff;
		}
		else if ( xDiff < 0 ) {

			xRotation -= xDegreeOfRotation * 4;

		}
		if ( xRotation > 180 ) {

			xRotation -= 360;

		}
		else if ( xRotation < -180 ) {

			xRotation += 360;

		}
		else {

			// não faz nada! x está entre os valores esperados

		}

		std::cout << " xRotation is " << xRotation << std::endl;

		// calculate the diference of the  y mouse position and the middle of the window
	
		GLdouble yMiddleWindowPos = ( GLdouble )_winSize[ 1 ] / 2.0;
		GLdouble yDiff = y - yMiddleWindowPos;
		
		// multiply that diference by the y degree of rotation
		GLdouble yDegreeOfRotation = 180.0 / ( GLdouble )_winSize[ 1 ];
		GLdouble nextYRotation;
		if ( yDiff > 0 ) {

			nextYRotation = yRotation + ( yDegreeOfRotation * 4 );
			if ( nextYRotation > 90 ) {

				nextYRotation = 90;

			}
		
		}
		else if ( yDiff < 0 ) {

			nextYRotation = yRotation - ( yDegreeOfRotation * 4 );
			if ( nextYRotation < -90 ) {

				nextYRotation = -90;

			}

		}else {

			// the yDiff is 0 so the nextYRotation is equal to the yRotation
			
			nextYRotation = yRotation;

		}

		
		yRotation = nextYRotation;
		std::cout << " yDiff " << yDiff << std::endl;
		std::cout << " yRotation is " << yRotation << std::endl;

	}

	GLdouble* MyFPSCamera::getUnchangedMVMatrix() {

		return &unchangedModelViewMatrix[ 0 ];

	}

}
