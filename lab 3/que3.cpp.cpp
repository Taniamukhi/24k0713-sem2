#include<iostream>
using namespace std;

class glass{
	public:
		int liquid_level = 200;
		void drink(int milliliters){
			if(milliliters > 0)
			{
				liquid_level -= milliliters;
			}
			else
			{
				liquid_level = 0;
			}
			cout<< "You have drank "<< milliliters << "ml." << endl;
		
		if(liquid_level < 100)
		{
			refill();
		}
	}
		void refill()
		{
			liquid_level = 200;
			cout<< "Glass is refilled" << endl;
		}
};

int main()
{
	glass user_glass;
	int quantity;
	string command;
	cout << "Enter 'drink <quantity>' or 'exit' to stop the process" << endl;
	while(true){
		cout<< "Command: ";
		cin>> command;
		if(command == "drink")
		{
			cin>> quantity;
			user_glass.drink(quantity);
		}
		else if(command == "exit")
		{
			break;
		}
		else
		{
			cout<< "Invalid command" << endl;
		}
	}
}

