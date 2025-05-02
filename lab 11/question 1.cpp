#include<iostream>
#include<any>
#include<typeinfo>
#include<stdexcept>
using namespace std;

class BadTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type requested from TypeSafeContainer.";
    }
};

class TypeSafeContainer {
private:
    std::any data;

public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() const {
        if (!data.has_value()) {
            throw BadTypeException();
        }

        try {
            return std::any_cast<T>(data);
        } catch (const std::bad_any_cast&) {
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer container;
    container.store<string>("Hello, world!");
    try {
        string str = container.get<string>();
        cout<< "Retrieved: " << str << endl;
        int number = container.get<int>();
        cout<< "Number: " << number << endl;
    } catch (const BadTypeException& ex) {
        cerr<< "Exception caught: " << ex.what() << endl;
    }
    return 0;
}
