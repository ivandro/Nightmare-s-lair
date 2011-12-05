#ifndef BOX_ENTITY_H
#define BOX_ENTITY_H

#include "Box.h"
#include "cg/cg.h"


namespace example {

	class BoxEntity {
	
	protected:
		
		Box * _box;
		float _damage; //different box entities allow different dmg
		cg::Vector3f _center;

	public:

		BoxEntity(Box * box, float damage, cg::Vector3f center);
		~BoxEntity();
		Box * getbox();
		cg::Vector3f getCenter();	
		void setCenter(cg::Vector3f center);
		float getDamage();
		virtual void playerCollision();
		void debugBox(cg::Vector3f color);
	};

}

#endif