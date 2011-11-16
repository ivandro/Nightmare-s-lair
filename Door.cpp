#include "Door.h"

namespace example{

	Door::Door(int x, int y, float blocksize, std::string id) : cg::Entity(id) 
	{
			_pos[0]=x;
			_pos[1]=y;
			_blocksize=blocksize;
	}

	Door::~Door(void)
	{
	}

	void Door::init(){
		_isClosed=true;
	}


	void Door::draw() {

		_doorState->getTexture();

		glPushMatrix();
		glTranslatef((GLfloat)_pos[0]*_blocksize,0,(GLfloat)_pos[1]*_blocksize);
		glScalef(_blocksize,_blocksize,_blocksize);
		glColor3f(1.0,0.0,0.0);
		
		glPushMatrix();
			glBegin(GL_POLYGON);
				glVertex3d(0,1,0);
				glVertex3d(1,1,0);
				glVertex3d(1,1,1);
				glVertex3d(0,1,1);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glVertex3d(0,0,0);
				glVertex3d(0,1,0);
				glVertex3d(0,1,1);
				glVertex3d(0,0,1);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glVertex3d(1,1,1);
				glVertex3d(1,1,0);
				glVertex3d(1,0,0);
				glVertex3d(1,0,1);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glVertex3d(0,0,0);
				glVertex3d(1,0,0);
				glVertex3d(1,1,0);
				glVertex3d(0,1,0);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glVertex3d(1,1,1);
				glVertex3d(1,0,1);
				glVertex3d(0,0,1);
				glVertex3d(0,1,1);
				

			glEnd();
		glPopMatrix();
		glPopMatrix();
	}


}