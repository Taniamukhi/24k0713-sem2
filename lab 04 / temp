#include <iostream>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class circle {
public:
    circle(double r) : rad(r) {}
    double getarea(){
        return M_PI * rad * rad;
    }
    double getperimeter() {
        return 2 * M_PI * rad;
    }

private:
    double rad;
};

int main() {
    circle myCircle(3);
    cout << "Area of circle: " << myCircle.getarea() << endl;
    cout << "Perimeter of circle: " << myCircle.getperimeter() << endl;
    return 0;
}