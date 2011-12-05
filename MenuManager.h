#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include "cg/cg.h"
#include "MenuTypes.h"
#include "FreeImage.h"
#include "TextureBank.h"

namespace example {

	class MenuManager : public cg::Entity, cg::IDrawListener
	{
	private:
		//TextureBank textureBank;
		MenuTypes actualMenuMode;
		cg::Vector2d _winSize;

	public:

		MenuManager( std::string id, MenuTypes menuType );
		~MenuManager();
		void init();

		// draw listener Methods
		void draw( );

		void setMenu( MenuTypes menuType );
		bool inMenu();
		bool inMenu( MenuTypes menuType );

	};
}

#endif