#include "Player.h"

using namespace std;

Player::Player (char* spritePath, float x, float y)
{
	sprite.load(spritePath);
	sprite.setPosition(x, y);
	sprite.setScale(1.5, 1.5);
	sprite.play();
	dirX = dirY = 0;
}
Player::~Player()
{
}
cgf::Sprite Player::getSprite()
{
	return sprite;
}
void Player::move(int dirX, int dirY, cgf::Game* game)
{
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;
	x += dirX*5;
	y += dirY*5;
	sprite.setPosition(x,y);
	sprite.update(game->getUpdateInterval());
}
void plantBanana()
{
	
}
