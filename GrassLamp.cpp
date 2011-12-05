#include "GrassLamp.h"

namespace example{

	GrassLamp::GrassLamp(int x, int y, float blocksize, std::string id) : Lamp(x,y,blocksize,id,0.05,0.35,0.05) {
		_mod = 1;
		_inc =0.1f;
	}

	GrassLamp::~GrassLamp() {}

	void  GrassLamp::update(unsigned long elapsed_millis){
		 _inc += 0.002f*(float)_mod; // soften the animation

		if(_inc < 0.0f || _inc > 1.0f/3.0f)
			_mod = -1*_mod;	

	}
	void GrassLamp::makeBulb(){
		GLUquadricObj * _cylinderObj = gluNewQuadric();
		gluQuadricNormals(_cylinderObj, GLU_FLAT);
		gluQuadricOrientation(_cylinderObj, GLU_INSIDE);
		//light stuff
		glPushMatrix();
		glTranslated(0.55,_inc,0.55);
		glScaled(0.05,0.2f,0.05);
		glRotatef(270,1.0,0.0,0.0);
			glPushMatrix();
				glTranslated(-1,1,0);//centers cylinders
				gluCylinder	(_cylinderObj, 0, 1, 1, 25, 10);
				glTranslated(0,0,1);
				gluCylinder	(_cylinderObj, 1, 1, 1, 25, 10);
				glTranslated(0,0,1);
				gluCylinder	(_cylinderObj, 1, 0, 1, 25, 10);
			glPopMatrix();
		glPopMatrix();

	}
	void GrassLamp::makeHead(){
		GLUquadricObj * _cylinderObj = gluNewQuadric();
		gluQuadricNormals(_cylinderObj, GLU_FLAT);
		gluQuadricOrientation(_cylinderObj, GLU_INSIDE);

		glPushMatrix();
			glTranslatef(0.0f,0.55f,0.0f);
			glScalef(0.1f,0.125f,0.1f);
			
			
			makeBulb(); //bulb

			glBegin(GL_POLYGON); //top
				glVertex3d(0,1,0);
				glVertex3d(1,1,0);
				glVertex3d(1,1,1);
				glVertex3d(0,1,1);
				
			glEnd();

			glBegin(GL_POLYGON); // bot
				glVertex3d(0,0,0);
				glVertex3d(1,0,0);
				glVertex3d(1,0,1);
				glVertex3d(0,0,1);
				
			glEnd();

			glPushMatrix(); // cylinders

				glPushMatrix();
				glTranslatef(0.1f,0.0f,0.1f);
				glScaled(0.1,1.0,0.1);
				glRotatef(270,1.0f,0.0f,0.0f);
				gluCylinder	(_cylinderObj, 1, 1, 1, 25, 10);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.9f,0.0f,0.1f);
					glScaled(0.1,1.0,0.1);
					glRotatef(270,1.0f,0.0f,0.0f);
					gluCylinder	(_cylinderObj, 1, 1, 1, 25, 10);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0.9f,0.0f,0.9f);
					glScaled(0.1,1.0,0.1);
					glRotatef(270,1.0f,0.0f,0.0f);
					gluCylinder	(_cylinderObj, 1, 1, 1, 25, 10);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.1f,0.0f,0.9f);
					glScaled(0.1,1.0,0.1);
					glRotatef(270,1.0f,0.0f,0.0f);
					gluCylinder	(_cylinderObj, 1, 1, 1, 25, 10);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	}
	void GrassLamp::makePole(){
		glPushMatrix();
			glTranslatef(0.05f,0.0f,0.05f);
			glScalef(0.05f,0.55f,0.05f);
			glRotatef(270,1.0f,0.0f,0.0f);
			GLUquadricObj * _cylinderObj = gluNewQuadric();
			gluQuadricNormals(_cylinderObj, GLU_FLAT);
			gluQuadricOrientation(_cylinderObj, GLU_INSIDE);
			gluCylinder	(_cylinderObj, 0.5, 1, 1, 25, 10);
		glPopMatrix();
	}
	
	void GrassLamp::getModel(){

		glPushMatrix();
		glScalef(1.0f,0.7f,1.0f);
			makePole();
			makeHead();

		glPopMatrix();
	}
}



