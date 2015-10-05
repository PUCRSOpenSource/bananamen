/*
 * Gabriel Carlos e Vinicius Warlet
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"
#include "PauseState.h"

int main(int argc, char **argv)
{
    cgf::Game game(5,30);

	game.init("Bomberman (Versao Alternativa)",480,416,false);

    game.changeState(MenuState::instance());

	while(game.isRunning())
	{
		game.handleEvents();
		game.update();
		game.draw();
	}

	// cleanup the engine
	game.clean();

    return 0;
}
