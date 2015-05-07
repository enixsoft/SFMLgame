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

	void Add(std::string name, VisibleGameObject* gameObject);
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
				Add(""+pTank->getId(), pTank);
				//OutputDebugStringW(L"LOOPIN IN GETFREELOC\n");
				//OutputDebu
				//PlayerTank* p=new PlayerTank;
				//Add(p->getId,p);
				break;
			}


		}


		

	}


	int getFreeLocation(){

		int randomNumber = rand() % 9;//init point scan
	
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

	


	void initSpawnPoints(){//vsetky lokacie validne
		for (int i = 0; i < (sizeof(spawnAvail) / sizeof(spawnAvail[0])); i++){
			spawnAvail[i] = true;
		}
	}

private:
	Point spawnLocations[9]; //y=768 + //original velktost tanku png
	bool spawnAvail[9];//spawn availability

	std::map<std::string, VisibleGameObject*> _gameObjects;
	sf::Clock clock;
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};


};
