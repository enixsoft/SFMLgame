#pragma once
#include "VisibleGameObject.h"

enum TANK_TYPE{
	PLAYER,LIGHT, MEDIUM, HEAVY
};

class Tank :public VisibleGameObject{//abst class
private:
	float _maxVelocity;
	float _velocity;  // -- left ++ right

	int ammo;//-1 unlimited ammo
	int id=0;//nula hrac
	TANK_TYPE tankType;
	int rateOfFire;//ako rychlo tank striela
	int health;//rozne tanky maju viac zivota ako druhe

	static int idCiel;//vrch id generovane

public:
	
	Tank();
	Tank(int ammo, TANK_TYPE tankType, int rateOfFire,int health);

	virtual ~Tank()=0;//pure virtual



	virtual void Update(float elapsedTime);

	virtual void spawn(float x,float z);//overwrite in subclass

	void Draw(sf::RenderWindow& rw);


	bool shoot();
	void destroyed();//moze sa menit obrazok a dat navedomie ze sa znicil tank

	//getters / setters
	


	void setMaxVelocity(float _maxVelocity){
		this->_maxVelocity = _maxVelocity;
	}

	float getMaxVelocity(){
		return _maxVelocity;
	}

	float GetVelocity()
	{
		return _velocity;
	}
	void setVelocity(float _velocity){
		this->_velocity = _velocity;
	}



	static int getIdCiel() {
		return idCiel;
	}

	int getId(){
		return id;
	}
	void setAmmo(int ammo){
		(ammo >= 0) ? this->ammo : 0;
	}
	int getAmmo(){
		return ammo;
	}
	void setTankType(TANK_TYPE tankType){

	}
	TANK_TYPE getTankType(){
		return tankType;
	}
	void setRateOfFire(int rateOfFire){
		this->rateOfFire = rateOfFire;
	}
	int getRateOfFire(){
		return rateOfFire;
	}
	void setHealth(int health){
		if (health<100&&health<=0){
			this->health = health;
		}
	}
	int getHealth(){
		return health;
	}



};