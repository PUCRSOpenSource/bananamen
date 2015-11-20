#ifndef _MAP_H_
#define _MAP_H_

#include <tmx/MapLoader.h>
#include "Game.h"
#include "Player.h"
#include "Sprite.h"

class Map
{
	public:
		Map (char* mapPath, uint8_t collisionLayer);
		~Map ();

		void draw (sf::RenderWindow* screen);
		void update (cgf::Game* game, Player* player1, Player* player2);
		bool checkCollision (cgf::Game* game, cgf::Sprite obj);
		sf::Uint16 getCellFromMap (uint8_t layernum, float x, float y);

	private:
		tmx::MapLoader* map;
		int collisionLayer;
		//Banana[] bananas;
		//Enemy [] enemies;
};
#endif
