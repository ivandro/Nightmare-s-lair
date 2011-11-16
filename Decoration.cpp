#include "Decoration.h"

namespace example{

	Decoration::Decoration(int x, int y, float blocksize, std::string id) : cg::Entity(id) {
		_pos[0] =x*blocksize;
		_pos[1]=y*blocksize;
		_blocksize = blocksize;
	}

	Decoration::~Decoration() {}
	void Decoration::init(){}
	
	void Decoration::draw(){
		
		glPushMatrix();
			glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
			glScalef(_blocksize,_blocksize,_blocksize);
			getModel();
		glPopMatrix();

	}
}


