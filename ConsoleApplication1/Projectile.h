#pragma once
#include "VisibleGameObject.h"
#include "Point.h"
enum PROJECTILE_DIRECTION{
	DIRECTION_NORTH, DIRECTION_EAST, DIRECTION_SOUTH, DIRECTION_WEST//clockwise 0-3 // staci nam len juh a sever
};

class Projectile :public VisibleGameObject{

private:
	float velocity=300;//does not need getters/setter
	PROJECTILE_DIRECTION projectileDirection;


public:

	Projectile(Point spawnPoint, PROJECTILE_DIRECTION emmitDirection){

		Load("images/bullet_16x16.png");
		assert(IsLoaded());//kontrola

		GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);//center origin on image

		spawn(spawnPoint.getX(), spawnPoint.getY(), emmitDirection);
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
				if (!(GetPosition().y <= 0)){//ak sa nachadzam hore
					GetSprite().move(0, velocity * elapsedTime);
				}
				else{
					delete this;//nesom si isty
				}
				break;
			}
			case DIRECTION_EAST:{//not to be implemented

				break;
			}
			case DIRECTION_SOUTH:{
				if (!(GetPosition().y >=768)){//ak sa nachadzam hore
					GetSprite().move(0, velocity * elapsedTime);
				}
				else{
					delete this;//nesom si isty
				}
				break;
			}
			case DIRECTION_WEST:{//not to be implemented

				break;
			}



		}//end switch
	}//end meth


};