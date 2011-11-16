#include "Stone.h"

namespace example {

	Stone::Stone(std::string id) : cg::Entity(id) {
	}
	Stone::~Stone() {
	}

	inline
	void Stone::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_OBSIDIAN); //PEWTER
		 m->shade(GL_FRONT);

  		glEndList();
	}
	void Stone::init() {
		_physics.setPosition(0,0.25,0);
		//_physics.setAngularVelocity(20.0);
		makeSphere();
		makeSphereModel();
		makeTorus();
		makeTorusModel();
		makeMaterial();
	}

	inline
	void Stone::makeSphere() {
		_SphereObj = gluNewQuadric();
		gluQuadricCallback(_SphereObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_SphereObj, GLU_FILL);
		gluQuadricOrientation(_SphereObj, GLU_OUTSIDE); 
		gluQuadricNormals(_SphereObj, GLU_SMOOTH);
		gluQuadricTexture(_SphereObj, GL_FALSE);
	}

	void Stone::makeTorus(){
		_TorusObj = gluNewQuadric();
		gluQuadricCallback(_TorusObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_TorusObj, GLU_FILL);
		gluQuadricOrientation(_TorusObj, GLU_OUTSIDE); 
		gluQuadricNormals(_TorusObj, GLU_SMOOTH);
		gluQuadricTexture(_TorusObj, GL_FALSE);
	
	}
	inline
	void Stone::makeSphereModel() {
		_modelSphere = glGenLists(1);
		assert(_modelSphere != 0);
		glNewList(_modelSphere,GL_COMPILE);
			gluSphere	(_SphereObj, 2, 5, 10);
		glEndList();
	}
	
	inline
	void Stone::makeTorusModel() {
		_modelTorus = glGenLists(1);
		assert(_modelTorus != 0);
		glNewList(_modelTorus,GL_COMPILE);
			glutSolidTorus(1, 1, 5, 7);
		glEndList();
	}
	
	void Stone::draw() {
		glPushMatrix();
			glCallList(_materialDL);
			_physics.applyTransforms();
			
			glCullFace(GL_BACK);
			
			glRotated(30,0,1,1);
			glScaled(0.2,0.2,0.2);

			glPushMatrix();
				glTranslated(0,0,3);
				glCallList(_modelSphere);		
			glPopMatrix();

			//pequena1
			glPushMatrix();
				glTranslated(3,-1.5,0);
				glRotated(30,0,1,1);
				glScaled(0.5,0.5,0.5);
				glCallList(_modelSphere);		
			glPopMatrix();
			//pequena2
			glPushMatrix();
				glTranslated(4,-2.5,0);
				glRotated(50,0,1,1);
				glScaled(0.3,0.3,0.3);
				glCallList(_modelSphere);		
			glPopMatrix();

			glPushMatrix();	
				glRotated(30,0,1,0);
				glCallList(_modelTorus);
			glPopMatrix();
			//pequena atras do torus
			glPushMatrix();
				glTranslated(-1.2,0.5,-2);
				glScaled(0.5,0.5,0.5);
				glCallList(_modelSphere);		
			glPopMatrix();

			glCullFace(GL_FRONT);
		glPopMatrix();
	}
 }