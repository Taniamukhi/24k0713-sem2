#include<iostream>
#include<vector>
using namespace std;

class person {
protected:
    string name, id, address, phonenumber, email;
public:
    person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phonenumber(p), email(e) {}
    
     string getname() const
     { 
         return name; 
         
     }
     
    virtual void displayinfo() {
        cout<< "Name: " << name << endl;
		cout<< "ID: " << id << endl;
		cout<< "Address: " << address << endl;
        cout<< "Phone: " << phonenumber << endl;
		cout<< "Email: " << email << endl;
    }

    virtual void updateinfo(string newaddress, string newphonenumber, string newemail) {
        address = newaddress;
        phonenumber = newphonenumber;
        email = newemail;
    }

    virtual ~person() {}
};

class student : public person {
private:
    vector<string> coursesenrolled;
    double GPA;
    int enrollmentyear;
public:
    student(string n, string i, string a, string p, string e, int year) : person(n, i, a, p, e), enrollmentyear(year), GPA(0.0) {}

    void enrollcourse(string course) {
        coursesenrolled.push_back(course);
    }

    void updateGPA(double newGPA) {
        GPA = newGPA;
    }

    void displayinfo() override {
        person::displayinfo();
        cout<< "Enrollment Year: " << enrollmentyear << "\nGPA: " << GPA << "\nCourses Enrolled: ";
        for (const string& course : coursesenrolled) {
            cout<< course << " ";
        }
        cout<< endl;
    }
};

class professor : public person {
private:
    string department;
    vector<string> coursestaught;
    double salary;
public:
    professor(string n, string i, string a, string p, string e, string dept, double sal) : person(n, i, a, p, e), department(dept), salary(sal) {}

    void addcourse(string course) {
        coursestaught.push_back(course);
    }

    void updatesalary(double newsalary) {
        salary = newsalary;
    }

    void displayinfo() override {
        person::displayinfo();
        cout<< "Department: " << department << endl;
		cout<< "Salary: $" << salary << endl;
        cout<< "\nCourses Taught: ";
        for (const string& course : coursestaught) {
            cout<< course << " ";
        }
        cout<< endl;
    }
};

class staff : public person {
private:
    string department, position;
    double salary;
public:
    staff(string n, string i, string a, string p, string e, string dept, string pos, double sal) : person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void updatesalary(double newsalary) {
        salary = newsalary;
    }

    void displayinfo() override {
        person::displayinfo();
        cout << "Department: " << department << endl;
		cout<< "\nPosition: " << position << endl;
        cout<< "\nSalary: $" << salary << endl;
    }
};

class course {
private:
    string courseid, coursename, instructor;
    int credit;
    vector<student*> enrolledstudents;
public:
    course(string id, string name, int cr, string instr) : courseid(id), coursename(name), credit(cr), instructor(instr) {}

    void registerstudent(student* student) {
        enrolledstudents.push_back(student);
        student->enrollcourse(coursename);
    }

    void displaycourseinfo() {
        cout << "course ID: " << courseid << endl;
		cout<< "course Name: " << coursename << endl; 
        cout<< "Instructor: " << instructor << endl;
		cout<< "Credits: " << credit << endl; 
        cout<< "Enrolled students: ";
        for (student* s : enrolledstudents) {
            cout<< s->getname() << " ";
        }
        cout<< endl;
    }
};

int main() {
    student s1("Ali Khan", "S1002", "456 Elm St", "555-4321", "ali@email.com", 2022);
    professor p1("Dr. Ahmed", "P2002", "12 University Rd", "555-9876", "ahmed@university.com", "Mathematics", 92000);
    staff st1("Zubair Ali", "ST3003", "202 Library Rd", "555-7654", "zubair@university.com", "Library", "Librarian", 55000);  
    course c1("CS101", "Introduction to Programming", 3, "Dr. Smith");
    c1.registerstudent(&s1);    
    cout << "--- student Info ---\n";
    s1.displayinfo();    
    cout << "\n--- professor Info ---\n";
    p1.displayinfo();   
    cout << "\n--- staff Info ---\n";
    st1.displayinfo();
    cout << "\n--- course Info ---\n";
    c1.displaycourseinfo();
    return 0;
}
