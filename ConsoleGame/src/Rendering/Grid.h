#pragma once
#include "Renderable.h"

class Grid : public Renderable
{
private:
	wchar_t* grid;

public:
	int width;
	int height;

	Grid(int sizeX, int sizeY);
	Grid(int sizeX, int sizeY, wchar_t filler);
	wchar_t& getCell(int x, int y);
	void fill(wchar_t filler);



	// Inherited via Renderable
	virtual int getWidth() override;
	virtual int getHeight() override;
	virtual wchar_t getChar(int x, int y) override;

};

