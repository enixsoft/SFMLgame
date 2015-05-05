#include "StdAfx.h"
#include "Tank.h"
#include "Game.h"


Tank::Tank(){//abst class
	idCiel=idCiel++;
}
Tank::Tank(int ammo, TANK_TYPE tankType, int rateOfFire, int health){
	idCiel = idCiel++;

	setAmmo(ammo);
	setTankType(tankType);
	setRateOfFire(rateOfFire);
	setHealth(health);
	idCiel++;
}

Tank::~Tank(){}



int Tank::idCiel = 0;