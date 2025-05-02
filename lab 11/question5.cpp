#include <iostream>
#include <stdexcept>
using namespace std;

class Stackunderflowexception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Attempt to pop or access top from an empty stack!";
    }
};

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topindex;
public:
    Stack(int cap) : capacity(cap), topindex(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (topindex == capacity - 1) {
            cout<< "Stack overflow: Cannot push, stack is full!" << endl;
            return;
        }
        arr[++topindex] = value;
    }

    void pop() {
        if (topindex == -1) {
            throw Stackunderflowexception(); 
        }
        topindex--;
    }

    T top() {
        if (topindex == -1) {
            throw Stackunderflowexception(); 
        }
        return arr[topindex];
    }

    bool isEmpty() const {
        return topindex == -1;
    }
};

int main() {
    try {
        Stack<int> stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        cout<< "Top element: " << stack.top() << endl;  
        stack.pop();
        cout<< "Top element after pop: " << stack.top() << endl; 
        stack.pop();
        stack.pop();
        stack.pop(); 
        stack.pop();
    } catch (const Stackunderflowexception& e) {
        cout<< "Exception caught: " << e.what() << endl;
    }
    return 0;
}
