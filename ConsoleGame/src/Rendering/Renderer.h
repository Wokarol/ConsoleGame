#pragma once
#include <iostream>
#include <windows.h>

#include "../World/Grid.h"

class Renderer
{
private:
	Grid frameBuffer;
	HANDLE out;
	CONSOLE_CURSOR_INFO cursorInfo{};

public:
	Renderer(int width, int height);
	void clearFrame(wchar_t background);
	void draw(Grid& grid, int x, int y);
	void outputToConsole();
};