#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include "FreeImage.h"
#include "cg/cg.h"

namespace example {

	class ResourceLoader {

	private:

		int lastImageWidth;
		int lastImageHeight;

	public:

		ResourceLoader();
		~ResourceLoader();

		
		BYTE* loadImage( std::string imagePath );
		int getLastImageWidth();
		int getLastImageHeight();

	};

}

#endif