#include "StdAfx.h"
#include "Tank.h"
#include "Game.h"
#include "Windows.h"

Tank::Tank(){//abst class
	idCiel=idCiel++;

	//todo 
}
Tank::Tank(int ammo, TANK_TYPE tankType, int rateOfFire, int health){
	idCiel = idCiel++;

	setAmmo(ammo);
	setTankType(tankType);
	setRateOfFire(rateOfFire);
	setHealth(health);
	idCiel++;

	//Load("images/PlayerTank.png");//podla typu davat obrazok//nemusi to tu byt
	//assert(IsLoaded());//kontrola

	OutputDebugStringW(L"VOLAM KOKOTINY\n");

	//orig hodnoty player
	//setVelocity(0);
	//setMaxVelocity(600.0f);
	//GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);//nastavenie spawnu playeru
}

void Tank::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}



Tank::~Tank(){}
void Tank::spawn(float x,float z){}
void Tank::Update(float elapsedTime){}


int Tank::idCiel = 0;