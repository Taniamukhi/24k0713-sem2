#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	string student_name;
	double test_scores[5];
	double average;
	double total=0.0;
	int i;
	
	cout << "Enter the student name: ";
	getline(cin, student_name);
	cout << "Enter the five test scores: ";
	for(i=0; i<5; i++)
	{
		cin >> test_scores[i];
		total += test_scores[i];
	}
	average = total/5;
	cout << "Student name:"<< student_name <<endl;
	cout<< "Test scores:";
	for(i=0; i<5; i++)
	{
		cout << fixed <<setprecision(2) << test_scores[i]<< " ";
	}
	cout <<endl;
    cout << "Average test score:"<< fixed <<setprecision(2) << average<<endl;
}
