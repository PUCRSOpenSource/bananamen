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
		bool checkCollision2 (cgf::Sprite sprite);
		bool checkCollision(cgf::Sprite s1, cgf::Sprite s2);
		sf::Uint16 getCellFromMap (uint8_t layernum, float x, float y);

	private:
		tmx::MapLoader* map;
		int *collisionLayers;
		std::vector<Banana*> bananas;
		std::vector<Explosion*> explosions;
		void explode(Banana* banana);
		bool makeExplosion(float x, float y);
		bool between(float a1, float a2, float b);
};
#endif
