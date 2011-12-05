#ifndef AMMUNITION_MANAGER_H
#define AMMUNITION_MANAGER_H

#include <map>
#include <sstream>
#include "cg/cg.h"
#include "Munition.h"
#include "MunitionObserver.h"


namespace example {

	class MunitionManager: public cg::Entity, public MunitionObserver {
	private:
		std::map< std::string, Munition* > notInUseMunitions;
		std::map< std::string, Munition* > inUseMunitions;
		int managedMunitions;

	public:
		MunitionManager( std::string id, int managedMunitions );
		~MunitionManager();

		void init();

		bool bindMunition( std::string *munitionId );
		void setMunitionPosition( std::string munitionId, cg::Vector3d munitionPosition );
		void setMunitionOrientation( std::string munitionId, cg::Vector3d up, cg::Vector3d front, cg::Vector3d right );
		void setMunitionTimeToLive( std::string munitionId, double timeToLive );
		void shootMunition( std::string munitionId );

		
		void colisionNotification( std::string munitionId );
		void notActiveNotification( std::string munitionId );

	};

}

#endif