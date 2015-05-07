#pragma once
#include "VisibleGameObject.h"
#include "Point.h"
#include "Tank.h"


class TankLight :public Tank{

private:

public:
	TankLight():Tank(){

	}
	TankLight(Point spawnPoint) :Tank(){//TODO nedokoncene 

		Load("images/tankLight_67x77.png");
		assert(IsLoaded());//kontrola

		//kokotina
		setVelocity(0);
		setMaxVelocity(600.0f);
		//end kokotina

		GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
		GetSprite().rotate(180);
		spawn(spawnPoint.getX(), spawnPoint.getY());
	}
	~TankLight(){

	}


	virtual void spawn(float x, float z){
		SetPosition(x, z);
	}


};