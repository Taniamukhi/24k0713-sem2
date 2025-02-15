#include <iostream>
using namespace std;

class account {
public:
    account(double initial_balance = 0.0) : balance(initial_balance) {}
    void add_amount(double amount) {
        if (amount > 0)
            balance += amount;
    }
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    double getbalance() {
        return balance;
    }

private:
    double balance;
};

int main() {
    account myAccount(200.0); 
    cout << "Initial Balance: " << myAccount.getbalance() << endl;
    myAccount.add_amount(56.0);
    cout << "After credit of 56: " << myAccount.getbalance() << endl;
    if (myAccount.withdraw(80.0)) {
        cout << "After debit of 80: " << myAccount.getbalance() << endl;
    }
    myAccount.add_amount(120.0);
    return 0;
}