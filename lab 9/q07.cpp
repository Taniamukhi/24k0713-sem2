#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata() {
        cout<< "Enter name: ";
        cin>> name;
        cout<< "Enter age: ";
        cin>> age;
    }

    virtual void displaydata() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    virtual void bonus() = 0;  
};

class Admin : virtual public Person {
protected:
    float salary;
public:
    void getdata() {
        Person::getdata();
        cout<< "Enter Admin salary: ";
        cin>> salary;
    }

    void displaydata() {
        Person::displaydata();
        cout<< "Admin Salary: " << salary << endl;
    }

    void bonus() {
        cout<< "Admin Bonus: " << salary * 0.20 << endl;
    }
};

class Account : virtual public Person {
protected:
    float salary;
public:
    void getdata() {
        Person::getdata();
        cout<< "Enter Account salary: ";
        cin>> salary;
    }

    void displaydata() {
        Person::displaydata();
        cout<< "Account Salary: " << salary << endl;
    }

    void bonus() {
        cout<< "Account Bonus: " << salary * 0.10 << endl;
    }
};

class Master : public Admin, public Account {
	private:
		float salary;
public:
    void getdata() {
        Person::getdata();
        cout<< "Enter Master salary: ";
        cin >> salary;
    }

    void displaydata() {
        Person::displaydata();
        cout<< "Master Salary: " << salary << endl;
    }

    void bonus() {
        cout<< "Master Bonus: " << salary * 0.30 << endl;
    }
};

int main() {
    Person* emp;
    cout << "\n== Admin Employee ==\n";
    Admin admin;
    emp = &admin;
    emp->getdata();
    emp->displaydata();
    emp->bonus();
    cout << "\n== Account Employee ==\n";
    Account acc;
    emp = &acc;
    emp->getdata();
    emp->displaydata();
    emp->bonus();
    cout << "\n== Master Employee ==\n";
    Master master;
    emp = &master;
    emp->getdata();
    emp->displaydata();
    emp->bonus();
    return 0;
}
