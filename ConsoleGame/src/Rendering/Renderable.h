#pragma once
class Renderable
{
public:
	int virtual getWidth() = 0;
	int virtual getHeight() = 0;
	wchar_t virtual getChar(int x, int y) = 0;
};

