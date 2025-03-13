#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
    int id;
    string name;

public:
    employee(int empid, string empname) : id(empid), name(empname) {}
    virtual void showdetail() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~employee() {}
};

class iordertaker {
public:
    virtual void takeorder(const string &order) = 0;
    virtual ~iordertaker() {}
};

class iorderpreparer {
public:
    virtual void prepareorder(const string &order) = 0;
    virtual ~iorderpreparer() {}
};

class ibiller {
public:
    virtual void generatebill(double amount) = 0;
    virtual ~ibiller() {}
};

class waiter : public employee, public iordertaker {
public:
    waiter(int id, string name) : employee(id, name) {}

    void takeorder(const string &order) override {
        cout << "Waiter " << name << " took order: " << order << endl;
    }
};

class chef : public employee, public iorderpreparer {
public:
    chef(int id, string name) : employee(id, name) {}

    void prepareorder(const string &order) override {
        cout << "Chef " << name << " is preparing: " << order << endl;
    }
};

class cashier : public employee, public ibiller {
public:
    cashier(int id, string name) : employee(id, name) {}

    void generatebill(double amount) override {
        cout << "Cashier " << name << " generated bill: $" << amount << endl;
    }
};

class manager : public employee, public iordertaker, public ibiller {
public:
    manager(int id, string name) : employee(id, name) {}

    void takeorder(const string &order) override {
        cout << "Manager " << name << " took VIP order: " << order << endl;
    }

    void generatebill(double amount) override {
        cout << "Manager " << name << " approved a bill of $" << amount << endl;
    }
};

class menu {
protected:
    string items[5];
    double prices[5];

public:
    virtual void showmenu() const = 0;
    virtual double calculatetotalcost(int itemindex, int quantity) = 0;
    virtual ~menu() {}
};

class foodmenu : public menu {
public:
    foodmenu() {
        items[0] = "Steak"; prices[0] = 12.0;
        items[1] = "Sushi"; prices[1] = 18.0;
        items[2] = "Tacos"; prices[2] = 10.0;
        items[3] = "Salad"; prices[3] = 11.5;
        items[4] = "Fries"; prices[4] = 9.0;
    }

    void showmenu() const override {
        cout << "Food Menu:\n";
        for (int i=0; i<5; i++) {
            cout<< i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    double calculatetotalcost(int itemindex, int quantity) override {
        return prices[itemindex] * quantity;
    }
};

class beveragemenu : public menu {
public:
    beveragemenu() {
        items[0] = "Lemonade"; prices[0] = 4.0;
        items[1] = "Smoothie"; prices[1] = 7.5;
        items[2] = "Iced tea"; prices[2] = 2.5;
        items[3] = "Coffee"; prices[3] = 2.2;
        items[4] = "Milkshake"; prices[4] = 5.0;
    }

    void showmenu() const override {
        cout << "Beverage Menu:\n";
        for(int i=0; i<5; i++) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    double calculatetotalcost(int itemindex, int quantity) override {
        return (prices[itemindex] * quantity) * 1.10; 
    }
};

int main() {
    waiter w(1, "Aalam");
    chef c(2, "Ali");
    cashier cash(3, "Abdul");
    manager m(4, "Fatima");
    employee* employees[4] = {&w, &c, &cash, &m};
    for(int i=0; i<4; i++) 
	{
        employees[i]->showdetail();
    }
    w.takeorder("Steak");
    m.takeorder("VIP Shushi");
    c.prepareorder("Steak");
    cash.generatebill(25.0);
    m.generatebill(30.0);
    foodmenu food;
    beveragemenu beverage;
    food.showmenu();
    beverage.showmenu();
    cout<< "Total cost for 2 Sushi: $" << food.calculatetotalcost(1, 2) << endl;
    cout<< "Total cost for 3 Smoothies: $" << beverage.calculatetotalcost(1, 3) << endl;
    return 0;
}
