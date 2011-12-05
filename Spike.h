#ifndef SPIKE_H
#define SPIKE_H

#include "cg/cg.h"
#include <string>
#include "Obstacle.h"
#include "MaterialBank.h"

namespace example {

	class Spike : public Obstacle
	{
	private:
		GLUquadricObj *_SpikeObj;	

		int _modelSpike;
		int _materialDL;
		GLUquadricObj * _spikeQuadric;

		void makeSpike();
		void makeMaterial();
	public:
		Spike(int x, int y, float blocksize, std::string id);
		~Spike();
		void makeModel();
	};

}

#endif