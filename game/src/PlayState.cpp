#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "InputManager.h"

PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{
	dirX = dirY = 0;
	map = new tmx::MapLoader("data/maps");
	map->Load("map.tmx");

	player = new Player("data/img/p1.png", 40, 40);

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
	delete player;
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
	sf::View view = screen->getView(); // gets the view
	sf::Event event;

	while (screen->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			game->quit();
	}
	int newDir = currentDir;

	if(im->testEvent("left"))
		dirX = -1;

	if(im->testEvent("right"))
		dirX = 1;

	if(im->testEvent("up")) 
		dirY = -1;

	if(im->testEvent("down")) 
		dirY = 1;

	if(im->testEvent("quit") || im->testEvent("rightclick"))
		game->quit();

	if(im->testEvent("stats"))
		game->toggleStats();
}

void PlayState::update(cgf::Game* game)
{
	screen = game->getScreen();
	player->move(dirX, dirY, game);
	dirX = dirY = 0;
}

void PlayState::draw(cgf::Game* game)
{
	screen = game->getScreen();
	map->Draw(*screen);
	screen->draw(player->getSprite());
}
