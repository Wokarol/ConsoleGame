#include <iostream>
#include <stdlib.h>

#include "Rendering.h"

using namespace rendering;

void rendering::initializeFrameBuffer(int width, int height)
{
	frameBuffer[width][height];
	rendering::width = width;
	rendering::height = height;
}

void rendering::clearFrame(char background)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			frameBuffer[x][y] = background;
		}
	}
}

void rendering::outputToConsole()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			std::cout << frameBuffer[x][y];
		}

		std::cout << std::endl;
	}
}
