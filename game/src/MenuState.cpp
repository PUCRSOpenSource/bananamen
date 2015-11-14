#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "MenuState.h"
#include "PlayState.h"


MenuState MenuState::m_MenuState;

using namespace std;

void MenuState::init()
{
	menuSprite.load("data/img/menu.png"); // load menu state bitmap
	cout << "MenuState Init Successful" << endl;
}

void MenuState::cleanup()
{
	cout << "MenuState Cleanup Successful" << endl;
}

void MenuState::pause()
{
	cout << "MenuState Paused" << endl;
}

void MenuState::resume()
{
	cout << "MenuState Resumed" << endl;
}

void MenuState::handleEvents(cgf::Game* game)
{
	sf::Event event;
	sf::RenderWindow* screen = game->getScreen();

	while (screen->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				game->quit();
				break;

				// key pressed
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Space)
					game->changeState(PlayState::instance());
				if(event.key.code == sf::Keyboard::Escape)
					game->quit();
				break;

			default:
				break;
		}
	}
}

void MenuState::update(cgf::Game* game)
{
}

void MenuState::draw(cgf::Game *game)
{
	menuSprite.setPosition(50,50);
	game->getScreen()->draw(menuSprite);
}

