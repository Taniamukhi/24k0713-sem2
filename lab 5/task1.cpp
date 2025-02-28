#include<iostream>
using namespace std;

class Engine{
	private:
		bool isrunning;
	public:
		Engine() : isrunning(false){
		}
		
		void start(){
			if(!isrunning){
				isrunning = true;
				cout<< "An engine is started" << endl;
			}
			else
			{
				cout<< "An engine is running...." << endl;
			}
		}
		
		void stop()
		{
			if(isrunning)
			{
				isrunning = false;
				cout<< "An engine is stopped." << endl;
			}
			else
			{
				cout<< "An engine is already stopped." << endl;
			}
		}
};

class Car{
	private:
		Engine engine;
	public:
		void startcar(){
			cout<< "Car is starting..." << endl;
			engine.start();
		}
		
		void stopcar(){
			cout<< "Car stopped..." << endl;
			engine.stop();
		}
};

int main()
{
	Car car;
	car.startcar();
	car.stopcar();
	return 0;
}
