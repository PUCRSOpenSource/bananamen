#include <iostream>
#include <vector>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "WinState.h"
#include "InputManager.h"

PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{
	player1 = new Player("data/img/p1.png", 32, 32);
	player2 = new Player("data/img/p2.png", 100, 100);

	map = new Map("map2.tmx", 2);

	im = cgf::InputManager::instance();

	im->addKeyInput("quit", sf::Keyboard::Escape);
	im->addKeyInput("info", sf::Keyboard::R);

	im->addKeyInput("up1",    sf::Keyboard::Up);
	im->addKeyInput("down1",  sf::Keyboard::Down);
	im->addKeyInput("left1",  sf::Keyboard::Left);
	im->addKeyInput("right1", sf::Keyboard::Right);
	im->addKeyInput("bomb1",  sf::Keyboard::RControl);

	im->addKeyInput("up2",    sf::Keyboard::W);
	im->addKeyInput("down2",  sf::Keyboard::S);
	im->addKeyInput("left2",  sf::Keyboard::A);
	im->addKeyInput("right2", sf::Keyboard::D);
	im->addKeyInput("bomb2",  sf::Keyboard::Space);

	im->addKeyInput("quit",   sf::Keyboard::Escape);
	im->addKeyInput("pause",  sf::Keyboard::P);

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
	if(firstTime) {
		setup(game);
		firstTime = false;
	}

	while (screen->pollEvent(event))
		if(event.type == sf::Event::Closed)
			game->quit();

	if(im->testEvent("left1"))
		player1->setDirX(-1);

	if(im->testEvent("right1"))
		player1->setDirX(1);

	if(im->testEvent("up1"))
		player1->setDirY(-1);

	if(im->testEvent("down1"))
		player1->setDirY(1);

	if(im->testEvent("left2"))
		player2->setDirX(-1);

	if(im->testEvent("right2"))
		player2->setDirX(1);

	if(im->testEvent("up2"))
		player2->setDirY(-1);

	if(im->testEvent("down2"))
		player2->setDirY(1);

	if(im->testEvent("quit"))
		game->quit();

	if(im->testEvent("info"))
		game->toggleStats();

	if(im->testEvent("bomb1"))
		map->putBomb(player1);

	if(im->testEvent("bomb2"))
		map->putBomb(player2);
}

void PlayState::update(cgf::Game* game)
{
	screen = game->getScreen();
	player1->update();
	player2->update();
	map->update(game, player1, player2);
	if (player1->dead || player2->dead)
	{
		WinState* state2 = WinState::instance();
		if (player1->dead && player2->dead)
		       state2->setWinner(0);
		else if (player1->dead)
			state2->setWinner(2);
		else	
			state2->setWinner(1);
		game->changeState(state2);
		//if (player1->dead && player2->dead)
	}
}

void PlayState::draw(cgf::Game* game)
{
	map->draw(screen);
	screen = game->getScreen();
	screen->draw(player1->sprite);
	screen->draw(player2->sprite);
}
void PlayState::setup(cgf::Game* game)
{
	screen = game->getScreen();
	screen->setVerticalSyncEnabled(true);

	music.openFromFile("data/audio/map1.ogg");
	music.setVolume(50);
	music.setLoop(true);
	music.play();
}
