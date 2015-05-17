#include "StdAfx.h"
#include "PlayerTank.h"
#include "Game.h"
#include "Windows.h"

PlayerTank::PlayerTank()
{

}

//metoda ktora spravuje funkciu pohybu
void PlayerTank::Update(float elapsedTime)
{
	//input hraca 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setVelocity(GetVelocity()-3.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setVelocity(GetVelocity()+3.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setVelocity(0.0f);
	}
	//rychlost pohybu
	if (GetVelocity() > getMaxVelocity()){
		setVelocity(getMaxVelocity());
	}if (GetVelocity() < -getMaxVelocity()){
		setVelocity(-getMaxVelocity());
	}
	
	sf::Vector2f pos = this->GetPosition();
	//pozera na okraje 
	if (pos.x  < GetSprite().getLocalBounds().height / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
	{
		setVelocity(-GetVelocity()); //odrazi sa rychlostout v protismere
		
	}
	//pohnutie spritu/hraca
	GetSprite().move(GetVelocity() * elapsedTime, 0);
}