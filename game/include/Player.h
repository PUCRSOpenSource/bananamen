#ifndef PLAYER_H_
#define PLAYER_H_

#include "Sprite.h"
#include "Game.h"
#include "Direction.hpp"

class Player
{
public:
	Player (char* spritePath, float x, float y);
	Player (void){};

	virtual ~Player ();

	void die();
	void draw();
	void move(int dirX, int dirY, cgf::Game* game);
	void plantBanana();
	cgf::Sprite getSprite();
private:
	cgf::Sprite sprite;
	float moveSpeed;
	int delay;
	int explodeLentgh;
	int dirX;
	int dirY;
};
#endif /* ifndef _PLAYER_H */
