#pragma once
#include "../Rendering/Renderable.h"

class Player : public Renderable
{
public:
	int x, y;

	// Inherited via Renderable
	virtual int getWidth() override;
	virtual int getHeight() override;
	virtual wchar_t getChar(int x, int y) override;

	void handleInput();
};

