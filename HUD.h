#ifndef HUD_H
#define HUD_H

#include "cg/cg.h"
#include <windows.h>
#include "MainCharacter.h"

namespace example {

	class HUD : public cg::Entity,
		public cg::IUpdateListener,
		public cg::IDrawListener
		//public cg::IDrawOverlayListener
	{

	private: 
		cg::Vector2d _position;
		int _modelHeartIcon, _modelMunitionIcon;
		int width;
		int height;
		int _LifeCount, _MunitionCount, _KeyCount;
		int deltaPixel;
		//std::map<int, int> mapcoordinates;
		int mapcoordinates[25][25];
		cg::Vector2d _characterPosition;

	public:
		HUD(std::string id);
		~HUD();
		void init();

		void update(unsigned long elapsed_millis);
		void drawOverlay();
		void draw();
		void drawInformation();
		void drawHeartIcon();	
		void drawMunitionIcon();
		void drawKeyIcon();
		void drawMiniMap();
		void drawCrosshair();
		void drawCharacterPosition();
		void addMapCoordinates(int x, int y);
		void setCharacterPosition(int charPosX, int charPosY);
	};
}

#endif