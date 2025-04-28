#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const string TASK_FILE = "tasks.txt";
const int MAX_TASKS = 100; 

void addtask() {
    string task;
    cout<< "Enter the task: ";
    getline(cin >> ws, task);
    ofstream fout(TASK_FILE, ios::app);
    if (fout.is_open()) {
        fout << task << endl;
        fout.close();
        cout<< "Task added successfully." << endl;
    } else {
        cout<< "Error opening file to add task." << endl;
    }
}

void viewtasks() {
    ifstream fin(TASK_FILE);
    if (!fin.is_open()) {
        cout<< "No tasks found." << endl;
        return;
    }
    string task;
    int count = 1;
    cout<< "\nYour Tasks: " << endl;
    while (getline(fin, task)) {
        cout<< count << ". " << task << endl;
        count++;
    }
    fin.close();
}

void marktaskdone() {
    ifstream fin(TASK_FILE);
    if (!fin.is_open()) {
        cout<< "No tasks found." << endl;
        return;
    }
    string tasks[MAX_TASKS]; 
    int taskCount = 0;
    string line;
    while (getline(fin, line) && taskCount < MAX_TASKS) {
        tasks[taskCount++] = line;
    }
    fin.close();
    if (taskCount == 0) {
        cout<< "No tasks to mark as done." << endl;
        return;
    }
    cout<< "\nYour Tasks:\n";
    for (int i=0; i<taskCount; i++) {
        cout<< (i + 1) << ". " << tasks[i] << endl;
    }

    int task_num;
    cout<< "\nEnter the number of the task you completed: ";
    cin>> task_num;

    if (task_num < 1 || task_num > taskCount) {
        cout<< "Invalid task number." << endl;
        return;
    }

    for (int i=task_num - 1; i<taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--; 

    ofstream fout(TASK_FILE);
    if (fout.is_open()) {
        for (int i = 0; i < taskCount; i++) {
            fout << tasks[i] << endl;
        }
        fout.close();
        cout<< "Task marked as done and updated.\n";
    } else {
        cout<< "Error opening file to update tasks.\n";
    }
}

int main() {
    int choice;
    do {
        cout<< "\nTo-Do List Manager\n";
        cout<< "1. Add Task\n";
        cout<< "2. View Tasks\n";
        cout<< "3. Mark Task as Done\n";
        cout<< "4. Exit\n";
        cout<< "Enter your choice: ";
        cin>> choice;
        switch (choice) {
            case 1:
                addtask();
                break;
            case 2:
                viewtasks();
                break;
            case 3:
                marktaskdone();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
