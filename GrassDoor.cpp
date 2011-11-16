#include "GrassDoor.h"

namespace example{

	GrassDoor::GrassDoor(int x, int y, float blocksize, std::string id): Door(x, y, blocksize, id){
		_doorState = new GrassClosedDoor();
	}
	GrassDoor::~GrassDoor(void){}



	void GrassDoor::openClose(){
		if(_isClosed)
			_doorState = new GrassOpenDoor();
		else
			_doorState = new GrassClosedDoor();
		_isClosed = !_isClosed;
	}

}