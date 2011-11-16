#ifndef GRASS_DECORATION_H
#define GRASS_DECORATION_H

#include "Decoration.h"

namespace example {

	class GrassDecoration : public Decoration
	{
		private:

			void makePot();
			void makeTree();

		public:

			GrassDecoration(int x, int y, float blocksize, std::string id);
			~GrassDecoration();

			void getModel();
	};
}

#endif