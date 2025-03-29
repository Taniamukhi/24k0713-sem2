#include <iostream>
using namespace std;

class Person {
protected:
    int empID;
public:
    void getData() {
        cout<< "Enter Employee ID: ";
        cin>> empID;
    }
    void displayData() const {
        cout<< "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    double monthly_income;
public:
    void getData() {
        Person::getData();
        cout<< "Enter Name: ";
        cin>> name;
        cout<< "Enter Monthly Income: ";
        cin>> monthly_income;
    }
    double bonus() const {
        return monthly_income * 12 * 0.05;
    }
    void displayData() const {
        Person::displayData();
        cout<< "Name: " << name << endl;
        cout<< "Monthly Income: " << monthly_income << endl;
        cout<< "Annual Bonus: " << bonus() << endl;
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthly_income;
public:
    void getData() {
        Person::getData();
        cout<< "Enter Name: ";
        cin>> name;
        cout<< "Enter Monthly Income: ";
        cin>> monthly_income;
    }
    double bonus() const {
        return monthly_income * 12 * 0.05;
    }
    void displayData() const {
        Person::displayData();
        cout<< "Name: " << name << endl;
        cout<< "Monthly Income: " << monthly_income << endl;
        cout<< "Annual Bonus: " << bonus() << endl;
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;
    cout<< "Enter Admin Employee Details:\n";
    adminEmp.getData();
    cout<< "\nEnter Accounts Employee Details:\n";
    accountsEmp.getData();
    cout<< "\nAdmin Employee Information:\n";
    adminEmp.displayData();
    cout<< "\nAccounts Employee Information:\n";
    accountsEmp.displayData();
    return 0;
}
