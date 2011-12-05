
#include "Obstacle.h"

namespace example {
	Obstacle::Obstacle(int x, int y, float blocksize, std::string id, float height, float maxX, float maxZ) : cg::Entity(id),
		BoxEntity(new Box(Box::BOX_OBSTACLE,height*blocksize,maxX*blocksize,maxZ*blocksize),0,cg::Vector3f(x*blocksize+blocksize/2,0,y*blocksize+blocksize/2)) {
		_pos[0] =x*blocksize;
		_pos[1] = y*blocksize;
		_blocksize =blocksize;
	}
	Obstacle::~Obstacle(){}
	
	void Obstacle::init(){
	}
		
	void Obstacle::draw(){
		debugBox(cg::Vector3f(0.5,0.5,0.5));
	
		makeModel();

	}


}
