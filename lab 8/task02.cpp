#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    vector<int> coefficients;
    void trim() {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
public:
    friend class PolynomialUtils;
    Polynomial() {}
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    friend ostream& operator<<(ostream& os, const Polynomial& p);
};

Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t maxSize = max(coefficients.size(), other.coefficients.size());
    vector<int> result(maxSize, 0);
    for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
    for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] += other.coefficients[i];
    return Polynomial(result);
}
Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxSize = max(coefficients.size(), other.coefficients.size());
    vector<int> result(maxSize, 0);
    for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
    for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] -= other.coefficients[i];
    return Polynomial(result);
}
Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(result);
}
ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coefficients.empty()) {
        os << "0";
        return os;
    }
    bool first = true;
    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        int coef = p.coefficients[i];
        if (coef == 0) continue;
        if (!first) {
            os << (coef > 0 ? " + " : " - ");
        } else if (coef < 0) {
            os << "-";
        }
        if (abs(coef) != 1 || i == 0) {
            os << abs(coef);
        }
        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
        first = false;
    }
    return os;
}
int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int coef : p.coefficients) {
        result += coef * power;
        power *= x;
    }
    return result;
}
Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coefficients.size() <= 1) return Polynomial({0});
    vector<int> derivCoeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); ++i) {
        derivCoeffs[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(derivCoeffs);
}

int main() {
    Polynomial p1({5, 3, 2}); 
    Polynomial p2({7, -5, 4}); 
    cout<< "p1: " << p1 << endl;
    cout<< "p2: " << p2 << endl;    
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;    
    cout<< "p1 + p2: " << sum << endl;
    cout<< "p1 - p2: " << diff << endl;
    cout<< "p1 * p2: " << prod << endl;    
    int value = PolynomialUtils::evaluate(p1, 2);
    cout<< "p1(2) = " << value << endl;    
    Polynomial deriv = PolynomialUtils::derivative(p1);
    cout<< "p1' : " << deriv << endl; 
    return 0;
}
