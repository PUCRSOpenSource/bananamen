#include "Explosion.h"

Explosion::Explosion(Sprite* bananaSprite, int explodeLength)
{
	sprite->load("data/img/explosao.png");
	sprite->setPosition(position);
	length = explodeLength;
	
}

Explosion::update(Player* p1, Player* p2)
{

}
