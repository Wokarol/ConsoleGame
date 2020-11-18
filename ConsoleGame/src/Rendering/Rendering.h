#pragma once
#include <iostream>

#include "../World/Grid.h"

namespace rendering
{
	char** frameBuffer;
	int width;
	int height;

	void initializeFrameBuffer(int width, int height);
	void clearFrame(char background);
	void draw(Grid& grid, int x, int y);
	void clearConsole()
	{
		system("cls");
	}
	void outputToConsole();
}