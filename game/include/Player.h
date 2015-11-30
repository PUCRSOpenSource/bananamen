#ifndef PLAYER_H_
#define PLAYER_H_

#include "Sprite.h"
#include "Game.h"

class Player
{
public:
	Player (char* spritePath, float x, float y);
	Player (void){};

	virtual ~Player ();

	void die();
	void draw();
	void setDirX(int x);
	void setDirY(int y);
	int getDirX();
	int getDirY();
	int getExplodeLength();
	int getMaxBananas();
	void plantBanana();
	cgf::Sprite sprite;
	float moveSpeed;
	void update();
private:
	int delay;
	int explodeLength;
	int maxBananas;
	int dirX;
	int dirY;
	int animationTimer;
	int getAnimationSpeed();
	void setAnimation();
	int direction;
};
#endif /* ifndef _PLAYER_H */
