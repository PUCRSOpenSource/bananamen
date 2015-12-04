#ifndef _BANANA_H_
#define _BANANA_H_

#include "Sprite.h"
#include "Player.h"
#include "Explosion.h"

class Banana
{
public:
	Banana (Player* player);
//	Banana (){};

	virtual ~Banana ();

	cgf::Sprite sprite;
	bool wantsToExplode();
	int explodeLength;
private:
	int explodeTime;
	Player* player;
	sf::Clock clock;
};
#endif
