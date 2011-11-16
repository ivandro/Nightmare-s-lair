#ifndef DOOR_H
#define DOOR_H

#include "cg/cg.h"
#include "DoorState.h"

namespace example{

	class Door: public cg::Entity,
			public cg::IDrawListener
	{

	protected:
			cg::Vector2i _pos;
			float _blocksize;
			DoorState * _doorState;
			bool _isClosed;
		
	public:
		Door(int x, int y, float blocksize, std::string id);
		~Door(void);

		void init();
		void draw();
		virtual void openClose() = 0;
	};

}
#endif