#include "Explosion.h"
using namespace std;

Explosion::Explosion(cgf::Sprite* bananaSprite, int explodeLength)
{
	sprite.load("data/img/explosao.png");
	sprite.setPosition(bananaSprite->getPosition());
	length = explodeLength;
}

void Explosion::update(Player* p1, Player* p2)
{

}
