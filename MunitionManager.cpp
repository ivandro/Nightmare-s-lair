#include "MunitionManager.h"
namespace example {

	MunitionManager::MunitionManager( std::string id, int managedMunitions ): cg::Entity( id ), managedMunitions( managedMunitions ) {

		cg::Registry *registry = cg::Registry::instance();
		for ( int currentMunitionId = 0; currentMunitionId < managedMunitions; currentMunitionId++ ) {

			std::stringstream nameStream;
			nameStream << "munition" << currentMunitionId;
			std::string name = nameStream.str();
			std::cout << "munition name is " << name << " and currentMunitionId is " << currentMunitionId << std::endl;
			Munition *munition = new Munition( name, this );
			registry->add( munition );
			notInUseMunitions[ name ] = munition;

		}

	}

	MunitionManager::~MunitionManager(){}

	void MunitionManager::init() {

		
		cg::Registry *registry = cg::Registry::instance();
		cg::View *v = ( cg::View* )registry->get( "view" );
		
		for ( int currentMunitionId = 0; currentMunitionId < managedMunitions; currentMunitionId++ ) {

			std::stringstream nameStream;
			nameStream << "munition" << currentMunitionId;
			std::string name = nameStream.str();
			v->linkEntityAtEnd(name);
		
		}

	}


	void MunitionManager::setMunitionPosition( std::string ammunitionId, cg::Vector3d ammunitionPosition ) {
		 
		 if ( inUseMunitions.count( ammunitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ ammunitionId ];
			munition->setPosition( ammunitionPosition );

		 }
		 else {

			// munition is not active, so here nothing is done

		 }

	}
	void MunitionManager::setMunitionOrientation( std::string ammunitionId, cg::Vector3d up, cg::Vector3d front, cg::Vector3d right ){
		
		 if ( inUseMunitions.count( ammunitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ ammunitionId ];
			munition->setOrientation( up, front, right );

		}
		else {

			// munition is not active, so here nothing is done

		}
	
	}

	void MunitionManager::setMunitionTimeToLive( std::string ammunitionId, double timeToLive ) {
		
		 if ( inUseMunitions.count( ammunitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ ammunitionId ];	
			munition->setTimer( timeToLive );

		}
		else {

			// munition is not active, so here nothing is done

		}

	}

	void MunitionManager::shootMunition( std::string ammunitionId ){ 
	
		 if ( inUseMunitions.count( ammunitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ ammunitionId ];		
			munition->shoot();

		}
		else {

			// munition is not active, so here nothing is done

		}
	
	}

	
	bool MunitionManager::bindMunition( std::string *munitionId ) {
		
		std::map< std::string, Munition*>::iterator nAvailableMunitionsIt = notInUseMunitions.begin();
		
		if ( nAvailableMunitionsIt != notInUseMunitions.end() ) {
			
			*munitionId = nAvailableMunitionsIt->first;
			Munition *munition = nAvailableMunitionsIt->second;
			
			notInUseMunitions.erase( *munitionId );
			inUseMunitions[ *munitionId ] = munition;

			return true;

		}
		else {

			return false;

		}

	}

	void MunitionManager::colisionNotification( std::string munitionId ) {
		
		 if ( inUseMunitions.count( munitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ munitionId ];	
			inUseMunitions.erase( munitionId );
			std::cout << "in inUseMunitions there are " << inUseMunitions.count( munitionId ) << " with id " << munitionId << std::endl;

			notInUseMunitions[ munitionId ] = munition;
		}
		else {

			// munition is not active, so here nothing is done

		}

	}

	void MunitionManager::notActiveNotification( std::string munitionId ) {
		
		if ( inUseMunitions.count( munitionId ) > 0 ) {
			
			Munition *munition = inUseMunitions[ munitionId ];	
			inUseMunitions.erase( munitionId );
			std::cout << "in inUseMunitions there are " << inUseMunitions.count( munitionId ) << " with id " << munitionId << std::endl;

			notInUseMunitions[ munitionId ] = munition;
		}
		else {

			// munition is not active, so here nothing is done

		}

	}

}