#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerTank.h"

void Game::Start(void)
{
	if (Game::_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Tanky!", sf::Style::Close);



	PlayerTank *player = new PlayerTank();
	  player->Load("images/PlayerPaddle.png");//obrazok na tank
	  player->SetPosition((1024 / 2) - 45, 700);
	  _gameObjectManager.Add("Player", player);
		   
    
	   _gameState = Game::ShowingSplash;

	while (!IsExiting()){//!!! dvolezite
	
		GameLoop();//myska problem loop within loop break out of stack event
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

void Game::GameLoop(){
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
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
			//sf::Event currentEvent;
	
				_mainWindow.clear(sf::Color(0, 0, 0));
				_gameObjectManager.UpdateAll();
				_gameObjectManager.DrawAll(_mainWindow);
				_mainWindow.display();

	

				if (currentEvent.type == sf::Event::Closed) {
					_gameState = Game::Exiting;
				}

				if (currentEvent.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ShowMenu();
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
	//fsdfs
}



// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;