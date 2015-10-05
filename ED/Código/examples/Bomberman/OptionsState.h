/*
 * Gabriel Carlos e Vinicius Warlet
 */

#ifndef _OPTIONS_STATE_H_
#define _OPTIONS_STATE_H_

#include "GameState.h"
#include "Sprite.h"

class OptionsState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    static OptionsState* instance()
    {
        return &m_OptionsState;
    }

    protected:

    OptionsState() {}

    private:

    static OptionsState m_OptionsState;

    cgf::Sprite optionsSprite;
    cgf::Sprite cursor;

};

#endif



