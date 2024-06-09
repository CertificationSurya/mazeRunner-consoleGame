#pragma once
#include "fundamentals.h"
#include "helper.h"
#include "display.h"
#include "maze.h"
#include "menu.h"
#include "modes.h"

void game()
{
	// to restart the game if user press esc while playing
	while (true) {
		try	{
			mainMenu();
			clearScreen();
			classic();
		}
		catch (const std::runtime_error &e)	{
			if (e.what() == std::string("BreakException")) {
				std::cout << "Breaking out of everything!" << std::endl;
			}
			else {
				throw; // Re-throw other exceptions
			}
		}
	} // main while
}