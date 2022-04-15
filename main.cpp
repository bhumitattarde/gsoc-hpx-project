#include "matrix.h"

int main() {
    matrix matrix1(3, 3);
    matrix matrix2(3, 3);
    matrix1.print();
    matrix2.print();

    matrix multiplication = matrix1 * matrix2;
    multiplication.print();

    return 0;
}