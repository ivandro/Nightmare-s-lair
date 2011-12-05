#ifndef BOX_COLLISION_MANAGER_H
#define BOX_COLLISION_MANAGER_H

#include "cg\cg.h"
#include "BoxEntity.h"
#include "Key.h"
#include <vector>

namespace example {

	class BoxCollisionManager {
		
	private:

		std::vector<BoxEntity *> _static;
		std::vector<BoxEntity *> _movable;

	public:

		enum CollisionType {
			X,
			Z,
			XZ,
			//Y
		};

		struct CollisionStats
		{
			CollisionType colType;
			Box::EntityType entType;
			int dmg;
		};
		BoxCollisionManager();
		~BoxCollisionManager();
		void addStatic(BoxEntity * statics);
		void addMovable(BoxEntity * movable);
		CollisionStats * checkBoxColision(Box * box, cg::Vector3d oldPos,cg::Vector3d newPos, std::string id);
		bool linearCollision(double max, double center, double otherMax,  double otherCenter);

	};

}

#endif