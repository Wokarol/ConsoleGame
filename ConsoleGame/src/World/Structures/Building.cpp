#include "Building.h"


Building::Building(int width, int height)
{
	this->width = width;
	this->height = height;
}

Building::operator Grid()
{
	Grid grid(width, height);

	for (int x = 0; x < width; x++)
	{
		grid.getCell(x, 0) = '-';
		grid.getCell(x, height - 1) = '-';
	}

	for (int y = 1; y < height - 1; y++)
	{
		grid.getCell(0, y) = '|';
		grid.getCell(width - 1, y) = '|';
	}

	return grid;
}