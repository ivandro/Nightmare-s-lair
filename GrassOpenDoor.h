#ifndef GRASS_OPEN_DOOR_H
#define GRASS_OPEN_DOOR_H


#include "DoorState.h"

namespace example {

	class GrassOpenDoor : public DoorState {

	public:
		GrassOpenDoor();
		~GrassOpenDoor();
		void getTexture();

	};

}

#endif