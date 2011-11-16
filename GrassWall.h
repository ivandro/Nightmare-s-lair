#ifndef GRASSWALL_H
#define GRASSWALL_H

#include "cg/cg.h"

#include "Wall.h"

namespace example{

class GrassWall: public Wall
{
public:
	GrassWall(int x, int y, float blocksize, std::string id);
	~GrassWall(void);
	void getTexture();
};

}
#endif
