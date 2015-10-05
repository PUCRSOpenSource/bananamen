/*
 * Gabriel Carlos e Vinicius Warlet
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "InputManager.h"
#include "PauseState.h"
#include "MenuState.h"


PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{
    map = new tmx::MapLoader("data/maps");
    map->Load("map.tmx");

    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }
    text.setFont(font);
    text.setCharacterSize(50);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(10,150);

    // AUDIO
    /*
    buffer.loadFromFile("data/audio/.wav");
    sound.setBuffer(buffer);
    sound.play();
    */

    player1.load("data/img/p1.png");
    player1.setPosition(35,35);
    player1.setScale(1.5,1.5);

    player2.load("data/img/p2.png");
    player2.setPosition(500,500);
    player2.setScale(1.5,1.5);

    dirx1 = 0;
    diry1 = 0;
    dirx2 = 0;
    diry2 = 0;

    bomb1on = false;
    bomb2on = false;

    explodiu = false;
    colidiu = false;

    vivo1 = true;
    vivo2 = true;

    sumir1 = false;
    sumir2 = false;

    fim = false;

    int k = 0;
    int l = 0;

    expSize1 = 5;
    expSize2 = 5;

    tTij.loadFromFile("data/img/tijolo.png");
    tItem.loadFromFile("data/img/foguinho.png");


    for(int i = 32; i <= 416; i += 64)
    {
        for(int j = 64; j <= 320; j += 64)
        {
                tijolo[k].setTexture(tTij);
                tijolo[k].setPosition(i,j);
                k++;
        }
    }

    for(int i = 32; i <= 416; i += 64)
    {
        for(int j = 64; j <= 320; j += 64)
        {
                item[l].setTexture(tItem);
                item[l].setPosition(i,j);
                l++;
        }
    }

/*
    for(int i = 32; i < 416; i += 32)
    {
        for(int j = 96; j <= 320; j += 64)
        {
                tijolo[k].setTexture(texture);
                tijolo[k].setPosition(i,j);
                k++;
        }
    }
*/

    im = cgf::InputManager::instance();

    im->addKeyInput("left1", sf::Keyboard::Left);
    im->addKeyInput("right1", sf::Keyboard::Right);
    im->addKeyInput("up1", sf::Keyboard::Up);
    im->addKeyInput("down1", sf::Keyboard::Down);
    im->addKeyInput("left2", sf::Keyboard::A);
    im->addKeyInput("right2", sf::Keyboard::D);
    im->addKeyInput("up2", sf::Keyboard::W);
    im->addKeyInput("down2", sf::Keyboard::S);
    im->addKeyInput("bomb1", sf::Keyboard::RControl);
    im->addKeyInput("bomb2", sf::Keyboard::Space);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addKeyInput("pause", sf::Keyboard::P);

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

void PlayState::updateBomb1()
{
    if(clock1.getElapsedTime().asSeconds() >= 3)
    {
        bomb1.setVisible(false);

        tExp.loadFromFile("data/img/explosao.png");

        for(int i = 0; i < expSize1; i++)
        {
            explosao1[i].setTexture(tExp);
            explosao1[i].setScale(0.13,0.13);
        }

        explosao1[0].setPosition(bomb1.getPosition().x,bomb1.getPosition().y);
        explosao1[1].setPosition(bomb1.getPosition().x+26,bomb1.getPosition().y);
        explosao1[2].setPosition(bomb1.getPosition().x-26,bomb1.getPosition().y);
        explosao1[3].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+26);
        explosao1[4].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-26);
        explosao1[5].setPosition(bomb1.getPosition().x+52,bomb1.getPosition().y);
        explosao1[6].setPosition(bomb1.getPosition().x-52,bomb1.getPosition().y);
        explosao1[7].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+52);
        explosao1[8].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-52);
        explosao1[9].setPosition(bomb1.getPosition().x+78,bomb1.getPosition().y);
        explosao1[10].setPosition(bomb1.getPosition().x-78,bomb1.getPosition().y);
        explosao1[11].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+78);
        explosao1[12].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-78);
        explosao1[13].setPosition(bomb1.getPosition().x-104,bomb1.getPosition().y);
        explosao1[14].setPosition(bomb1.getPosition().x+104,bomb1.getPosition().y);
        explosao1[15].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-104);
        explosao1[16].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+104);
        explosao1[17].setPosition(bomb1.getPosition().x-130,bomb1.getPosition().y);
        explosao1[18].setPosition(bomb1.getPosition().x+130,bomb1.getPosition().y);
        explosao1[19].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-130);
        explosao1[20].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+130);
        explosao1[21].setPosition(bomb1.getPosition().x-156,bomb1.getPosition().y);
        explosao1[22].setPosition(bomb1.getPosition().x+156,bomb1.getPosition().y);
        explosao1[23].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-156);
        explosao1[24].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+156);
        explosao1[25].setPosition(bomb1.getPosition().x-182,bomb1.getPosition().y);
        explosao1[26].setPosition(bomb1.getPosition().x+182,bomb1.getPosition().y);
        explosao1[27].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-182);
        explosao1[28].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+182);
        explosao1[29].setPosition(bomb1.getPosition().x-208,bomb1.getPosition().y);
        explosao1[30].setPosition(bomb1.getPosition().x+208,bomb1.getPosition().y);
        explosao1[31].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-208);
        explosao1[32].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+208);
        explosao1[33].setPosition(bomb1.getPosition().x-234,bomb1.getPosition().y);
        explosao1[34].setPosition(bomb1.getPosition().x+234,bomb1.getPosition().y);
        explosao1[35].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-234);
        explosao1[36].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+234);
        explosao1[37].setPosition(bomb1.getPosition().x-260,bomb1.getPosition().y);
        explosao1[38].setPosition(bomb1.getPosition().x+260,bomb1.getPosition().y);
        explosao1[39].setPosition(bomb1.getPosition().x,bomb1.getPosition().y-260);
        explosao1[40].setPosition(bomb1.getPosition().x,bomb1.getPosition().y+260);

        bomb1on = false;

        clock1.restart();

        sumir1 = true;
        clock3.restart();
    }

}

void PlayState::updateBomb2()
{
    if(clock2.getElapsedTime().asSeconds() >= 3)
    {
        bomb2.setVisible(false);

        tExp.loadFromFile("data/img/explosao.png");

        for(int i = 0; i < expSize2; i++)
        {
            explosao2[i].setTexture(tExp);
            explosao2[i].setScale(0.13,0.13);
        }

        explosao2[0].setPosition(bomb2.getPosition().x,bomb2.getPosition().y);
        explosao2[1].setPosition(bomb2.getPosition().x+26,bomb2.getPosition().y);
        explosao2[2].setPosition(bomb2.getPosition().x-26,bomb2.getPosition().y);
        explosao2[3].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+26);
        explosao2[4].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-26);
        explosao2[5].setPosition(bomb2.getPosition().x+52,bomb2.getPosition().y);
        explosao2[6].setPosition(bomb2.getPosition().x-52,bomb2.getPosition().y);
        explosao2[7].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+52);
        explosao2[8].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-52);
        explosao2[9].setPosition(bomb2.getPosition().x+78,bomb2.getPosition().y);
        explosao2[10].setPosition(bomb2.getPosition().x-78,bomb2.getPosition().y);
        explosao2[11].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+78);
        explosao2[12].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-78);
        explosao2[13].setPosition(bomb2.getPosition().x-104,bomb2.getPosition().y);
        explosao2[14].setPosition(bomb2.getPosition().x+104,bomb2.getPosition().y);
        explosao2[15].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-104);
        explosao2[16].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+104);
        explosao2[17].setPosition(bomb2.getPosition().x-130,bomb2.getPosition().y);
        explosao2[18].setPosition(bomb2.getPosition().x+130,bomb2.getPosition().y);
        explosao2[19].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-130);
        explosao2[20].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+130);
        explosao2[21].setPosition(bomb2.getPosition().x-156,bomb2.getPosition().y);
        explosao2[22].setPosition(bomb2.getPosition().x+156,bomb2.getPosition().y);
        explosao2[23].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-156);
        explosao2[24].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+156);
        explosao2[25].setPosition(bomb2.getPosition().x-182,bomb2.getPosition().y);
        explosao2[26].setPosition(bomb2.getPosition().x+182,bomb2.getPosition().y);
        explosao2[27].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-182);
        explosao2[28].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+182);
        explosao2[29].setPosition(bomb2.getPosition().x-208,bomb2.getPosition().y);
        explosao2[30].setPosition(bomb2.getPosition().x+208,bomb2.getPosition().y);
        explosao2[31].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-208);
        explosao2[32].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+208);
        explosao2[33].setPosition(bomb2.getPosition().x-234,bomb2.getPosition().y);
        explosao2[34].setPosition(bomb2.getPosition().x+234,bomb2.getPosition().y);
        explosao2[35].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-234);
        explosao2[36].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+234);
        explosao2[37].setPosition(bomb2.getPosition().x-260,bomb2.getPosition().y);
        explosao2[38].setPosition(bomb2.getPosition().x+260,bomb2.getPosition().y);
        explosao2[39].setPosition(bomb2.getPosition().x,bomb2.getPosition().y-260);
        explosao2[40].setPosition(bomb2.getPosition().x,bomb2.getPosition().y+260);

        bomb2on = false;

        clock2.restart();

        sumir2 = true;
        clock4.restart();
    }
}

void PlayState::explodir()
{
    bboxP1 = player1.getGlobalBounds();
    bboxP2 = player2.getGlobalBounds();

    for(int i = 0; i < 30; i++)
        bboxT[i] = tijolo[i].getGlobalBounds();

    for(int i = 0; i < expSize1; i++)
        bboxE1[i] = explosao1[i].getGlobalBounds();

    for(int i = 0; i < expSize2; i++)
        bboxE2[i] = explosao2[i].getGlobalBounds();

    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < expSize1; j++)
        {
            if(bboxT[i].intersects(bboxE1[j])){
                tijolo[i].setPosition(1000,1000);
            }
        }
    }

    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < expSize2; j++)
        {
            if(bboxT[i].intersects(bboxE2[j])){
                tijolo[i].setPosition(1000,1000);
            }
        }
    }

    for(int i = 0; i < expSize1; i++)
    {
        if(bboxP1.intersects(bboxE1[i]) && bboxP2.intersects(bboxE1[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player1.getPosition());
            morte2.load("data/img/morte.png");
            morte2.setScale(0.05,0.05);
            morte2.setPosition(player2.getPosition());
            text.setPosition(120,150);
            vivo1 = false;
            vivo2 = false;
            if(!vivo1 && !vivo2){
                text.setString(L"EMPATE!");
                fim = true;
                clock.restart();
            }
        }
    }

    for(int i = 0; i < expSize2; i++)
    {
        if(bboxP1.intersects(bboxE2[i]) && bboxP2.intersects(bboxE2[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player1.getPosition());
            morte2.load("data/img/morte.png");
            morte2.setScale(0.05,0.05);
            morte2.setPosition(player2.getPosition());
            text.setPosition(120,150);
            vivo1 = false;
            vivo2 = false;
            if(!vivo1 && !vivo2){
                text.setString(L"EMPATE!");
                fim = true;
                clock.restart();
            }
        }
    }

    for(int i = 0; i < expSize1; i++)
    {
        if(bboxP1.intersects(bboxE1[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player1.getPosition());
            vivo1 = false;
            if(!vivo1 && vivo2){
                text.setString(L"PLAYER 2 VENCEU!");
                fim = true;
                clock.restart();
            }
        }

    }

    for(int i = 0; i < expSize2; i++)
    {
        if(bboxP1.intersects(bboxE2[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player1.getPosition());
            vivo1 = false;
            if(!vivo1 && vivo2){
                text.setString(L"PLAYER 2 VENCEU!");
                fim = true;
                clock.restart();
            }
        }
    }

    for(int i = 0; i < expSize1; i++)
    {
        if(bboxP2.intersects(bboxE1[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player2.getPosition());
            vivo2 = false;
            if(!vivo2 && vivo1){
                text.setString(L"PLAYER 1 VENCEU!");
                fim = true;
                clock.restart();
            }
        }
    }

    for(int i = 0; i < expSize2; i++)
    {
        if(bboxP2.intersects(bboxE2[i])){
            clock3.restart();
            morte.load("data/img/morte.png");
            morte.setScale(0.05,0.05);
            morte.setPosition(player2.getPosition());
            vivo2 = false;
            if(!vivo2 && vivo1){
                text.setString(L"PLAYER 1 VENCEU!");
                fim = true;
                clock.restart();
            }
        }
    }
}

void PlayState::colidir()
{
    bboxP1 = player1.getGlobalBounds();
    bboxP2 = player2.getGlobalBounds();

    for(int i = 0; i < 30; i++)
        bboxT[i] = tijolo[i].getGlobalBounds();

    for(int i = 0; i < 30; i++)
        bboxI[i] = item[i].getGlobalBounds();

    for(int i = 0; i < 30; i++)
    {
        if(bboxP1.intersects(bboxT[i]))
            colidiu = true;
        else colidiu = false;
    }

    for(int i = 0; i < 30; i++)
    {
        if(bboxP1.intersects(bboxI[i]))
        {
            item[i].setPosition(1000,1000);
            expSize1 += 4;
        }

        if(bboxP2.intersects(bboxI[i]))
        {
            item[i].setPosition(1000,1000);
            expSize2 += 4;
        }
    }
}

void PlayState::expFim1()
{
    if(clock3.getElapsedTime().asSeconds() > 0.3)
    {
        for(int i = 0; i < expSize1; i++)
            explosao1[i].setPosition(1000,1000);

        sumir1 = false;
        clock3.restart();
    }
}

void PlayState::expFim2()
{
    if(clock4.getElapsedTime().asSeconds() > 0.3)
    {
        for(int i = 0; i < expSize2; i++)
            explosao2[i].setPosition(1000,1000);

        sumir2 = false;
        clock4.restart();
    }
}

void PlayState::morrer(cgf::Game* game)
{/*
    if(clock.getElapsedTime().asSeconds() > 1)
    {
        game->changeState(MenuState::instance());

        fim = false;

        clock.restart();
    }
*/
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

    dirx1 = diry1 = dirx2 = diry2 = 0;

    if(im->testEvent("left1")) {
        if(!colidiu && vivo1 && vivo2)
            dirx1 = -1;
    }

    if(im->testEvent("right1")) {
        if(!colidiu && vivo1 && vivo2)
            dirx1 = 1;
    }

    if(im->testEvent("up1")) {
        if(!colidiu && vivo1 && vivo2)
            diry1 = -1;
    }

    if(im->testEvent("down1")) {
        if(!colidiu && vivo1 && vivo2)
            diry1 = 1;
    }

     if(im->testEvent("left2")) {
        if(!colidiu && vivo2 && vivo1)
            dirx2 = -1;
    }

    if(im->testEvent("right2")) {
        if(!colidiu && vivo2 && vivo1)
            dirx2 = 1;
    }

    if(im->testEvent("up2")) {
        if(!colidiu && vivo2 && vivo1)
            diry2 = -1;
    }

    if(im->testEvent("down2")) {
        if(!colidiu && vivo2 && vivo1)
            diry2 = 1;
    }

    if(im->testEvent("bomb1") && bomb1on == false && vivo1 && vivo2){
        float bpx = player1.getPosition().x;
        float bpy = player1.getPosition().y;
        if(!bomb1on){
            bomb1.load("data/img/bomba.png");
            bomb1.setVisible(true);
            bomb1.setPosition(bpx,bpy);
            bomb1.setScale(0.09,0.09);
        }
        bomb1on = true;
        clock1.restart();
    }

    if(im->testEvent("bomb2") && bomb2on == false && vivo2 && vivo1){
        float bpx = player2.getPosition().x;
        float bpy = player2.getPosition().y;
        if(!bomb2on){
            bomb2.load("data/img/bomba.png");
            bomb2.setVisible(true);
            bomb2.setPosition(bpx,bpy);
            bomb2.setScale(0.09,0.09);
        }
        bomb2on = true;
        clock2.restart();
    }

    if(im->testEvent("pause")){
        bomb1.setPosition(1000,1000);
        bomb2.setPosition(1000,1000);
        game->pushState(PauseState::instance());
    }

    player1.setXspeed(100*dirx1);
    player1.setYspeed(100*diry1);

    player2.setXspeed(100*dirx2);
    player2.setYspeed(100*diry2);
}

void PlayState::update(cgf::Game* game)
{
    screen = game->getScreen();
    checkCollision(2, game, &player1);
    checkCollision(2, game, &player2);
    //checkCollision(2, game, &explosao[0]);

    explodir();
    colidir();

    if(sumir1)
        expFim1();

    if(sumir2)
        expFim2();

    if(fim)
        morrer(game);

    if(bomb1on)
        updateBomb1();
    if(bomb2on)
        updateBomb2();
}

void PlayState::draw(cgf::Game* game)
{
    screen = game->getScreen();
    map->Draw(*screen);
    screen->draw(player1);
    screen->draw(player2);
    screen->draw(bomb1);
    screen->draw(bomb2);

    for(int i = 0; i < expSize1; i++)
        screen->draw(explosao1[i]);
    for(int i = 0; i < expSize2; i++)
        screen->draw(explosao2[i]);
    for(int i = 0; i < 100; i++)
        screen->draw(item[i]);
    for(int i = 0; i < 100; i++)
        screen->draw(tijolo[i]);


    screen->draw(morte);

    screen->draw(text);
}

bool PlayState::checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj)
{
    int i, x1, x2, y1, y2;
    bool bump = false;

    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2u tilesize = map->GetMapTileSize();

    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    mapsize.x--;
    mapsize.y--;

    sf::Vector2u objsize = obj->getSize();
    objsize.x *= obj->getScale().x;
    objsize.y *= obj->getScale().y;

    float px = obj->getPosition().x;
    float py = obj->getPosition().y;

    double deltaTime = game->getUpdateInterval();

    sf::Vector2f offset(obj->getXspeed()/1000 * deltaTime, obj->getYspeed()/1000 * deltaTime);

    float vx = offset.x;
    float vy = offset.y;

    i = objsize.y > tilesize.y ? tilesize.y : objsize.y;

    for (;;)
    {
        x1 = (px + vx) / tilesize.x;
        x2 = (px + vx + objsize.x - 1) / tilesize.x;

        y1 = (py) / tilesize.y;
        y2 = (py + i - 1) / tilesize.y;

        if (x1 >= 0 && x2 < mapsize.x && y1 >= 0 && y2 < mapsize.y)
        {
            if (vx > 0)
            {
                int upRight   = getCellFromMap(layer, x2*tilesize.x, y1*tilesize.y);
                int downRight = getCellFromMap(layer, x2*tilesize.x, y2*tilesize.y);
                if (upRight || downRight)
                {
                    px = x2 * tilesize.x;
                    px -= objsize.x;// + 1;
                    vx = 0;
                    bump = true;
                }
            }

            else if (vx < 0)
            {
                int upLeft   = getCellFromMap(layer, x1*tilesize.x, y1*tilesize.y);
                int downLeft = getCellFromMap(layer, x1*tilesize.x, y2*tilesize.y);
                if (upLeft || downLeft)
                {
                    px = (x1+1) * tilesize.x;
                    vx = 0;
                    bump = true;
                }
            }
        }

        if (i == objsize.y)
        {
            break;
        }

        i += tilesize.y;

        if (i > objsize.y)
        {
            i = objsize.y;
        }
    }

    i = objsize.x > tilesize.x ? tilesize.x : objsize.x;

    for (;;)
    {
        x1 = (px / tilesize.x);
        x2 = ((px + i-1) / tilesize.x);

        y1 = ((py + vy) / tilesize.y);
        y2 = ((py + vy + objsize.y-1) / tilesize.y);

        if (x1 >= 0 && x2 < mapsize.x && y1 >= 0 && y2 < mapsize.y)
        {
            if (vy > 0)
            {
                int downLeft  = getCellFromMap(layer, x1*tilesize.x, y2*tilesize.y);
                int downRight = getCellFromMap(layer, x2*tilesize.x, y2*tilesize.y);
                if (downLeft || downRight)
                {
                    py = y2 * tilesize.y;
                    py -= objsize.y;
                    vy = 0;
                    bump = true;
                }
            }

            else if (vy < 0)
            {
                int upLeft  = getCellFromMap(layer, x1*tilesize.x, y1*tilesize.y);
                int upRight = getCellFromMap(layer, x2*tilesize.x, y1*tilesize.y);
                if (upLeft || upRight)
                {
                    py = (y1 + 1) * tilesize.y;
                    vy = 0;
                    bump = true;
                }
            }
        }
        if (i == objsize.x)
        {
            break;
        }

        i += tilesize.x;

        if (i > objsize.x)
        {
            i = objsize.x;
        }
    }
    obj->setPosition(px+vx,py+vy);
    px = obj->getPosition().x;
    py = obj->getPosition().y;

    obj->update(deltaTime, false);

    if (px < 0)
        obj->setPosition(px,py);
    else if (px + objsize.x >= mapsize.x * tilesize.x)
        obj->setPosition(mapsize.x*tilesize.x - objsize.x - 1,py);

    if(py < 0)
        obj->setPosition(px,0);
    else if(py + objsize.y >= mapsize.y * tilesize.y)
        obj->setPosition(px, mapsize.y*tilesize.y - objsize.y - 1);

    return bump;
}

sf::Uint16 PlayState::getCellFromMap(uint8_t layernum, float x, float y)
{
    auto layers = map->GetLayers();
    tmx::MapLayer& layer = layers[layernum];
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2u tilesize = map->GetMapTileSize();
    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    int col = floor(x / tilesize.x);
    int row = floor(y / tilesize.y);
    return layer.tiles[row*mapsize.x + col].gid;
}
