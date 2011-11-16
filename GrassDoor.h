#ifndef GRASS_DOOR_H
#define GRASS_DOOR_H

#include "Door.h" 
#include "GrassClosedDoor.h"
#include "GrassOpenDoor.h"

namespace example {

	class GrassDoor : public Door {

public:
	GrassDoor(int x, int y, float blocksize, std::string id);
	~GrassDoor(void);
	void openClose();
	};

}

#endif