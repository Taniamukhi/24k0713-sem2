#include <iostream>
using namespace std;

class Car {
private:
    mutable int enginehorsepower;  
    mutable int seatingcapacity;
    mutable int noofspeakers;

public:
    Car(int hp, int seat, int speaker) : enginehorsepower(hp), seatingcapacity(seat), noofspeakers(speaker) {}
    void updatecar(int hp, int seat, int speaker) const {
        enginehorsepower = hp;
        seatingcapacity = seat;
        noofspeakers = speaker;
    }

    void display() const {
        cout << "Car Details:\n";
        cout << "Engine Horsepower: " << enginehorsepower << endl;
        cout << "Seating Capacity: " << seatingcapacity << endl;
        cout << "Number of Speakers: " << noofspeakers << endl;
    }
};

int main() {
    Car car(90, 4, 5);  
    car.display();
    cout << "\nUpdating Car attributes\n";
    car.updatecar(250, 4, 8);  
    car.display();  
    return 0;
}
