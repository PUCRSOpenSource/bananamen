#include "Map.h"

using namespace std;

Map::Map(char* mapPath, uint8_t collisionLayer)
{
	this->collisionLayer = collisionLayer;
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
	checkCollision(game, player1->getSprite());
	//std::cout << checkCollision(game, player2->getSprite()) << std::endl;
}

bool Map::checkCollision(cgf::Game* game, cgf::Sprite obj)
{
	int i, x1, x2, y1, y2;
	bool bump = false;

	sf::Vector2u mapsize = map->GetMapSize();
	sf::Vector2u tilesize = map->GetMapTileSize();

	mapsize.x /= tilesize.x;
	mapsize.y /= tilesize.y;
	mapsize.x--;
	mapsize.y--;

	// Get the height and width of the object (in this case, 100% of a tile)
	sf::Vector2u objsize = obj.getSize();
	objsize.x *= obj.getScale().x;
	objsize.y *= obj.getScale().y;

	float px = obj.getPosition().x;
	float py = obj.getPosition().y;

	double deltaTime = game->getUpdateInterval();

	sf::Vector2f offset(obj.getXspeed()/1000 * deltaTime, obj.getYspeed()/1000 * deltaTime);

	float vx = offset.x;
	float vy = offset.y;

	//cout << "px,py: " << px << " " << py << endl;

	//cout << "tilesize " << tilesize.x << " " << tilesize.y << endl;
	//cout << "mapsize " << mapsize.x << " " << mapsize.y << endl;

	// Test the horizontal movement first
	i = objsize.y > tilesize.y ? tilesize.y : objsize.y;

	for (;;)
	{
		x1 = (px + vx) / tilesize.x;
		x2 = (px + vx + objsize.x - 1) / tilesize.x;

		y1 = (py) / tilesize.y;
		y2 = (py + i - 1) / tilesize.y;

		if (x1 >= 0 && x2 < mapsize.x && y1 >= 0 && y2 < mapsize.y)
		{
			if (vx > 0)
			{
				// Trying to move right

				int upRight   = getCellFromMap(this->collisionLayer, x2*tilesize.x, y1*tilesize.y);
				int downRight = getCellFromMap(this->collisionLayer, x2*tilesize.x, y2*tilesize.y);
				if (upRight || downRight)
				{
					// Place the player as close to the solid tile as possible
					px = x2 * tilesize.x;
					px -= objsize.x;// + 1;
					vx = 0;
					bump = true;
				}
			}

			else if (vx < 0)
			{
				// Trying to move left

				int upLeft   = getCellFromMap(this->collisionLayer, x1*tilesize.x, y1*tilesize.y);
				int downLeft = getCellFromMap(this->collisionLayer, x1*tilesize.x, y2*tilesize.y);
				if (upLeft || downLeft)
				{
					// Place the player as close to the solid tile as possible
					px = (x1+1) * tilesize.x;
					vx = 0;
					bump = true;
				}
			}
		}

		if (i == objsize.y) // Checked player height with all tiles ?
		{
			break;
		}

		i += tilesize.y; // done, check next tile upwards

		if (i > objsize.y)
		{
			i = objsize.y;
		}
	}

	// Now test the vertical movement

	i = objsize.x > tilesize.x ? tilesize.x : objsize.x;

	for (;;)
	{
		x1 = (px / tilesize.x);
		x2 = ((px + i-1) / tilesize.x);

		y1 = ((py + vy) / tilesize.y);
		y2 = ((py + vy + objsize.y-1) / tilesize.y);

		if (x1 >= 0 && x2 < mapsize.x && y1 >= 0 && y2 < mapsize.y)
		{
			if (vy > 0)
			{
				// Trying to move down
				int downLeft  = getCellFromMap(this->collisionLayer, x1*tilesize.x, y2*tilesize.y);
				int downRight = getCellFromMap(this->collisionLayer, x2*tilesize.x, y2*tilesize.y);
				if (downLeft || downRight)
				{
					// Place the player as close to the solid tile as possible
					py = y2 * tilesize.y;
					py -= objsize.y;
					vy = 0;
					bump = true;
				}
			}

			else if (vy < 0)
			{
				// Trying to move up

				int upLeft  = getCellFromMap(this->collisionLayer, x1*tilesize.x, y1*tilesize.y);
				int upRight = getCellFromMap(this->collisionLayer, x2*tilesize.x, y1*tilesize.y);
				if (upLeft || upRight)
				{
					// Place the player as close to the solid tile as possible
					py = (y1 + 1) * tilesize.y;
					vy = 0;
					bump = true;
				}
			}
		}

		if (i == objsize.x)
		{
			break;
		}

		i += tilesize.x; // done, check next tile to the right

		if (i > objsize.x)
		{
			i = objsize.x;
		}
	}
	obj->setPosition(px+vx,py+vy);
	px = obj.getPosition().x;
	py = obj.getPosition().y;
	obj.update(deltaTime, false);

	if (px < 0)
		obj.setPosition(px,py);
	else if (px + objsize.x >= mapsize.x * tilesize.x)
		obj.setPosition(mapsize.x*tilesize.x - objsize.x - 1,py);

	if(py < 0)
		obj.setPosition(px,0);
	else if(py + objsize.y >= mapsize.y * tilesize.y)
		obj.setPosition(px, mapsize.y*tilesize.y - objsize.y - 1);

	return bump;
}

sf::Uint16 Map::getCellFromMap(uint8_t layernum, float x, float y)
{
    auto layers = map->GetLayers();
    tmx::MapLayer& layer = layers[this->collisionLayer];
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2u tilesize = map->GetMapTileSize();
    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    int col = floor(x / tilesize.x);
    int row = floor(y / tilesize.y);
    return layer.tiles[row*mapsize.x + col].gid;
}
