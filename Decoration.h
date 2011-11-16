#ifndef DECORATION_H
#define DECORATION_H

#include "cg/cg.h"

namespace example {


	class Decoration : public cg::Entity,
		public cg::IDrawListener
	{
	private:

		cg::Vector2f _pos;
		float _blocksize;

	public:
			Decoration(int x, int y, float blocksize, std::string id);
			~Decoration();
			void init();
			void draw(); 

			virtual void getModel() = 0;


	};
}

#endif