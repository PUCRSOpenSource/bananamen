#ifndef POWERUP_H_
#define POWERUP_H_

#include "Sprite.h"
#include "Player.h"

class Powerup
{
public:
	Powerup (float x, float y);
	Powerup (void){};

	virtual ~Powerup ();

	void draw();
	cgf::Sprite sprite;
	void upgrade(Player* player);
private:
	int power;
};
#endif 
