#include "Player.h"
#include <conio.h>

int Player::getWidth()
{
	return 1;
}

int Player::getHeight()
{
	return 1;
}

wchar_t Player::getChar(int x, int y)
{
	return L'\u263A';
}

void Player::handleInput()
{
	char key = _getch();
	if (key == 'd')
		x += 1;
	if (key == 'a')
		x -= 1;
	if (key == 'w')
		y -= 1;
	if (key == 's')
		y += 1;
}
