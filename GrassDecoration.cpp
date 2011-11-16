#include "GrassDecoration.h"

namespace example {		
		GrassDecoration::GrassDecoration(int x, int y, float blocksize, std::string id) : Decoration(x,y,blocksize,id) {
	
		}
		
		GrassDecoration::~GrassDecoration(){}



		void GrassDecoration::makePot() {
		GLUquadricObj * _cylinderObj = gluNewQuadric();
		gluQuadricNormals(_cylinderObj, GLU_FLAT);
		gluQuadricOrientation(_cylinderObj, GLU_INSIDE);
		
		
		glPushMatrix();
			glScaled(0.3,0.3,0.3);
			glRotated(270,1,0,0);
			gluCylinder	(_cylinderObj, 0.4, 0.7, 1, 25, 10);
			
			gluQuadricOrientation(_cylinderObj, GLU_OUTSIDE); //Second vase so we can see it drawn inside
			gluCylinder	(_cylinderObj, 0.4, 0.7, 1, 25, 10);

			glTranslated(0,0,0.8);		
			gluQuadricOrientation(_cylinderObj, GLU_INSIDE);
			gluDisk(_cylinderObj,0,0.64,25,10);
		glPopMatrix();


		}
		void GrassDecoration::makeTree(){
			 glPushMatrix();
				 glTranslatef(0,0.5,0);
				 glScaled(0.3,1,0.3);
				 glutSolidSphere(0.5,10,10);
			 glPopMatrix();			 
		}

	

		
		void GrassDecoration::getModel(){
			glPushMatrix();
				glTranslatef(0.3,0,0.3);
				makePot();
				makeTree();
			glPopMatrix();
		
		}

}