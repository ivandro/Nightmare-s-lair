#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "cg/cg.h"
#include "TextureBank.h"
#include "BoxEntity.h"

namespace example {


	class Obstacle : public cg::Entity,
		public cg::IDrawListener,
		public BoxEntity
	{
	protected:
		cg::Vector2f _pos;
		float _blocksize;

	public:
			Obstacle(int x, int y, float blocksize, std::string id, float height, float maxX, float maxZ);
			~Obstacle();
			void init();
			void draw(); 

			virtual void makeModel() = 0;


	};


}

#endif