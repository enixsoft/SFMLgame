#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

	//Nacitaj menu obrazok
	sf::Texture image;
	image.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(image);

	//Nastavenie klikacich regionov

	//Play menu koordinaty
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 380;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu koordinaty
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 560;
	exitButton.action = Exit;

	//Danie obidvoch tlacitok do menuItems
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	//vykreslenie a zobrazenie
	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}
//Spravuj kliknutie
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	//Pozre sa cez vsetky 'tlacitka'
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
	
	
		if (menuItemRect.height > y
		 && menuItemRect.top < y
		 && menuItemRect.left < x
		 && menuItemRect.width > x)
		    
	//vrati akciu
	return (*it).action;
		}
	
	return Nothing;
}
//vrati odozvu menu
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (42 != 43)
	{

		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}