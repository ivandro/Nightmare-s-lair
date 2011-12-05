#include "MainCharacter.h"
namespace example {

	MainCharacter::MainCharacter(int x, int y, float blocksize, std::string id, BlockCollisionsManager * cm, BoxCollisionManager *bm):
		
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
		movingLeftForward( false ),
		_CM(cm),
		_BM(bm),
		_keyCount(0),
		_blocksize(blocksize),
		BoxEntity(new Box(Box::BOX_PLAYER,0.4*blocksize,0.1*blocksize,0.1*blocksize), 0, cg::Vector3f(0,0,0)) //Change later
	
	{
		//_physics.setPosition(x*blocksize+blocksize/2,0,y*blocksize+blocksize/2); DEBUG
		_physics.setPosition(0,0,0);
	}

	MainCharacter::~MainCharacter() {
	}

	void MainCharacter::init() {
		_physics.setAngularVelocity(1000); //considerar sizeOfBlock/2 em x de 10  
		_physics.setLinearVelocity(100);
		_LifeCount = 3;
		_MunitionCount = 3;
		munitionManager = ( MunitionManager * )cg::Registry::instance()->get( "munition manager" );
	}

	void MainCharacter::update(unsigned long elapsed_millis) {
		
		rechargeMunition( elapsed_millis / (double)1000 );

		if(_movable && !_isDebug){

			cg::Vector3d oldPos = _physics.getPosition();

			if ( cg::KeyBuffer::instance()->isKeyDown( 'l' ) && munitionRecharged ) {
				
				std::string munitionId;
				
				if ( munitionManager->bindMunition( &munitionId ) ) {

					std::cout << "gonna shoot munition " << munitionId << std::endl;

					munitionManager->setMunitionTimeToLive( munitionId, 1 );
				
					// posicionar a bola
					
					cg::Vector3d position = _physics.getPosition();
					munitionManager->setMunitionPosition( munitionId, position );

					// orientar a bola
	
					cg::Vector3d up = _physics.getUp();
					cg::Vector3d front = _physics.getFront();
					cg::Vector3d right = _physics.getRight();
					munitionManager->setMunitionOrientation( munitionId, up, front, right );

					// disparar a bola
					munitionManager->shootMunition( munitionId );
					
				}
				else {

					// there are no munitions available
					std::cout << "There are no munitions available" << std::endl;

				}

				initializeMunitionRecharge( 0.2 );

			}		
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


			double elapsed_seconds = elapsed_millis / (double)10000;
			_physics.step(elapsed_seconds);

			
			cg::Vector3d newPos = _physics.getPosition();
			checkColisions(oldPos,newPos);

			cg::Vector3d _temp = _physics.getPosition();
			
			MyFPSCamera * fps = (MyFPSCamera *) cg::Registry::instance()->get("FPSCamera");
			fps->setPosition(_temp);
							
			Cloud * _cloud = (Cloud *)cg::Registry::instance()->get("Nuvem");
			_cloud->setPos(_temp[0],_temp[2]);
			
			MyLight * _sun = (MyLight *)cg::Registry::instance()->get("Sun");
			_sun->setPos(cg::Vector3d(_temp[0],_temp[1],_temp[2]));

			_center=cg::Vector3f(_temp[0],_temp[1],_temp[2]);
		}

	}

	void MainCharacter::rechargeMunition( double seconds ) {

		munitionRechargeTime -= seconds;

		if ( munitionRechargeTime <= 0 ) {

			munitionRecharged = true;

		}
		else {

			// munition still recharging

		}

	}
	
	void MainCharacter::initializeMunitionRecharge( double seconds ) {
		
		munitionRecharged = false;
		munitionRechargeTime = seconds;
	}

	void MainCharacter::onMousePassiveMotion(int x, int y) {

	}

	
		
	void MainCharacter::onMouse(int button, int state, int x, int y) {

		if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
			if ( munitionRecharged ) {
				
				std::string munitionId;
				
				if ( munitionManager->bindMunition( &munitionId ) ) {

					std::cout << "gonna shoot munition " << munitionId << std::endl;

					munitionManager->setMunitionTimeToLive( munitionId, 1 );
				
					// posicionar a bola
					
					cg::Vector3d position = _physics.getPosition();
					munitionManager->setMunitionPosition( munitionId, position );

					// orientar a bola
	
					cg::Vector3d up = _physics.getUp();
					cg::Vector3d front = _physics.getFront();
					cg::Vector3d right = _physics.getRight();
					munitionManager->setMunitionOrientation( munitionId, up, front, right );

					// disparar a bola
					munitionManager->shootMunition( munitionId );
					
				}
			}

		}
	}

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
			armAxesPosX = 0.25f,
		    armAxesPosY = 0.0f, 
			armAxesPosZ = 0.0f;
		GLfloat
			armScaleX = 4.0f,
			armScaleY = 1.0f,
			armScaleZ = 0.7f;
		GLfloat 
			scaleAdjustFactorX = ( armScaleX != 1.0f ) ? ( armScaleX / 2.0f ) : 0.0f,
			scaleAdjustFactorY = ( armScaleY != 1.0f ) ? ( armScaleY / 2.0f ) : 0.0f, 
			scaleAdjustFactorZ = ( armScaleZ != 1.0f ) ? ( armScaleZ / 2.0f ) : 0.0f;

			scaleAdjustFactorX *= ( armAxesPosX > 0 ) ? -1 : 1;
			scaleAdjustFactorY *= ( armAxesPosY > 0 ) ? -1 : 1;
			scaleAdjustFactorZ *= ( armAxesPosZ > 0 ) ? -1 : 1;

		glPushMatrix();
			
			glTranslatef( armAxesPosX, armAxesPosY, armAxesPosZ );
			glRotatef( rotationDegree, xAxis, yAxis, zAxis );
			glTranslatef( -armAxesPosX + scaleAdjustFactorX, -armAxesPosY + scaleAdjustFactorY, -armAxesPosZ + scaleAdjustFactorZ );
			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( -1 );

		glPopMatrix();

	}

	void drawLeg( GLfloat rotationDegree, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis ) {

		GLfloat 
			armAxesPosX = 0.0f,
		    armAxesPosY = 0.25f, 
			armAxesPosZ = 0.0f;
		GLfloat
			armScaleX = 1.0f,
			armScaleY = 4.0f,
			armScaleZ = 0.7f;
		GLfloat 
			scaleAdjustFactorX = ( armScaleX != 1.0f ) ? ( armScaleX / 2.0f ) : 0.0f,
			scaleAdjustFactorY = ( armScaleY != 1.0f ) ? ( armScaleY / 2.0f ) : 0.0f, 
			scaleAdjustFactorZ = ( armScaleZ != 1.0f ) ? ( armScaleZ / 2.0f ) : 0.0f;

			scaleAdjustFactorX *= ( armAxesPosX > 0 ) ? -1 : 1;
			scaleAdjustFactorY *= ( armAxesPosY > 0 ) ? -1 : 1;
			scaleAdjustFactorZ *= ( armAxesPosZ > 0 ) ? -1 : 1;

		glPushMatrix();
			
			glTranslatef( armAxesPosX, armAxesPosY, armAxesPosZ );
			glRotatef( rotationDegree, xAxis, yAxis, zAxis );
			glTranslatef( -armAxesPosX + scaleAdjustFactorX, -armAxesPosY + scaleAdjustFactorY, -armAxesPosZ + scaleAdjustFactorZ );
			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( -1 );

		glPopMatrix();

	}

	void drawChest() {

		GLfloat
			armScaleX = 1.0,
			armScaleY = 4.0,
			armScaleZ = 2.0;

		glPushMatrix();

			glScalef( armScaleX, armScaleY, armScaleZ );

			glutSolidCube( -1 );

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

			glutSolidCube( -1 );

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
		xchar = 0.0,
		ychar = 1.8,
		zchar = 0.0;


	/*
	** name: drawMainCharacter
	** description: draw the main character
	*/
	void MainCharacter::drawMainCharacter() {
		float scale = 0.07*_blocksize;
		glScalef(scale,scale, scale);
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
	
			if( _isDebug){
	
				debugBox(cg::Vector3f(0,1,1));
			}

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
		
		glPopMatrix();


		if ( fps->isFPSMode() ) {

			fpsTransformationEnd();
		
		}




	}

	void MainCharacter::togglemovable(){
		_movable = !_movable;
		Cloud * _cloud = (Cloud *)cg::Registry::instance()->get("Nuvem");
		_cloud->setPos(_physics.getPosition()[0],_physics.getPosition()[2]);
	}

	void MainCharacter::toggleDebugMode() {
		_isDebug = !_isDebug;
	}
	void MainCharacter::checkColisions(cg::Vector3d oldPos, cg::Vector3d newPos){
		int oldx = ((int)oldPos[0]) /_blocksize;
		int newx = ((int)newPos[0]) /_blocksize;
		int oldy = ((int)oldPos[2]) /_blocksize;
		int newy = ((int)newPos[2]) /_blocksize;
		if(oldx >=0 && newx >=0 && oldy >=0 && newy >=0)  //BlockColisions
			if(_CM->checkCollision(newx,newy)){
				if(oldx != newx && oldy!=newy )
					_physics.setPosition(oldPos[0],newPos[1],oldPos[2]);
				else if(oldx != newx)
					_physics.setPosition(oldPos[0],newPos[1],newPos[2]);
				else if(oldy!=newy)
					_physics.setPosition(newPos[0],newPos[1],oldPos[2]);
			}
			BoxCollisionManager::CollisionStats *check = _BM->checkBoxColision(_box,oldPos,newPos,getId()); //Box Collisions
					
			if(check != NULL){
				if(check->colType == BoxCollisionManager::CollisionType::XZ)
					_physics.setPosition(oldPos[0],newPos[1],oldPos[2]);
				else if(check->colType == BoxCollisionManager::CollisionType::X)
					_physics.setPosition(oldPos[0],newPos[1],newPos[2]);
				else if(check->colType == BoxCollisionManager::CollisionType::Z)
					_physics.setPosition(newPos[0],newPos[1],oldPos[2]);
				
				Box::EntityType type = check->entType;
				if(type==Box::EntityType::BOX_ENEMY){
					
				} else if (type==Box::EntityType::BOX_KEY){
					_keyCount++;
					if(_keyCount==3){
						Door *d = (Door *) cg::Registry::instance()->get( "Door" );
						d->openClose();
					}
				}
				if(_keyCount==3 && type ==Box::EntityType::BOX_DOOR){
					std::cout << "LEVEL OVER";
				}
				//Decide if dmg is necessary
			}
	}

	int MainCharacter::getNLifes() {
		return _LifeCount;
	}

	int MainCharacter::getNMunitions() {
		return _MunitionCount;
	}

	cg::Vector2d MainCharacter::getCharPos(){
		cg::Vector2d charPos;
		cg::Vector3d pos = _physics.getPosition();
		charPos[0] = pos[0]/_blocksize; //devolve x
		charPos[1] = pos[2]/_blocksize; //devolve z
		return charPos;
	}

}