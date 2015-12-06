#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Game.h"
#include "MenuState.h"

int main(int argc, char **argv)
{
	//cgf::Game game(5,30);

	//game.init("Framework com estados, sprites e tiling",480,480,true);

	//game.changeState(MenuState::instance());

	//while(game.isRunning())
	//{
		//game.handleEvents();
		//game.update();
		//game.draw();
	//}
	//game.clean();
	while (true) {
		if (sf::Joystick::isButtonPressed(0, 1))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 2))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 3))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 4))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 5))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 6))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 7))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 8))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
		if (sf::Joystick::isButtonPressed(0, 9))
			std::cout << "sf::Joystick::isButtonPressed(0, 1): " <<  sf::Joystick::isButtonPressed(0, 1) << std::endl;
	}
	return 0;
}
