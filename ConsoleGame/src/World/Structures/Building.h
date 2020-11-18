#pragma once

#include "../Grid.h"

struct Building
{
	int width;
	int height;

	Building(int width, int heigth);
	operator Grid();
};

