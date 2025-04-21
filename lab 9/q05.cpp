#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getarea() = 0;
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float getarea() {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getarea() {
        return 0.5 * base * height;
    }
};

int main() 
{
    Rectangle rec(10, 2);
    Triangle tri(3, 4);
    cout<< "Area of Rectangle: " << rec.getarea() << endl;
    cout<< "Area of Triangle: " << tri.getarea() << endl;
    return 0;
}
