#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
    int rows;
    int cols;

public:
    Matrix() : rows(0), cols(0) {}

    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        matrix.resize(rows, vector<int>(cols, 0));
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        matrix = other.matrix;
    }

    friend istream& operator>>(istream& CIN, Matrix& mat){
    	for(int i=0;i<mat.rows;i++){
    		for(int j=0;j<mat.cols;j++){
    			CIN>>mat.matrix[i][j];
			}
		}
		return CIN;
	}

    friend ostream& operator<<(ostream &out, Matrix &mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                out << mat.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    Matrix operator+(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout<<"error"<<endl;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout<<"error"<<endl;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix &other) {
        if (cols != other.rows) {
            cout<<"error"<<endl;
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    ~Matrix() {}
};

int main() {
	int row, col;
	cout<<"Enter the rows and column for both matrix:";
	cin>>row>>col;
    Matrix mat1(row,col), mat2(row,col);
    cout << "Enter dimensions of matrix 1 (rows cols): ";
    cin >> mat1;
    cout << "Enter dimensions of matrix 2 (rows cols): ";
    cin >> mat2;

    cout << "Matrix Addition Result:\n";
    cout<<(mat1+mat2)<<endl;

    cout << "Matrix Subtraction Result:\n";
    cout<<(mat1-mat2)<<endl;

    cout << "Matrix Multiplication Result:\n";
    cout<<(mat1*mat2)<<endl;
    
    
    return 0;
}
