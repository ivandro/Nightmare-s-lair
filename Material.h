#ifndef MATERIAL_H
#define MATERIAL_H

#include "cg/cg.h"

namespace example {
		
		class Material {
			private:
				
				GLfloat _ambient[4];
				GLfloat _diffuse[4];
				GLfloat _specular[4];
				GLfloat _shininess;

			
		
			public:

				Material();
				Material(GLfloat ambientR,GLfloat ambientG,GLfloat ambientB,
						GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
						GLfloat specularR, GLfloat specularG, GLfloat specularB,
						GLfloat shine);
				~Material();
				void shade(GLenum face);
				void shade(GLenum face, float param);

			};


}


#endif