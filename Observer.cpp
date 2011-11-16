#include "Observer.h"

namespace example{

Observer::Observer( std::string id ): cg::Entity( id ){
			
}
Observer::~Observer(){}

	void Observer::init() {
			light = (MyLight*)cg::Registry::instance()->get("Sun");
			obj = (MainCharacter*)cg::Registry::instance()->get("MainCharacter");
			cl = (Cloud*)cg::Registry::instance()->get("Nuvem");
			fpscamera = (MyFPSCamera*)cg::Registry::instance()->get("FPSCamera");
			camera = (MyCamera*)cg::Registry::instance()->get("Camera");
			debugcamera = (DebugCamera*)cg::Registry::instance()->get("DebugCamera");

			if(!light || !obj || !cl || !fpscamera || !camera || !debugcamera){
				std::cout << "ERROR!!!" << std::endl;
		}
	}
	void Observer::toggleObjects() {
		light->toggleDebugMode();
		obj->toggleDebugMode();
		cl->toggleDebugMode();			
	}
	void Observer::toggleCameras() {
		camera->toggleTopMode();	
		fpscamera->toggleFPSMode();		
	}

	void Observer::activeDebug(){
		cg::Vector3d position;
		if(debugcamera){
				if(fpscamera->isActive()) {
					fpscamera->toggleFPSMode();	
					position = fpscamera->getPosition();
					debugcamera->_physics.setPosition(position[0],position[1],position[2]);
					debugcamera->toggleDebugMode();
				}
				else if(camera->isActive()) {
					camera->toggleTopMode(); 
					position = camera->getPosition();
					debugcamera->_physics.setPosition(position[0],position[1],position[2]);
					debugcamera->toggleDebugMode();
				}
				else if(debugcamera->isActive()) {
					debugcamera->toggleDebugMode(); 
					fpscamera->toggleFPSMode();	//if debugactivo volta 'a CAMERA FPS
				}
		}
	
	}
}