#include<iostream>
#include<string>
using namespace std;

class Wallet{
	private:
		double balance;
		double dailydeposit;
		double dailywithdraw;
		const double MAX_DAILY_DEPOSIT = 4000.0;
		const double MAX_DAILY_WITHDRAW = 2000.0;
	public:
		Wallet() : balance(0.0), dailydeposit(0.0), dailywithdraw(0.0) {
			
		} 
		
		bool deposit(double amount){
			if(amount<=0)
			{
				cout<< "Invalid deposit amount."<< endl;
				return false;
			}
			if(dailydeposit + amount > MAX_DAILY_DEPOSIT){
				cout<< " Daily deposite limit exceed!"<< endl;
				return false;
			}
			balance += amount;
			dailydeposit += amount;
			cout<< "Deposited "<< amount << endl;
			cout<< "Current balance: "<< balance << endl;
			return true;
		}
		
		bool withdraw(double amount){
			if(amount<=0)
			{
				cout<< "Invalid withdraw amount."<< endl;
				return false;
			}
			if(amount > balance)
			{
				cout<< "Insufficient balance."<< endl;
				return false;
			}
			if(dailydeposit + amount > MAX_DAILY_WITHDRAW){
				cout<< " Daily withdraw limit exceed!"<< endl;
				return false;
			}
			balance -= amount;
			dailydeposit += amount;
			cout<< "withdrew "<< amount << endl;
			cout<< "Current balance: "<< balance << endl;
			return true;
		}
		
		double getbalance(){
			return balance;
		}
		
		void resetdailylimit(){
			dailydeposit = 0.0;
			dailywithdraw = 0.0;
		}
};

class user{
	private:
		string userid;
		string username;
		Wallet wallet;
	public:
		user(string id, string name) : userid(id), username(name) {
			
		}
		
		void deposit(double amount){
			cout<< " " << username << " . Attempting to deposit: " << amount << endl;
			wallet.deposit(amount);
		}
		
		void withdraw(double amount){
			cout<< " " << username << " . Attempting to withdraw: " << amount << endl;
			wallet.withdraw(amount);
		}
		
		void displaybalance() {
			cout<< " " << username << " . Current balance: "<< wallet.getbalance() << endl;
		}
		
		void resetlimit(){
			wallet.resetdailylimit();
		}
};

int main()
{
	user user1("001", "Ali");
	user user2("002", "Aslam");
	user1.deposit(1000);
	user1.deposit(5000);
	user1.withdraw(600);
	user1.withdraw(3000);
	user1.displaybalance();
	cout<< "\n" ;
	user2.deposit(4000);
	user2.withdraw(700);
	user2.displaybalance();
	cout<< "\n New Day: Resetting limits \n";
    user1.resetlimit();
    user2.resetlimit();
    user1.deposit(3000);
    user1.withdraw(1000);
    user1.displaybalance();
    return 0;
}
