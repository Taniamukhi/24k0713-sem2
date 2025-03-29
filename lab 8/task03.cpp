#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    cout<<vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger() : isNegative(false) {}
    BigInteger(std::string num) {
        if (num[0] == '-') {
            isNegative = true;
            num = num.substr(1);
        } else {
            isNegative = false;
        }
        cout<< reverse(num.begin(), num.end());
        for (char c : num) {
            digits.push_back(c - '0');
        }
        removeLeadingZeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t maxSize = std::max(digits.size(), other.digits.size());
            for (size_t i = 0; i < maxSize || carry; i++) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            return result;
        }
        return *this - (-other);
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        if (*this < other) {
            return -(other - *this);
        }
        BigInteger result;
        result.isNegative = isNegative;
        int borrow = 0, diff;
        for (size_t i = 0; i < digits.size(); i++) {
            diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        result.isNegative = (isNegative != other.isNegative);
        for (size_t i = 0; i < digits.size(); i++) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; j++) {
                long long current = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator/(const BigInteger& other) const {
        if (other == BigInteger("0")) {
            throw std::runtime_error("Division by zero");
        }
        BigInteger quotient, remainder;
        quotient.digits.resize(digits.size());
        quotient.isNegative = (isNegative != other.isNegative);
        remainder.isNegative = false;
        for (int i = digits.size() - 1; i >= 0; i--) {
            remainder.digits.insert(remainder.digits.begin(), digits[i]);
            remainder.removeLeadingZeros();
            int count = 0;
            while (!(remainder < other)) {
                remainder = remainder - other;
                count++;
            }
            quotient.digits[i] = count;
        }
        quotient.removeLeadingZeros();
        return quotient;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits && isNegative == other.isNegative;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (digits.size() != other.digits.size()) return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
        }
        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        result.isNegative = !isNegative;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) os << '-';
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger a, b;
    cout<< "Enter two big integers: ";
    cin>> a >> b;
    cout<< "Sum: " << (a + b) << std::endl;
    cout<< "Difference: " << (a - b) << std::endl;
    cout<< "Product: " << (a * b) << std::endl;
    cout<< "Quotient: " << (a / b) << std::endl;
    return 0;
}
