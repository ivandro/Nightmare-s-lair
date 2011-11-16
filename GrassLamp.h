#ifndef GRASS_LAMP_H
#define GRASS_LAMP_H

#include "Lamp.h"

namespace example {

	class GrassLamp : public Lamp,
		public cg::IUpdateListener {
	private:
		float _inc;
		int _mod;
		void makeBulb();
		void makeHead();
		void makePole();

	public:

		GrassLamp(int x, int y, float blocksize, std::string id);
		~GrassLamp();

		void getModel();
		void  update(unsigned long elapsed_millis);
	};
}

#endif