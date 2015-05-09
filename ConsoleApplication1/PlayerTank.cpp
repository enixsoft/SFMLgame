#include "StdAfx.h"
#include "PlayerTank.h"
#include "Game.h"
#include "Windows.h"

PlayerTank::PlayerTank()
{

}


//PlayerTank::~PlayerTank()
//{
//}




void PlayerTank::Update(float elapsedTime)
{
	
	//input
	

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
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//{
	//	shoot();//shoot projectile//spawned ones shoot in random interval in range of random numbers
	//}
	//



	if (GetVelocity() > getMaxVelocity()){
		setVelocity(getMaxVelocity());
	}if (GetVelocity() < -getMaxVelocity()){
		setVelocity(-getMaxVelocity());
	}

	sf::Vector2f pos = this->GetPosition();

	if (pos.x  < GetSprite().getLocalBounds().height / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
	{
		setVelocity(-GetVelocity()); // Bounce by current velocity in opposite direction
		
	}

	GetSprite().move(GetVelocity() * elapsedTime, 0);
}