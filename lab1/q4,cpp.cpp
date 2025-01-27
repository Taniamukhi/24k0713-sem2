#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double weight_kg;
	double weight_lb;
	cout<<"Enter weight in kilograms(kg): "<<endl;
	cin>>weight_kg;
	weight_lb = weight_kg*2.2;
	cout <<fixed<<setprecision(2);
	cout << "Weight in kilograms: " << weight_kg<<"kg"<<endl;
    cout << "Equivalent weight in Pounds: " << weight_lb<<"lbs"<<endl;
	
}
