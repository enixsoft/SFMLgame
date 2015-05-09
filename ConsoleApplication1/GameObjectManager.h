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
				OutputDebugStringW(L"------------------TANK VYTVORENY\n");
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
			OutputDebugStringW(L"LOOPIN IN GETFREELOC\n");
			if (randomNumber == 9){//ak za poslednou skoc na zaciatok
				randomNumber = 0;
				OutputDebugStringW(L"rovna sa 9\n");
			}
			if (spawnAvail[randomNumber]){
				OutputDebugStringW(L"spawn najdeny\n");
				break;
			}
			randomNumber++;
			OutputDebugStringW(L"spawn je bloknuty\n");
		}
		OutputDebugStringW(L"blokujem spawn\n");
		spawnAvail[randomNumber] = false;
		return randomNumber;

	}

	


	void initSpawnPoints(){//vsetky lokacie validne
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

	int idCiel=-1;//-1 lebo 0 je pre hraca ktory podje do manageru ako prvy
	int idCielProjectiles = 0;//will go to negative nums

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
