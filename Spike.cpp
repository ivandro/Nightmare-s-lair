#include "Spike.h"

namespace example {

	Spike::Spike(int x, int y, float blocksize, std::string id) : Obstacle(x, y, blocksize, id,0.1,0.3,0.3) {
		makeSpike();
		makeMaterial();
	}
	Spike::~Spike() {
	}

	void Spike::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_SILVER);
		 m->shade(GL_FRONT);

  		glEndList();
	}

	
	void Spike::makeSpike() {

		_spikeQuadric = gluNewQuadric();
		gluQuadricNormals(_spikeQuadric, GLU_FLAT);
		gluQuadricOrientation(_spikeQuadric, GLU_INSIDE);
		

		_modelSpike = glGenLists(1);
		assert(_modelSpike != 0);
		glNewList(_modelSpike,GL_COMPILE);
		
		glTranslated(0.1f,0,-0.1f);
		glRotated(270,1,0,0);
		gluCylinder(_spikeQuadric,0.1f,0,0.15f,10,10);

		glEndList();
	}
	
	void Spike::makeModel() {

		glPushMatrix();
			glTranslatef(_pos[0],0,_pos[1]);
			glScaled(_blocksize,_blocksize,_blocksize);
			glCallList(_materialDL);

			for(float j = 0.0f; j < 0.6; j = j + 0.2f)
				for(float i = 0.2f; i <= 0.8; i = i + 0.2f){

					glPushMatrix();
						glTranslated(j+0.2,0,i+0.2);
						glCallList(_modelSpike);		
					glPopMatrix();
				}
	

			glCullFace(GL_FRONT);
		glPopMatrix();
	}
 }