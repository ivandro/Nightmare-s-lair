#ifndef LAMP_H
#define LAMP_H

#include "cg/cg.h"
#include "BoxEntity.h"

namespace example {


	class Lamp : public cg::Entity,
		public cg::IDrawListener,
		public BoxEntity
	{
	private:
		cg::Vector2f _pos;
		float _blocksize;
		

	public:
			Lamp(int x, int y, float blocksize, std::string id, float maxX, float height,float maxZ);
			~Lamp();
			void init();
			void draw(); 

			virtual void getModel() = 0;


	};


}

#endif