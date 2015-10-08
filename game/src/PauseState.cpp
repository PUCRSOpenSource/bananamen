#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "PauseState.h"
#include "PlayState.h"

PauseState PauseState::m_PauseState;

using namespace std;

void PauseState::init()
{
    pauseSprite.load("data/img/prototipopausa.png");
    pauseSprite.setPosition(90,90);

    map = new tmx::MapLoader("data/maps");
    map->Load("map.tmx");

    cout << "PauseState Init Successful" << endl;
}

void PauseState::cleanup()
{
    cout << "PauseState Cleanup Successful" << endl;
}

void PauseState::pause()
{
    cout << "PauseState Paused" << endl;
}

void PauseState::resume()
{
    cout << "PauseState Resumed" << endl;
}

void PauseState::handleEvents(cgf::Game* game)
{
    sf::Event event;
    screen = game->getScreen();

    while (screen->pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
        case sf::Event::Closed:
            game->quit();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Q)
                game->popState();

            break;
        default:
            break;
        }
    }
}

void PauseState::update(cgf::Game* game)
{
}

void PauseState::draw(cgf::Game *game)
{
    game->getScreen()->clear(sf::Color(255,255,255));
    game->getScreen()->draw(pauseSprite);
}



