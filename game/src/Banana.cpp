#include "Banana.h"

using namespace std;

Banana::Banana(Player* player)
{
	sprite.load("data/img/bomba.png");
	float x = player->sprite.getPosition().x;
	float y = player->sprite.getPosition().y;
	explodeLength = player->getExplodeLength();
	x-= (int)x%32;
	y-= (int)y%32;
	sprite.setPosition(x, y);
	sprite.setScale(0.75, 0.75);
	clock.restart();
}

Banana::~Banana()
{
}
