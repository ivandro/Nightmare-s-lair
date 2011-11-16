#include "Wall.h"

namespace example{

	Wall::Wall(int x, int y, float blocksize, std::string id) : cg::Entity(id) 
	{
			_pos[0]=x;
			_pos[1]=y;
			_blocksize=blocksize;
	}

	Wall::~Wall(void)
	{
	}
	void texture();
	static GLubyte checkImage[64][64][4];
	GLuint wallTexture;
	void Wall::init(){ 
		TextureBank *textureBank = (TextureBank *) cg::Registry::instance()->get( "TextureBank" );
		wallTexture = textureBank->loadTexture("Images\\Wall\\dirtyWall\\grass.tga");

		for ( int i= 0; i < 64; i++) {

			for ( int j = 0; j < 64; j++ ) {
				int c = ( ( ( i & 0x8 ) == 0 ) ^ ( ( j & 0x8 ) == 0 ) ) * 255;
				checkImage[i][j][0] = (GLubyte)c;
				checkImage[i][j][1] = (GLubyte)c;
				checkImage[i][j][2] = (GLubyte)c;
				checkImage[i][j][3] = (GLubyte)255;
			}
		}


	}
	
	void texture() {
	
		char filename[] = "Images\\Wall\\dirtyWall\\grass.tga";
		// adequerir informação sobre imagem
		FREE_IMAGE_FORMAT fileFormat = FreeImage_GetFileType( filename, 0 );
		FIBITMAP *fiWall = FreeImage_Load( fileFormat, filename, 0);
		fiWall = FreeImage_ConvertTo32Bits( fiWall );
		if ( fiWall != NULL ) {
			int width = FreeImage_GetWidth( fiWall );
			int height = FreeImage_GetHeight( fiWall );

			BYTE *bits = new BYTE[ width * height * 4 ];

			BYTE *pixels = (BYTE *)FreeImage_GetBits( fiWall );

			for(int pix=0; pix < width * height; pix++) {

				bits[ pix*4 + 0 ] = pixels[ pix*4 + 2 ];
				bits[ pix * 4 + 1 ] = pixels[ pix * 4 + 1 ];
				bits[ pix * 4 + 2 ] = pixels[ pix * 4 + 0 ];
				bits[ pix* 4 + 3 ] = pixels[ pix * 4  + 3 ];

			}

			glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
			glGenTextures( 1, &wallTexture );
				// definir objecto da textura
				glBindTexture( GL_TEXTURE_2D, wallTexture );
				// definir os parametros sobre filtros ( minimation and magnization )
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
				// definir os parametros sobre cobertura ( clamp_t e clamp_s )
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
				glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits ); 
		}		

	}
		
	void Wall::draw() {

		glEnable( GL_TEXTURE_2D );
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
		glBindTexture( GL_TEXTURE_2D, wallTexture );
		//getTexture();

		glPushMatrix();
		glTranslatef((GLfloat)_pos[0]*_blocksize,0,(GLfloat)_pos[1]*_blocksize);
		glScalef(_blocksize,_blocksize,_blocksize);
		glColor3f(1.0f,0.0f,0.0f);
		
		glPushMatrix();
			glBegin(GL_POLYGON);
				glTexCoord2f( 1.0f, 1.0f );glVertex3f(0.0f,1.0f,0.0f);
				glTexCoord2f( 1.0f, 0.0f );glVertex3f(1.0f,1.0f,0.0f);
				glTexCoord2f( 0.0f, 0.0f );glVertex3f(1.0f,1.0f,1.0f);
				glTexCoord2f( 0.0f, 1.0f );glVertex3f(0.0f,1.0f,1.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glTexCoord2f( 1.0f, 0.0f ); glVertex3f(0.0f,0.0f,0.0f);
				glTexCoord2f( 1.0f, 1.0f );glVertex3f(0.0f,1.0f,0.0f);
				glTexCoord2f( 0.0f, 1.0f );glVertex3f(0.0f,1.0f,1.0f);
				glTexCoord2f( 0.0f, 0.0f );glVertex3f(0.0f,0.0f,1.0f);
			glEnd();
		glPopMatrix();


		glPushMatrix();
			glBegin(GL_POLYGON);
				glTexCoord2f( 0.0f, 1.0f );glVertex3f(1.0f,1.0f,1.0f);
				glTexCoord2f( 1.0f, 1.0f );glVertex3f(1.0f,1.0f,0.0f);
				glTexCoord2f( 1.0f, 0.0f );glVertex3f(1.0f,0.0f,0.0f);
				glTexCoord2f( 0.0f, 0.0f );glVertex3f(1.0f,0.0f,1.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glTexCoord2f( 1.0f, 0.0f );glVertex3f(0.0f,0.0f,0.0f);
				glTexCoord2f( 1.0f, 1.0f );glVertex3f(1.0f,0.0f,0.0f);
				glTexCoord2f( 0.0f, 1.0f );glVertex3f(1.0f,1.0f,0.0f);
				glTexCoord2f( 0.0f, 0.0f );glVertex3f(0.0f,1.0f,0.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glBegin(GL_POLYGON);
				glTexCoord2f( 0.0f, 1.0f );glVertex3f(1.0f,1.0f,1.0f);
				glTexCoord2f( 1.0f, 1.0f );glVertex3f(1.0f,0.0f,1.0f);
				glTexCoord2f( 1.0f, 0.0f );glVertex3f(0.0f,0.0f,1.0f);
				glTexCoord2f( 0.0f, 0.0f );glVertex3f(0.0f,1.0f,1.0f);
				

			glEnd();
		glPopMatrix();
		glPopMatrix();
		
		glDisable( GL_TEXTURE_2D );
	}


}