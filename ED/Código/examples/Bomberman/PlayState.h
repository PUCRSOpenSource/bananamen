/*
 * Gabriel Carlos e Vinicius Warlet
 */


#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>

class PlayState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:

    PlayState() {}

    private:

    static PlayState m_PlayState;

    enum { RIGHT=0, LEFT, UP, DOWN };
    std::string walkStates1[4];
    std::string walkStates2[4];
    int currentDir1;
    int currentDir2;

    int x, y;
    int dirx1, diry1;
    int dirx2, diry2;

    int expSize1;
    int expSize2;

    bool bomb1on;
    bool bomb2on;

    bool explodiu;
    bool colidiu;

    bool vivo1;
    bool vivo2;

    bool fim;

    bool sumir1;
    bool sumir2;

    cgf::Sprite player1;
    cgf::Sprite player2;
    cgf::Sprite bomb1;
    cgf::Sprite bomb2;
    cgf::Sprite morte;
    cgf::Sprite morte2;

    sf::Texture tTij;
    sf::Texture tItem;
    sf::Texture tExp;
    sf::Sprite tijolo[100];
    sf::Sprite explosao1[100];
    sf::Sprite explosao2[100];
    sf::FloatRect bboxP1;
    sf::FloatRect bboxP2;
    sf::FloatRect bboxT[100];
    sf::FloatRect bboxE1[100];
    sf::FloatRect bboxE2[100];
    sf::Sprite item[100];
    sf::FloatRect bboxI[100];

    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::RenderWindow* screen;
    cgf::InputManager* im;

    tmx::MapLoader* map;

    sf::Font font;
    sf::Text text;

    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;

    void updateBomb1();
    void updateBomb2();

    void explodir();
    void colidir();
    void expFim1();
    void expFim2();
    void morrer(cgf::Game* game);

    // Centers the camera on the player position
    void centerMapOnPlayer();

    // Checks collision between a sprite and a map layer
    bool checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj);

    // get a cell GID from the map (x and y in world coords)
    sf::Uint16 getCellFromMap(uint8_t layernum, float x, float y);
};

#endif
