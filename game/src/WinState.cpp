#include <iostream>
#include <vector>
#include <cmath>
#include "Game.h"
#include "WinState.h"
#include "InputManager.h"

WinState WinState::m_WinState;

using namespace std;

void WinState::init()
{
	im = cgf::InputManager::instance();
	im->addKeyInput("quit", sf::Keyboard::Escape);
	cout << "WinState: Init" << endl;
	if(winner == 0)
		sprite.load("data/img/empate.png");
	else if(winner == 1)
		sprite.load("data/img/p1_wins.png");
	else
		sprite.load("data/img/p2_wins.png");
}

void WinState::cleanup()
{
	cout << "WinState: Clean" << endl;
}

void WinState::pause()
{
	cout << "WinState: Paused" << endl;
}

void WinState::resume()
{
	cout << "WinState: Resumed" << endl;
}

void WinState::handleEvents(cgf::Game* game)
{
	screen = game->getScreen();
	sf::View view = screen->getView();
	sf::Event event;
	while (screen->pollEvent(event))
		if(event.type == sf::Event::Closed)
			game->quit();
	if(im->testEvent("quit"))
		game->quit();
	                                    
}

void WinState::update(cgf::Game* game)
{
}

void WinState::draw(cgf::Game* game)
{
	game->getScreen()->draw(sprite); 
}

void WinState::setWinner(int player)
{
	winner = player;
}
