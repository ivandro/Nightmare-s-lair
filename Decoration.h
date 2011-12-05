#ifndef DECORATION_H
#define DECORATION_H

#include "cg/cg.h"
#include "BoxEntity.h"
#include "Box.h"

namespace example {


	class Decoration : public cg::Entity,
		public cg::IDrawListener,
		public BoxEntity
	{
	private:

		cg::Vector2f _pos;
		float _blocksize;


	public:
			Decoration(int x, int y, float blocksize, std::string id,float _maxX,float height, float _maxZ);
			~Decoration();
			void init();
			void draw(); 

			virtual void getModel() = 0;

	};
}

#endif