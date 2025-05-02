#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayIndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

template <typename T>
class Safearray {
private:
    T* arr;
    size_t size;
public:
    Safearray(size_t size) : size(size) {
        arr = new T[size];
    }

    ~Safearray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(size)) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    try {
        Safearray<int> safeArr(5); 

        for (int i=0; i<5; ++i) {
            safeArr[i] = i * 10;
        }
        cout<< "Element at index 0: " << safeArr[0] << endl;
        cout<< "Element at index 4: " << safeArr[4] << endl;
        cout<< "Element at index 6: " << safeArr[6] << endl;  
    }
    catch (const ArrayIndexOutOfBounds& e) {
        cerr<< "Exception caught: " << e.what() << endl;
    }
    return 0;
}