#include<iostream>
#include<string>
using namespace std;

class account{
	protected:
		string accountnumber;
		string accountholdername;
		double balance;
		string accounttype;
	public:
		account(string num, string name, double bal, string type) : accountnumber(num), accountholdername(name), balance(bal), accounttype(type){
		}
		
		virtual void deposit(double amount) {
        if(amount>0) {
            balance += amount;
            cout<< "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        }
		else 
		{
            cout<< "Invalid deposit amount!\n";
        }
    }
    
     virtual void withdraw(double amount) {
        if (amount>0 && balance>=amount) 
		{
            balance -= amount;
            cout<< "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } 
		else 
		{
            cout<< "Insufficient funds or invalid amount!\n";
        }
    }
    
     virtual double calculateinterest() = 0;
     
     virtual void printstatement() {
        cout<< "Account Type: " << accounttype << endl;
        cout<< "Account Number: " << accountnumber << endl;
        cout<< "Account Holder: " << accountholdername << endl;
        cout<< "Balance: $" << balance << endl;
    }
    
     virtual string getaccountinfo() {
        return "Account Type: " + accounttype + "\n" +
               "Account Number: " + accountnumber + "\n" +
               "Account Holder: " + accountholdername + "\n" +
               "Balance: $" + to_string(balance);
    }
    
    virtual ~account()
    {
	}
};

class savingaccount : public account{
	private:
		double interestrate;
		double minimumbalance;
	public:
		savingaccount(string num, string name, double bal, double rate, double minibal) : account(num, name, bal, "saving"), interestrate(rate), minimumbalance(minibal){
			
		}
		
    double calculateinterest() override {
        return balance*interestrate / 100;
    }

    void withdraw(double amount) override {
        if (balance-amount >= minimumbalance) {
            account::withdraw(amount);
        }
		 else 
		 {
            cout << "Withdrawal denied! Minimum balance requirement not met.\n";
        }
    }
    
    void printstatement() override {
        account::printstatement();
        cout<< "Interest Rate: " << interestrate << "%" << endl;
        cout<< "Minimum Balance: $" << minimumbalance << endl;
    }
    
    string getaccountinfo() override {
        return account::getaccountinfo() + "\nInterest Rate: " + to_string(interestrate) + "%\n" +
               "Minimum Balance: $" + to_string(minimumbalance);
    }
};

class checkingaccount : public account{
	public:
		checkingaccount(string num, string name, double bal) : account(num, name, bal, "checking") {
			
		}
		
		double calculateinterest() override {
        return 0; 
    }

    void printstatement() override {
        account::printstatement();
        cout << "Account Type: Checking (No Interest)\n";
    }

    string getaccountinfo() override {
        return account::getaccountinfo() + "\nAccount Type: Checking (No Interest)";
    }
};

class fixeddepositeaccount : public account{
	private:
		double fixedinterestrate;
		int maturitydate;
	public:
		fixeddepositeaccount(string num, string name, double bal, double rate, int maturity) : account(num, name, bal, "fixed deposite"), fixedinterestrate(rate), maturitydate(maturity)
		{
			
		}
		
		double calculateinterest() override {
        return balance*fixedinterestrate / 100;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal denied! Fixed deposit accounts do not allow withdrawals before maturity.\n";
    }

    void printstatement() override {
        account::printstatement();
        cout<< "Fixed Interest Rate: " << fixedinterestrate << "%" << endl;
        cout<< "Maturity Date (in months): " << maturitydate << endl;
    }

    string getaccountinfo() override {
        return account::getaccountinfo() + "\nFixed Interest Rate: " + to_string(fixedinterestrate) + "%\n" +
               "Maturity Date: " + to_string(maturitydate) + " months";
    }
};

int main()
{
	savingaccount save1("SA001", "Jonny", 8000, 4.2, 1500);
    checkingaccount check1("CA002", "Amna", 3200);
    fixeddepositeaccount deposit1("FD003", "Mandeep", 15000, 6.0, 24);
    cout << "\n--- Savings Account ---\n";
    save1.printstatement();
    cout<< save1.getaccountinfo() << endl;
    save1.deposit(500);
    save1.withdraw(2000);
    save1.withdraw(4500);
    cout<< "Interest Earned: $" << save1.calculateinterest() << endl;
    cout<< "\n--- Checking Account ---\n";
    check1.printstatement();
    cout<< check1.getaccountinfo() << endl;
    check1.deposit(1000);
    check1.withdraw(500);
    cout<< "Interest Earned: $" << check1.calculateinterest() << endl;
    cout<< "\n--- Fixed Deposit Account ---\n";
    deposit1.printstatement();
    cout<< deposit1.getaccountinfo() << endl;
    deposit1.withdraw(5000); 
    cout<< "Interest Earned: $" << deposit1.calculateinterest() << endl;
    return 0;
}
