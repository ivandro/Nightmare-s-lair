#ifndef FLOOR_H
#define FLOOR_H

#include "cg/cg.h"
#include "TextureBank.h"

namespace example {


	class Floor : public cg::Entity,
		public cg::IDrawListener
	{
	private:
		cg::Vector2i _pos;
		float _blocksize;

	public:
			Floor(int x, int y, float blocksize, std::string id);
			~Floor();
			void init();
			void draw(); 

			virtual void getTexture() = 0;


	};


}

#endif