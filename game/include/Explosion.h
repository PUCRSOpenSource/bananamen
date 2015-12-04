#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "Sprite.h"
#include "Banana.h"
#include "Player.h"

class Explosion
{
public:
	Explosion (cgf::Sprite* bananaSprite, int explodeLength);
//	Explosion () {};

	virtual ~Explosion (){};

	cgf::Sprite sprite;
//	bool finished();
	void update(Player* p1, Player* p2);

private:
//	int explosionTime();
	int length;
};
#endif
