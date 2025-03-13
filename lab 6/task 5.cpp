#include <iostream>
#include <string>
using namespace std;

class vehicle{
protected:
    double price;
public:
    vehicle(double p) : price(p) {}

    virtual void showdetail() const {
        cout<< "Price: $" << price << endl;
    }

    virtual ~vehicle() {}
};

class car : public vehicle{
protected:
    int seatingcapacity;
    int numberofdoors;
    string fueltype; 
public:
    car(double p, int seat, int doors, string fuel) : vehicle(p), seatingcapacity(seat), numberofdoors(doors), fueltype(fuel) {}

    void showdetail() const override {
        vehicle::showdetail();
        cout<< "Seating Capacity: " << seatingcapacity << endl;
        cout<< "Number of Doors: " << numberofdoors << endl;
        cout<< "Fuel Type: " << fueltype << endl;
    }
};

class motorcycle : public vehicle{
protected:
    int numberofcylinders;
    int numberofgears;
    int numberofwheels;
public:
    motorcycle(double p, int cylinders, int gears, int wheels) : vehicle(p), numberofcylinders(cylinders), numberofgears(gears), numberofwheels(wheels) {}

    void showdetail() const override {
        vehicle::showdetail();
        cout<< "Number of Cylinders: " << numberofcylinders << endl;
        cout<< "Number of Gears: " << numberofgears << endl;
        cout<< "Number of Wheels: " << numberofwheels << endl;
    }
};

class audi : public car {
private:
    string modeltype;
public:
    audi(double p, int seat, int doors, string fuel, string model) : car(p, seat, doors, fuel), modeltype(model) {}

    void showdetail() const override {
        cout<< "Audi Car Details:\n";
        car::showdetail();
        cout<< "Model Type: " << modeltype << endl;
    }
};

class yamaha : public motorcycle {
private:
    string maketype;
public:
    yamaha(double p, int cylinders, int gears, int wheels, string make) : motorcycle(p, cylinders, gears, wheels), maketype(make) {}

    void showdetail() const override {
        cout<< "Yamaha Motorcycle Details:\n";
        motorcycle::showdetail();
        cout<< "Make Type: " << maketype << endl;
    }
};

int main() {
    audi a(4000, 5, 4, "Deisel", "r6");
    yamaha y(2200, 2, 6, 2, "AS-1");
    a.showdetail();
    cout<< "---------------------\n";
    y.showdetail();
    return 0;
}
