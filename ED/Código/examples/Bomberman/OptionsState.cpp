/*
 * Gabriel Carlos e Vinicius Warlet
 */

#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "OptionsState.h"
#include "PlayState.h"
#include "MenuState.h"

OptionsState OptionsState::m_OptionsState;

using namespace std;

void OptionsState::init()
{
    optionsSprite.load("data/img/prototipocomandos.png");
    optionsSprite.setPosition(50,50);
    cout << "OptionsState Init Successful" << endl;

    cursor.load("data/img/bomba.png");
    cursor.setPosition(190,260);
    cursor.setScale(0.05,0.05);
}

void OptionsState::cleanup()
{
    cout << "OptionsState Cleanup Successful" << endl;
}

void OptionsState::pause()
{
    cout << "OptionsState Paused" << endl;
}

void OptionsState::resume()
{
    cout << "OptionsState Resumed" << endl;
}

void OptionsState::handleEvents(cgf::Game* game)
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
                game->changeState(MenuState::instance());
            if(event.key.code == sf::Keyboard::Escape)
                game->changeState(MenuState::instance());

            break;
        default:
            break;
        }
    }
}

void OptionsState::update(cgf::Game* game)
{
}

void OptionsState::draw(cgf::Game *game)
{
    game->getScreen()->clear(sf::Color(255,255,255));
    game->getScreen()->draw(optionsSprite);
    game->getScreen()->draw(cursor);
}



