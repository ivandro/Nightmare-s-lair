#ifndef WORLDFACTORY_H
#define WORLDFACTORY_H

#include <string>
#include "cg/cg.h"
#include "World.h"
namespace example {

class WorldFactory
{
public:
	WorldFactory();
	~WorldFactory();

	virtual World * createWorld() const = 0;

};

}

#endif
