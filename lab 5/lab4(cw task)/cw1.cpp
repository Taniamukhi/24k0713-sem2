#include<iostream>
#include<vector>
using namespace std;

class matrix{
    private:
    int rows, columns;
    double **data;
    // vector< vector<int> > matrix;

    public:
    matrix():rows(0),columns(0), data(nullptr){}
    matrix(int rows, int columns): rows(rows), columns(columns){
        data = new double*[rows];
        for(int i=0; i<rows; i++){
            data[i]= new double[columns];
            for(int j=0; j<columns; j++){
                data[i][j]= 0.0;
            }
        }
    }
    matrix(const matrix& other) : rows(other.rows), columns(other.columns){
        data = new double*[rows];
        for(int i=0; i<rows; i++){
            data[i]= new double[columns];
            for(int j=0; j<columns; j++){
                data[i][j]= other.data[i][j];
            }
        }
    }
    matrix(matrix&& other) noexcept : rows(other.rows), columns(other.columns), data(other.data){
        other.rows = other.columns = 0;
        other.data = nullptr;
    }

    ~matrix(){
        if(data != nullptr){
            for(int i=0; i<rows; i++){
                delete[] data[i];
            }
            delete data;
        }
    }

    int getrows(){
        return rows;
    }

    int getcolumns(){
        return columns;
    }

    void fill(double value){
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                data[i][j]= value;
            }
        }
    }

    matrix transpose()
    {
        matrix result(columns, rows);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
               result.data[i][j] = data[i][j]; 
            }
        }
         return result;
    }

    void print(){
       
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                cout << data[i][j] << " ";
            }
            cout<< endl;
        }
    }

};

int main(){
    matrix a(1,2);
    a.fill(3);
    cout<< "Matrix a: "<< endl;
    a.print();
    matrix b = a;
    cout<< "Matrix b: "<< endl;
    b.print();
    matrix c = std::move(a);
    cout<< "Matrix c: "<< endl;
    c.print();
    cout<< "Transpose of matrix c: "<< endl;
    matrix d = c.transpose();
    d.print();
	return 0;
}
