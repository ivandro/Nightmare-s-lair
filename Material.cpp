#include "Material.h"

namespace example{

				Material::Material() {
					_ambient[0]=0.0f; 
					_ambient[1]=0.0f;
					_ambient[2]=0.0f;
					_ambient[3]=1.0f;
					_diffuse[0]=0.0f; 
					_diffuse[1]=0.0f;
					_diffuse[2]=0.0f;
					_diffuse[3]=1.0f;
					_specular[0]=0.0f; 
					_specular[1]=0.0f;
					_specular[2]=0.0f;
					_specular[3]=1.0f;
					_shininess=0.0f;
				}

				Material::Material(GLfloat ambientR,GLfloat ambientG,GLfloat ambientB,
						GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
						GLfloat specularR, GLfloat specularG, GLfloat specularB,
						GLfloat shine){
					_ambient[0]=ambientR; 
					_ambient[1]=ambientG;
					_ambient[2]=ambientB;
					_ambient[3]=1.0f;
					_diffuse[0]=diffuseR; 
					_diffuse[1]=diffuseG;
					_diffuse[2]=diffuseB;
					_diffuse[3]=1.0f;
					_specular[0]=specularR; 
					_specular[1]=specularG;
					_specular[2]=specularB;
					_specular[3]=1.0f;
					_shininess=0.0f;
					_shininess = shine;

				}
				Material::~Material(){}

				void Material::shade(GLenum face){
					glMaterialfv(face, GL_AMBIENT, _ambient);
					glMaterialfv(face, GL_DIFFUSE, _diffuse);
					glMaterialfv(face, GL_SPECULAR, _specular);
					glMaterialf(face, GL_SHININESS, _shininess);
				}

				void Material::shade(GLenum face,float param){
					_ambient[3] = param; 
					_diffuse[3] = param; 
					_specular[3] = param; 
					glMaterialfv(face, GL_AMBIENT, _ambient);
					glMaterialfv(face, GL_DIFFUSE, _diffuse);
					glMaterialfv(face, GL_SPECULAR, _specular);
					glMaterialf(face, GL_SHININESS, _shininess);
				}


}