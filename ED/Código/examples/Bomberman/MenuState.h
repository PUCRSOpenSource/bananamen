#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <iostream>

#include "Game.h"
#include "GameState.h"
#include "InputManager.h"
#include "OptionsState.h"
#include "PlayState.h"
#include "Sprite.h"

class MenuState : public cgf::GameState
{
	public:

		void init();
		void cleanup();

		void pause();
		void resume();

		void handleEvents(cgf::Game* game);
		void update(cgf::Game* game);
		void draw(cgf::Game* game);

		static MenuState* instance()
		{
			return &m_MenuState;
		}

	protected:

		MenuState() {}

	private:

		static MenuState m_MenuState;

		cgf::Sprite menuSprite;
		cgf::Sprite cursor;

};

#endif


