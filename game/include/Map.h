#ifndef _MAP_H_
#define _MAP_H_

#include <vector>

#include <tmx/MapLoader.h>
#include "Game.h"
#include "Player.h"
#include "Sprite.h"
#include "Banana.h"

class Map
{
	public:
		Map (char* mapPath, uint8_t collisionLayer);
		~Map ();

		void draw (sf::RenderWindow* screen);
		void update (cgf::Game* game, Player* player1, Player* player2);
		void move(cgf::Game* game, Player* player);
		void putBomb(Player* player);
		bool checkCollision2 (cgf::Game* game, Player* player);
		std::vector<Banana* > getBananas();
		sf::Uint16 getCellFromMap (uint8_t layernum, float x, float y);

	private:
		tmx::MapLoader* map;
		int *collisionLayers;
		std::vector<Banana*> bananas;
		//Enemy [] enemies;
};
#endif
