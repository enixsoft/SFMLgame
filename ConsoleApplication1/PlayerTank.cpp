#include "StdAfx.h"
#include "PlayerTank.h"
#include "Game.h"
#include "Windows.h"

PlayerTank::PlayerTank():
_velocity(0),
_maxVelocity(600.0f)
{

	Load("images/PlayerPaddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);

}


PlayerTank::~PlayerTank()
{
}

void PlayerTank::Draw(sf::RenderWindow & rw)
{
	OutputDebugStringW(L"Draw\n");
	VisibleGameObject::Draw(rw);
}

float PlayerTank::GetVelocity() const
{
	return _velocity;
}

void PlayerTank::Update(float elapsedTime)
{
	

	OutputDebugStringW(L"update playertank\n");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_velocity -= 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_velocity += 3.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	if (pos.x  < GetSprite().getLocalBounds().height / 2
		|| pos.x >(Game::SCREEN_WIDTH- GetSprite().getLocalBounds().width / 2))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
	}

	GetSprite().move(_velocity * elapsedTime, 0);
}