#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	string movie_name;
	double adult_ticketprice;
	double child_ticketprice;
	int adult_ticketssold;
	int child_ticketssold;
	double gross_amount;
	double amount_donated;
	double percent_donated;
	double net_sale;	
	cout<<"Enter the movie name: "<<endl;
	getline(cin, movie_name);
    cout <<"Enter price of an adult ticket: ";
    cin >>adult_ticketprice;
    cout <<"Enter price of a child ticket: ";
    cin >>child_ticketprice;
    cout <<"Enter the number of adult tickets sold: ";
    cin >>adult_ticketssold;
    cout <<"Enter the number of child tickets sold: ";
    cin >>child_ticketssold;
    cout <<"Enter the percentage of the gross amount to be donated: ";
    cin >>percent_donated;
    
    gross_amount=(adult_ticketssold*adult_ticketprice)+(child_ticketssold*child_ticketprice);    
	amount_donated=gross_amount*(percent_donated/100);
    net_sale=gross_amount-amount_donated;
    cout <<endl;
    cout <<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout <<"Movie Name:..........................."<<movie_name<<endl;
    cout <<"Number of Tickets Sold:..............."<<adult_ticketssold+child_ticketssold<<endl;
    cout <<"Gross Amount:.........................$"<<fixed<<setprecision(2)<<gross_amount<<endl;
    cout <<"Percentage of Gross Amount Donated:..."<<fixed<<setprecision(2)<<percent_donated<<"%"<<endl;
    cout <<"Amount Donated:.......................$"<<fixed<<setprecision(2)<<amount_donated<<endl;
    cout <<"Net Sale:.............................$"<<fixed<<setprecision(2)<<net_sale<<endl;
}
