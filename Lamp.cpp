
#include "Lamp.h"

namespace example {
	Lamp::Lamp(int x, int y, float blocksize, std::string id) : cg::Entity(id) {
		_pos[0] =x*blocksize+blocksize/2;
		_pos[1] = y*blocksize+blocksize/2;
		_blocksize =blocksize;
	}
	Lamp::~Lamp(){}
	void Lamp::init(){}


	void Lamp::draw(){


		glPushMatrix();
		glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
		glScalef(_blocksize,_blocksize,_blocksize);
		getModel();
		glPopMatrix();
		}


}
