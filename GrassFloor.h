#ifndef GRASS_FLOOR_H
#define GRASS_FLOOR_H

#include "Floor.h"

namespace example {

	class GrassFloor : public Floor {

	public:

		GrassFloor(int x, int y, float blocksize, std::string id);
		~GrassFloor();

		void getTexture();

	};
}

#endif