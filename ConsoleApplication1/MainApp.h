#pragma once
#include <Windows.h>
#include "Game.h"



class MainApp{
private:
	Game game;

public:
	MainApp(){

	}
	~MainApp(){

	}
	Game getGame(){
		return game;
	}
};

 MainApp mainApp;

