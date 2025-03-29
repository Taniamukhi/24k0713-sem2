#include<iostream>
using namespace std;

class fraction{
    private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const
    {
        while(b!=0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return(a<0) ? -a : a;
    }

    void reduce()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor; 
        denominator /= divisor; 

        if(denominator<0)
        {
            numerator = -numerator;
            denominator -= denominator;
        }
    }

    public:
    fraction(int num, int den) : numerator(num), denominator(den){
        if(denominator==0){
            cout<< "Denminator can not be zero" << endl;
            EXIT_FAILURE;
        }
        reduce();
    }

    fraction operator+(const fraction& other) const
    {
        return fraction(numerator*other.denominator + other.numerator*denominator, denominator*other.denominator);
    }

    fraction operator-(const fraction& other) const
    {
        return fraction(numerator*other.denominator - other.numerator*denominator, denominator*other.denominator);
    }

    fraction operator*(const fraction& other) const
    {
        return fraction(numerator*other.numerator , denominator*other.denominator);
    }

    fraction operator/(const fraction& other) const
    {
       if(other.numerator == 0){
        cout<< "DIVISION BY ZERO, ERROR" << endl;
        EXIT_FAILURE;
       }
       return fraction(numerator*other.denominator , denominator*other.numerator);
    }

    bool operator==(const fraction& other) const
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

     bool operator!=(const fraction& other) const
    {
        return !(*this == other);
    }

     bool operator<(const fraction& other) const
    {
        return numerator*other.denominator < denominator*other.numerator*denominator;
    }

    bool operator>(const fraction& other) const
    {
        return numerator*other.denominator > other.numerator*denominator;
    }

    bool operator<=(const fraction& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const fraction& other) const
    {
        return !(*this < other);
    }

    friend ostream& operator<<(std::ostream& os, const fraction& f)
    {
        os << f.numerator;
        if(f.denominator != 1)
        {
            os << "/" << f.denominator;
        }
        return os;
    }

    friend istream& operator>>(std::istream& is, fraction& f)
    {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if(f.denominator == 0)
        {
            cout<< "Denminator can not be zero" << endl;
            EXIT_FAILURE;
        }
        f.reduce();
        return is;
    }
};

int main()
{
    fraction f1(2,4), f2(4,8);
    cout<< (f1+f2) << endl;
    return 0;
}
