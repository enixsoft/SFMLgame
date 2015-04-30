#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerPaddle.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Game!", sf::Style::Close);
	    
	PlayerPaddle *player1 = new PlayerPaddle();
	  player1->Load("images/PlayerPaddle.png");
	  player1->SetPosition((1024 / 2) - 45, 700);
	  _gameObjectManager.Add("Paddle1", player1);
		   
      GameBall *ball = new GameBall();
      ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);
	  _gameObjectManager.Add("Ball", ball);
		   
	   _gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
		
	switch (_gameState)
		{
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{
			sf::Event currentEvent;
			while (_mainWindow.pollEvent(currentEvent))
			{
				_mainWindow.clear(sf::Color(0, 0, 0));
				_gameObjectManager.DrawAll(_mainWindow);
				_mainWindow.display();

				

				if (currentEvent.type == sf::Event::Closed) 
					_gameState = Game::Exiting;

				if (currentEvent.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ShowMenu();
					//if(currentEvent.Key.Code == sf::Key::Escape) ShowMenu();
				}
			}
			break;
		 }
		
	}
}
void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
	case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
    case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;