#ifndef TAG_FILE_BITMAP_CONVERTER
#define TAG_FILE_BITMAP_CONVERTER

#include "cg\cg.h"
#include "Tags.h"

namespace example {

	class TagFileBitmapConverter {

	protected:
		std::map< TextureTags, std::string > tagFileMap;

	public:

		TagFileBitmapConverter();
		~TagFileBitmapConverter();

		 virtual std::string convert( TextureTags tag ) = 0;

	};

}



#endif