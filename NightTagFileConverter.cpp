#include "NightTagFileConverter.h"

namespace example {

	NightTagFileConverter::NightTagFileConverter() { 
	
		tagFileMap[ TEXTURE_WALL ] = "Images\\Wall\\dirtyWall\\wall4.jpg";
		tagFileMap[ TEXTURE_FLOOR ] = "Images\\Grass\\Grass3.jpg";
	
	}

	NightTagFileConverter::~NightTagFileConverter() {}

	std::string NightTagFileConverter::convert( TextureTags tag ) { 
	
		return tagFileMap[ tag ];
	
	}


}