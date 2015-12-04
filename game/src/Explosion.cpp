#include "Explosion.h"
using namespace std;

Explosion::Explosion()
{
	clock.restart();
	sprite.setScale(0.75, 0.75);
}

Explosion::~Explosion()
{
}

void Explosion::update(Player* p1, Player* p2)
{

}

bool Explosion::finished()
{
	return clock.getElapsedTime().asSeconds() > 0.5f;
}
