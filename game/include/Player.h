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

	void draw();
	void setDirX(int x);
	void setDirY(int y);
	int getDirX();
	int getDirY();
	int getExplodeLength();
	void plantBanana();
	cgf::Sprite sprite;
	float moveSpeed;
	void update();
	bool dead;
	void upgrade(int power);
private:
	int explodeLength;
	int dirX;
	int dirY;
	int animationTimer;
	int getAnimationSpeed();
	int direction;
};
#endif /* ifndef _PLAYER_H */
