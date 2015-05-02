#pragma once
#include "VisibleGameObject.h"

enum TANK_TYPE{
	LIGHT, MEDIUM, HEAVY
};

class Tank :public VisibleGameObject{
private:
	int ammo;
	int id;
	TANK_TYPE tankType;
	int rateOfFire;//ako rychlo tank striela
	int health;//rozne tanky maju viac zivota ako druhe

public:
	
	Tank();
	~Tank();


	bool shoot();
	void destroyed();//moze sa menit obrazok a dat navedomie ze sa znicil tank

	//getters / setters
	

	int getId(){
		return id;
	}
	void setTankType(TANK_TYPE tankType){

	}
	TANK_TYPE getTankType(){
		return tankType;
	}

	

};