#include "Banana.h"

using namespace std;

Banana::Banana(float x, float y, int explodeLength)
{
	sprite.load("data/img/bomba.png");
	x-= (int)x%32;
	y-= (int)y%32;
	sprite.setPosition(x, y);
	sprite.setScale(0.10, 0.10);
}

Banana::~Banana()
{
}
