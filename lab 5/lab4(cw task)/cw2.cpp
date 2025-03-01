#include <iostream>
using namespace std;

class polynomial {
private:
    double* coefficient; 
    int degree;            

public:
    polynomial() : degree(0) {
        coefficient = new double[1]{0}; 
    }
   
    polynomial(int deg, const double* coeff) : degree(deg) {
        coefficient = new double[degree + 1];  
        for (int i=0; i<=degree; i++) {
            coefficient[i] = coeff[i];  
        }
    }

    polynomial(const polynomial& other) : degree(other.degree) {
        coefficient = new double[degree + 1];
        for (int i=0; i<=degree; i++) {
            coefficient[i] = other.coefficient[i];
        }
    }
  
    polynomial(polynomial&& other) noexcept : degree(other.degree), coefficient(other.coefficient) {
        other.coefficient = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficient;
    }

    int getdegree() const {
        return degree;
    }
   
    double evaluate(double x) const {
        double result = 0.0;
        double power = 1;
        for (int i=0; i<=degree; i++) {
            result += coefficient[i] * power;
            power *= x;  
        }
        return result;
    }
    
    polynomial add(const polynomial& other) const {
        int maxdegree = max(degree, other.degree);
        double* newcoeff = new double[maxdegree + 1]{0}; 
        for (int i=0; i<=degree; i++) {
            newcoeff[i] += coefficient[i];  
        }
        for (int i=0; i<=other.degree; i++) {
            newcoeff[i] += other.coefficient[i];  
        }
        return polynomial(maxdegree, newcoeff);
    }
    
    polynomial multiply(const polynomial& other) const {
        int newdegree = degree + other.degree;
        double* newcoeff = new double[newdegree + 1]{0};  
        for (int i=0; i<=degree; i++) {
            for (int j=0; j<=other.degree; j++) {
                newcoeff[i + j] += coefficient[i] * other.coefficient[j];  
            }
        }
        return polynomial(newdegree, newcoeff);
    }
    
    void display() const {
        for (int i=degree; i>=0; i--) {
            cout << coefficient[i] << "x^" << i;
            if (i>0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    double coeff1[] = {5, 3, 2};  
    double coeff2[] = {8, 1};     
    polynomial p1(2, coeff1);
    polynomial p2(1, coeff2);
    cout << "Polynomial1: ";
    p1.display();
    cout << "Polynomial2: ";
    p2.display();
    polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();
    polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.display();
    cout << "Evaluation at x=2 for Polynomial1: " << p1.evaluate(2) << endl;
    return 0;
}
