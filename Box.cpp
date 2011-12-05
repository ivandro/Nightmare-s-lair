
#include "Box.h"

namespace example {

	
		Box::Box(EntityType type, float height,float maxX, float maxZ) : 
			_type(type), _height(height), _maxX(maxX), _maxZ(maxZ)
		{}

		Box::~Box(){}
		
		float Box::getHeight(){return _height;}
		float Box::getMaxX(){return _maxX;}
		float Box::getMaxZ(){return _maxZ;}
		Box::EntityType Box::getType(){return _type;}

}