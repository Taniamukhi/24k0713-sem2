#include <iostream>
using namespace std;

class DimensionMismatchException {
public:
    const char* what() const {
        return "Matrix dimensions do not match for the operation.";
    }
};

class IndexOutOfBoundsException {
public:
    const char* what() const {
        return "Matrix index out of bounds.";
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c, const T& initial = T()) {
        rows = r;
        cols = c;
        data = new T*[rows];
        for (int i=0; i<rows; ++i) {
            data[i] = new T[cols];
            for (int j=0; j<cols; ++j)
                data[i][j] = initial;
        }
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (int i=0; i<rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    ~Matrix() {
        for (int i=0; i<rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw IndexOutOfBoundsException();
        return data[r][c];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix result(rows, cols);
        for (int i=0; i<rows; ++i)
            for (int j=0; j<cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix result(rows, other.cols, T());
        for (int i=0; i<rows; ++i)
            for (int j=0; j<other.cols; ++j)
                for (int k=0; k<cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    void print() const {
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j)
                cout<< data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);
        A.at(0, 0) = 1; A.at(0, 1) = 2;
        A.at(1, 0) = 3; A.at(1, 1) = 4;
        B.at(0, 0) = 5; B.at(0, 1) = 6;
        B.at(1, 0) = 7; B.at(1, 1) = 8;
        Matrix<int> C = A + B;
        Matrix<int> D = A * B;
        cout<< "A + B:\n";
        C.print();
        cout<< "\nA * B:\n";
        D.print();
    }
    catch(DimensionMismatchException& e) {
        cout<< "Exception: " << e.what() << endl;
    }
    catch(IndexOutOfBoundsException& e) {
        cout<< "Exception: " << e.what() << endl;
    }
    return 0;
}