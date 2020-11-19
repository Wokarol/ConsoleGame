#include "Building.h"


Building::Building(int width, int height)
{
	this->width = width;
	this->height = height;
}

int Building::getWidth()
{
	return width;
}

int Building::getHeight()
{
	return height;
}

wchar_t Building::getChar(int x, int y)
{
	// Corners
	if (x == 0 && y == 0)
		return L'\u250C';
	if (x == width - 1 && y == height - 1)
		return L'\u2518';
	if (x == 0 && y == height - 1)
		return L'\u2514';
	if (x == width - 1 && y == 0)
		return L'\u2510';

	// Left/Right
	if ((x == 0 || x == width - 1) && (y >= 1 || x <= height - 1))
		return L'\u2502';

	// Left/Right
	if ((y == 0 || y == height - 1) && (x >= 1 || x <= width - 1))
		return L'\u2500';

	else 
		return 0;
}