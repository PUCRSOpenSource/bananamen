#ifndef _BANANA_H_
#define _BANANA_H_

#include "Sprite.h"

class Banana
{
public:
	Banana (float x, float y, int explodeLength);
	Banana (){};

	virtual ~Banana ();

	void explode();
	cgf::Sprite sprite;
private:
	int explodeLength;
	int explodeTime;
	sf::Clock clock;
};
#endif
