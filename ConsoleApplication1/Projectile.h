#pragma once
#include "VisibleGameObject.h"
#include "Point.h"
#include <Windows.h>

enum PROJECTILE_DIRECTION{
	DIRECTION_NORTH, DIRECTION_EAST, DIRECTION_SOUTH, DIRECTION_WEST//clockwise 0-3 // staci nam len juh a sever
};

class Projectile :public VisibleGameObject{

private:
	int id;
	float velocity=300;//does not need getters/setter
	PROJECTILE_DIRECTION projectileDirection;


public:

	Projectile(Point spawnPoint, PROJECTILE_DIRECTION emmitDirection){

		Load("images/bullet_16x16.png");
		assert(IsLoaded());//kontrola

		GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);//center origin on image

		if (emmitDirection == DIRECTION_NORTH){
			spawn(spawnPoint.getX(), spawnPoint.getY() - 38.5, emmitDirection);
		}
		else{
			spawn(spawnPoint.getX(), spawnPoint.getY() + 38.5, emmitDirection);
		}
		

		//after spawn fly straight till next object encountered or out of bounds
		

		//check whether or not position at the edge then destory object

	}
	~Projectile(){

	}

	void spawn(float x, float y, PROJECTILE_DIRECTION projectileDirection){//not inhereted ! just same name as other ones//todo change on point//spawns projectile
		SetPosition(x,y);
		this->projectileDirection = projectileDirection;
	}

	void Update(float elapsedTime){//neviem ci by nebol lepsi background daemon thread ktory by skenoval pozicie objektov z objekt manageru a staral sa o koliziu medzi nimi
	
		switch (projectileDirection){
			//	DIRECTION_NORTH, DIRECTION_EAST, DIRECTION_SOUTH, DIRECTION_WEST//clockwise 0-3
		case DIRECTION_NORTH:{
				if (!(GetPosition().y < -100)){//ak sa nachadzam hore
					GetSprite().move(0, (velocity*elapsedTime)*-1);
				}
				else{
					//delete this;//nesom si isty
				}
				break;
			}
			case DIRECTION_EAST:{//not to be implemented

				break;
			}
			case DIRECTION_SOUTH:{
				if (!(GetPosition().y >=868)){//ak sa nachadzam hore
					GetSprite().move(0, velocity * elapsedTime);
				}
				else{
					
				}
				break;
			}
			case DIRECTION_WEST:{//not to be implemented

				break;
			}



		}//end switch
	}//end meth

	void setId(int id){
		if (id<0){
			this->id = id;
		}
	}
	int getId(){
		return id;
	}

};