#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerTank.h"
#include "GameObjectManager.h"

class Game
{
private:
	bool IsExiting();
	void GameLoop();

	void ShowSplashScreen();
	void ShowMenu();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	GameState _gameState = Uninitialized;
	//sf::RenderWindow Game::_mainWindow;
	//static sf::RenderWindow _mainWindow;
	GameObjectManager _gameObjectManager;

	static sf::RenderWindow _mainWindow;

public:
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	 void Start();
	


	 GameObjectManager getGameObjectManager(){
		 return _gameObjectManager;
	 }
	 GameState getGameState(){
		 return _gameState;
	 }



};
