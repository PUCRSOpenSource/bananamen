#include "Player.h"

using namespace std;

Player::Player (char* spritePath, float x, float y)
{
	sprite.load(spritePath);
	sprite.setPosition(x, y);
	sprite.setScale(1.5, 1.5);
	sprite.play();
	dirX = dirY = 0;
	moveSpeed = 5;
}
Player::~Player()
{
}

void Player::move(cgf::Game* game)
{
	//float x = sprite.getPosition().x + dirX*5;
	//float y = sprite.getPosition().y + dirY*5;
	//sprite.setPosition(x,y);
	//sprite.setXspeed(1);//dirX * 100);
	//sprite.setYspeed(1);//dirY * 100);
	//sprite.update(game->getUpdateInterval());
	//dirX = dirY = 0;
}
void Player::plantBanana()
{
	
}
void Player::setDirX(int x)
{
	dirX = x;
}
void Player::setDirY(int y)
{
	dirY = y;
}
int Player::getDirX()
{
	return dirX;
}
int Player::getDirY()
{
	return dirY;
}
int Player::getExplodeLength()
{
	return explodeLength;
}
