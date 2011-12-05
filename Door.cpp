#include "Door.h"

namespace example{

	Door::Door(int x, int y, float blocksize, std::string id) : cg::Entity(id), 
		BoxEntity(new Box(Box::EntityType::BOX_DOOR,blocksize,blocksize/2,blocksize/2), 0, cg::Vector3f(x*blocksize+blocksize,0,y*blocksize+blocksize/2))
	{
			_pos[0]=x*blocksize;
			_pos[1]=y*blocksize;
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
		glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
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