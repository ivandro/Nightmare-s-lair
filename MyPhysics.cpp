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

#include "MyPhysics.h"

namespace example {

	MyPhysics::MyPhysics() {
		_axesScale = 1.0;
		_position.set(0,0,0);
		_orientation.setRotationDeg(0,cg::Vector3d(0,1,0));
		_orientation.getGLMatrix(_rotationMatrix);
		_front.set(1,0,0);
		_up.set(0,1,0);
		_right.set(0,0,1);
		_linearVelocity = 0;
		_angularVelocity = 0;
		_backModifier = 0.4;
		_sideModifier = 0.7;
		_isGoAhead = false;
		_isGoBack = false;
		_isYawLeft = false;
		_isYawRight = false;
		_isPitchUp = false;
		_isPitchDown = false;
		_isRollLeft = false;
		_isRollRight = false;
		_isStrafeLeft =false;
		_isStrafeRight =false;

		cameraRotationVector[ 0 ] = 0.0;
		cameraRotationVector[ 1 ] = 0.0;

	}
	MyPhysics::~MyPhysics() {
	}
	void MyPhysics::setPosition(double x, double y, double z) {
		_position.set(x,y,z);
	}
	void MyPhysics::setLinearVelocity(double value) {
		_linearVelocity = value;
	}
	void MyPhysics::setAngularVelocity(double value) {
		_angularVelocity = value;
	}

	void MyPhysics::setBackModifier(double value) {
		_backModifier = value;
	}
	void MyPhysics::setSideModifier(double value) {
		_sideModifier = value;
	}

	cg::Vector3d MyPhysics::getPosition() {
		return _position;
	}


	void MyPhysics::goAhead() { _isGoAhead = true; }
	void MyPhysics::goBack() { _isGoBack = true; }
	void MyPhysics::yawLeft() { _isYawLeft = true; }
	void MyPhysics::yawRight() { _isYawRight = true; }
	void MyPhysics::pitchUp() { _isPitchUp = true; }
	void MyPhysics::pitchDown() { _isPitchDown = true; }
	void MyPhysics::rollLeft() { _isRollLeft = true; }
	void MyPhysics::rollRight() { _isRollRight = true; }
	void MyPhysics::strafeLeft() { _isStrafeLeft = true; }
	void MyPhysics::strafeRight() { _isStrafeRight = true; }


	inline
	void MyPhysics::rotate(double elapsed_seconds, int direction, 
						   cg::Vector3d axis, cg::Vector3d& v1, cg::Vector3d& v2) 
	{
		_q.setRotationDeg(direction * _angularVelocity * elapsed_seconds,axis);
		v1 = apply(_q,v1);
		v2 = apply(_q,v2);
		_orientation = _q * _orientation;
	}
	void MyPhysics::step(double elapsed_seconds) {
		if(_isStrafeLeft){
		 if(_isGoBack)
			_position +=_right * _linearVelocity * elapsed_seconds * _backModifier * _sideModifier;
		 else 
			_position +=_right * _linearVelocity * elapsed_seconds * _sideModifier;
		 _isStrafeLeft = false;
		}
		if(_isStrafeRight){
		  		 if(_isGoBack)
			_position -=_right * _linearVelocity * elapsed_seconds*_backModifier * _sideModifier;
		 else 
			_position -=_right * _linearVelocity * elapsed_seconds * _sideModifier;
		 _isStrafeRight = false;
		}
		if(_isGoAhead) {
			_position -= _front * _linearVelocity * elapsed_seconds;
			_isGoAhead = false;
		}
		if(_isGoBack) {
			_position += _front * _linearVelocity * elapsed_seconds*_backModifier;
			_isGoBack = false;
		}
		if(_isYawLeft) {
			rotate(elapsed_seconds,1,_up,_front,_right);
			_isYawLeft = false;
		}
		if(_isYawRight) {
			rotate(elapsed_seconds,-1,_up,_front,_right);
			_isYawRight = false;
		}
		if(_isPitchUp) {
			rotate(elapsed_seconds,1,_right,_up,_front);
			_isPitchUp = false;
		}
		if(_isPitchDown) {
			rotate(elapsed_seconds,-1,_right,_up,_front);
			_isPitchDown = false;
		}
		if(_isRollLeft) {
			rotate(elapsed_seconds,1,_front,_right,_up);
			_isRollLeft = false;
		}
		if(_isRollRight) {
			rotate(elapsed_seconds,-1,_front,_right,_up);
			_isRollRight = false;
		}
		_orientation.getGLMatrix(_rotationMatrix);
	}
	void MyPhysics::applyTransforms() {
        glTranslated(_position[0],_position[1],_position[2]);
		glMultMatrixd(_rotationMatrix);
	}
	void MyPhysics::setAxesScale(double scale) {
		_axesScale = scale;
	}
	void MyPhysics::drawAxes() {
		glPushMatrix();
			glTranslated(_position[0],_position[1],_position[2]);
			glScaled(_axesScale,_axesScale,_axesScale);
			glColor3f(1.0f,0.0f,0.0f);
			glBegin(GL_LINES);
				glVertex3d(0.0,0.0,0.0);
				glVertex3d(_front[0],_front[1],_front[2]);
			glEnd();
			glColor3f(0.0f,1.0f,0.0f);
			glBegin(GL_LINES);
				glVertex3d(0.0,0.0,0.0);
				glVertex3d(_up[0],_up[1],_up[2]);
			glEnd();
			glColor3f(0.0f,0.0f,1.0f);
			glBegin(GL_LINES);
				glVertex3d(0.0,0.0,0.0);
				glVertex3d(_right[0],_right[1],_right[2]);
			glEnd();
		glPopMatrix();
	}


	/*
	** name: calculateCameraRotationVector
	** description: calculate the  camera rotation vector correspondent with the mouse move  
	** parameters:
	**		x - x mouse position
	**		y - y mouse position
	**		_winSize - size of the game window
	*/
	void MyPhysics::calculateCameraRotationVector( int x, int y, cg::Vector2d _winSize ) {

		// calculate the diference of the  x mouse position and the middle of the window
	
		GLdouble xMiddleWindowPos = ( GLdouble )_winSize[ 0 ] / 2.0;
		GLdouble xDiff = x - xMiddleWindowPos;
		
		// multiply that diference by the x degree of rotation
	
	const double xRotationVelocity = 8;
		GLdouble xDegreeOfRotation = 360.0 / ( GLdouble )_winSize[ 0 ];
		if ( xDiff > 0 ) {

			cameraRotationVector[ 0 ] += xDegreeOfRotation * xRotationVelocity;// * xDiff;
		
		}
		else if ( xDiff < 0 ) {

			cameraRotationVector[ 0 ] -= xDegreeOfRotation * xRotationVelocity;

		}
		if ( cameraRotationVector[ 0 ] > 180 ) {

			cameraRotationVector[ 0 ] -= 360;

		}
		else if ( cameraRotationVector[ 0 ] < -180 ) {

			cameraRotationVector[ 0 ] += 360;

		}
		else {

			// não faz nada! x está entre os valores esperados

		}

		//std::cout << " xRotation is " << cameraRotationVector[ 0 ] << std::endl;

		// calculate the diference of the  y mouse position and the middle of the window
	
		GLdouble yMiddleWindowPos = ( GLdouble )_winSize[ 1 ] / 2.0;
		GLdouble yDiff = y - yMiddleWindowPos;
		
		// multiply that diference by the y degree of rotation
		GLdouble yDegreeOfRotation = 180.0 / ( GLdouble )_winSize[ 1 ];
		GLdouble nextYRotation;
		const double yRotationVelocity = 8;
		if ( yDiff > 0 ) {

			nextYRotation = cameraRotationVector[ 1 ] + ( yDegreeOfRotation * yRotationVelocity );
			if ( nextYRotation > 90 ) {

				nextYRotation = 90;

			}
		
		}
		else if ( yDiff < 0 ) {

			nextYRotation = cameraRotationVector[ 1 ] - ( yDegreeOfRotation * yRotationVelocity );
			if ( nextYRotation < -90 ) {

				nextYRotation = -90;

			}

		}else {

			// the yDiff is 0 so the nextYRotation is equal to the yRotation
			
			nextYRotation = cameraRotationVector[ 1 ];

		}

		
		cameraRotationVector[ 1 ] = nextYRotation;

		// std::cout << " yDiff " << yDiff << std::endl;
		// std::cout << " yRotation is " << cameraRotationVector[ 1 ] << std::endl;

	}

	/*
	** name: getCameraRotationX
	** description: acessor method for the x coordinate of the camera rotation vector
	** return: x coordinate of the camera rotation vector
	*/

	GLdouble MyPhysics::getCameraRotationX() {

		return cameraRotationVector[ 0 ];

	}

	/*
	** name: getCameraRotationY
	** description: acessor method for the y coordinate of the camera rotation vector
	** return: y coordinate of the camera rotation vector
	*/

	GLdouble MyPhysics::getCameraRotationY() {

		return cameraRotationVector[ 1 ];

	}

	/*
	** name: cameraRotation
	** description: rotate the camera
	** parameters:
	**		degree: angle( in degrees ) in wich the camera will be rotated
	**		xAxis: degree in which the rotation is made in the xAxis
	**		yAxis: degree in which the rotation is made in the yAxis
	**		zAxis: degree in which the rotation is made in the zAxis
	*/
	
	void MyPhysics::cameraRotation( GLdouble degree, GLdouble xAxis, GLdouble yAxis, GLdouble zAxis ) {

		glRotated( -degree, xAxis, yAxis, zAxis );

	}

	/*
	** name: cameraTranslation
	** description: translate the camera
	** parameters:
	**		x: the x coordinate camera displacement
	**		y: the y coordinate camera displacement
	**		z: the z coordinate camera displacement
	*/
	
	void MyPhysics::cameraTranslation( GLdouble x, GLdouble y, GLdouble z ) {

		glTranslated( -x, -y, -z );

	}

	/*
	** name: setFront
	** description: set the front vector
	** parameters:
	**		front - vector that points to the actual front direction
	*/
	
	void MyPhysics::setFront( cg::Vector3d front ) {

		_front = front;

	}

	/*
	** name: setRight
	** description: set the right vector
	** parameters:
	**		right - vector that points to the actual right direction
	*/

	void MyPhysics::setRight( cg::Vector3d right ) {

		_right = right;

	}

	/*
	** name: setUp
	** description: set the up vector
	** parameters:
	**		up - vector that points to the actual up direction
	*/

	void MyPhysics::setUp( cg::Vector3d up ) {

		_up = up;

	}

	
	cg::Vector3d MyPhysics::getFront() {

		return _front;

	}

	cg::Vector3d MyPhysics::getRight() {

		return _right;

	}

	cg::Vector3d MyPhysics::getUp() {

		return _up;

	}
}

	