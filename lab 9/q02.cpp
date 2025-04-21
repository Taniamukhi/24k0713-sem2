#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Logger{
private:
    const size_t MAX_LOGS = 1000;
    vector<string> logs;
    void addlog(const string& severity, const string& module, const string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin()); 
        }
        string formatted = "[" + severity + "] [" + module + "] " + message;
        logs.push_back(formatted);
    }
public:
    void loginf(const string& module, const string& message) {
        addlog("INFO", module, message);
    }
    void logwarning(const string& module, const string& message) {
        addlog("WARN", module, message);
    }
    void logerror(const string& module, const string& message) {
        addlog("ERROR", module, message);
    }
    friend class logauditor;
};

class logauditor {
private:
    string password = "admin456";
    bool authenticate(const string& attempt) const {
        return attempt == password;
    }
public:
    vector<string> getLogs(const Logger& logger, const string& passwordattempt) const {
        if (!authenticate(passwordattempt)) {
            cout << "Access denied: Authentication failed.\n";
            return {};
        }
        return logger.logs;
    }
};

int main() 
{
    Logger logger;
    logger.loginf("Scheduler", "Task scheduled successfully.");
    logger.logwarning("Database", "Connection pool nearly full.");
    logger.logerror("API", "Failed to parse JSON request.");
    logger.loginf("Scheduler", "Task scheduled successfully.");
    logger.logerror("Storage", "Failed to write to disk.");
    logauditor auditor;
    string password;
    cout<< "\n== Log Audit Attempt ==\n";
    cout<< "Enter auditor password: ";
    cin>> password;
    vector<string> logs = auditor.getLogs(logger, password);
    if (!logs.empty()) {
        cout<< "\n--- Retrieved Logs ---\n";
        for (const auto& log : logs) {
            cout<< log << endl;
        }
    }
    return 0;
}
