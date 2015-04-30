#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"


PlayerPaddle::PlayerPaddle() :
_velocity(0),
_maxVelocity(600.0f)

{
	Load("images/PlayerPaddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);

}


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(float elapsedTime)
{

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

	if (pos.x  < GetSprite().getLocalBounds().x / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
	}

	GetSprite().Move(_velocity * elapsedTime, 0);
}