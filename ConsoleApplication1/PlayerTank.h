#pragma once
#include "VisibleGameObject.h"
#include "Tank.h"

enum SCORE_VALUES{
	//hodnoty score
	TANK_LIGHT = 10,
	TANK_MEDIUM = 15,
	TANK_HEAVY = 30,
	STREAK_10 = 10,
	STREAK_20 = 20,
	STREAK_30 = 30,
	LEVEL_PASS=100,
	LEVEL_FAILURE=-300

};

class PlayerTank :public Tank
{

private:
	

	int score=0;//defaultna hodnota 0
	int numberOfDeaths=0;
	int numberOfLives = 3;//neviem spravime to tak?
	int streak = 0;//nuluje sa ak hrac umrie , pocet tankov hrac znicil bez umretia

public:
	PlayerTank();//def hod

	PlayerTank(int ammo, TANK_TYPE tankType, int rateOfFire, int health,int score,int numberOfeaths,int numberOfLives,int streak) :Tank(ammo, tankType, rateOfFire, health){
		setScore(score);
		setNumberOfDeaths(numberOfDeaths);
		setNumberOfLives(numberOfLives);
		setStreak(streak);


		Load("images/PlayerTank_64x77.png");//podla typu davat obrazok//nemusi to tu byt

		assert(IsLoaded());//kontrola

		setVelocity(0);
		setMaxVelocity(600.0f);
		GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
		//GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);
		
		spawn((1024 / 2) - 45, 700);//nastav hraca dole v strede

		//nastavenie obrazku
		//setImageName("PlayerTank.png");
	   //Load(getImageName());
	}

	//~PlayerTank();

	void Update(float elapsedTime);

	//zvysenie skora / moze byt aj negativnou hodnotou pokial hrac umre a neprejde level alebo take nieco
	void increaseScore(int score);
	void increaseScore(SCORE_VALUES score);



	virtual void spawn(float x,float z){//create spawn manager
		SetPosition(x,z);
	}

	void respawn();//player hit = vola sa metoda respawn


	//getters/setters
	void setScore(int score){
		(score > 1 && score < std::numeric_limits<int>::max()) ? this->score = score : this->score = this->score;
	}
	int getScore(){
		return score;
	}
	void setNumberOfDeaths(int numberOfDeaths){
		(numberOfDeaths >= 0) ? this->numberOfDeaths = numberOfDeaths : 0;
	}
	int getNumberOfDeaths(){
		return numberOfDeaths;
	}
	void setNumberOfLives(int numberOfLives){
		this->numberOfLives = numberOfLives;
	}
	void setStreak(int streak){
		if (streak > 0){
			(streak > 30) ? 1 : this->streak = streak;
		}
		else{
			streak = 0;
		}
	}
	int getStreak(){
		return streak;
	}

};
