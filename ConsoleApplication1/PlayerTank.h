#pragma once
#include "VisibleGameObject.h"

class PlayerTank :
	public VisibleGameObject
{
public:
	PlayerTank();
	~PlayerTank();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
};
