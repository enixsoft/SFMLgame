#pragma once
#include "GameObjectManager.h"
#include <sstream>//fix na tostring not a member of namespace
#include "VisibleGameObject.h"
#include <thread>

//tato classa musi byt keby mame pozerat z kazdeho objektu samostatne kolizie vsetkyc hostatnych objektov program by proste nemal dostatok proceso
/*Thread ktory bezi animaciu explozie , musi bezat mimo hlavneho a kolizneho.*/
void runAnimationExplode(VisibleGameObject& vgo){
	//todo create thread
	vgo.Load("images/explosion1_45x40.png");
	Sleep(200);
	vgo.Load("images/explosion_2_56x56.png");
	Sleep(200);
	vgo.Load("images/explosion3_72x66.png");
}

void projectileTankColisionTask(GameObjectManager &objectManager){
	//Nekonecny loop
	while (true){
		//spanie threadu 50 milisekund
		Sleep(50);
		//loopuje cez projektily,projektily maju minusove IDcka
		for (int i = 0; i < objectManager.GetObjectCount;i++){
			VisibleGameObject* vgo = objectManager.Get(std::to_string((i*-1)));//projektil

			//loopuje cez tanky , pozitivne idecka
			for (int j = 0; j < objectManager.GetObjectCount; j++){

			//tank
			VisibleGameObject* vgoTank = objectManager.Get(std::to_string(j));
			//todo zmenit na bounds check nie na mid check , ohlad sa musi brat na vysku a sirku tanku
			if (vgo->GetPosition().y == vgoTank->GetPosition().y&&vgo->GetPosition().x == vgoTank->GetPosition().x){
				//vytvorenie noveho tready animacia explozie
				//zbavit sa objektu z game manageru

				//std::thread runAnimationExplode(runAnimationExplode, std::ref(vgo));//shared memory
				//delete objectManager.Get(std::to_string((i*-1)));// ak nepojde da sa ich len vyhodit zo sceny takze budu mimo oka uzivatela.. // neefektivne//sposoby pravedpodobmne crash
			}
		}
		
	}
}
//todo
void tankTankColisionTask(GameObjectManager &objectManager){
	while (true){
		

	}
}

class ColisionDaemon{

private:




public:
	ColisionDaemon(){
	}
	ColisionDaemon(GameObjectManager &objectManager){
		/*Vytvorenie 2 threadov jeden pre checkovanie kolizie projektil tank druhy pre tank s tank*/

			//try catch block asi bude potrebny ak thread interupted
			//Pouzivanie ref()  aby mohol thread menit objekt
			std::thread thread1(projectileTankColisionTask, std::ref(objectManager));
			/*Thread detachnuty od main threadu*/
			thread1.detach;

			std::thread thread2(tankTankColisionTask, std::ref(objectManager));
			thread1.detach;
		

	}


};