#include "StdAfx.h"
#include "PlayerTank.h"
#include "Game.h"
#include "Windows.h"

PlayerTank::PlayerTank()
{
	setVelocity(0);
	setMaxVelocity(600.0f);

	Load("images/PlayerPaddle.png");

	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);
	
}


//PlayerTank::~PlayerTank()
//{
//}

void PlayerTank::Draw(sf::RenderWindow & rw)
{
	OutputDebugStringW(L"Draw\n");
	VisibleGameObject::Draw(rw);
}



void PlayerTank::Update(float elapsedTime)
{
	

	OutputDebugStringW(L"update playertank\n");
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