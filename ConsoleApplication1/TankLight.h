#pragma once
#include "VisibleGameObject.h"
#include "Point.h"
#include "Tank.h"
#include <Windows.h>
#include <random>
class TankLight :public Tank{

private:

public:
	TankLight():Tank(){

	}
	TankLight(Point spawnPoint) :Tank(){//TODO nedokoncene 

		Load("images/tankLight_67x77.png");
		assert(IsLoaded());//kontrola

		//nahodna rychlost nastavena tanku
		setVelocity((rand() % 20)+30);

		GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
		//otocenie tanku aby celil smeru hraca
		GetSprite().rotate(180);
		spawn(spawnPoint.getX(), spawnPoint.getY());
	}
	~TankLight(){

	}


	
	virtual void spawn(float x, float z){
		SetPosition(x, z);
	}

	void Update(float elapsedTime){
		//ak sa nachadzam hore
		if (!(GetPosition().y > (768+100))){
			GetSprite().move(0, (GetVelocity()*elapsedTime));
		}
		else{
			//delete 
		}
	}

	

};