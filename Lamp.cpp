
#include "Lamp.h"

namespace example {
	Lamp::Lamp(int x, int y, float blocksize, std::string id, float maxX, float height, float maxZ) : cg::Entity(id),
		BoxEntity(new Box(Box::BOX_EXTRA,height*blocksize,maxX*blocksize,maxZ*blocksize),0,cg::Vector3f(x*blocksize+blocksize/2+maxX*blocksize,0,y*blocksize+blocksize/2+maxZ*blocksize)){
		_pos[0] =x*blocksize+blocksize/2;
		_pos[1] = y*blocksize+blocksize/2;
		_blocksize =blocksize;
	}
	Lamp::~Lamp(){}
	void Lamp::init(){}


	void Lamp::draw(){
		debugBox(cg::Vector3f(1,1,0));

		glPushMatrix();
		glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
		glScalef(_blocksize,_blocksize,_blocksize);
		getModel();
		glPopMatrix();
		}


}
