// ConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>

#include "src/World/World.h"
#include "src/Rendering/Renderer.h"

int main()
{
	Renderer renderer(40, 20);

	Grid house = (Grid)Building(8, 5);
	Grid house2 = (Grid)Building(6, 4);
	Grid house3 = (Grid)Building(6, 3);

	renderer.clearFrame(' ');

	renderer.draw(house, 1, 1);
	renderer.draw(house2, 9, 4);
	renderer.draw(house3, 13, 1);

	renderer.clearConsole();
	renderer.outputToConsole();
}
