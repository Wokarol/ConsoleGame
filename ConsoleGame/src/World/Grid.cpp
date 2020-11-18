#include <stdexcept>

#include "Grid.h"

Grid::Grid(int sizeX, int sizeY)
{
	grid = new char[sizeX * sizeY];
	width = sizeX;
	height = sizeY;
}

Grid::Grid(int sizeX, int sizeY, char filler) : Grid(sizeX, sizeY)
{
	fill(filler);
}

char& Grid::getCell(int x, int y)
{
	if (x < 0 || x >= width)
		throw std::out_of_range("Yeet?");
	if (y < 0 || y >= height)
		throw std::out_of_range("Yeet?");

	return grid[x + y * width];
}


void Grid::fill(char filler)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			getCell(x, y) = filler;
		}
	}
}