#pragma once
#include <iostream>
#include <windows.h>

#include "Renderable.h"
#include "Grid.h"

class Renderer
{
private:
	Grid frameBuffer;
	HANDLE out;
	CONSOLE_CURSOR_INFO cursorInfo{};

public:
	Renderer(int width, int height);
	void clearFrame(wchar_t background);
	void draw(Renderable& grid, int x, int y);
	void outputToConsole();
};