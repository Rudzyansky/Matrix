#include "Matrix.h"

int main() {
    Matrix *matrix = new Matrix(3);
    matrix->aa[0][0].real(21);
    matrix->aa[0][0].imag(5);
    matrix->aa[0][1].real(-3);
    matrix->aa[0][1].imag(4);
    matrix->aa[0][2].real(4);
    matrix->aa[0][2].imag(-4);
    matrix->aa[1][0].real(-3);
    matrix->aa[1][0].imag(2);
    matrix->aa[1][1].real(8);
    matrix->aa[1][1].imag(3);
    matrix->aa[1][2].real(1);
    matrix->aa[1][2].imag(2);
    matrix->aa[2][0].real(0);
    matrix->aa[2][0].imag(18);
    matrix->aa[2][1].real(-3);
    matrix->aa[2][1].imag(0);
    matrix->aa[2][2].real(7);
    matrix->aa[2][2].imag(-17);
    matrix->yy[0].real(3);
    matrix->yy[0].imag(6);
    matrix->yy[1].real(1);
    matrix->yy[1].imag(13);
    matrix->yy[2].real(0);
    matrix->yy[2].imag(10);
    matrix->print();
    matrix->gauss();
    matrix->print();
    return 0;
}