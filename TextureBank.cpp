#include "TextureBank.h"

namespace example {


	/*
	* TextureBank constructor
	*/
	TextureBank::TextureBank( std::string id , TagFileBitmapConverter *tagFileBitmapConverter ): 
		cg::Entity( id ),
		position( 0 ),
		width( 0 ),
		height( 0 ),
		textureObjectId( 0 ),
		tagFileBitmapConverter( tagFileBitmapConverter ){

		textureBankSave = new std::map< TextureTags, GLint >();
		resourceLoader = new ResourceLoader();

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
	** parameter: tag - the tag that identify the texture to be loaded
	*/
	GLint TextureBank::loadTexture( TextureTags tag ) {
		//std::cout << " Chamaram-me! " << std::endl;
		textureObjectId = (*textureBankSave)[ tag ];
		// If the image was'nt seen yet
		if ( textureObjectId == 0 ) {
			
			// load the image
			BYTE *bits = loadImage( tag );
			// create a Texture Object of the loaded image
			textureObjectId = makeTextureObject( bits );
			// safe pair < imagePath, TextureObjectId >
			( *textureBankSave )[ tag ] = textureObjectId;

		}
		// Else
		else {

			// do nothing. textureObjectId already have the id of the texture object 

		}
		return textureObjectId;

	}

	std::string TextureBank::convert( TextureTags tag ) { 

		return tagFileBitmapConverter->convert( tag );
		
	} 

	void TextureBank::changeConverter( TagFileBitmapConverter **inout_tagFileBitmapConverter,
		std::map< TextureTags, GLint> **inout_textureBankSave ) {

			
		std::map< TextureTags, GLint > *oldTextureBankSave = this->textureBankSave;
		this->textureBankSave = *inout_textureBankSave;
		*inout_textureBankSave = oldTextureBankSave;

		TagFileBitmapConverter *oldTagFileBitmapConverter = this->tagFileBitmapConverter;

		this->tagFileBitmapConverter = *inout_tagFileBitmapConverter;
		*inout_tagFileBitmapConverter = oldTagFileBitmapConverter;

	}

	/*
	** name: loadImage
	** description: load the image from the image into the application
	** parameter: imagePath - path from the image to load
	** return: Array of bytes representing the image
	*/
	BYTE *TextureBank::loadImage( TextureTags tag ) {

		std::string str = convert( tag );
		BYTE *bits = resourceLoader->loadImage( str );

		width = resourceLoader->getLastImageWidth();
		height = resourceLoader->getLastImageHeight();
		return bits;
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
