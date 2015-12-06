#include "Map.h"

using namespace std;

Map::Map(char* mapPath, uint8_t collisionLayer)
{
	this->collisionLayers = new int[2];//collisionLayer;
	this->collisionLayers[0] = 1;
	this->collisionLayers[1] = 2;
	map = new tmx::MapLoader("data/maps");
	map->Load(mapPath);
}
Map::~Map()
{
}

void Map::draw(sf::RenderWindow* screen)
{
	map->Draw(*screen);
	int len = explosions.size();
	for(int i = 0; i < len; i++)
		screen->draw(explosions[i]->sprite);
	len = bananas.size();
	for(int i = 0; i < len; i++)
		screen->draw(bananas[i]->sprite);
	len = powerups.size();
	for(int i = 0; i < len; i++)
		screen->draw(powerups[i]->sprite);
	
}
void Map::update(cgf::Game* game, Player* player1, Player* player2)
{
	move(game, player1);
	move(game, player2);
	for (int i = 0; i < explosions.size(); i++)
	{
		if (checkCollision(explosions[i]->sprite, player1->sprite))
			player1->dead = true;	
		if (checkCollision(explosions[i]->sprite, player2->sprite))
			player2->dead = true;
		if (explosions[i]->finished())
			explosions.erase(explosions.begin() + i);
	}
	for (int i = 0; i < bananas.size(); i++)
		if (bananas[i]->wantsToExplode())
		{
			explode(bananas[i]);
			bananas.erase(bananas.begin() + i);
		}
	for (int i = 0; i < powerups.size(); i++)
		if (checkCollision(powerups[i]->sprite, player1->sprite))
			{
				powerups[i]->upgrade(player1);
				powerups.erase(powerups.begin() + i);
			}
		else if (checkCollision(powerups[i]->sprite, player2->sprite))
			{
				powerups[i]->upgrade(player2);
				powerups.erase(powerups.begin() + i);
			}
	if(rand() % 100 == 0)
	{
		cout << "OK" << endl;
		float x = rand() % 15 * 32;
		float y = rand() % 15 * 32;
		Powerup* powerup = new Powerup(x, y);
		if(!checkCollision2(powerup->sprite))
			powerups.push_back(powerup);
	}
}

void Map::move(cgf::Game* game, Player* player)
{
	float x, y, amount;
	//test move x
	amount = player->moveSpeed;
	x = player->sprite.getPosition().x;
	y = player->sprite.getPosition().y;
	while(amount >= 1){
		float x1 = x + (player->getDirX() * amount);
		player->sprite.setPosition(x1, y);
		if(!checkCollision2(player->sprite))
			break;
		player->sprite.setPosition(x, y);
		amount /= 2.0f;	
	}
	//test move y
	x = player->sprite.getPosition().x;
	amount = player->moveSpeed;
	while(amount >= 1){
		float y1 = y + (player->getDirY() * amount);
		player->sprite.setPosition(x, y1);
		if(!checkCollision2(player->sprite))
			break;
		player->sprite.setPosition(x, y);
		amount /= 2.0f;	
	}
	player->sprite.update(game->getUpdateInterval());
	player->setDirX(0);
	player->setDirY(0);
}

void Map::putBomb(Player* player)
{
	Banana* banana = new Banana(player);
	bananas.push_back(banana);
}

bool Map::checkCollision2(cgf::Sprite sprite)
{
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;
	sf::Vector2u size = sprite.getSize();
	size.x *= sprite.getScale().x;
	size.y *= sprite.getScale().y;
	for(int k = 0; k <= 1; k++)
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
				if(getCellFromMap(collisionLayers[k], x + (size.x * i), y + (size.y * j)))
					return true;
	return false;
}

bool Map::checkCollision(cgf::Sprite s1, cgf::Sprite s2)
{
	float x11 = s1.getPosition().x,
	      y11 = s1.getPosition().y,
	      x12 = x11 + (s1.getSize().x * s1.getScale().x),
	      y12 = y11 + (s1.getSize().y * s1.getScale().y),
    	      x21 = s2.getPosition().x,
	      y21 = s2.getPosition().y,
	      x22 = x21 + (s2.getSize().x * s2.getScale().x),
	      y22 = y21 + (s2.getSize().y * s2.getScale().y);
	return (between(x11, x12, x21)
	     || between(x11, x12, x22)
	     || between(x21, x22, x11)
	     || between(x21, x22, x12)) && 
	       (between(y11, y12, y21)
	     || between(y11, y12, y22)
	     || between(y21, y22, y11)
	     || between(y21, y22, y12));
}

bool Map::between(float a1, float a2, float b){
	return b >= a1 && b <= a2;
}
sf::Uint16 Map::getCellFromMap(uint8_t layernum, float x, float y)
{
    auto layers = map->GetLayers();
    tmx::MapLayer& layer = layers[layernum];
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2u tilesize = map->GetMapTileSize();
    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    int col = floor(x / tilesize.x);
    int row = floor(y / tilesize.y);
    return layer.tiles[row*mapsize.x + col].gid;
}

void Map::explode(Banana* banana)
{
	float startX = banana->sprite.getPosition().x;
	float startY = banana->sprite.getPosition().y;
	makeExplosion(startX, startY);
	float tileSize = banana->sprite.getSize().x * banana->sprite.getScale().x;
	bool left = true, right = true, up = true, down = true;
	for (int i = 1; i < banana->explodeLength; i++)
	{
		if(right)
			right = makeExplosion(startX + tileSize * i, startY);
		if(left)
			left = makeExplosion(startX - tileSize * i, startY);
		if(up)
			up = makeExplosion(startX, startY + tileSize * i);
		if(down)
			down = makeExplosion(startX, startY - tileSize * i);
	}
}

bool Map::makeExplosion(float x, float y)
{
	Explosion* explosion;
	explosion = new Explosion();
	explosion->sprite.load("data/img/explosao.png");
	explosion->sprite.setPosition(x, y);
	if (checkCollision2(explosion->sprite))
		return false;
	explosions.push_back(explosion);
	return true;
}

