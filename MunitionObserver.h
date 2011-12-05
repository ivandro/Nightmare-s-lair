#ifndef MUNITION_OBSERVER_H
#define MUNITION_OBSERVER_H

#include <string>

namespace example {

	class MunitionObserver {

	public:

		virtual void colisionNotification( std::string munitionId ) = 0;
		virtual void notActiveNotification( std::string munitionId ) = 0;

	};

}

#endif