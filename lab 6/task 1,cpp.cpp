#include <iostream>
using namespace std;

class bankaccount {
protected:
    string accountnumber;
    double balance;

public:
    bankaccount(string num, double bal) : accountnumber(num), balance(bal)
	{}
    virtual ~bankaccount()
	{}
    
    virtual void deposit(double amount) {
        balance += amount;
        cout<< "Deposited " << amount << " into account " << accountnumber << endl;
    }
    
    virtual void withdraw(double amount) {
        if (balance>=amount) {
            balance -= amount;
            cout<< "Withdrew " << amount << " from account " << accountnumber << endl;
        } else {
            cout<< "Insufficient balance." << accountnumber << endl;
        }
    }
    
    virtual void applymonthlychanges() = 0; 
    
    virtual void display() const
	{
        cout<<"Account: " << accountnumber <<", Balance: " << balance << endl;
    }
};

class savingaccount : public bankaccount {
    double interestrate;

public:
    savingaccount(string num, double bal, double rate) : bankaccount(num, bal), interestrate(rate) 
	{}
    void applymonthlychanges()  {
        balance += balance*interestrate;
        cout<<"Interest applied. New balance: " << balance << endl;
    }
};

class checkingaccount : public bankaccount {
    double overdraftlimit;

public:
    checkingaccount(string num, double bal, double limit) : bankaccount(num, bal), overdraftlimit(limit)
	 {}
    void withdraw(double amount)  {
        if (balance + overdraftlimit >= amount) {
            balance -= amount;
            cout<< "Overdraft used! Withdrawn " << amount << " from account " << accountnumber << endl;
        } else {
            cout<< "Overdraft limit exceeded on account " << accountnumber << endl;
        }
    }
    void applymonthlychanges() {}
};

class businessaccount : public bankaccount {
    double taxrate;

public:
    businessaccount(string num, double bal, double tax) : bankaccount(num, bal), taxrate(tax) {}
    void deposit(double amount) {
        double taxamount = amount*taxrate;
        balance += (amount-taxamount);
        cout<< "Corporate tax deducted. Deposited " << amount - taxamount << " into account " << accountnumber << endl;
    }
    void applymonthlychanges()  {}
};

class user {
protected:
    string name;

public:
    user(string n) : name(n) {
	}
    virtual ~user() {
	}
    virtual void performoperation(bankaccount *account, double amount) = 0;
};

class customer : public user {
public:
    customer(string n) : user(n) {
	}
    void performoperation(bankaccount *account, double amount){
        account->deposit(amount);
    }
};

class employee : public user {
public:
    employee(string n) : user(n) {}
};

class teller : public employee {
public:
    teller(string n) : employee(n) {
	}
    void performoperation(bankaccount *account, double amount) {
        account->withdraw(amount);
    }
};

class manager : public employee {
public:
    manager(string n) : employee(n) {}
    void performoperation(bankaccount *account, double amount){
        account->deposit(amount);
    }
    void overrideaccount(bankaccount *account, double newbalance) {
        cout<< "Manager override: Setting new balance to " << newbalance << endl;
    }
};

int main() {
    bankaccount* accounts[3] = {
        new savingaccount("N111", 100, 0.02),
        new checkingaccount("K456", 90, 20),
        new businessaccount("A769", 8000, 0.05)
    };

    user* users[3] = {
        new customer("Ali"),
        new teller("Aslam"),
        new manager("Asif")
    };
    
    int i;
    for (i=0; i<3; i++) {
        accounts[i]->applymonthlychanges();
        accounts[i]->display();
    }
    
    users[0]->performoperation(accounts[0], 200);
    users[1]->performoperation(accounts[1], 300);
    users[2]->performoperation(accounts[2], 500);
    
    for (i=0; i<3; i++){
    	accounts[i]->display();
	} 
    
    for (i=0; i<3; i++)
	{
		delete accounts[i];
	 } 
    for (i=0; i<3; i++)
	{
		delete users[i];
	 } 
    return 0;
}
