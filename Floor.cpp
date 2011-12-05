
#include "Floor.h"

namespace example {
	Floor::Floor(int x, int y, float blocksize, std::string id) : cg::Entity(id) {
		_pos[0] =x*blocksize;
		_pos[1] = y*blocksize;
		_blocksize =blocksize;
	}
	Floor::~Floor(){}
	
	GLint floorTexture;
	void Floor::init(){
		
		textureBank = (TextureBank *) cg::Registry::instance()->get( "TextureBank" );
	}
		
	void Floor::draw(){

		floorTexture = textureBank->loadTexture( TEXTURE_FLOOR );
		
		glEnable( GL_TEXTURE_2D );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
		glBindTexture( GL_TEXTURE_2D, floorTexture );
		//loads texture stuff from child classes ->Template pattern
		getTexture();

		glPushMatrix();
		glTranslatef((GLfloat)_pos[0],0,(GLfloat)_pos[1]);
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
