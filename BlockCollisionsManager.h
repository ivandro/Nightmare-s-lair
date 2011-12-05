#ifndef BLOCK_COLISIONS_MANAGER_H
#define BLOCK_COLISIONS_MANAGER_H

#include <map>
#include <sstream>


namespace example {

	class BlockCollisionsManager {

		private:

			std::map<std::string,bool> _allowedMap;
	
		public:

			BlockCollisionsManager();	
			~BlockCollisionsManager();

			void addCollisionCondition(int x, int y, bool val);
		
			/*
			*	Returns true if there is a collision false otherwise
			**/
			bool checkCollision(int x, int y); 


	};
}


#endif