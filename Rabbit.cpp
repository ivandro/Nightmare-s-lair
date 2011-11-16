#include "Rabbit.h"

namespace example {
	 
	Rabbit::Rabbit(std::string id):

		cg::Entity(id),	
	//	_animationflag (true),
		_isDebug(false){
	}

	Rabbit::~Rabbit() {
	}

	inline
	void Rabbit::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_GOLD);//MATERIAL_PLASTIC_YELLOW
		m->shade(GL_FRONT);

  		glEndList();
	}

inline void Rabbit::drawCube(){
		//lateralEsq
		glBegin(GL_POLYGON);
			glNormal3f(0,0,1);
			glVertex3f(-1,-1,1);
			glVertex3f(1,-1,1);
			glVertex3f(1,1,1);
			glVertex3f(-1,1,1);
		glEnd();

		//lateralDir
		glBegin(GL_POLYGON);
			glNormal3f(0,0,-1);
			glVertex3f(-1,-1,-1);
			glVertex3f(-1,1,-1);
			glVertex3f(1,1,-1);
			glVertex3f(1,-1,-1);
		glEnd();

		//frente
		glBegin(GL_POLYGON);
			glNormal3f(1,0,0);
			glVertex3f(1,-1,-1);
			glVertex3f(1,1,-1);
			glVertex3f(1,1,1);
			glVertex3f(1,-1,1);
		glEnd();

		//tras
		glBegin(GL_POLYGON);
			glNormal3f(-1,0,0);
			glVertex3f(-1,-1,-1);
			glVertex3f(-1,-1,1);
			glVertex3f(-1,1,1);
			glVertex3f(-1,1,-1);
		glEnd();

		//cima
		glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glVertex3f(-1,1,-1);
			glVertex3f(-1,1,1);
			glVertex3f(1,1,1);
			glVertex3f(1,1,-1);
		glEnd();
		
		//baixo
		glBegin(GL_POLYGON);
			glNormal3f(0,-1,0);
			glVertex3f(-1,-1,-1);
			glVertex3f(1,-1,-1);
			glVertex3f(1,-1,1);
			glVertex3f(-1,-1,1);
		glEnd();
}
	
	void Rabbit::makeEar() {
		_modelEar = glGenLists(1);
		assert(_modelEar != 0);
		glNewList(_modelEar,GL_COMPILE);

		glPushMatrix();
			drawCube();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,2,0);
			glRotated(30,0,0,-1);
			drawCube();
		glPopMatrix();
			
		glPushMatrix();
			glTranslated(1.7,3.5,0);
			glRotated(60,0,0,-1);
			drawCube();
		glPopMatrix();

		glEndList();
	}

	void Rabbit::makeBody() {
		_modelBody = glGenLists(1);
		assert(_modelBody != 0);
		glNewList(_modelBody,GL_COMPILE);

		glPushMatrix();
			drawCube();
		glPopMatrix();
			
		glEndList();
	}

	void Rabbit::makeFoot() {
		_modelFoot = glGenLists(1);
		assert(_modelFoot != 0);
		glNewList(_modelFoot,GL_COMPILE);

		glPushMatrix();
			drawCube();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.2,-1.3,0);
			glScaled(1.2,0.3,1);
			drawCube();
		glPopMatrix();
			
		glEndList();
	}

	void Rabbit::init() {
		_physics.setPosition(2,1.7,0);
		_physics.setAngularVelocity(1000); 
		_physics.setLinearVelocity(100); 

		_angle = 1.0f;
		_rotateFace=0.3f;	
		faceMod=1;
		rotatefaceMod=1;

		//_timer =1.0f;
		makeEar();
		makeBody();
		makeFoot();
		makeMaterial();
	}

	void Rabbit::draw() {
		glPushMatrix();
			glCallList(_materialDL);
			_physics.applyTransforms();
			
			glCullFace(GL_BACK);
			
			glPushMatrix();
				glTranslated(0,_rotateFace,0);

				//criacao de orelhas
				glPushMatrix();
					glScaled(0.25,0.25,0.25);
				
					glPushMatrix();
						glTranslated(0,4,1.5);
						glRotated(_angle,0,0,1);
						glCallList(_modelEar);		
					glPopMatrix();
					glPushMatrix();
						glTranslated(0,4,-1.5);
						glRotated(_angle,0,0,1); 
						glCallList(_modelEar);		
					glPopMatrix();				
				glPopMatrix();
		
				//criacao do corpo
				glPushMatrix();	
					glScaled(0.75,1,1);
					glCallList(_modelBody);
				glPopMatrix();

				//criação dos pés
				glPushMatrix();
					glScaled(0.4,0.4,0.30);
					glPushMatrix();	
						glTranslated(0,-3,1.5);
						glRotated(-_angle,0,0,1);
						glCallList(_modelFoot);
					glPopMatrix();
					glPushMatrix();	
						glTranslated(0,-3,-1.5);
						glRotated(-_angle,0,0,1); 
						glCallList(_modelFoot);
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();
			glCullFace(GL_FRONT);
		glPopMatrix();
	}

	void Rabbit::update(unsigned long elapsed_millis) {
		if(!_isDebug){

			double elapsed_seconds = elapsed_millis / (double)10000;

			_rotateFace =_rotateFace + (float)rotatefaceMod*0.04f;
			_angle = _angle + (float)faceMod*1.7f;
			if(_rotateFace > 0.7f|| _rotateFace < 0.0f)
				rotatefaceMod=-1*rotatefaceMod;	
			if(_angle >= 30.0f|| _angle <= 0.0f)
				faceMod=-1*faceMod;	
		}
	}

	void Rabbit::toggleDebugMode() {
		_isDebug = !_isDebug;
	}

}