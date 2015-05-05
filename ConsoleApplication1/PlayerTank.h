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
	


	int ammo=20;//only for player  spawned = unlimited
	int score=0;//defaultna hodnota 0
	int numberOfDeaths=0;
	int numberOfLives = 3;//neviem spravime to tak?
	int streak = 0;//nuluje sa ak hrac umrie , pocet tankov hrac znicil bez umretia

public:
	PlayerTank();
	//~PlayerTank();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	//zvysenie skora / moze byt aj negativnou hodnotou pokial hrac umre a neprejde level alebo take nieco
	void increaseScore(int score);
	void increaseScore(SCORE_VALUES score);


	void respawn();//player hit = vola sa metoda respawn


	//getters/setters
	void setScore(int score){
		(score > 1 && score < std::numeric_limits<int>::max()) ? this->score = score : this->score = this->score;
	}
	int getScore(){
		return score;
	}
	



};
