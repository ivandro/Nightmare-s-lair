#ifndef OBSERVER_H
#define OBSERVER_H

#include "cg/cg.h"
#include "MyLight.h"
#include "MyCamera.h"
#include "DebugCamera.h"
#include "MyFPSCamera.h"
#include "MainCharacter.h"
#include "Cloud.h"
#include "MyLight.h"

namespace example{

class Observer : public cg::Entity {

public:
	MyLight *light;
	MainCharacter *obj;
	Cloud *cl;
	MyFPSCamera *fpscamera;
	MyCamera *camera;
	DebugCamera *debugcamera;

	Observer( std::string id );
	~Observer();
	void init();
	void toggleObjects();
	void toggleCameras();
	void activeDebug();
};

}
#endif
