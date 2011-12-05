#include "GrassTagFileConverter.h"

namespace example {

	GrassTagFileConverter::GrassTagFileConverter() { 
	
		tagFileMap[ TEXTURE_WALL ] = "Images\\Wall\\dirtyWall\\grass.tga";
		tagFileMap[ TEXTURE_FLOOR ] = "Images\\Grass\\Grass2.jpg";
	
	}

	GrassTagFileConverter::~GrassTagFileConverter() {}

	std::string GrassTagFileConverter::convert( TextureTags tag ) { 
	
		return tagFileMap[ tag ];
	
	}


}