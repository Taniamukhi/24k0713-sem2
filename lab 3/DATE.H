#define DATE_H
#include<iostream>
using namespace std;

class date{
	private:
		int month;
		int day;
		int year;
		
		public:
			int display_date()
			{
				cout<< month << "/" << day << "/" << year;
			}
			
			int get_month()
			{
				return month;
			}
			
			int get_day()
			{
				return day;
			}
			
			int get_year()
			{
				return year;
			}
			
			void set_month(int m)
			{
				month=m; 
			}
			
			void set_day(int d)
			{
				day=d; 
			}
			
			void set_year(int y)
			{
				year=y; 
			}
};
