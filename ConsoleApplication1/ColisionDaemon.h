#pragma once
#include "GameObjectManager.h"
#include <sstream>//fix na tostring not a member of namespace
#include "VisibleGameObject.h"
#include <thread>

//tato classa musi byt keby mame pozerat z kazdeho objektu samostatne kolizie vsetkyc hostatnych objektov program by proste nemal dostatok proceso
void runAnimationExplode(VisibleGameObject& vgo){
	vgo.Load("images/explosion1_45x40.png");
	Sleep(200);
	vgo.Load("images/explosion_2_56x56.png");
	Sleep(200);
	vgo.Load("images/explosion3_72x66.png");
}

void projectileTankColisionTask(GameObjectManager &objectManager){
	while (true){
		Sleep(50);
		
		for (int i = 0; i < objectManager.GetObjectCount;i++){//loop thru projectiles
			VisibleGameObject* vgo = objectManager.Get(std::to_string((i*-1)));//projektil

			for (int j = 0; j < objectManager.GetObjectCount; j++){//loop thru tanks

			VisibleGameObject* vgoTank = objectManager.Get(std::to_string(j));//tank
			if (vgo->GetPosition().y == vgoTank->GetPosition().y&&vgo->GetPosition().x == vgoTank->GetPosition().x){//tolerancia  na bounds musi byt asi... a nie na jeden pixel//sirga vyska tanku /2
				//create new thread that makes exploding animation parameter visible object pointer
				//Load(std::string filename);
				//std::thread runAnimationExplode(runAnimationExplode, std::ref(vgo));//shared memory
				delete objectManager.Get(std::to_string((i*-1)));// ak nepojde da sa ich len vyhodit zo sceny takze budu mimo oka uzivatela.. // neefektivne
				
			}
		}
		
	}
}

void tankTankColisionTask(GameObjectManager &objectManager){
	while (true){
		//Sleep(50);

	}
}

class ColisionDaemon{

private:




public:
	ColisionDaemon(){
	}
	ColisionDaemon(GameObjectManager &objectManager){

			//try catch block asi bude potrebny ak thread interupted
			std::thread thread1(projectileTankColisionTask, std::ref(objectManager));
			thread1.detach;

			std::thread thread2(tankTankColisionTask, std::ref(objectManager));
			thread1.detach;
			//get locations of other objects and compare with mayne


			//for (int i = 1; i < Game::getObjectManager().GetObjectCount;i++){//scans player also might be problem when emmiting shoud start in safe range prolly 

			//}

		

				//Sleep(50);

	}


};