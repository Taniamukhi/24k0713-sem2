#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data; 
    int length; 
public:
    DynamicArray() : data(nullptr), length(0) {}
    
    DynamicArray(int n) : length(n) {
        data = new int[length](); 
    }
   
    DynamicArray(const DynamicArray& other) : length(other.length) {
        data = new int[length];
        for (int i=0; i<length; i++)
            data[i] = other.data[i];
    }
    
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }
    
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) 
		{
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i=0; i<length; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
  
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) 
		{
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    
    ~DynamicArray() {
        delete[] data;
    }
  
    int size() const {
        return length;
    }
  
    int& at(int index) {
        return data[index];
    }
    
    void resize(int newsize) {
        int* newdata = new int[newsize]();
        int minsize = (newsize < length) ? newsize : length;
        for (int i=0; i<minsize; i++)
            newdata[i] = data[i];
        delete[] data;
        data = newdata;
        length = newsize;
    }

    void print() const {
        for (int i=0; i<length; i++)
            cout<< data[i] << " ";
            cout<< endl;
    }
};

int main() {
    DynamicArray array(5);
    array.at(2) = 2;
    array.print();
    array.resize(6);
    array.print(); 
    return 0;
}
