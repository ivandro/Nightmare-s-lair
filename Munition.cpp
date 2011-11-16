#include "Munition.h"
 
namespace example {

	Munition::Munition(std::string id) : cg::Entity(id) {
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
		_disappear = false;
		_physics.setPosition(0,1.0,4); //deve ser a posicao do user
		_physics.setAngularVelocity(1000);
		_physics.setLinearVelocity(250);
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
		assert(_modelCylinder != 0);
		glNewList(_modelMunition,GL_COMPILE);
			gluSphere	(_sphereObj, 1, 15, 25);
		glEndList();
	}

	
	void Munition::draw() {
		if(!_disappear){
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
		
		if(!_disappear){
			//std::cout << "---------------------- " << _physics.getPosition() << std::endl;
			if(cg::KeyBuffer::instance()->isKeyDown('b')) { //REMOVE --> test
					attack();		
			}

			if(cg::KeyBuffer::instance()->isKeyDown('n')) { //REMOVE --> test
					reborn();		
			}


			double elapsed_seconds = elapsed_millis / (double)10000;
				_physics.step(elapsed_seconds);
		}
	}

	void Munition::attack() { //lanca a bola para a frente e torna-a invisivel
		for(int i=0;i<2;i++){
			_physics.goAhead();
		}
		//_disappear = true;
	}

	void Munition::reborn() { //coloca a bola na posicao do utilizador e torna-a visivel
		/*MyBox *user = (MyBox*)cg::Registry::instance()->get("Boxmagica");
		cg::Vector3d position = user->_physics.getPosition();
		std::cout << "positionkaka: " << position << std::endl;
		_physics.setPosition(position[1],position[2],position[3]);*/

		/*SOLUCAO --- o MyBox quando chama a funçao attack, se ainda tiver municoes, deve chamar reborn e fazer
		Munition *munition = (Munition*)cg::Registry::instance()->get("munition");
		munition->setPosition(_physics.getPosition());
		*/
		_disappear = false;
	}

 }