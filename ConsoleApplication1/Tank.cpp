#include "StdAfx.h"
#include "Tank.h"
#include "Game.h"
#include "Windows.h"



Tank::Tank(){//abstraktna class

}
Tank::Tank(int ammo, TANK_TYPE tankType, int rateOfFire, int health){

	setAmmo(ammo);
	setTankType(tankType);
	setRateOfFire(rateOfFire);
	setHealth(health);
}

void Tank::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}



Tank::~Tank(){}
void Tank::spawn(float x,float z){}
void Tank::Update(float elapsedTime){}


