#include <iostream>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "Renderer.h"

Renderer::Renderer(int width, int height) : frameBuffer(width, height) {}

void Renderer::clearFrame(wchar_t background)
{
	frameBuffer.fill(background);
}

void Renderer::draw(Grid& obj, int posX, int posY)
{
	for (int x = 0; x < obj.width; x++)
	{
		for (int y = 0; y < obj.height; y++)
		{
			if (obj.getCell(x, y) != 0)
				frameBuffer.getCell(x + posX, y + posY) = obj.getCell(x, y);
		}
	}
}

void Renderer::clearConsole()
{
	system("cls");
}

void Renderer::outputToConsole()
{
	for (int y = 0; y < frameBuffer.height; y++)
	{
		for (int x = 0; x < frameBuffer.width; x++)
		{
			_setmode(_fileno(stdout), _O_U16TEXT);
			std::wcout << frameBuffer.getCell(x, y);
		}

		std::wcout << std::endl;
	}
}
