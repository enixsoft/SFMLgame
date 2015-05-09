#include "stdafx.h"
#include <Windows.h>
#include "Game.h"
#include "MainApp.h"


int main(int argc, _TCHAR* argv[])
{
	OutputDebugStringW(L"My output string.\n");

	//Game game;

	mainApp.getGame().Start();

	//Game::Start();
	//hey

	return 0;
}
