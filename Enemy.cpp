#include "Enemy.h"


namespace example {

		
		Enemy::Enemy(int x, int y, float blocksize, std::string id,float maxX, float height, float maxZ): cg::Entity(id),
			BoxEntity(new Box(Box::BOX_ENEMY,height*blocksize,maxX*blocksize,maxZ*blocksize),0,cg::Vector3f(x*blocksize+blocksize/2,0,y*blocksize+blocksize/2)),
		_blocksize(blocksize)
		{
			_pos[0]=x*blocksize+blocksize/2;
			_pos[1]=y*blocksize+blocksize/2;
		}
		Enemy::~Enemy(){}


}