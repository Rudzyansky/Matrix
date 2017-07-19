#ifndef GAUSS_MATRIX_H
#define GAUSS_MATRIX_H

#include <complex>

using namespace std;

class Matrix {
    int n;
public:
    complex<double> **aa;
    complex<double> *yy;

    friend const Matrix operator+(const Matrix& left, const Matrix& right);
    friend const Matrix operator-(const Matrix& left, const Matrix& right);
    friend const Matrix operator*(const Matrix& left, const Matrix& right);
    Matrix & operator=(const Matrix& right);
    friend bool operator==(const Matrix& left, const Matrix& right);
    friend bool operator!=(const Matrix& left, const Matrix& right);
    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);

    int getN();
    void print();
    Matrix();
    Matrix(int n);
    complex<double> *gauss();
    ~Matrix();
};

#endif //GAUSS_MATRIX_H
