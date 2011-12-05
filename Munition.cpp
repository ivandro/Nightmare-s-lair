#include "Munition.h"
 
namespace example {

	Munition::Munition(std::string id) : cg::Entity(id), timer( 0 ), isActive( false ) {

		this->id = id;

	}
	Munition::Munition(std::string id, MunitionObserver *munitionObserver ) : cg::Entity(id), timer( 0 ), isActive( false ) {

		this->id = id;
		this->munitionObserver = munitionObserver;

	}

	void Munition::setMunitionObserver( MunitionObserver *munitionObserver ) {

		this->munitionObserver = munitionObserver;

	}
	Munition::~Munition() {
	}

	inline
	void Munition::makeMaterial() {
		_materialDL = glGenLists(1);
		assert(_materialDL != 0);
		glNewList(_materialDL,GL_COMPILE);	 	 

		Material *m = MaterialBank::getMaterial(MaterialBank::MATERIAL_COPPER);//?
		 m->shade(GL_FRONT);

  		glEndList();
	}
	void Munition::init() {
		
		_physics.setPosition(3,1.01,-3);
		_physics.setAngularVelocity(1000);
		_physics.setLinearVelocity(25);
		makeSphere();
		makeMunitionModel();
		makeMaterial();
	}

	inline
	void Munition::makeSphere() {
		_sphereObj = gluNewQuadric();
		gluQuadricCallback(_sphereObj, GLU_ERROR, 0);
		gluQuadricDrawStyle(_sphereObj, GLU_FILL);
		gluQuadricOrientation(_sphereObj, GLU_OUTSIDE); 
		gluQuadricNormals(_sphereObj, GLU_SMOOTH);
		gluQuadricTexture(_sphereObj, GL_FALSE);
	}

	
	inline
	void Munition::makeMunitionModel() {
		_modelMunition = glGenLists(1);
		assert(_modelMunition != 0);
		glNewList(_modelMunition,GL_COMPILE);
			gluSphere	(_sphereObj, 1, 15, 25);
		glEndList();
	}

	
	void Munition::draw() {
		if ( isActive ){

			glPushMatrix();
				glCallList(_materialDL);
				_physics.applyTransforms();
			
				glCullFace(GL_BACK);			

				glPushMatrix();
					glScaled(0.4,0.4,0.4);
					glCallList(_modelMunition);		
				glPopMatrix();					

				glCullFace(GL_FRONT);
			glPopMatrix();
		
		}
	
	}


	void Munition::update(unsigned long elapsed_millis) {
	
		if( isActive ){
			
			fly();
			double elapsed_seconds = elapsed_millis / (double)1000;
			_physics.step( elapsed_seconds);
			actualizeTimer( elapsed_seconds );
			
			if ( isEndTimer() ) {

				endTimer();

			}
		
		}
		else {

			// the ball is inactive so don't update 

		}
	}

	void Munition::actualizeTimer( double timePassed ) {

		timer += timePassed;

	}

	void Munition::shoot() {

		isActive = true;
		initTimer();

	}

	void Munition::fly() {

		// animation of the fly of the munition
		_physics.goAhead();

	}

	bool Munition::currentlyActive() {

		return isActive;

	}

	void Munition::setTimer( double seconds ) {


		timeToLive = seconds;

	}

	
	void Munition::initTimer() {
	
		timer = 0;
	
	}

	bool Munition::isEndTimer() {
			
		return timer >= timeToLive;

	}

	void Munition::endTimer() {

			isActive = false;
			munitionObserver->notActiveNotification( id );

	}

	void Munition::setPosition( cg::Vector3d position ) {
	
		_physics.setPosition( position[ 0 ], position[ 1 ], position[ 2 ] );
	
	}

	void Munition::setOrientation( cg::Vector3d up, cg::Vector3d front, cg::Vector3d right ){
	
		_physics.setUp( up );
		_physics.setFront( front );
		_physics.setRight( right );
	
	}
	void Munition::Collision(){}
	

 }