#include "ResourceLoader.h"

namespace example {


	/*
	* ResourceLoader constructor
	*/
	ResourceLoader::ResourceLoader() {}

	/*
	* ResourceLoader destructor
	*/
	ResourceLoader::~ResourceLoader() {}

	/*
	** name: loadImage
	** description: load the image from the image into the application
	** parameter: imagePath - path from the image to load
	** return: Array of bytes representing the image
	*/
	BYTE *ResourceLoader::loadImage( std::string imagePath ) {

		char *filename = new char[ imagePath.size() + 1 ];
		strcpy ( filename,  imagePath.c_str() );

		// adquerir informação sobre imagem
		FREE_IMAGE_FORMAT fileFormat = FreeImage_GetFileType( filename, 0 );
		FIBITMAP *fiWall = FreeImage_Load( fileFormat, filename, 0);
		fiWall = FreeImage_ConvertTo32Bits( fiWall );
		
		if ( fiWall != NULL ) {

			lastImageWidth = FreeImage_GetWidth( fiWall );
			lastImageHeight = FreeImage_GetHeight( fiWall );

			BYTE *bits = new BYTE[ lastImageWidth * lastImageHeight * 4 ];

			BYTE *pixels = (BYTE *)FreeImage_GetBits( fiWall );

			for(int pix=0; pix < lastImageWidth * lastImageHeight; pix++) {

				bits[ pix*4 + 0 ] = pixels[ pix*4 + 2 ];
				bits[ pix * 4 + 1 ] = pixels[ pix * 4 + 1 ];
				bits[ pix * 4 + 2 ] = pixels[ pix * 4 + 0 ];
				bits[ pix* 4 + 3 ] = pixels[ pix * 4  + 3 ];

			}
			return bits;

		}

		return NULL;

	}

	int ResourceLoader::getLastImageWidth() {

		return lastImageWidth;

	}

	int ResourceLoader::getLastImageHeight() {

		return lastImageHeight;

	}

}
