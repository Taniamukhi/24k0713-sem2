#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    Car(string m) : model(m), price(0) {}

    string getmodel() {
        return model;
    }

    float getprice() {
        return price;
    }

    void setmodel(string m) {
        model = m;
    }

    virtual void setprice(float p) = 0;

    virtual void display() {
        cout<< "Model: " << model << endl;
        cout<< "Price: $" << price << endl;
    }

    virtual ~Car() {}
};

class Color : public Car {
private:
    string carcolor;
public:
    Color(string m, string c) : Car(m), carcolor(c) {}

    void setprice(float p) {
        price = p + 500;
    }

    void display() {
        Car::display();
        cout<< "Color: " << carcolor << endl;
    }
};

class Company : public Car {
private:
    string companyname;
public:
    Company(string m, string comp) : Car(m), companyname(comp) {}

    void setprice(float p) {
        price = p + 1000;
    }

    void display() {
        Car::display();
        cout<< "Company: " << companyname << endl;
    }
};

int main() {
    Color car1("Model-B", "Black");
    car1.setprice(15000);
    cout<< "=== Car 1 Details (Color)  ===" << endl;
    car1.display();
    cout<< endl;
    Company car2("Model-D", "Audi");
    car2.setprice(45000);
    cout<< "=== Car 2 Details (Company) ===" << endl;
    car2.display();
    return 0;
}
