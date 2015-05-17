#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerTank.h"
#include <random>

/*Objekt hraca*/
PlayerTank *player;


//ColisionDaemon cd;//dojebane includy zase


/*Metoda ktora riadi chod hry*/
void Game::Start(void)
{

	/*Pokial hra nieje neinicializovana neni mozne vykonavat tuto metodu*/
	if (Game::_gameState != Uninitialized)
		return;


	/*Vytvorenie okna ktore ma za moznost byt zatvorene a fixnute parametre*/
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Tanky!", sf::Style::Close);

	

	//Inicializacia hraca
	player = new PlayerTank(0,PLAYER,100,100,100,0,3,0);

	/*Pridavanie objektov do objekt managera hrac,tanky*/
	  _gameObjectManager.Add(player);

	  for (int i = 0; i < 9;i++){
		  _gameObjectManager.spawnEnemyTank(LIGHT);
		  //sprav thread ktory bude robit strielat tanky
	  }

	  /*Zmena stavu na ukazuje splash screen*/
	   _gameState = Game::ShowingSplash;

	   /*Pokial sa nezmeni state na is exiting vykonavat cyklus hry*/
	while (!IsExiting()){//!!! dvolezite
	
		GameLoop();//myska problem loop within loop break out of stack event
	}
	
	_mainWindow.close();
}

/*Metoda ktora sa stara o uzatvorenie hry*/
bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}
/*Vykonava sa nanstop*/
void Game::GameLoop(){

	/*Zobranie event poolu z okna hry*/
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
			/*Vykonavanie akcii na zaklade eventov*/

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

				if (currentEvent.type == sf::Event::KeyPressed)
				{
					/*Strelba hraca*/
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						if (player->getAmmo() != 0 || player->getAmmo()==-1){
							Projectile *tmp = player->shoot();
							std::string id=_gameObjectManager.Add(tmp);

						}
					}
				}
				/*Loop cez vsetky  tanky*/
				for (int i = 1; i <_gameObjectManager.GetObjectCount(); i++){//if instance of 
					VisibleGameObject* t = _gameObjectManager.Get(std::to_string(i));
					/*Strielaj v nahodnom intrevale - strelba pre spawnute nepriatelske tanky nachadzajuce sa v objekt managery*/
					if (t){
						if (!(rand() % 2000)){
							/*Vytvorenie projektilu a vsunutie ho do objekt manageru*/
							Projectile *pp =new Projectile(Point(t->GetPosition().x, t->GetPosition().y), DIRECTION_SOUTH);
							_gameObjectManager.Add(pp);
						}
					}
					

					
				}

			break;
		 }
		
	}
}
/*Ukaze splash screen aplikacie*/
void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}
/*Ukaze menu aplikacie s moznostou spustit hru a  ukoncit,meni state hry*/
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

sf::RenderWindow Game::_mainWindow;
