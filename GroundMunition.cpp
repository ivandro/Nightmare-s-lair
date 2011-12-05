#include "GroundMunition.h"
 
namespace example {

	GroundMunition::GroundMunition(int x, int y, float blocksize, std::string id) : cg::Entity(id) {
		_pos[0] =x*blocksize;
		_pos[1] = y*blocksize;
		_blocksize = blocksize;
	}
	GroundMunition::~GroundMunition() {
	}

	inline
	void GroundMunition::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_COPPER);//?
		 m->shade(GL_FRONT);

  		glEndList();
	}
	void GroundMunition::init() {
		_rotateFace=0.0f;
		rotatefaceMod=1;

		_physics.setPosition(0,0,0);
		makeSphere();
		makeGroundMunitionModel();
		makeMaterial();
	}

	inline
	void GroundMunition::makeSphere() {
		_sphereObj = gluNewQuadric();
		gluQuadricCallback(_sphereObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_sphereObj, GLU_FILL);
		gluQuadricOrientation(_sphereObj, GLU_OUTSIDE); 
		gluQuadricNormals(_sphereObj, GLU_SMOOTH);
		gluQuadricTexture(_sphereObj, GL_FALSE);
	}
		
	inline
	void GroundMunition::makeGroundMunitionModel() {
		_modelGroundMunition = glGenLists(1);
		assert(_modelGroundMunition != 0);
		glNewList(_modelGroundMunition,GL_COMPILE);
			gluSphere	(_sphereObj, 1, 15, 25);
		glEndList();
	}

	
	void GroundMunition::draw() {
			glPushMatrix();
				glCallList(_materialDL);
				_physics.applyTransforms();
			
				glCullFace(GL_BACK);

				glTranslatef(_pos[0], 0, _pos[1]);
				glScaled(0.1*_blocksize,0.1*_blocksize,0.1*_blocksize);

				glPushMatrix();
					glTranslated(0,_rotateFace,0);
					glCallList(_modelGroundMunition);		
				glPopMatrix();	

				glPushMatrix();
					glTranslated(1.5,_rotateFace/2,-1);
					glCallList(_modelGroundMunition);		
				glPopMatrix();	

				glPushMatrix();
					glTranslated(1.5,_rotateFace/3,1);
					glCallList(_modelGroundMunition);		
				glPopMatrix();	

				glCullFace(GL_FRONT);
			glPopMatrix();
	}



	void GroundMunition::update(unsigned long elapsed_millis) {
		//if(!_isDebug){

			_rotateFace =_rotateFace + (float)rotatefaceMod*0.1f;
			
			if(_rotateFace > 5.0f|| _rotateFace < 0.0f)
				rotatefaceMod=-1*rotatefaceMod;	
			
		//}
	}

 }