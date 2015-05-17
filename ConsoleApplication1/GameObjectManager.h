#pragma once
#include "VisibleGameObject.h"
#include "Point.h"
#include "TankLight.h"
#include <random>
#include "Windows.h"

class GameObjectManager
{
public:
	

	GameObjectManager();
	~GameObjectManager();

	std::string Add(VisibleGameObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);
	void GameObjectManager::UpdateAll();


	//spawn(GetSprite().getScale().x / 2, GetSprite().getScale().x / 2);
	//	GetSprite().setOrigin(x,z);//spawn dole v strede
	void spawnEnemyTank(TANK_TYPE tankType){

		Point freeLoc = spawnLocations[getFreeLocation()];
		
		switch (tankType){
			case LIGHT:{
				TankLight* pTank = new TankLight(freeLoc);//pouzit iny konstruktor
				Add(pTank);
				break;
			}


		}


		

	}

	/*Nachadza volnu lokaciu pre spawn tanku*/
	int getFreeLocation(){
		//bod od ktoreho zacina skenovat pre volnu lokaciu, musi byt nahodne inak by to vyzeralo zle po zniceni tanku.
		int randomNumber = rand() % 9;
	
			
		while(true){
			if (randomNumber == 9){//ak za poslednou skoc na zaciatok
				randomNumber = 0;
			}
			if (spawnAvail[randomNumber]){
				break;
			}
			randomNumber++;
		}
		spawnAvail[randomNumber] = false;
		return randomNumber;

	}

	

	//vsetky lokacie validne
	void initSpawnPoints(){
		for (int i = 0; i < 9; i++){
			spawnAvail[i] = true;
		}
	}

	int getIdCiel(){
		return idCiel;
	}
	int getIdCielProjectiles(){
		return idCielProjectiles;
	}
private:
	//drzi vrch doteraz pritomnych id na scene , pre tanky
	int idCiel=-1;//-1 lebo 0 je pre hraca ktory podje do manageru ako prvy


	int idCielProjectiles = 0;//ide do negativnych hodnot

	//9 spawn lokacii defaultne , inicializovane v kontruktory
	Point spawnLocations[9]; //y=768 + //original velkost tanku png

	//dostupnost lokacii false, zmeni sa v kontruktore na true
	bool spawnAvail[9];//spawn availability

	std::map<std::string, VisibleGameObject*> _gameObjects;
	sf::Clock clock;

	//dealokuje miest opre objekty, vola ich kontruktory.
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};


};
