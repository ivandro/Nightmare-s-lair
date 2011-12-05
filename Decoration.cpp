#include "Decoration.h"

namespace example{

	Decoration::Decoration(int x, int y, float blocksize, std::string id, float maxX,float height,float maxZ) : cg::Entity(id), 
		BoxEntity(new Box(Box::BOX_EXTRA,height*blocksize,maxX*blocksize,maxZ*blocksize),0,cg::Vector3f(x*blocksize+blocksize/2,0,y*blocksize+blocksize/2)) {
		_pos[0] =x*blocksize;
		_pos[1]=y*blocksize;
		_blocksize = blocksize;
	}

	Decoration::~Decoration() {}
	void Decoration::init(){}
	
	void Decoration::draw(){
		
		glPushMatrix();
			debugBox(cg::Vector3f(0,1,0));
			glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
			
			glScalef(_blocksize,_blocksize,_blocksize);
			getModel();

				glColor3f(0,128,128);
				glLineWidth(2.0);
				
				
		glPopMatrix();
	}

	
}


