#include <iostream>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#include "Renderer.h"

Renderer::Renderer(int width, int height) : frameBuffer(width, height)
{
	SetConsoleTextAttribute(out, 0xFC);
	system("cls");
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	auto _ = _setmode(_fileno(stdout), _O_U16TEXT);
}

void Renderer::clearFrame(wchar_t background)
{
	frameBuffer.fill(background);
}

void Renderer::draw(Renderable& obj, int posX, int posY)
{
	int minX = posX;
	int minY = posY;

	int distToEdgeX = frameBuffer.getWidth() - posX;
	int distToEdgeY = frameBuffer.getHeight() - posY;

	int startX = max(-minX, 0);
	int startY = max(-minY, 0);
	int endX = min(distToEdgeX, obj.getWidth());
	int endY = min(distToEdgeY, obj.getHeight());

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			wchar_t c = obj.getChar(x, y);
			if (c != 0)
				frameBuffer.getCell(x + posX, y + posY) = c;
		}
	}
}

void Renderer::outputToConsole()
{
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(out, coord);

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	std::wcout << std::endl;
	std::wcout << L"  \u2554";
	for (int i = 0; i < frameBuffer.getWidth(); i++)
	{
		std::wcout << L'\u2550';
	}
	std::wcout << L'\u2557' << std::endl;

	for (int y = 0; y < frameBuffer.getHeight(); y++)
	{
		std::wcout << L"  \u2551";
		for (int x = 0; x < frameBuffer.getWidth(); x++)
		{
			std::wcout << frameBuffer.getCell(x, y);
		}
		std::wcout << L'\u2551';

		std::wcout << std::endl;
	}

	std::wcout << L"  \u255A";
	for (int i = 0; i < frameBuffer.getWidth(); i++)
	{
		std::wcout << L'\u2550';
	}
	std::wcout << L'\u255D' << std::endl;
}
