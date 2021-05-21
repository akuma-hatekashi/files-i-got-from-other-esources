#include <iostream>
#include <cstdlib>
#include <sstream>
#include "game.hpp"

int choice;

int main()
{
	std::string choiceStr;
	std::cout << "(1) - Play with friend\n(2) - Play with computer\n(3) - Simulate full game\nOption: ";
	reEnterInt:

		std::cin >> choiceStr;

	if (choiceStr != "1"
		and choiceStr != "2"
		and choiceStr != "3")
	{
		std::cout << "\nInvalid choice. Re-enter!\n\nOption: ";
		goto reEnterInt;
	}

	choice = std::stoi(choiceStr);

	if (choice == 1)
	{
		work2 = true;
		work3 = true;
	}
	else if (choice == 2)
	{
		work3 = false;
	}
	else if (choice == 3)
	{
		work2 = false;
	}
	srand(time(0));

	sim_full = !work2;
	simulating = !work3;

	play_game();
}
