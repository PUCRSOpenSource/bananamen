#ifndef _PAUSE_STATE_H_
#define _PAUSE_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>

class PauseState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    static PauseState* instance()
    {
        return &m_PauseState;
    }

    protected:

    PauseState() {}

    private:

    static PauseState m_PauseState;

    cgf::Sprite pauseSprite;

    cgf::Sprite player1;
    cgf::Sprite player2;
    cgf::Sprite bomb1;
    cgf::Sprite bomb2;

    sf::RenderWindow* screen;
    tmx::MapLoader* map;
};
#endif

