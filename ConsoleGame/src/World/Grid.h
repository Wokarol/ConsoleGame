#pragma once
class Grid
{
public:
	int width;
	int height;

	Grid(int sizeX, int sizeY);
	Grid(int sizeX, int sizeY, char filler);
	char& getCell(int x, int y);

private:
	char* grid;
	void fill(char filler);
};

