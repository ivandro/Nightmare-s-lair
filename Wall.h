#ifndef WALL_H
#define WALL_H

#include "cg/cg.h"
#include "FreeImage.h"
#include "TextureBank.h"

namespace example{

	class Wall: public cg::Entity,
			public cg::IDrawListener
	{

	private:
			cg::Vector2i _pos;
			float _blocksize;
			GLuint wallTexture;
			TextureBank *textureBank;
		
	public:
		Wall(int x, int y, float blocksize, std::string id);
		~Wall(void);

		void init();
		void draw();
		virtual void getTexture() = 0;
	private:
		void texture();
};

}
#endif