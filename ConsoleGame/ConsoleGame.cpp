#include <conio.h>

#include "src/World/World.h"
#include "src/Rendering/Renderer.h"


int main()
{
	Renderer renderer(80, 40);
	Grid square = (Grid)Building(4, 2);

	int posX = 0, posY = 0;

	while (true)
	{
		renderer.clearFrame(' ');

		renderer.draw(square, posX, posY);

		renderer.outputToConsole();

		char key = _getch();
		if (key == 'd')
			posX += 1;
		if (key == 'a')
			posX -= 1;
		if (key == 'w')
			posY -= 1;
		if (key == 's')
			posY += 1;
	}
}
