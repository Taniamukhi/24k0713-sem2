#include <iostream>
using namespace std;

class Shape {
private:
    double area;
public:
    Shape(double a = 0) : area(a) {}

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& s) const {
        return Shape(this->Area() + s.Area());
    }

    void display() const {
        cout << "Area: " << Area() << endl;
    }
};

int main() {
    Shape shape1(2.5), shape2(20.5); 
    Shape totalArea = shape1 + shape2; 
    cout << "Shape 1: ";
    shape1.display();
    cout << "Shape 2: ";
    shape2.display();
    cout << "Total Area: ";
    totalArea.display();
    return 0;
}
