#include "Player.h"
#include <iostream>

using namespace std;

Player::Player (char* spritePath, float x, float y)
{
	sprite.load(spritePath,16,16,0,0,0,0,8,1,8);
	sprite.setPosition(x, y);
	sprite.setScale(1.5, 1.5);
//	sprite.play();
	dirX = dirY = 0;
	moveSpeed = 3;
	animationTimer = 0;
//	sprite.setFrameRange(0,0);
//	sprite.setAnimRate(4);
	direction = 0;
}
Player::~Player()
{
}

void Player::setAnimation()
{
	if (dirX == 0 && dirY == 1)
	{
//		sprite.setFrameRange(4, 5);
	}
}

void Player::update()
{
	int newDir = -1;
	if (dirX == 1)
		newDir = 4;
	else if (dirX == -1)
		newDir = 0;
	if (dirY == 1)
		newDir = 2;
	else if (dirY == -1)
		newDir = 6;
	if (dirX == 0 && dirY == 0)
		newDir = -1;

	if(newDir == -1){
		animationTimer = 0;
		sprite.setCurrentFrame(direction);
	}
	else if (newDir != direction){
		direction = newDir;
		sprite.setCurrentFrame(direction);
		animationTimer = 0;
	//	sprite.play();
	}
	animationTimer++;
	if (animationTimer == getAnimationSpeed()){
		animationTimer = 0;
		if (sprite.getCurrentFrame() == direction)
			sprite.setCurrentFrame(direction + 1);
		else
			sprite.setCurrentFrame(direction);
	}		
}

int Player::getAnimationSpeed(){
	return 17 / moveSpeed;
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
