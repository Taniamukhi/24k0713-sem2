#include<iostream>
#include<vector>
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
		string name;
		int id;
	public:
		Car(string car_name, int car_id): name(car_name), id(car_id) {
		}
		
		string getname() const
		{
			return name;
		}
		
		int getid() const
		{
			return id;
		}
		
		void startcar(){
			cout<< "Car is starting..." << endl;
			engine.start();
		}
		
		void stopcar(){
			cout<< "Car stopped..." << endl;
			engine.stop();
		}
};

class Garage{
	private:
		vector<Car*>cars;
	public:
		void parkcar(Car* car){
			cars.push_back(car); 
		
		}
		
		void listcar() {
			cout<< "Cars in the garage : " << endl;
			for(const auto* car : cars){
				cout<< ".Car's id: "<< car->getid() << endl;
				cout<< "Car's name: "<< car->getname() << endl;
			}
		}
};

int main()
{
	Car car("Rolax", 12);
	car.startcar();
	car.stopcar();
	
	Car car1("abc", 2);
	Car car2("wwe", 3);
	Garage garage;
	garage.parkcar(&car1);
	garage.parkcar(&car2);
	garage.listcar();
	return 0;
}
