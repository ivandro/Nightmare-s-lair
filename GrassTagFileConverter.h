#ifndef GRASS_TAG_FILE_CONVERTER
#define GRASS_TAG_FILE_CONVERTER

#include "cg\cg.h"
#include "TagFileBitmapConverter.h"

namespace example {

	class GrassTagFileConverter : public TagFileBitmapConverter {
	public:

		GrassTagFileConverter();
		~GrassTagFileConverter();

		std::string convert( TextureTags tag );

	};

}



#endif