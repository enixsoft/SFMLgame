#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"
#include <random>
#include <limits>

GameObjectManager::GameObjectManager()
{
	initSpawnPoints();
	spawnLocations[0] = Point(44,50);
	spawnLocations[1] = Point(157, 50);
	spawnLocations[2] = Point(271, 50);
	spawnLocations[3] = Point(384, 50);
	spawnLocations[4] = Point(498, 50);
	spawnLocations[5] = Point(611, 50);
	spawnLocations[6] = Point(725, 50);
	spawnLocations[7] = Point(838, 50);
	spawnLocations[8] = Point(952, 50);



	srand((unsigned int)time(NULL));//init point scan
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

std::string GameObjectManager::Add(VisibleGameObject* gameObject)//ak je tank pozitivne id ak je naboj negativne id
{
	//asi ciel bude pre projektily a tanky zvlast 

	if (Tank* t = dynamic_cast<Tank*>(gameObject)) {// nieco ako instanceof in java .. 
		//incrementuj tank id etc
		idCiel += 1;
		gameObject->setId(idCiel);
		std::string name = std::to_string(idCiel);//positive tanks//negative projectiles
		_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
		return std::to_string(idCiel);
	}
	else if (Projectile* t = dynamic_cast<Projectile*>(gameObject)){
		idCielProjectiles -= 1;
		gameObject->setId(idCielProjectiles);
		std::string name = std::to_string(idCielProjectiles);//positive tanks//negative projectiles
		_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
		return std::to_string(idCielProjectiles);
	}
	else{
		return std::to_string(std::numeric_limits<int>::max());
	}



	
	//gameObject->setId(idCiel);
	//std::string name =std::to_string(idCiel);//positive tanks//negative projectiles
	//_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
	//return std::to_string(idCiel);
}

void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;

}

int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::UpdateAll()
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr =
		_gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while (itr != _gameObjects.end())
	{
		itr->second->Update(timeDelta);
		itr++;
	}

	


}



