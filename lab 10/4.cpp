#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Logger {
private:
    string base_filename;
    size_t max_size;
    int log_count;
    void rotateLogs() {
        ifstream file(base_filename, ios::binary | ios::ate);
        if (file.is_open()) {
            size_t file_size = file.tellg();
            file.close();
            if (file_size > max_size) {
                log_count++; 
                stringstream new_filename;
                new_filename << base_filename << log_count << ".txt"; 
                string new_log_file = new_filename.str();
                rename(base_filename.c_str(), new_log_file.c_str());
                cout<< "Log file rotated. New log file: " << new_log_file << endl;
            }
        }
    }

public:
    Logger(string filename, size_t max_size) : base_filename(filename), max_size(max_size), log_count(0) {}

    void logmessage(const string& message) {
        rotateLogs();  
        ofstream log_file(base_filename, ios::app);  
        if (log_file.is_open()) {
            log_file << "[LOG] " << message << endl;  
            log_file.close();
        } else {
            cout<< "Error opening log file" << endl;
        }
    }
};

int main() {
    Logger logger("log.txt", 1048576);  
    logger.logmessage("This is the first log message.");
    logger.logmessage("This is second log message.");
    logger.logmessage("This is a third log message.");
    return 0;
}
