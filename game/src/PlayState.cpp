#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "InputManager.h"

PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{
	player1 = new Player("data/img/p1.png", 32, 32);
	player2 = new Player("data/img/p2.png", 80, 80);

	map = new Map("map.tmx", 2);
	//map->Load("map.tmx");

	im = cgf::InputManager::instance();

	im->addKeyInput("left", sf::Keyboard::Left);
	im->addKeyInput("right", sf::Keyboard::Right);
	im->addKeyInput("up", sf::Keyboard::Up);
	im->addKeyInput("down", sf::Keyboard::Down);

	im->addKeyInput("quit", sf::Keyboard::Escape);
	im->addKeyInput("stats", sf::Keyboard::S);

	cout << "PlayState: Init" << endl;
}

void PlayState::cleanup()
{
	delete map;
	cout << "PlayState: Clean" << endl;
}

void PlayState::pause()
{
	cout << "PlayState: Paused" << endl;
}

void PlayState::resume()
{
	cout << "PlayState: Resumed" << endl;
}

void PlayState::handleEvents(cgf::Game* game)
{
	screen = game->getScreen();
	sf::View view = screen->getView();
	sf::Event event;

	while (screen->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			game->quit();
	}
	int newDir = currentDir;

	if(im->testEvent("left"))
		player1->setDirX(-1);

	if(im->testEvent("right"))
		player1->setDirX(1);

	if(im->testEvent("up"))
		player1->setDirY(-1);

	if(im->testEvent("down"))
		player1->setDirY(1);

	if(im->testEvent("quit") || im->testEvent("rightclick"))
		game->quit();

	if(im->testEvent("stats"))
		game->toggleStats();
}

void PlayState::update(cgf::Game* game)
{
	screen = game->getScreen();
	player1->move(game);
	map->update(game, player1, player2);
}

void PlayState::draw(cgf::Game* game)
{
	screen = game->getScreen();
	map->draw(screen);
	screen->draw(player1->sprite);
	screen->draw(player2->sprite);
}
