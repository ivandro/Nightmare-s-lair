
#include "Floor.h"

namespace example {
	Floor::Floor(int x, int y, float blocksize, std::string id) : cg::Entity(id) {
		_pos[0] =x;
		_pos[1] = y;
		_blocksize =blocksize;
	}
	Floor::~Floor(){}
	
	GLint floorTexture;
	void Floor::init(){
		TextureBank *textureBank = (TextureBank *) cg::Registry::instance()->get( "TextureBank" );
		floorTexture = textureBank->loadTexture("Images\\Grass\\Grass2.jpg");
	}
		
	void Floor::draw(){
		
		glEnable( GL_TEXTURE_2D );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
		glBindTexture( GL_TEXTURE_2D, floorTexture );
		//loads texture stuff from child classes ->Template pattern
		getTexture();

		glPushMatrix();
		glTranslatef((GLfloat)_pos[0]*_blocksize,0,(GLfloat)_pos[1]*_blocksize);
		glScalef(_blocksize,0,_blocksize);
		glColor3f(0.5,0.5,0.5);

		glBegin(GL_POLYGON);
			
			glTexCoord2f( 1.0f, 0.0f ); glVertex3f(0.0f,0.0f,0.0f);
			glTexCoord2f( 1.0f, 1.0f );glVertex3f(1.0f,0.0f,0.0f);
			glTexCoord2f( 0.0f, 1.0f );glVertex3f(1.0f,0.0f,1.0f);
			glTexCoord2f( 0.0f, 0.0f );glVertex3f(0.0f,0.0f,1.0f);

		glEnd();
		glPopMatrix();
	}


}
