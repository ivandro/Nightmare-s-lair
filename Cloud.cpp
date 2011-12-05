#include "Cloud.h"

namespace example {

	Cloud::Cloud(int x, int y, float blocksize,std::string id) : cg::Entity(id){
		_blocksize = blocksize;
		_physics.setPosition(x*blocksize+(blocksize/2),blocksize*1.5,y*blocksize+(blocksize/2));
	}
	Cloud::~Cloud(void){}
	 void Cloud::init(){
		
		_physics.setAngularVelocity(500); //considerar sizeOfBlock/2 em x de 10  
		_physics.setLinearVelocity(50); 
		_movable=false;
		_isDebug = false;
		_startPos.set(3,1.01,-3);
		_shrinkVal =1.0;
		_sign = -1;
		_timer =1.0f;
	 }
	 void Cloud::shrink(){
		if(_shrinkVal < 0.8||_shrinkVal>1.0)
			 _sign = -_sign;
			 _shrinkVal =_shrinkVal+0.003f*_sign;
	 }
	 void Cloud::update(unsigned long elapsed_millis){
		    shrink();


	 		if(_movable && !_isDebug){
				if(cg::KeyBuffer::instance()->isKeyDown('w')) {
					_physics.goAhead();
					timeRemanant();
				}
				if(cg::KeyBuffer::instance()->isKeyDown('s')) {
					
					_physics.goBack();	
				}
				if(cg::KeyBuffer::instance()->isKeyDown('a')) {
					_physics.yawLeft();
				}
				if(cg::KeyBuffer::instance()->isKeyDown('d')) {
					_physics.yawRight();
				}
				MyCamera * tps = (MyCamera *) cg::Registry::instance()->get("Camera");
				tps->setPosition(_physics.getPosition());

				double elapsed_seconds = elapsed_millis / (double)10000;
				_physics.step(elapsed_seconds);
		}
	 }
	 void Cloud::draw(){
		
		 glPushMatrix();
		 _physics.applyTransforms();
		 glScaled(0.8*_shrinkVal,0.4,0.5); //Flattens the cloud Note when mooving make it shrink and expand by changing the z value according to
		 
		 Material * m = MaterialBank::getMaterial(MaterialBank::MATERIAL_PEARL);
		 m->shade(GL_FRONT_AND_BACK);
		
		 glutSolidSphere(-1,5,10);
		 glTranslated(1,0,0);
		 glutSolidSphere(-0.5,5,10);
		 glTranslated(-2,0,0);
		 glutSolidSphere(-1.5,5,10);
		 
		 
		 glPopMatrix();
		 glFlush();
	 }

	 void Cloud::togglemovable(){
		 _movable = !_movable;
	 }

	 void Cloud::toggleDebugMode() {
		_isDebug = !_isDebug;
	}

	 void Cloud::CreateRemanant(){
		cg::Vector3d pos = _physics.getPosition();	
		CloudRemanant* cr = (CloudRemanant*)cg::Registry::instance()->get("ResidualCloud");
		cr->setPos(_physics.getPosition());
		cr->state.enable();
	 }

	void Cloud::timeRemanant(){
		_timer = _timer- 0.05f;
		if(_timer <= -0.01f) {
			CreateRemanant();
			_timer = 1.0f;
		}
	}
	void Cloud::setPos(float x, float z){
		_physics.setPosition(x,_physics.getPosition()[1],z);
	}

}