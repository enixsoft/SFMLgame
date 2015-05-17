#pragma once
#include "Projectile.h"
#include "VisibleGameObject.h"
#include <Windows.h>

//typ tanku
enum TANK_TYPE{
	PLAYER,LIGHT, MEDIUM, HEAVY
};

class Tank :public VisibleGameObject{//abst class
private:
	float _maxVelocity;
	float _velocity;  // -- vlavo ++ vpravo

	int ammo;//-1 unlimited ammo
	TANK_TYPE tankType;
	int rateOfFire;//ako rychlo tank striela// v pixeloch .. pracuje s poziciou tanku kolk osa pohol etc//neni pouzite
	int health;//rozne tanky maju viac zivota ako druhe

public:
	
	Tank();
	Tank(int ammo, TANK_TYPE tankType, int rateOfFire,int health);

	virtual ~Tank()=0;//pure virtual



	virtual void Update(float elapsedTime);

	virtual void spawn(float x,float z);//prepisat v subclass

	void Draw(sf::RenderWindow& rw);


	Projectile* shoot(){
			ammo -= 1;
			return new Projectile(Point(GetPosition().x, GetPosition().y), DIRECTION_NORTH);
			
	}
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