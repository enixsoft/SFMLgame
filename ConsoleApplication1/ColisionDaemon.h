#pragma once
#include "GameObjectManager.h"
#include "VisibleGameObject.h"
#include <sstream>
#include <thread>


namespace explosionAnimation{
	//tato classa musi byt keby mame pozerat z kazdeho objektu samostatne kolizie vsetkyc hostatnych objektov program by proste nemal dostatok proceso
	/*Thread ktory bezi animaciu explozie , musi bezat mimo hlavneho a kolizneho.*/
	void runAnimationExplode(VisibleGameObject &vgo, GameObjectManager &objectManager,int j){
		//todo create thread
		try{
			//vgo.Load("images/explosion1_45x40.png");
			//Sleep(1000);
			//vgo.Load("images/explosion_2_56x56.png");
			//Sleep(1000);
			vgo.Load("images/explosion3_72x66.png");
			Sleep(1000);
		    objectManager.Remove(std::to_string(j));
		}
		catch (...){
			OutputDebugStringA("thread interrupt\n");
		}
	}

}


namespace colisionFunctions{

	using namespace explosionAnimation;

	void projectileTankColisionTask(GameObjectManager &objectManager){
		//Nekonecny loop
		while (true){
			OutputDebugStringA("threaaaad\n");
			//spanie threadu 50 milisekund
			try{
				Sleep(20);


				//loopuje cez projektily,projektily maju minusove IDcka
				for (int i = 1; i < objectManager.GetObjectCount(); i++){
					VisibleGameObject* projektil = objectManager.Get(std::to_string((i*-1)));//projektil

					//loopuje cez tanky , pozitivne idecka
					for (int j = 0; j < objectManager.GetObjectCount(); j++){

						//tank
						VisibleGameObject* vgoTank = objectManager.Get(std::to_string(j));
						//todo zmenit na bounds check nie na mid check , ohlad sa musi brat na vysku a sirku tanku
						if (vgoTank&&projektil){

							
							if (sf::Rect<int>(projektil->GetPosition().x, projektil->GetPosition().y, 16, 16).intersects(sf::Rect<int>(vgoTank->GetPosition().x, vgoTank->GetPosition().y, 67, 77))){
								OutputDebugStringA("TRAFENY");

								std::thread thread2(runAnimationExplode, std::ref(*vgoTank), std::ref(objectManager),j);
								thread2.detach();
								//vgoTank->Load("images/explosion3_72x66.png");
								//objectManager.Remove(std::to_string(j));
								//vgoTank->SetPosition(100, 100);
							}
						}
						
					}

				}

			}
			catch (...){
				std::cout << "Exception occurred";
				OutputDebugStringA("odchytene");
			}
		}
	}
}

using namespace colisionFunctions;

class ColisionDaemon{

private:




public:
	ColisionDaemon(){
	}
	~ColisionDaemon(){
	}
	ColisionDaemon(GameObjectManager &objectManager){
		/*Vytvorenie 2 threadov jeden pre checkovanie kolizie projektil tank druhy pre tank s tank*/

			//try catch block asi bude potrebny ak thread interupted
			//Pouzivanie ref()  aby mohol thread menit objekt
			std::thread thread1(projectileTankColisionTask, std::ref(objectManager));
			/*Thread detachnuty od main threadu*/
			thread1.detach();
			
		
			//std::thread thread2(tankTankColisionTask, std::ref(objectManager));
			//thread1.detach();
			OutputDebugStringW(L"------------------thread vytvoreny\n");

	}


};