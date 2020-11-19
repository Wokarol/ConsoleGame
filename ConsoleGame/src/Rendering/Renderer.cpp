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
	int minX = posX;
	int minY = posY;

	int distToEdgeX = frameBuffer.width - posX;
	int distToEdgeY = frameBuffer.height - posY;

	int startX = std::max(-minX, 0);
	int startY = std::max(-minY, 0);
	int endX = std::min(distToEdgeX, obj.width);
	int endY = std::min(distToEdgeY, obj.height);

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
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
	_setmode(_fileno(stdout), _O_U16TEXT);

	std::wcout << std::endl;
	std::wcout << L"  \u2554";
	for (int i = 0; i < frameBuffer.width; i++)
	{
		std::wcout << L'\u2550';
	}
	std::wcout << L'\u2557' << std::endl;

	for (int y = 0; y < frameBuffer.height; y++)
	{
		std::wcout << L"  \u2551";
		for (int x = 0; x < frameBuffer.width; x++)
		{
			std::wcout << frameBuffer.getCell(x, y);
		}
		std::wcout << L'\u2551';

		std::wcout << std::endl;
	}

	std::wcout << L"  \u255A";
	for (int i = 0; i < frameBuffer.width; i++)
	{
		std::wcout << L'\u2550';
	}
	std::wcout << L'\u255D' << std::endl;
}
