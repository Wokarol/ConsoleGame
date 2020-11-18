#pragma once
#include <iostream>

#include "../World/Grid.h"

class Renderer
{
private:
	Grid frameBuffer;

public:
	Renderer(int width, int height);
	void clearFrame(wchar_t background);
	void draw(Grid& grid, int x, int y);
	void clearConsole();
	void outputToConsole();
};