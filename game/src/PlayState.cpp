#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "InputManager.h"

PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{
	map = new tmx::MapLoader("data/maps");
	map->Load("map.tmx");

	//walkStates[0] = "walk-right";
	//walkStates[1] = "walk-left";
	//walkStates[2] = "walk-up";
	//walkStates[3] = "walk-down";
	//currentDir = RIGHT;
	//player.load("data/img/warrior.png",64,64,0,0,0,0,13,21,273);
	player = new Player("data/img/p1.png", 40, 40);
	//player.setPosition(40,100);
	//player.loadAnimation("data/img/warrioranim.xml");
	//player.setAnimation(walkStates[currentDir]);
	//player.setAnimRate(15);
	//player.setScale(0.5,0.5);
	//player.play();

	//ghost.load("data/img/Char14.png");
	//ghost.setPosition(100,300);
	//ghost.setScale(sf::Vector2f(2,2));
	//ghost.setXspeed(100);
	//ghostDirx = 1;

	dirx = 0; // sprite dir: right (1), left (-1)
	diry = 0; // down (1), up (-1)

	im = cgf::InputManager::instance();

	im->addKeyInput("left", sf::Keyboard::Left);
	im->addKeyInput("right", sf::Keyboard::Right);
	im->addKeyInput("up", sf::Keyboard::Up);
	im->addKeyInput("down", sf::Keyboard::Down);
	im->addKeyInput("quit", sf::Keyboard::Escape);
	im->addKeyInput("stats", sf::Keyboard::S);
	//im->addMouseInput("rightclick", sf::Mouse::Right);


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
	sf::View view = screen->getView(); // gets the view
	sf::Event event;

	while (screen->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			game->quit();
	}

	dirx = diry = 0;
	int newDir = currentDir;

	if(im->testEvent("left")) {
		dirx = -1;
		newDir = LEFT;
	}

	if(im->testEvent("right")) {
		dirx = 1;
		newDir = RIGHT;
	}

	if(im->testEvent("up")) {
		diry = -1;
		newDir = UP;
	}

	if(im->testEvent("down")) {
		diry = 1;
		newDir = DOWN;
	}

	if(im->testEvent("quit") || im->testEvent("rightclick"))
		game->quit();

	if(im->testEvent("stats"))
		game->toggleStats();

	if(im->testEvent("zoomin")) {
		view.zoom(1.01);
		screen->setView(view);
	}
	else if(im->testEvent("zoomout")) {
		view.zoom(0.99);
		screen->setView(view);
	}
}

void PlayState::update(cgf::Game* game)
{
	screen = game->getScreen();
	player->move(dirx, diry, game);
	centerMapOnPlayer();
}

void PlayState::draw(cgf::Game* game)
{
	screen = game->getScreen();
	map->Draw(*screen);          // draw all layers
	//    map->Draw(*screen, 1);     // draw only the second layer
	screen->draw(player->getSprite());
}

void PlayState::centerMapOnPlayer()
{
}

bool PlayState::checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj)
{
}

// Get a cell GID from the map (x and y in global coords)
sf::Uint16 PlayState::getCellFromMap(uint8_t layernum, float x, float y)
{
}
