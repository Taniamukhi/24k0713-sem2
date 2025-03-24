#include <iostream>
#include <cmath>
using namespace std;

class shape {
protected:
    string color;
    int X, Y; 
    double borderthickness;

public:
    shape(string c, int x, int y, double border=1.0) : color(c), X(x), Y(y), borderthickness(border) {}

    virtual void draw() = 0; 
    virtual double calculatearea() = 0;
    virtual double calculateperimeter() = 0;

    virtual ~shape() {}
};

class circle : public shape {
private:
    double radius;

public:
    circle(string c, int x, int y, double r, double border=1.0) : shape(c, x, y, border), radius(r) {}

    void draw() override {
        cout << "Drawing circle at (" << X << ", " << Y << ") with radius " << radius << " and color " << color << endl;
    }

    double calculatearea() override {
        return M_PI * radius * radius;
    }

    double calculateperimeter() override {
        return 2 * M_PI * radius;
    }
};

class rectangle : public shape {
private:
    double width, height;

public:
    rectangle(string c, int x, int y, double w, double h, double border=1.0) : shape(c, x, y, border), width(w), height(h) {}

    void draw() override {
        cout << "Drawing rectangle at (" << X << ", " << Y << ") with width " << width << " and height " << height << " with color " << color << endl;
    }

    double calculatearea() override {
        return width*height;
    }

    double calculateperimeter() override {
        return 2 * (width + height);
    }
};

class triangle : public shape {
private:
    double base, height, side_A, side_B, side_C;

public:
    triangle(string c, int x, int y, double b, double h, double a, double b_side, double c_side, double border=1.0) : shape(c, x, y, border), base(b), height(h), side_A(a), side_B(b_side), side_C(c_side) {}

    void draw() override {
        cout << "Drawing triangle at (" << X << ", " << Y << ") with base " << base << " and height " << height << " with color " << color << endl;
    }

    double calculatearea() override {
        return (base * height) / 2;
    }

    double calculateperimeter() override {
        return side_A + side_B + side_C;
    }
};

class polygon : public shape {
private:
    int numside;
    double sidelength;

public:
    polygon(string c, int x, int y, int side, double length, double border = 1.0) : shape(c, x, y, border), numside(side), sidelength(length) {}

    void draw() override {
        cout << "Drawing polygon at (" << X << ", " << Y << ") with " << numside << " sides of length " << sidelength << " with color " << color << endl;
    }

    double calculatearea() override {
        return (numside * sidelength * sidelength) / (4 * tan(M_PI / numside));  
    }

    double calculateperimeter() override {
        return numside * sidelength;
    }
};

int main() {
    shape* shapes[4];
    shapes[0] = new circle("Black", 3, 4, 10);
    shapes[1] = new rectangle("Brown", 3, 3, 17, 10);
    shapes[2] = new triangle("orange", 3, 3, 6, 8, 6, 8, 10);
    shapes[3] = new polygon("Red", 4, 4, 6, 5);
    int i;
    for(i=0; i<4; i++) 
	{
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculatearea() << endl;
        cout << "Perimeter: " << shapes[i]->calculateperimeter() << endl << endl;
    }
    for(i=0; i<4; i++) 
	{
        delete shapes[i];
    }
    return 0;
}
