#include "Matrix.h"

const Matrix operator+(const Matrix &left, const Matrix &right) {
    if (left.n != right.n) return 0;
    Matrix *matrix = new Matrix(left.n);
    for (int i = 0; i < left.n; ++i) {
        for (int j = 0; j < left.n; ++j) {
            matrix->aa[i][j] = left.aa[i][j] + right.aa[i][j];
        }
        matrix->yy[i] = left.yy[i] + right.yy[i];
    }
    return *matrix;
}

const Matrix operator-(const Matrix &left, const Matrix &right) {
    if (left.n != right.n) return 0;
    Matrix *matrix = new Matrix(left.n);
    for (int i = 0; i < left.n; ++i) {
        for (int j = 0; j < left.n; ++j) {
            matrix->aa[i][j] = left.aa[i][j] - right.aa[i][j];
        }
        matrix->yy[i] = left.yy[i] - right.yy[i];
    }
    return *matrix;
}

const Matrix operator*(const Matrix &left, const Matrix &right) {
    if (left.n != right.n) return 0;
    Matrix *matrix = new Matrix(left.n);
    for (int i = 0; i < left.n; ++i) {
        for (int j = 0; j < left.n; ++j) {
            matrix->aa[i][j] = left.aa[i][j] * right.aa[i][j];
        }
        matrix->yy[i] = left.yy[i] * right.yy[i];
    }
    return *matrix;
}

bool operator==(const Matrix &left, const Matrix &right) {
    if (left.n != right.n) return false;
    for (int i = 0; i < left.n; ++i) {
        for (int j = 0; j < left.n; ++j) {
            if (left.aa[i][j] == right.aa[i][j]) continue;
            return false;
        }
        if (left.yy[i] == right.yy[i]) continue;
        return false;
    }
    return true;
}

bool operator!=(const Matrix &left, const Matrix &right) {
    if (left.n != right.n) return true;
    for (int i = 0; i < left.n; ++i) {
        for (int j = 0; j < left.n; ++j) {
            if (left.aa[i][j] == right.aa[i][j]) continue;
            return true;
        }
        if (left.yy[i] == right.yy[i]) continue;
        return true;
    }
    return false;
}

Matrix &Matrix::operator=(const Matrix &right) {
    if (this == &right) return *this;
    this->~Matrix();
    Matrix *matrix = new Matrix(right.n);
    for (int i = 0; i < right.n; ++i) {
        for (int j = 0; j < right.n; ++j) {
            matrix->aa[i][j] = right.aa[i][j];
        }
        matrix->yy[i] = right.yy[i];
    }
    return *matrix;
}

ostream &operator<<(ostream &os, const Matrix &m) {
    os << m.n << " ";
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            os << m.aa[i][j].real() << " " << m.aa[i][j].imag() << " ";
        }
        os <<  m.yy[i].real() << " " << m.yy[i].imag() << " ";
    }
    return os;
}

istream &operator>>(istream &is, Matrix &m) {
    double tmp;
    m.~Matrix();
    is >> m.n;
    m.aa = new complex<double> *[m.n];
    m.yy = new complex<double>[m.n];
    for (int i = 0; i < m.n; ++i) {
        m.aa[i] = new complex<double>[m.n];
        for (int j = 0; j < m.n; ++j) {
            is >> tmp;
            m.aa[i][j].real(tmp);
            is >> tmp;
            m.aa[i][j].imag(tmp);
        }
        is >> tmp;
        m.yy[i].real(tmp);
        is >> tmp;
        m.yy[i].imag(tmp);
    }
    return is;
}