#include <iostream>
#include <string>
using namespace std;

class student {
protected:
    int id;
    string name;
public:
    void getstudentdetail() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }
    void displaystudentdetail() const {
        cout << "Student ID: " << id << "\n";
        cout << "Student Name: " << name << "\n";
    }
};

class marks : public student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;
public:
    void getmarks() {
        cout << "Enter marks of OOP: ";
        cin >> marks_oop;
        cout << "Enter marks of PF: ";
        cin >> marks_pf;
        cout << "Enter marks of DS: ";
        cin >> marks_ds;
        cout << "Enter marks of DB: ";
        cin >> marks_db;
    }
    void displaymarks() const {
        cout << "Marks in OOP: " << marks_oop << "\n";
        cout << "Marks in PF: " << marks_pf << "\n";
        cout << "Marks in DS: " << marks_ds << "\n";
        cout << "Marks in DB: " << marks_db << "\n";
    }
    int gettotalmarks() const {
        return marks_oop + marks_pf + marks_ds + marks_db;
    }
};

class result : public marks {
private:
    int totalmarks;
    double avgmarks;
public:
    void calculateresult() {
        totalmarks = gettotalmarks();
        avgmarks = totalmarks / 4.0; 
    }
    void displayresult() const {
        cout<< "Total Marks: " << totalmarks << "\n";
        cout<< "Average Marks: " << avgmarks << "\n";
    }
};

int main() {
    result student;
    student.getstudentdetail();
    student.getmarks();
    student.calculateresult();
    cout << "\nStudent Details\n";
    student.displaystudentdetail();
    cout << "\nMarks Obtained\n";
    student.displaymarks();
    cout << "\nFinal Result\n";
    student.displayresult();
    return 0;
}
