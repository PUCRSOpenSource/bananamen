#include "Powerup.h"
#include <iostream>

using namespace std;

Powerup::Powerup (float x, float y)
{
	sprite.load("data/img/powerup.png");
	sprite.setPosition(x, y);
	sprite.setScale(1.5, 1.5);
	power = rand() % 2;
}

Powerup::~Powerup()
{
}

void Powerup::draw()
{

}

void Powerup::upgrade(Player* player)
{
	player->upgrade(power);
}
