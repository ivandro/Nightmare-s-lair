#ifndef NIGHT_TAG_FILE_CONVERTER
#define NIGHT_TAG_FILE_CONVERTER

#include "cg\cg.h"
#include "TagFileBitmapConverter.h"

namespace example {

	class NightTagFileConverter : public TagFileBitmapConverter {
	public:

		NightTagFileConverter();
		~NightTagFileConverter();

		std::string convert( TextureTags tag );

	};

}



#endif