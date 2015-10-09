#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "OptionsState.h"

MenuState MenuState::m_MenuState;

using namespace std;

void MenuState::init()
{
	menuSprite.load("data/img/prototipomenu.png");
	menuSprite.setPosition(50,50);
	cout << "MenuState Init Successful" << endl;
	cursor.load("data/img/bomba.png");
	cursor.setPosition(217,122);
	cursor.setScale(0.05,0.05);
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

			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Return)
				{
					if(cursor.getPosition().y == 122)
						game->changeState(PlayState::instance());
					else game->changeState(OptionsState::instance());
				}
				if(event.key.code == sf::Keyboard::Escape)
					game->quit();
				if(event.key.code == sf::Keyboard::Down)
					cursor.setPosition(217,157);
				if(event.key.code == sf::Keyboard::Up)
					cursor.setPosition(217,122);
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
	game->getScreen()->clear(sf::Color(255,255,255));
	game->getScreen()->draw(menuSprite);
	game->getScreen()->draw(cursor);
}
