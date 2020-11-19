#pragma once

#include "../../Rendering/Rendering.h"

struct Building
{
	int width;
	int height;

	Building(int width, int heigth);
	operator Grid();
};

