#include <stdexcept>

#include "Grid.h"

Grid::Grid(int sizeX, int sizeY)
{
	int size = sizeX * sizeY;
	grid = new wchar_t[size];
	width = sizeX;
	height = sizeY;
}

Grid::Grid(int sizeX, int sizeY, wchar_t filler) : Grid(sizeX, sizeY)
{
	fill(filler);
}

wchar_t& Grid::getCell(int x, int y)
{
	if (x < 0 || x >= width)
		throw std::out_of_range("Yeet?");
	if (y < 0 || y >= height)
		throw std::out_of_range("Yeet?");

	return grid[x + y * width];
}


void Grid::fill(wchar_t filler)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			getCell(x, y) = filler;
		}
	}
}

int Grid::getWidth()
{
	return width;
}

int Grid::getHeight()
{
	return height;
}

wchar_t Grid::getChar(int x, int y)
{
	return getCell(x, y);
}
