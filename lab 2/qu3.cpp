#include <iostream>
using namespace std;

int* memoryallocation(int size) {
    return new int[size];
}

int* resize_array(int* pre_array, int pre_size, int new_size) {
    int* new_array = memoryallocation(new_size);
    int i;
    for (i=0; i<pre_size; i++) {
        new_array[i] = pre_array[i];
    }
    delete[] pre_array;
    return new_array;
}

int main() {
    int count = 0;
    int size = 5;
    int* array = memoryallocation(size);
    cout<< "Enter Elements of Array (-1 to exit): " << endl;
    int input;
    while (true) {
        cin>> input;
        if (input == -1) {
            break;
        }
        if (count == size) {
            cout<< "Resizing the Array. Current size: " << size << endl;
            array = resize_array(array, size, size * 2);
            size *= 2;
            cout<< "New size: " << size << endl;
        }
        array[count++] = input;
    }
    array = resize_array(array, size, count);

    cout << "Final Array Size: " << count << endl;
    cout << "original Array: ";
    int i;
    for (i=0; i<count; i++) {
        cout<< array[i] << " ";
    }
    cout<< endl;
    return 0;
}
