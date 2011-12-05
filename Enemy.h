#ifndef ENEMY_H
#define ENEMY_H

#include "cg\cg.h"
#include "BoxEntity.h"

namespace example {
	class Enemy : public cg::Entity, 
		public cg::IDrawListener,
	public cg::IUpdateListener,
	public BoxEntity
	{
	
	protected:
		float _blocksize;
		cg::Vector2f _pos;
	public:
		Enemy(int x, int y, float blocksize, std::string id,float maxX, float height, float maxZ);
		~Enemy();
		virtual void init() = 0;
        virtual void update(unsigned long elapsed_millis) = 0;
        virtual void draw() = 0;

	};


}


#endif