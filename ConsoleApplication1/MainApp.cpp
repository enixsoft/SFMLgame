// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <Windows.h>

int main(int argc, _TCHAR* argv[])
{
	OutputDebugStringW(L"My output string.\n");
	std::cout << "main test" << std::endl;
	Game::Start();
	//hey

	return 0;
}