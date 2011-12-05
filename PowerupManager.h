#ifndef POWERUPMANAGER_H
#define POWERUPMANAGER_H

#include "cg/cg.h"
#include <string>
#include <map>
#include "Powerup.h"

namespace example {

	//class PowerupManager : public cg::IUpdateListener
	class PowerupManager : public cg::Entity,
		public cg::IUpdateListener
	{
	private:
		static const int MAXPOWERUPS = 5;
		
	public:
		typedef std::map<std::string, Powerup*> StringPowerUp;
		StringPowerUp coordinates;
		/*struct coord {
		  int x;
		  int y;
		  Powerup powerup;
		} cenas;*/

		PowerupManager(std::string id);
		~PowerupManager();
		void init();
		void update(unsigned long elapsed_millis);

		void addCoordinates(int x, int y, Powerup *powerup);
		void powerupCatched(std::string name);
	};

}

#endif