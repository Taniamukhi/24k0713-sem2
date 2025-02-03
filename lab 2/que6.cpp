#include<iostream>
#include<vector>
using namespace std;

struct subject{
	string subject_name;
};

struct student{
	int id;
	vector<subject> subjects;
};

int main()
{
	int numb_students;
	cout<< "Enter the number of totaal students: ";
    cin>> numb_students;
    vector<student> students(numb_students);
    int i;
    for(i=0; i<numb_students; i++)
    {
    	cout<< "Enter information of students " << i+1 << ":" <<endl;
        cout<< "id: ";
        cin>> students[i].id;
        int numb_subjects;
        cout<< "Enter the number of subjects" << i+1 << ": ";
        cin>> numb_subjects;
        cin.ignore(); 
        int j;
        for (j=0; j<numb_subjects; j++)
		{
            subject sub;
            cout << "Enter name of subject " << j+1 << ": ";
            getline(cin, sub.subject_name);
            students[i].subjects.push_back(sub);
        }
    }
    	cout<< "Student Details:\n";
		for (const auto& student : students) {
        cout<< "ID: " << student.id << endl;
        cout<< "Subjects: " << endl;
        for (const auto& subject : student.subjects) {
            cout << "  - " << subject.subject_name << endl;
        }
        cout<< endl;
    }
}