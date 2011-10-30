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

#ifndef MY_PHYSICS_H
#define MY_PHYSICS_H

#include "cg/cg.h"

namespace example {

	class MyPhysics {
	private:
		cg::Vector3d _position;
		cg::Quaterniond _orientation;
		cg::Vector3d _front, _up, _right;
		double _linearVelocity;
		double _angularVelocity;
		double _backModifier;
		double _sideModifier;
		cg::Quaterniond _q;
		double _rotationMatrix[16];

		bool _isGoAhead, _isGoBack;
		bool _isYawLeft, _isYawRight;
		bool _isPitchUp, _isPitchDown;
		bool _isRollLeft, _isRollRight;
		bool _isStrafeLeft, _isStrafeRight;
		void rotate(double elapsed_seconds,int direction, cg::Vector3d axis, cg::Vector3d& v1, cg::Vector3d& v2);

		double _axesScale;

	public:
		MyPhysics();
		~MyPhysics();

		void goAhead();
		void goBack();
		void yawLeft();
		void yawRight();
		void pitchUp();
		void pitchDown();
		void rollLeft();
		void rollRight();
		void strafeLeft();
		void strafeRight();

		void setPosition(double x, double y, double z);
		void setLinearVelocity(double value);
		void setAngularVelocity(double value);
		void setBackModifier(double value);
		void setSideModifier(double value);
		cg::Vector3d getPosition();

		void step(double elapsed_seconds);
		void applyTransforms();

		void setAxesScale(double scale);
		void drawAxes();
	};

}

#endif