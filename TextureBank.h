#ifndef TEXTURE_BANK_H
#define TEXTURE_BANK_H

#include <string>
#include <map>
#include "FreeImage.h"
#include "cg/cg.h"
#include "TagFileBitmapConverter.h"
#include "Tags.h"
#include "ResourceLoader.h"

namespace example {

	class TextureBank: public cg::Entity {

	private:
		ResourceLoader *resourceLoader;
		std::map< TextureTags, GLint > *textureBankSave;
		TagFileBitmapConverter *tagFileBitmapConverter;
		int position;
		int width;
		int height;
		GLint textureObjectId;

	public:

		TextureBank( std::string id, TagFileBitmapConverter *tagFileBitmapConverter );
		~TextureBank();

		void init();
		GLint loadTexture( TextureTags tag );
		std::string convert( TextureTags tag );

		void changeConverter( TagFileBitmapConverter **inout_tagFileBitmapConverter,
			std::map< TextureTags, GLint> **inout_TextureBankSave );

		
		BYTE* loadImage( TextureTags tag );
	private:

		GLint makeTextureObject( BYTE* bits );

	};

}

#endif