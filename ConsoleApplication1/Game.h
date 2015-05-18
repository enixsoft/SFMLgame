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

	/*Rozne stadia v ktorych sa hra moze nachadzat*/
	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	/*defaultne game state neinicializovana*/
	GameState _gameState = Uninitialized;
	GameObjectManager _gameObjectManager;

	static sf::RenderWindow _mainWindow;

public:
	/*Konstanty pre vysku a sirku obrazovky, teda v nasom pripade okna aplikacie.*/
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

