#ifndef POWERUPMANAGER_H
#define POWERUPMANAGER_H

#include "cg/cg.h"
#include <string>
#include "MyPhysics.h"
#include "MaterialBank.h"
#include "Munition.h"
#include "GroundMunition.h"
#include "Heart.h"
#include "Stone.h"

namespace example {

	class PowerupManager : public cg::Entity,
		public cg::IUpdateListener
	{
	private:
		
		int _nVidas, _nMunition;

	public:
		PowerupManager(std::string id);
		~PowerupManager();
		void init();
		void update(unsigned long elapsed_millis);

	};

}

#endif