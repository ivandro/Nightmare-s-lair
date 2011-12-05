#include "BoxEntity.h"

namespace example {

		BoxEntity::BoxEntity(Box * box, float damage, cg::Vector3f center) : 
		_box(box), _damage(damage), _center(center)
		{}

		BoxEntity::~BoxEntity(){
		}
		
		Box * BoxEntity::getbox() { return _box;}
		
		cg::Vector3f BoxEntity::getCenter(){ return _center;}
		
		void BoxEntity::setCenter(cg::Vector3f center){ _center = center;}

		float BoxEntity::getDamage(){return _damage;}

		void  BoxEntity::debugBox(cg::Vector3f color){
			glPushMatrix();
				glBegin(GL_LINE_STRIP);
					glColor3f(color[0],color[1],color[2]);
					glVertex3f(_center[0]-_box->getMaxX(),0,_center[2]-_box->getMaxZ());
					glVertex3f(_center[0]-_box->getMaxX(),0,_center[2]+_box->getMaxZ());
					glVertex3f(_center[0]+_box->getMaxX(),0,_center[2]+_box->getMaxZ());
					glVertex3f(_center[0]+_box->getMaxZ(),0,_center[2]-_box->getMaxZ());
					glVertex3f(_center[0]-_box->getMaxX(),0,_center[2]-_box->getMaxZ());
				glEnd();
			glPopMatrix();
		}

		void BoxEntity::playerCollision(){}
}