#include "TextureBank.h"

namespace example {


	/*
	* TextureBank constructor
	*/
	TextureBank::TextureBank( std::string id ): cg::Entity( id ), position( 0 ), width( 0 ), height( 0 ), textureObjectId( 0 ) {

	}

	/*
	* TextureBank destructor
	*/
	TextureBank::~TextureBank(){
	}

	/*
	** name: init
	** description: initialize the texture Bank
	*/
	void TextureBank::init() {

	}

	/*
	** name: loadTexture
	** description: This function load the textures and configure them, in this way you can start to associate it with the vertices
	** parameter: imagePath - path of the image that gonna be used for the texture
	*/
	GLint TextureBank::loadTexture( char* imagePath ) {
		//std::cout << " Chamaram-me! " << std::endl;
		textureObjectId = textureBankSafe[ imagePath ];
		// If the image was'nt seen yet
		if ( textureObjectId == 0 ) {
			
			// load the image
			BYTE *bits = loadImage( imagePath );
			// create a Texture Object of the loaded image
			textureObjectId = makeTextureObject( bits );
			// safe pair < imagePath, TextureObjectId >
			textureBankSafe[ imagePath ] = textureObjectId;

		}
		// Else
		else {

			// do nothing. textureObjectId already have the id of the texture object 

		}
		return textureObjectId;

	}

	/*
	** name: loadImage
	** description: load the image from the image into the application
	** parameter: imagePath - path from the image to load
	** return: Array of bytes representing the image
	*/
	BYTE *TextureBank::loadImage( char *imagePath ) {

		char *filename = imagePath;

		// adequerir informação sobre imagem
		FREE_IMAGE_FORMAT fileFormat = FreeImage_GetFileType( filename, 0 );
		FIBITMAP *fiWall = FreeImage_Load( fileFormat, filename, 0);
		fiWall = FreeImage_ConvertTo32Bits( fiWall );
		if ( fiWall != NULL ) {
			width = FreeImage_GetWidth( fiWall );
			height = FreeImage_GetHeight( fiWall );

			BYTE *bits = new BYTE[ width * height * 4 ];

			BYTE *pixels = (BYTE *)FreeImage_GetBits( fiWall );

			for(int pix=0; pix < width * height; pix++) {

				bits[ pix*4 + 0 ] = pixels[ pix*4 + 2 ];
				bits[ pix * 4 + 1 ] = pixels[ pix * 4 + 1 ];
				bits[ pix * 4 + 2 ] = pixels[ pix * 4 + 0 ];
				bits[ pix* 4 + 3 ] = pixels[ pix * 4  + 3 ];

			}

			return bits;

		}

	}

	/*
	** name: makeTextureObject
	** description: create the Texture in opengl and place it in a texture object
	** parameter: bits - Array representing the image that gonna be transformed in a texture
	** return: the id of the texture object created
	*/
	GLint TextureBank::makeTextureObject( BYTE *bits ) {

		GLuint textureId;

		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
		glGenTextures( 1, &textureId );
				
		// definir objecto da textura
		glBindTexture( GL_TEXTURE_2D, textureId );
		// definir os parametros sobre filtros ( minimation and magnization )
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		// definir os parametros sobre cobertura ( clamp_t e clamp_s )
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits );

		return textureId;
	}

}
