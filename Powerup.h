#ifndef POWERUP_H
#define POWERUP_H

#include "cg/cg.h"
#include <string>
#include "Munition.h"
#include "GroundMunition.h"
#include "Heart.h"
//#include "PowerupManager.h"

namespace example {

	class Powerup : public cg::Entity,
		public cg::IUpdateListener
	{
	private:
		std::string _name;
		bool _heartActive; //we can have heart or munition
		bool _catched;
		cg::Vector2f _pos;
		float _blocksize;
		Heart *_heart;
		GroundMunition *_gmunition;
		int _timestamp;

	public:
		Powerup(Heart *heart, GroundMunition *gmunition, std::string id);
		Powerup(std::string id);
		~Powerup();
		void init();
		void update(unsigned long elapsed_millis);

		void activePowerup();
		void setCatched(bool catched);	
		void setTimestamp(int timestamp);
		int getTimestamp();
	};

}

#endif