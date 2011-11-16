#ifndef TEXTURE_BANK_H
#define TEXTURE_BANK_H

#include <string>
#include <map>
#include "FreeImage.h"
#include "cg/cg.h"

namespace example {

	class TextureBank: public cg::Entity {

	private:
		std::map< std::string, GLint > textureBankSafe;
		int position;
		int width;
		int height;
		GLint textureObjectId;

	public:

		TextureBank( std::string id );
		~TextureBank();

		void init();
		GLint loadTexture( char *ImagePath );

	private:

		BYTE* loadImage( char *ImagePath );
		GLint makeTextureObject( BYTE* bits );

	};

}

#endif