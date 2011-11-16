#ifndef GRASS_CLOSED_DOOR_H
#define GRASS_CLOSED_DOOR_H


#include "DoorState.h"

namespace example {

	class GrassClosedDoor : public DoorState {
	
	public:

		GrassClosedDoor();
		~GrassClosedDoor();
		void getTexture();

	};

}

#endif