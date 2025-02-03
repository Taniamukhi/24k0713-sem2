#include<iostream>
using namespace std;

struct employee{
	int employee_id;
	string employee_name;
	double employee_salary;
};

struct organisation{
	string organisation_name;
	string organisation_number;
	employee emp;
};

int main()
{
	organisation org;
	cout<< "Enter the organisation name: ";
	getline(cin, org.organisation_name);
	cout<< "Enter the organisation number: ";
	getline(cin, org.organisation_number);
	cout<< "Enter the employee id: ";
	cin>> org.emp.employee_id;
	cin.ignore();
	cout<< "Enter the employee name: ";
	getline(cin, org.emp.employee_name);
	cout<< "Enter the employee salary: ";
	cin>> org.emp.employee_salary;
	cin.ignore();
	
	cout<< "The size of structure organisation: "<< sizeof(org) << endl;
	cout << "Organisation name: "<< org.organisation_name << endl;
	cout << "Organisation number: "<< org.organisation_number << endl;
	cout << "Employee id: "<< org.emp.employee_id << endl;
	cout << "Employee name: "<< org.emp.employee_name << endl;
	cout << "Employee salary: "<< org.emp.employee_salary << endl;	
}
