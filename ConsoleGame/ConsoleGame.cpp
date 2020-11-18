// ConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>

#include "src/World/World.h"
#include "src/Rendering/Rendering.h"

int main()
{
	rendering::initializeFrameBuffer(10, 10);

	//Grid house = (Grid)Building(5, 5);

	rendering::clearFrame('.');
	rendering::clearConsole();
	rendering::outputToConsole();
}
