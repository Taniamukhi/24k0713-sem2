#include<iostream>
#include<string>
using namespace std;

class currency {
protected:
    double amount;
    string currencycode;
    string currencysymbol;
    double exchangerate;
public:
    currency(double amo, string code, string symbol, double rate) : amount(amo), currencycode(code), currencysymbol(symbol), exchangerate(rate) {}

    virtual double converttobase() const {
        return amount * exchangerate;
    }

    virtual double convertto(const currency& targetcurrency) const {
        double baseamount = converttobase();
        return baseamount / targetcurrency.exchangerate;
    }

    virtual void displaycurrency() const {
        cout << "currency: " << currencycode << " (" << currencysymbol << ") | Amount: " << amount << endl;
    }

    virtual ~currency() {}
};

class dollar : public currency {
public:
    dollar(double amo) : currency(amo, "USD", "$", 1.0) {} 

    void displaycurrency() const override {
        cout << "dollar Amount: $" << amount << endl;
    }
};

class euro : public currency {
public:
    euro(double amo) : currency(amo, "EUR", "€", 1.1) {} 

    void displaycurrency() const override {
        cout << "euro Amount: €" << amount << endl;
    }
};

class rupee : public currency {
public:
    rupee(double amo) : currency(amo, "INR", "?", 0.012) {} 

    void displaycurrency() const override {
        cout << "rupee Amount: ?" << amount << endl;
    }
};

int main() 
{
    dollar usd(100);
    euro eur(50);
    rupee inr(5000);
    cout << "--- currency Details ---" << endl;
    usd.displaycurrency();
    eur.displaycurrency();
    inr.displaycurrency();
    cout << "\nConverting 50 EUR to USD: $" << eur.convertto(usd) << endl;
    cout << "Converting 5000 INR to USD: $" << inr.convertto(usd) << endl;
    cout << "Converting 100 USD to INR: ?" << usd.convertto(inr) << endl;
    return 0;
}
