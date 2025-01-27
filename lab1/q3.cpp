#include<iostream>
using namespace std;

int main()
{
	int customer_id;
	string customer_name;
	int units_consumed;
	double chargeperunit;
	double sur_charge = 0.0;
	
	cout<<"Enter the customer id: "<<endl;
	cin>>customer_id;
	cout<<"Enter the customer name: "<<endl;
	cin>>customer_name;
	cout<<"Enter the units consumed: "<<endl;
	cin>>units_consumed;
	
	if(units_consumed<=199)
	{
		chargeperunit=16.20;
	}
	else if(units_consumed>=200 && units_consumed<300)
	{
		chargeperunit=20.10;
	}
	else if(units_consumed>=300 && units_consumed<500)
	{
		chargeperunit=27.10;
	}
	else
	{
		chargeperunit=35.90;
	}
	double total_amount= units_consumed*chargeperunit;
	if(total_amount > 18000)
	{
		sur_charge=total_amount*0.15;
	}
	
	double net_amount= total_amount + sur_charge;
	
	cout<<"Customer ID : "<<customer_id<<endl;
	cout<<"Customer Name : "<<customer_name<<endl;
	cout<<"Units Consumed : "<<units_consumed<<endl;
	cout<<"Amount charge @Rs."<<chargeperunit<<"per unit:"<<total_amount<<endl;
	cout<<"Surcharge Amount : "<<sur_charge<<endl;
	cout<<"Net Amount Paid by the Customer : "<<net_amount<<endl;
	
}
