#ifndef _BANANA_H_
#define _BANANA_H_

#include "Sprite.h"
#include "Player.h"

class Banana
{
public:
	Banana (Player* player);
	Banana (){};

	virtual ~Banana ();

	void explode();
	cgf::Sprite sprite;
private:
	int explodeLength;
	int explodeTime;
	Player* player;
	sf::Clock clock;
};
#endif
