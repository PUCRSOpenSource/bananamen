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
}
void Map::update(cgf::Game* game, Player* player1, Player* player2)
{
	move(game, player1);
	move(game, player2);
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
		if(!checkCollision2(game, player))
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
		if(!checkCollision2(game, player))
			break;
		player->sprite.setPosition(x, y);
		amount /= 2.0f;	
	}
	player->sprite.update(game->getUpdateInterval());
	player->setDirX(0);
	player->setDirY(0);	
}

bool Map::checkCollision2(cgf::Game* game, Player* player)
{
	float x = player->sprite.getPosition().x;
	float y = player->sprite.getPosition().y;
	sf::Vector2u size = player->sprite.getSize();
	size.x *= player->sprite.getScale().x;
	size.y *= player->sprite.getScale().y;
	for(int k = 0; k <= 1; k++)
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
				if(getCellFromMap(collisionLayers[k], x + (size.x * i), y + (size.y * j)))
					return true;
	return false;
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
