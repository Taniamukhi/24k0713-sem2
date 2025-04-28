#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    string designation;
    int yearsofservice;
};

int loademployees(const string& filename, Employee employees[]) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout<< "Error opening file for reading!" << endl;
        return 0;
    }
    int count = 0;
    string line;
    while (getline(fin, line) && count < MAX_EMPLOYEES) {
        stringstream ss(line);
        ss >> employees[count].id >> employees[count].name >> employees[count].designation >> employees[count].yearsofservice;
        count++;
    }
    fin.close();
    return count; 
}

void saveemployees(const string& filename, Employee employees[], int count) {
    ofstream fout(filename.c_str());
    if (!fout) {
        cout<< "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        fout<< employees[i].id << " " << employees[i].name << " " << employees[i].designation << " " << employees[i].yearsofservice << endl;
    }
    fout.close();
}

void createdummydata(const string& filename) {
    ofstream fout(filename.c_str());
    fout<< "1 Ali Manager 3\n";
    fout<< "2 Aslam Clerk 1\n";
    fout<< "3 Chand Manager 1\n";
    fout<< "4 David CEO 5\n";
    fout<< "5 Akbar Manager 4\n";
    fout.close();
}

int main() {
    string filename = "employees.txt";
    createdummydata(filename);
    Employee employees[MAX_EMPLOYEES];
    int employeecount = loademployees(filename, employees);
    Employee filtered[MAX_EMPLOYEES];
    int filteredcount = 0;
    for (int i=0; i<employeecount; i++) {
        if (employees[i].designation == "Manager" && employees[i].yearsofservice >= 2) {
            filtered[filteredcount++] = employees[i];
        }
    }
    cout<< "Filtered Employees (Manager with >=2 years):" << endl;
    for (int i=0; i<filteredcount; i++) {
        cout << filtered[i].id << " " << filtered[i].name << " " << filtered[i].designation << " " << filtered[i].yearsofservice << endl;
    }
    saveemployees(filename, filtered, filteredcount);
    for (int i=0; i<filteredcount; i++) {
        filtered[i].id += 100; 
        filtered[i].yearsofservice += 1; 
    }
    saveemployees(filename, filtered, filteredcount);
    cout<< "\nData updated with incremented IDs and years of service.\n";
    return 0;
}
