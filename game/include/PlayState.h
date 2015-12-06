#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include <string>

#include <tmx/MapLoader.h>

#include "GameState.h"
#include "InputManager.h"
#include "Sprite.h"
#include "Map.h"

class PlayState : public cgf::GameState
{
	public:

		void init();
		void cleanup();

		void pause();
		void resume();

		void handleEvents(cgf::Game* game);
		void update(cgf::Game* game);
		void draw(cgf::Game* game);
		void setup(cgf::Game* game);
		void setMap(char map);
		static PlayState* instance()
		{
			return &m_PlayState;
		}

	protected:

		PlayState() {}

	private:

		static PlayState m_PlayState;

		bool firstTime = true;

		std::string walkStates[4];

		sf::Music music;
		sf::RenderWindow* screen;

		cgf::InputManager* im;

		Map* map;
		Player* player1;
		Player* player2;
		char mapToLoad;
};

#endif
