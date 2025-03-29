#include <iostream>
using namespace std;

class Number {
private:
    double value; 
public:
    Number(double val) : value(val) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this; 
        value /= 4.0; 
        return temp; 
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() 
{
    Number num(16);
    cout << "Initial value: ";
    num.display();    
    --num; 
    cout << "After prefix --: ";
    num.display();    
    num--; 
    cout << "After postfix --: ";
    num.display();
    return 0;
}
