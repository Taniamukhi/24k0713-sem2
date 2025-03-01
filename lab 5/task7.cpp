#include<iostream>
#include<string>
using namespace std;

class student{
	private:
		const int rollno;
		string studentname;
	public:
		student(int num, string name) : rollno(num), studentname(name){
		}
		
		static student createstudent()
		{
			int roll;
			string name;
			cout<< "Enter student name: ";
			getline(cin, name);
			cout<< "Enter roll number of student: ";
			cin >> roll;
			return student(roll, name);
		}
		
		void display()
		{
			cout<< "Student name: "<< studentname << endl;
			cout<< "Roll number: "<< rollno << endl;
		}
};

int main()
{
	student s1 = student::createstudent();
	s1.display();
	return 0;
}
