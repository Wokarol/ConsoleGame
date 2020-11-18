#pragma once
class Grid
{
public:
	int width;
	int height;

	Grid(int sizeX, int sizeY);
	Grid(int sizeX, int sizeY, wchar_t filler);
	wchar_t& getCell(int x, int y);
	void fill(wchar_t filler);

private:
	wchar_t* grid;
};

