#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Game.h"
#include "MenuState.h"

int main(int argc, char **argv)
{
	cgf::Game game(5,30);

	game.init("Framework com estados, sprites e tiling",480,480,true);

	game.changeState(MenuState::instance());

	while(game.isRunning())
	{
		game.handleEvents();
		game.update();
		game.draw();
	}
	game.clean();
	return 0;
}
