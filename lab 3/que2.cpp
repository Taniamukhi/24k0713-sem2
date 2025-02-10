#include<iostream>
#include "DATE.H"
using namespace std;

int main()
{
	date mydate;
	mydate.set_month(2);
	mydate.set_day(4);
	mydate.set_year(2025);
	cout<< "Date is: ";
	mydate.display_date();
}
