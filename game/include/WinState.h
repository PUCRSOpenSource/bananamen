#ifndef WIN_STATE_H_
#define WIN_STATE_H_

#include <string>

#include <tmx/MapLoader.h>

#include "GameState.h"
#include "InputManager.h"
#include "Sprite.h"
#include "Map.h"

class WinState : public cgf::GameState
{
	public:

		void init();
		void cleanup();

		void pause();
		void resume();

		void handleEvents(cgf::Game* game);
		void update(cgf::Game* game);
		void draw(cgf::Game* game);
		void setWinner(int player);

		// Implement Singleton Pattern
		static WinState* instance()
		{
			return &m_WinState;
		}

	protected:
		WinState() {}

	private:

		static WinState m_WinState;

		sf::RenderWindow* screen;
		cgf::InputManager* im;

		sf::Font font;
		sf::Text text;
		int winner;
		cgf::Sprite sprite;
		// Checks collision between a sprite and a map layer
		//bool checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj);

		// get a cell GID from the map (x and y in world coords)
};

#endif
