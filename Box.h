#ifndef BOXED_H
#define BOXED_H

namespace example {

	
	
	class Box {
		
	public :
		enum EntityType {
			BOX_PLAYER, BOX_ENEMY, BOX_OBSTACLE, BOX_POWERUP, BOX_EXTRA, BOX_KEY,BOX_DOOR};

		EntityType _type;
		float _height;
		float _maxX;
		float _maxZ;



		Box(EntityType type, float height,float maxX, float maxZ); //max values corresponde to the length of the max line between center and zmax, amongst all rotations
		~Box();
		float getHeight();
		float getMaxX();
		float getMaxZ();
		EntityType getType();
	};


	
}

#endif