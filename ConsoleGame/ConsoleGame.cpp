﻿#include <conio.h>

#include "src/World/World.h"
#include "src/Rendering/Rendering.h"
#include "src/Actors/Actors.h"


int main()
{
	Renderer renderer(20, 10);
	Building squareA = Building(4, 3);
	Building squareB = Building(7, 2);
	Player player = Player{};

	while (true)
	{
		renderer.clearFrame(' ');

		renderer.draw(squareA, 4, 6);
		renderer.draw(squareB, 7, 2);
		renderer.draw(player, player.x, player.y);

		renderer.outputToConsole();

		char key = _getch();
		if (key == 'd')
			player.x += 1;
		if (key == 'a')
			player.x -= 1;
		if (key == 'w')
			player.y -= 1;
		if (key == 's')
			player.y += 1;
	}
}
