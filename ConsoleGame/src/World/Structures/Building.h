#pragma once

#include "../../Rendering/Renderable.h"

class Building : public Renderable
{
public:
	int width;
	int height;

	Building(int width, int heigth);

	// Inherited via Renderable
	virtual int getWidth() override;
	virtual int getHeight() override;
	virtual wchar_t getChar(int x, int y) override;
};

