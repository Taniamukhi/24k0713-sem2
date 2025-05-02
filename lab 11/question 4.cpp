#include<iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T x, y; 
public: 
    Base(T a, T b) : x(a), y(b) {}

    T multiplybase() {
        return x * y;
    }
};

template <typename T>
class Derived : public Base<T> {
protected:
    T a, b;  
public:
    Derived(T x, T y, T p, T q) : Base<T>(x, y), a(p), b(q) {}

    T multiplydervied() {
        return a * b;
    }

    void printresults() {
        cout<< "Multiplication of base class variables: " << this->multiplybase() << endl;
        cout<< "Multiplication of derived class variables: " << multiplydervied() << endl;
    }
};

int main() {
    Derived<int> derivedObj(4, 5, 3, 2);  
    derivedObj.printresults();
    return 0;
}