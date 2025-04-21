#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;
public:
    Student(string n, int i) : name(n), id(i) {}

    virtual float gettuition(string status, int creditHours) = 0;

    virtual void display() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }

    virtual ~Student() {} 
};

class Graduatestudent : public Student {
private:
    string researchtopic;
public:
    Graduatestudent(string n, int i, string topic) : Student(n, i), researchtopic(topic) {}

    void setresearchtopic(string topic) {
        researchtopic = topic;
    }

    string getresearchtopic() const {
        return researchtopic;
    }

    float gettuition(string status, int creditHours) override {
        if (status == "undergraduate")
            return creditHours * 200;
        else if (status == "graduate")
            return creditHours * 300;
        else if (status == "doctoral")
            return creditHours * 400;
        else {
            cout<< "Invalid status.\n";
            return 0;
        }
    }

    void display() override {
        Student::display();
        cout<< "Research Topic: " << researchtopic << endl;
    }
};

int main() 
{
    Graduatestudent g1("Ali", 713, "Quantum Computing");
    g1.display();
    int credits = 8;
    float tuition = g1.gettuition("graduate", credits);
    cout<< "Tuition for " << credits << " credit hours: $" << tuition << endl;
    return 0;
}
