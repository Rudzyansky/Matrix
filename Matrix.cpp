#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {
    Matrix::n = 0;
    Matrix::aa = nullptr;
    Matrix::yy = nullptr;
}

Matrix::Matrix(int n) {
    Matrix::n = n;
    Matrix::aa = new complex<double> *[n];
    for (int i = 0; i < n; ++i) {
        Matrix::aa[i] = new complex<double>[n];
    }
    Matrix::yy = new complex<double>[n];
}

Matrix::~Matrix() {
    for (int i = 0; i < n; ++i) {
        delete[] aa[i];
    }
    delete[] aa;
    delete[] yy;
}

void Matrix::print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << aa[i][j].real() << " + " << aa[i][j].imag() << "i; \t";
        cout << "| " << yy[i].real() << " + " << yy[i].imag() << "i" << endl;
    }
    cout << endl;
}

complex<double> *Matrix::gauss() {
    complex<double> *x;
    double max;
    int k, index;
    const double eps = 0.00001;
    x = new complex<double>[n];
    k = 0;
    while (k < n) {
        max = abs(aa[k][k].real());
        index = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(aa[i][k].real()) > max) {
                max = abs(aa[i][k]);
                index = i;
            }
        }
        if (max < eps) {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        // Перестановка строк
        for (int j = 0; j < n; j++) {
            complex<double> temp = aa[k][j];
            aa[k][j] = aa[index][j];
            aa[index][j] = temp;
        }
        complex<double> temp = yy[k];
        yy[k] = yy[index];
        yy[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++) {
            complex<double> temp1 = aa[i][k];
            if (abs(temp1) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++) {
                aa[i][j] = aa[i][j] / temp1;
            }
            yy[i] = yy[i] / temp1;
            if (i == k) continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++) {
                aa[i][j] = aa[i][j] - aa[k][j];
            }
            yy[i] = yy[i] - yy[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--) {
        x[k] = yy[k];
        for (int i = 0; i < k; i++) {
            yy[i] = yy[i] - aa[i][k] * x[k];
            aa[i][k] = 0;
        }
    }
    return x;
}

int Matrix::getN() {
    return n;
}