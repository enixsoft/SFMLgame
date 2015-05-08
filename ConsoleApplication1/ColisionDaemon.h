#pragma once
#include <thread>
#include "GameObjectManager.h"
//tato classa musi byt keby mame pozerat z kazdeho objektu samostatne kolizie vsetkyc hostatnych objektov program by proste nemal dostatok proceso
enum COLISION_THREAD_TYPE{
	COLISION_THREAD_PROJECTILE,COLISION_THREAD_TANKS
};

class ColisionDaemon{

private:

	COLISION_THREAD_TYPE threadType;

	void process(){//starts process of the thread
		switch (threadType){
			case COLISION_THREAD_PROJECTILE:{//scan projectile colision with objects
				while (true){//try catch block asi bude potrebny ak thread interupted
					
					Sleep(50);//sleeps for 50milisec OPTIM 

					//get locations of other objects and compare with mayne


					//for (int i = 1; i < Game::getObjectManager().GetObjectCount;i++){//scans player also might be problem when emmiting shoud start in safe range prolly 

					//}



				}
				break;
			}
			case COLISION_THREAD_TANKS:{//scan tank colision with player/barricades // player colision with objects like ammo , and tank colision with the bottom of the screen that invoke fail on stage
				while (true){
					Sleep(50);

				}
				break;
			}
		}
	}


public:

	ColisionDaemon(GameObjectManager objectManager, COLISION_THREAD_TYPE threadType){
		this->threadType = threadType;
	}
	~ColisionDaemon(){

	}

	int getThreadType(){
		return threadType;
	}

};