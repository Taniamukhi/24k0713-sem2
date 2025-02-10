#include<iostream>
using namespace std;

class employee{
	private:
		string first_name;
	    string last_name;
	    double monthly_salary;
	    
	    public:
	    	employee(){
	    		first_name= " ";
	    		last_name= " ";
	    		monthly_salary= 0.0;
			}
			
			void setfirst_name(string fname){
				first_name = fname;
			}
			
			void setlast_name(string lname){
				last_name = lname;
			}
			
			void setmonthly_salary(double salary){
				if (salary>0)
				{
					monthly_salary= salary;
				}
				else
				{
					monthly_salary = 0.0; 
				}
			}
			
			string getfirst_name()
			{
				return first_name;
			}
			
			string getlast_name()
			{
				return last_name;
			}
			
			double getmonthly_salary()
			{
				return monthly_salary;
			}
			
			double getyearly_salary()
			{
				return monthly_salary*12;
			}
			
			void give_rise()
			{
				monthly_salary *= 1.10;
			}
	    	
};

int main()
{
	employee e1, e2;
	e1.setfirst_name("Asif");
	e1.setlast_name("Ali");
	e1.setmonthly_salary(40000.0);
	e2.setfirst_name("Rabia");
	e2.setlast_name("Faisal");
	e2.setmonthly_salary(20000);
	cout<< e1.getfirst_name() << " " << e1.getlast_name() << "'s yearly salary: " << e1.getyearly_salary() << endl;
	cout<< e2.getfirst_name() << " " << e2.getlast_name() << "'s yearly salary: " << e2.getyearly_salary() << endl;
}
