#include "Key.h"
 
namespace example {
	 
	Key::Key(int x, int y, float blocksize, std::string id) : cg::Entity(id),
		BoxEntity(new Box(Box::BOX_KEY,1*blocksize,0.2*blocksize,0.2*blocksize),0,cg::Vector3f(x*blocksize+blocksize*0.5,0,y*blocksize+blocksize*0.5)){
		_pos[0] =x*blocksize+blocksize*0.4;
		_pos[1] = y*blocksize+blocksize*0.4;
		_blocksize =blocksize;
	}
	Key::~Key() {
	}

	inline
	void Key::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_GOLD);
		 m->shade(GL_FRONT);

  		glEndList();
	}
	void Key::init() {
		
		_rotateFace=0.3f;
		rotatefaceMod=1;
		_angle = 60.0f;
		faceMod=1;

		_physics.setPosition(0,0,0);
		makeCylinder();
		makeCylinderModel();
		makeTorus();
		makeTorusModel();
		makeHead();
		makeMaterial();
	}
	void Key::update(unsigned long elapsed_millis) {

		_rotateFace =_rotateFace + (float)rotatefaceMod*0.15f;
			
		if(_rotateFace > 10.0f|| _rotateFace < 0.0f)
			rotatefaceMod=-1*rotatefaceMod;	

		_angle = _angle + (float)faceMod*1.0f;
			
		if(_angle >= 85.0f|| _angle <= 40.0f)
			faceMod=-1*faceMod;	
	}

	inline
	void Key::makeCylinder() {
		_cylinderObj = gluNewQuadric();
		gluQuadricCallback(_cylinderObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_cylinderObj, GLU_FILL);
		gluQuadricOrientation(_cylinderObj, GLU_OUTSIDE); 
		gluQuadricNormals(_cylinderObj, GLU_SMOOTH);
		gluQuadricTexture(_cylinderObj, GL_FALSE);
	}

	void Key::makeTorus(){
		_TorusObj = gluNewQuadric();
		gluQuadricCallback(_TorusObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_TorusObj, GLU_FILL);
		gluQuadricOrientation(_TorusObj, GLU_OUTSIDE); 
		gluQuadricNormals(_TorusObj, GLU_SMOOTH);
		gluQuadricTexture(_TorusObj, GL_FALSE);
	
	}
	inline
	void Key::makeCylinderModel() {
		_modelCylinder = glGenLists(1);
		assert(_modelCylinder != 0);
		glNewList(_modelCylinder,GL_COMPILE);
			gluCylinder	(_cylinderObj, 1, 1, 15.5, 25, 10);
		glEndList();
	}
	
	inline
	void Key::makeTorusModel() {
		_modelTorus = glGenLists(1);
		assert(_modelTorus != 0);
		glNewList(_modelTorus,GL_COMPILE);
			glutSolidTorus(1, 2, 5, 25);
		glEndList();
	}
	
	void Key::draw() {
		debugBox(cg::Vector3f(1,0,1));
		glPushMatrix();
			
			glCallList(_materialDL);
			_physics.applyTransforms();
			
			glCullFace(GL_BACK);
			glTranslatef(_pos[0], 0.2*_blocksize, _pos[1]);
			glScaled(0.1*_blocksize,0.1*_blocksize,0.1*_blocksize);
		
			glRotated(_angle,0,1,0);			
			glScaled(0.2,0.2,0.2);
			glTranslated(0,_rotateFace,0);

			glPushMatrix();
				glTranslated(0,0,2);
				glCallList(_modelCylinder);		
			glPopMatrix();
		
			glPushMatrix();	
				glTranslated(0,0,12);
				glScaled(0.90,1,0.55);
				glCallList(_modelHead);
			glPopMatrix();

			glPushMatrix();	
				glRotated(90,0,1,0);
				glCallList(_modelTorus);
			glPopMatrix();

			glCullFace(GL_FRONT);
		glPopMatrix();
	}

inline void Key::drawCube(){
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

inline
	void Key::makeHead() {
		_modelHead = glGenLists(1);
		assert(_modelHead != 0);
		
		glNewList(_modelHead,GL_COMPILE);

		glPushMatrix();
			glTranslated(0,0,4);
			glScaled(1,1,5);
			drawCube();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-2,0);
			drawCube();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-2,4);
			drawCube();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0,-2,8);
			drawCube();
		glPopMatrix();	

		glEndList();
	}

	void Key::playerCollision() {
		state.disable();
	}
 }