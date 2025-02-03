#include<iostream>
#include<algorithm>
using namespace std;

struct student{
	string name;
	int id;
};

bool compare_student(const student& a, const student& b) {
    if (a.id != b.id) 
	{
        return a.id < b.id;
    }
    return a.name < b.name; 
}

int main()
{
	int N;
	int i;
	cout<< "Enter the number of total students: ";
	cin>> N;
	student stud[N];
	for(i=0; i<N; i++)
	{
		cout<< "Enter information about students "<< i+1 << ":\n";
		cout<< "id: ";
		cin>> stud[i].id;
		cin.ignore();
		cout<< "name: ";
		getline(cin, stud[i].name);
	}
	cout<< "Students information list:";
	for (int i = 0; i < N; i++)
	{
        cout<< "id: " << stud[i].id << ", Name: " << stud[i].name <<endl;
    }
    sort(stud, stud + N, compare_student);
    cout<< "Sorted list of students: ";
    for (i=0; i<N; i++)
	{
        cout<< "ID: " << stud[i].id << ", Name: " << stud[i].name << endl;
    }
}
