#include "Building.h"


Building::Building(int width, int height)
{
	this->width = width;
	this->height = height;
}

Building::operator Grid()
{
	Grid grid(width, height);

	for (int x = 1; x < width - 1; x++)
	{
		wchar_t c = L'\u2500';
		grid.getCell(x, 0) = c;
		grid.getCell(x, height - 1) = c;
	}

	for (int y = 1; y < height - 1; y++)
	{
		wchar_t c = L'\u2502';
		grid.getCell(0, y) = c;
		grid.getCell(width - 1, y) = c;
	}

	grid.getCell(0, 0) = L'\u250C';
	grid.getCell(width - 1, height - 1) = L'\u2518';
	grid.getCell(0, height - 1) = L'\u2514';
	grid.getCell(width - 1, 0) = L'\u2510';

	for (int x = 1; x < grid.width - 1; x++)
	{
		for (int y = 1; y < grid.height - 1; y++)
		{
			grid.getCell(x, y) = 0;
		}
	}

	return grid;
}