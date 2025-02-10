#include <iostream>
using namespace std;

class matrix {
private:
    int rows;
    int columns;
    int** elements; 
public:
    matrix(int r = 0, int c = 0) {
        rows = r;
        columns = c;
        if (rows > 0 && columns > 0) {
            elements = new int*[rows];
            for (int i = 0; i < rows; i++) {
                elements[i] = new int[columns]{0}; // Initialize with zeros
            }
        } else {
            elements = nullptr;
        }
    }
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return columns;
    }
    void set_element(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < columns) {
            elements[i][j] = value;
        } else {
            cout << "Invalid position (" << i << "," << j << ")!" << endl;
        }
    }
    void display(){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
    matrix add_matrix(const matrix& other) {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrices cannot be added due to size mismatch!" << endl;
            return matrix(0, 0);
        }
        matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }
     matrix multiply_matrix(const matrix& other) {
        if (columns != other.rows) {
            cout << "Matrices cannot be multiplied due to size mismatch!" << endl;
            return matrix(0, 0);
        }
        matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r, c, value;
    cout << "Enter rows and columns for the matrices: ";
    cin >> r >> c;
    matrix m1(r, c), m2(r, c);
    cout << "Enter elements for Matrix 1:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> value;
            m1.set_element(i, j, value);
        }
    }
    cout << "Enter elements for Matrix 2:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> value;
            m2.set_element(i, j, value);
        }
    }
    cout << "\nMatrix 1:\n";
    m1.display();
    cout << "\nMatrix 2:\n";
    m2.display();
    cout << "\nResult of Matrix Addition:\n";
    matrix sum = m1.add_matrix(m2);
    sum.display();
    cout << "\nResult of Matrix Multiplication:\n";
    matrix product = m1.multiply_matrix(m2);
    product.display();
    return 0;
}