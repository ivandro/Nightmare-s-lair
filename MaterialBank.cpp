#include "MaterialBank.h"

namespace example  {

		Material* MaterialBank::materialData[25] = {NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL};
		MaterialBank::MaterialBank(void)
		{
		}

		MaterialBank::~MaterialBank(void)
		{
		}

		Material* MaterialBank::getMaterial(materialType type) {
			switch(type){
				case MATERIAL_EMERALD: 
					if(materialData[MATERIAL_EMERALD] ==NULL)  
						materialData[MATERIAL_EMERALD] = new Material(0.0215f, 0.1745f, 0.0215f, 0.07568f, 0.61424f, 0.07568f, 0.633f, 0.727811f, 0.633f, 0.6f);
					return materialData[MATERIAL_EMERALD];
				case MATERIAL_JADE: 
					if(materialData[MATERIAL_JADE] ==NULL)  
						materialData[MATERIAL_JADE] = new Material(0.135f,  0.2225f, 0.1575f, 0.54f, 0.89f, 0.63f, 0.316228f, 0.316228f, 0.316228f, 0.1f);
					return materialData[MATERIAL_JADE];
				case MATERIAL_OBSIDIAN:
					if(materialData[MATERIAL_OBSIDIAN] ==NULL) 
						materialData[MATERIAL_OBSIDIAN] = new Material(0.05375f, 0.05f, 0.06625f, 0.18275f, 0.17f, 0.22525f, 0.332741f, 0.328634f, 0.346435f, 0.3f);
					return materialData[MATERIAL_OBSIDIAN];
				case MATERIAL_PEARL:
					if(materialData[MATERIAL_PEARL] ==NULL)  
						materialData[MATERIAL_PEARL] = new Material(0.25f, 0.20725f, 0.20725f, 1.0f, 0.829f, 0.829f, 0.296648f, 0.296648f, 0.296648f, 0.088f);
					return materialData[MATERIAL_PEARL];
				case MATERIAL_RUBY:
					if(materialData[MATERIAL_RUBY] ==NULL)  
						materialData[MATERIAL_RUBY] = new Material(0.1745f, 0.01175f, 0.01175f, 0.61424f, 0.04136f, 0.04136f, 0.727811f, 0.626959f, 0.626959f, 0.6f);
					return materialData[MATERIAL_RUBY];
				case MATERIAL_TURQUOISE:
					if(materialData[MATERIAL_TURQUOISE] ==NULL)  
						materialData[MATERIAL_TURQUOISE] = new Material(0.1f, 0.18725f, 0.1745f, 0.396f, 0.74151f, 0.69102f, 0.297254f, 0.30829f, 0.306678f, 0.1f);
					return materialData[MATERIAL_TURQUOISE];
				case MATERIAL_BRASS:
					if(materialData[MATERIAL_BRASS] ==NULL)  
						materialData[MATERIAL_BRASS] = new Material(0.329412f, 0.223529f, 0.027451f, 0.780392f, 0.568627f, 0.113725f, 0.992157f, 0.941176f, 0.807843f, 0.21794872f);
					return materialData[MATERIAL_BRASS];
				case MATERIAL_BRONZE:
					if(materialData[MATERIAL_BRONZE] ==NULL)  
						materialData[MATERIAL_BRONZE] = new Material(0.2125f, 0.1275f, 0.054f, 0.714f, 0.4284f, 0.18144f, 0.393548f, 0.271906f, 0.166721f, 0.2f);
					return materialData[MATERIAL_BRONZE];
				case MATERIAL_CHROME:
					if(materialData[MATERIAL_CHROME] ==NULL)  
						materialData[MATERIAL_CHROME] = new Material(0.25f, 0.25f, 0.25f, 0.4f, 0.4f, 0.4f, 0.774597f, 0.774597f, 0.774597f, 0.6f);
					return materialData[MATERIAL_CHROME];
				case MATERIAL_COPPER:
					if(materialData[MATERIAL_COPPER] ==NULL)  
						materialData[MATERIAL_COPPER] = new Material(0.19125f, 0.0735f, 0.0225f, 0.7038f, 0.27048f, 0.0828f, 0.256777f, 0.137622f, 0.086014f, 0.1f);
					return materialData[MATERIAL_COPPER];
				case MATERIAL_SILVER:
					if(materialData[MATERIAL_SILVER] ==NULL)  
						materialData[MATERIAL_SILVER] = new Material(0.19225f, 0.19225f, 0.19225f, 0.50754f, 0.50754f, 0.50754f, 0.508273f, 0.508273f, 0.508273f, 0.4f);
					return materialData[MATERIAL_SILVER];
				case MATERIAL_GOLD:
					if(materialData[MATERIAL_GOLD] ==NULL)  
						materialData[MATERIAL_GOLD] = new Material(0.24725f, 0.1995f, 0.0745f, 0.75164f, 0.60648f, 0.22648f, 0.628281f, 0.555802f, 0.366065f, 0.4f);
					return materialData[MATERIAL_GOLD];
				case MATERIAL_PEWTER:
					if(materialData[MATERIAL_PEWTER] ==NULL)  
						materialData[MATERIAL_PEWTER] = new Material(0.105882f, 0.058824f, 0.113725f, 0.427451f, 0.470588f, 0.541176f, 0.333333f, 0.333333f, 0.521569f, 9.84615f);
					return materialData[MATERIAL_PEWTER];
				case MATERIAL_PLASTIC_BLACK:
					if(materialData[MATERIAL_PLASTIC_BLACK] ==NULL)  
						materialData[MATERIAL_PLASTIC_BLACK] = new Material(0.0f, 0.0f, 0.0f, 0.01f, 0.01f, 0.01f, 0.50f, 0.50f, 0.50f, 0.25f);
					return materialData[MATERIAL_PLASTIC_BLACK];
				case MATERIAL_PLASTIC_CYAN:
					if(materialData[MATERIAL_PLASTIC_CYAN] ==NULL)  
						materialData[MATERIAL_PLASTIC_CYAN] = new Material(0.0f, 0.1f, 0.06f, 0.0f, 0.50980392f, 0.50980392f, 0.50196078f, 0.50196078f, 0.50196078f, 0.25f);
					return materialData[MATERIAL_PLASTIC_CYAN];
				case MATERIAL_PLASTIC_GREEN:
					if(materialData[MATERIAL_PLASTIC_GREEN] ==NULL)  
						materialData[MATERIAL_PLASTIC_GREEN] = new Material(0.0f, 0.0f, 0.0f, 0.1f, 0.35f, 0.1f, 0.45f, 0.55f, 0.45f, 0.25f);
					return materialData[MATERIAL_PLASTIC_GREEN];
				case MATERIAL_PLASTIC_RED:
					if(materialData[MATERIAL_PLASTIC_RED] ==NULL)  
						materialData[MATERIAL_PLASTIC_RED] = new Material(0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.7f, 0.6f, 0.6f, 0.25f);
					return materialData[MATERIAL_PLASTIC_RED];
				case MATERIAL_PLASTIC_WHITE:
					if(materialData[MATERIAL_PLASTIC_WHITE] ==NULL)  
						materialData[MATERIAL_PLASTIC_WHITE] = new Material(0.0f, 0.0f, 0.0f, 0.55f, 0.55f, 0.55f, 0.70f, 0.70f, 0.70f, 0.25f);	
					return materialData[MATERIAL_PLASTIC_WHITE];
				case MATERIAL_PLASTIC_YELLOW:
					if(materialData[MATERIAL_PLASTIC_YELLOW] ==NULL)  
						materialData[MATERIAL_PLASTIC_YELLOW] = new Material(0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.0f, 0.60f, 0.60f, 0.50f, 0.25f);
					return materialData[MATERIAL_PLASTIC_YELLOW];
				case MATERIAL_RUBBER_BLACK:
					if(materialData[MATERIAL_RUBBER_BLACK] ==NULL)  
						materialData[MATERIAL_RUBBER_BLACK] = new Material(0.02f, 0.02f, 0.02f, 0.01f, 0.01f, 0.01f, 0.4f, 0.4f, 0.4f, 0.078125f);	
					return materialData[MATERIAL_RUBBER_BLACK];
				case MATERIAL_RUBBER_CYAN:
					if(materialData[MATERIAL_RUBBER_CYAN] ==NULL)  
						materialData[MATERIAL_RUBBER_CYAN] = new Material(0.0f, 0.05f, 0.05f, 0.4f, 0.5f, 0.5f, 0.04f, 0.7f, 0.7f, 0.078125f);
					return materialData[MATERIAL_RUBBER_CYAN];
				case MATERIAL_RUBBER_GREEN:
					if(materialData[MATERIAL_RUBBER_GREEN] ==NULL)  
						materialData[MATERIAL_RUBBER_GREEN] = new Material(0.0f, 0.05f, 0.0f, 0.4f, 0.5f, 0.4f, 0.04f, 0.7f, 0.04f, 0.078125f);
					return materialData[MATERIAL_RUBBER_GREEN];
				case MATERIAL_RUBBER_RED:
					if(materialData[MATERIAL_RUBBER_RED] ==NULL)  
						materialData[MATERIAL_RUBBER_RED] = new Material(0.05f, 0.0f, 0.0f, 0.5f, 0.4f, 0.4f, 0.7f, 0.04f, 0.04f, 0.078125f);
					return materialData[MATERIAL_RUBBER_RED];
				case MATERIAL_RUBBER_WHITE:
					if(materialData[MATERIAL_RUBBER_WHITE] ==NULL)  
						materialData[MATERIAL_RUBBER_WHITE] = new Material(0.05f, 0.05f, 0.05f, 0.5f, 0.5f, 0.5f, 0.7f, 0.7f, 0.7f, 0.078125f);
					return materialData[MATERIAL_RUBBER_WHITE];
				case MATERIAL_RUBBER_YELLOW:
					if(materialData[MATERIAL_RUBBER_YELLOW] ==NULL)  
						materialData[MATERIAL_RUBBER_YELLOW] = new Material(0.05f, 0.05f, 0.0f, 0.5f, 0.5f, 0.4f, 0.7f, 0.7f, 0.04f, 0.078125f);
					return materialData[MATERIAL_RUBBER_YELLOW];
				default:
					return new Material();
			}	
		}

}

