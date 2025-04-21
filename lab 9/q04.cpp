#include <iostream>
#include <string>
using namespace std;

class Flight{
private:
    string Flightnumber;
    string departure;
    string arrival;
    int capacity;
    int bookedseat;
public:
    Flight(const string& flightNum, const string& dep, const string& arr, int cap) : Flightnumber(flightNum), departure(dep), arrival(arr), capacity(cap), bookedseat(0) {}

    bool bookseat() {
        if(bookedseat < capacity) 
		{
            bookedseat++;
            cout<< "Seat booked successfully on flight " << Flightnumber << "." << endl;
            return true;
        }
        cout<< "No seats available on flight " << Flightnumber << "." << endl;
        return false;
    }

    bool cancelseat() {
        if(bookedseat > 0) 
		{
            bookedseat--;
            cout<< "Seat canceled successfully on flight " << Flightnumber << "." << endl;
            return true;
        }
        cout<< "No booked seats to cancel on flight " << Flightnumber << "." << endl;
        return false;
    }

    bool upgradeseat() {
        if (bookedseat > 0) 
		{
            cout<< "Seat upgraded successfully on flight " << Flightnumber << "." <<  endl;
            return true;
        }
        cout<< "No seats to upgrade on flight " << Flightnumber << "." << endl;
        return false;
    }

    string getflightnumber() const { return Flightnumber; }
    string getdeparture() const { return departure; }
    string getarrival() const { return arrival; }
    int getavailableseat() const { return capacity - bookedseat; }

    void setcapacity(int newcapacity) {
        if(newcapacity >= bookedseat) 
		{
            capacity = newcapacity;
        } else 
		{
            cout<< "New capacity cannot be less than booked seats." << endl;
        }
    }
};

class Passenger {
private:
    string passengerid;
    string name;
public:
    Passenger(const string& id, const string& n) : passengerid(id), name(n) {}

    void requestbooking(Flight& flight) {
        if(!flight.bookseat()) 
		{
            cout<< "Booking failed for " << name << " on flight " << flight.getflightnumber() << "." << endl;
        }
    }

    void requestcancellation(Flight& flight) {
        if (!flight.cancelseat()) {
            cout<< "Cancellation failed for " << name << " on flight " << flight.getflightnumber() << "." << endl;
        }
    }

    void requestupgrade(Flight& flight) {
        if (!flight.upgradeseat()) 
		{
            cout<< "Upgrade failed for " << name << " on flight " << flight.getflightnumber() << "." << endl;
        }
    }
};

int main() {
    Flight flight1("BD232", "Iran", "Los Angeles", 90);
    Passenger p1("P001", "Ali");
    Passenger p2("P002", "Aslam");
    Passenger p3("P003", "Chand");
    p1.requestbooking(flight1); 
    p2.requestbooking(flight1); 
    p3.requestbooking(flight1); 
    p3.requestbooking(flight1);  
    cout<< "Available seats after bookings: " << flight1.getavailableseat() << endl;
    p1.requestcancellation(flight1);  
    p2.requestcancellation(flight1);  
    p1.requestupgrade(flight1); 
    p3.requestupgrade(flight1);  
    cout<< "Available seats after cancellations and upgrades: " << flight1.getavailableseat() << endl;
    p1.requestbooking(flight1);  // Should fail (no more available seats)
    return 0;
}
