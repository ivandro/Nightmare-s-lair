#include "MainCharacter.h"

namespace example {

	MainCharacter::MainCharacter(std::string id):

		cg::Entity(id),
		_movable( true ),
		_isDebug( false ),
		m_lastMousePosition( 0.0, 0.0, -1.0 ),
		rotRightArm( 0.0 ),
		rotRightLeg( 0.0 ),
		rotLeftArm( 0.0 ),
		rotLeftLeg( 0.0 ),
		movingRightUp( true ),
		movingRightForward( true ),
		movingLeftUp( false ),
		movingLeftForward( false )
		{

	}

	MainCharacter::~MainCharacter() {
	}

	void MainCharacter::init() {
		_physics.setPosition(3,1.01,-3);
		_physics.setAngularVelocity(1000); //considerar sizeOfBlock/2 em x de 10  
		_physics.setLinearVelocity(100); 
	}

	void MainCharacter::update(unsigned long elapsed_millis) {
		if(_movable && !_isDebug){
			if(cg::KeyBuffer::instance()->isKeyDown('w')) {
				moveRightArm();
				moveLeftArm();
				moveRightLeg();
				moveLeftLeg();
				_physics.goAhead();
		
			}
			if(cg::KeyBuffer::instance()->isKeyDown('s')) {
				moveRightArm();
				moveLeftArm();
				moveRightLeg();
				moveLeftLeg();
				_physics.goBack();	
		
			}
			if(cg::KeyBuffer::instance()->isKeyDown('a')) {
				moveRightArm();
				moveLeftArm();
				moveRightLeg();
				moveLeftLeg();
				_physics.strafeLeft();
			}
			if(cg::KeyBuffer::instance()->isKeyDown('d')) {
				moveRightArm();
				moveLeftArm();
				moveRightLeg();
				moveLeftLeg();
				_physics.strafeRight();
			}
			// _lastposition.set(_physics.getPosition()); REMOVE
			MyFPSCamera * fps = (MyFPSCamera *) cg::Registry::instance()->get("FPSCamera");
			fps->setPosition(_physics.getPosition());

			double elapsed_seconds = elapsed_millis / (double)10000;
			_physics.step(elapsed_seconds);
		}
	}

	void MainCharacter::onMousePassiveMotion(int x, int y) {

	}

	int drawPasses = 100;

	/*
	** name: fpsTransformationBegin
	** description: transformation that the box suffer when the camera is the fpsCamera. PS: the function must be called with its counterpart
	**		fpsTransformationEnd
	*/

	void MainCharacter::fpsTransformationBegin() {


		// change the direction of the box to be equal to the direction of the camera
		
		MyFPSCamera *fps = (MyFPSCamera *) cg::Registry::instance()->get( "FPSCamera" );
		cg::Vector3d *newFront = new cg::Vector3d( cos( fps->getRotationX() * degreeToRadianus ), 0.0, sin( fps->getRotationX() * degreeToRadianus ) );
		cg::Vector3d *newRight = new cg::Vector3d( -sin( fps->getRotationX() * degreeToRadianus ), 0.0, cos( fps->getRotationX() * degreeToRadianus ) );

		_physics.setFront ( *newFront );
		_physics.setRight( *newRight );
		// put the matrix mode to modelview
		
		glMatrixMode( GL_MODELVIEW );
		// safe the actual modelview matrix
		
		glPushMatrix();

			// get the camera unchanged modelview matrix
			// put the unchanged matrix as the currently matrix
		
			glLoadMatrixd( fps->getUnchangedMVMatrix() );

	}

	/*
	** name: fpsTransformationEnd
	** description: terminating the fpsTransformation that the box suffer when in the fpsCamera
	*/

	void MainCharacter::fpsTransformationEnd() {

		glPopMatrix();

	}

	void drawArm( GLfloat rotationDegree, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis ) {

		GLfloat 
			armAxesPosX = 0.25,
		    armAxesPosY = 0.0, 
			armAxesPosZ = 0.0;
		GLfloat
			armScaleX = 4.0,
			armScaleY = 1.0,
			armScaleZ = 0.7;
		GLfloat 
			scaleAdjustFactorX = ( armScaleX != 1.0 ) ? ( armScaleX / 2.0 ) : 0.0,
			scaleAdjustFactorY = ( armScaleY != 1.0 ) ? ( armScaleY / 2.0 ) : 0.0, 
			scaleAdjustFactorZ = ( armScaleZ != 1.0 ) ? ( armScaleZ / 2.0 ) : 0.0;

			scaleAdjustFactorX *= ( armAxesPosX > 0 ) ? -1 : 1;
			scaleAdjustFactorY *= ( armAxesPosY > 0 ) ? -1 : 1;
			scaleAdjustFactorZ *= ( armAxesPosZ > 0 ) ? -1 : 1;

		glPushMatrix();
			
			glTranslatef( armAxesPosX, armAxesPosY, armAxesPosZ );
			glRotatef( rotationDegree, xAxis, yAxis, zAxis );
			glTranslatef( -armAxesPosX + scaleAdjustFactorX, -armAxesPosY + scaleAdjustFactorY, -armAxesPosZ + scaleAdjustFactorZ );
			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( 1 );

		glPopMatrix();

	}

	void drawLeg( GLfloat rotationDegree, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis ) {

		GLfloat 
			armAxesPosX = 0.0,
		    armAxesPosY = 0.25, 
			armAxesPosZ = 0.0;
		GLfloat
			armScaleX = 1.0,
			armScaleY = 4.0,
			armScaleZ = 0.7;
		GLfloat 
			scaleAdjustFactorX = ( armScaleX != 1.0 ) ? ( armScaleX / 2.0 ) : 0.0,
			scaleAdjustFactorY = ( armScaleY != 1.0 ) ? ( armScaleY / 2.0 ) : 0.0, 
			scaleAdjustFactorZ = ( armScaleZ != 1.0 ) ? ( armScaleZ / 2.0 ) : 0.0;

			scaleAdjustFactorX *= ( armAxesPosX > 0 ) ? -1 : 1;
			scaleAdjustFactorY *= ( armAxesPosY > 0 ) ? -1 : 1;
			scaleAdjustFactorZ *= ( armAxesPosZ > 0 ) ? -1 : 1;

		glPushMatrix();
			
			glTranslatef( armAxesPosX, armAxesPosY, armAxesPosZ );
			glRotatef( rotationDegree, xAxis, yAxis, zAxis );
			glTranslatef( -armAxesPosX + scaleAdjustFactorX, -armAxesPosY + scaleAdjustFactorY, -armAxesPosZ + scaleAdjustFactorZ );
			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( 1 );

		glPopMatrix();

	}

	void drawChest() {

		GLfloat
			armScaleX = 1.0,
			armScaleY = 4.0,
			armScaleZ = 2.0;

		glPushMatrix();

			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( 1 );

		glPopMatrix();

	}

	void drawHead() {

		// define porportions
		GLfloat 
			headScaleX = 1.0,
			headScaleY = 1.25,
			headScaleZ = 1.0;

		// draw head with unitary porprotions
		glPushMatrix();
			//scale to porportions
			glScalef( headScaleX, headScaleY, headScaleZ );

			glutSolidCube( 1 );

		glPopMatrix();

	}

	void MainCharacter::moveRightArm() {

		if ( rotRightArm < -35 ) {

			movingRightUp = false;

		}
		else if ( 35 < rotRightArm ) {

			movingRightUp = true;

		}

		if ( movingRightUp ) {

			rotRightArm--;

		}else {

			rotRightArm++;

		}

	}

	void MainCharacter::moveRightLeg() {

		if ( rotRightLeg < -35 ) {

			movingRightForward = false;

		}
		else if ( 35 < rotRightLeg ) {

			movingRightForward = true;

		}

		if ( movingRightForward ) {

			rotRightLeg--;

		}else {

			rotRightLeg++;

		}

	}

	void MainCharacter::moveLeftArm() {

		if ( rotLeftArm < -35 ) {

			movingLeftUp = false;

		}
		else if ( 35 < rotLeftArm ) {

			movingLeftUp = true;

		}

		if ( movingLeftUp ) {

			rotLeftArm--;

		}else {

			rotLeftArm++;

		}

	}

	void MainCharacter::moveLeftLeg() {

		if ( rotLeftLeg < -35 ) {

			movingLeftForward = false;

		}
		else if ( 35 < rotLeftLeg ) {

			movingLeftForward = true;

		}

		if ( movingLeftForward ) {

			rotLeftLeg--;

		}else {

			rotLeftLeg++;

		}

	}
	
	
	GLdouble 
		xchar = 0.63,
		ychar = 1.25,
		zchar = 0.0;


	/*
	** name: drawMainCharacter
	** description: draw the main character
	*/
	void MainCharacter::drawMainCharacter() {

		glScaled( 0.375, 0.375, 0.375 );

			// drawchest at center
		drawChest();
			// draw rightArm at top right corner of chest
		glPushMatrix();
			glTranslated( 0.5, 1.5, -1.7 );
			drawArm( rotRightArm, 0.0, 0.0, 1.0 );
		glPopMatrix();
			// draw leftArm at top left corner of chest
		glPushMatrix();
			glTranslated( 0.5, 1.5, 1.0 );
			drawArm( rotLeftArm, 0.0, 0.0, 1.0 );
		glPopMatrix();
			// draw right leg at bottom right corner of chest
		glPushMatrix();
			glTranslated( 0.0, -2.0, -0.95 );
			drawLeg( rotRightLeg, 0.0, 0.0, 1.0 );
		glPopMatrix();
			// draw left leg at bottom left corner of chest
		glPushMatrix();
			glTranslated( 0.0, -2.0, 0.35 );
			drawLeg( rotLeftLeg, 0.0, 0.0, 1.0 );
		glPopMatrix();
			// draw head at top of the chest
		glPushMatrix();
			glTranslated( 0.0, 2.625, 0.0 );
			drawHead();
		glPopMatrix();
	}

	void MainCharacter::draw() {

		
		MyFPSCamera *fps = (MyFPSCamera *) cg::Registry::instance()->get( "FPSCamera" );
		if ( fps->isFPSMode() ) {

			fpsTransformationBegin();

		}

		glPushMatrix();
			_physics.applyTransforms();
			//glCallList(_modelDL);
			//glDisable( GL_LIGHTING );
			
		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_PLASTIC_RED);
		 m->shade(GL_FRONT_AND_BACK);

			glTranslated( xchar, ychar, zchar );
			drawMainCharacter();
			//glEnable( GL_LIGHTING );
		glPopMatrix();
			glEnable( GL_LIGHTING );
		glPopMatrix();


		if ( fps->isFPSMode() ) {

			fpsTransformationEnd();
		
		}

	}

	void MainCharacter::togglemovable(){
		_movable = !_movable;
	}

	void MainCharacter::toggleDebugMode() {
		_isDebug = !_isDebug;
	}

}