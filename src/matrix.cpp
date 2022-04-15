#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

#include "matrix.h"

using std::string;

matrix::matrix(const size_t rows, const size_t columns, bool random)
    : _rows(rows), _columns(columns), _matrix(_rows, std::vector<double>(columns)) {
    if (random) { _generate(_rows, _columns); }
}

matrix::matrix(const std::vector<std::vector<double>>& matrix)
    : _matrix(matrix), _rows(matrix.size()), _columns(matrix[0].size()) {}

// methods
void matrix::print() {
    const size_t rows = _matrix.size();
    const size_t columns = _matrix[0].size();

    std::cout << '\n';
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) { std::cout << _matrix[r][c] << ' '; }
        std::cout << '\n';
    };
    std::cout << '\n';
};

size_t matrix::rows() const noexcept { return _rows; }

size_t matrix::colmuns() const noexcept { return _columns; }

// operator overloads
matrix matrix::operator*(const matrix& rhs) { return _multiply(*this, rhs); }

double matrix::operator()(int rowPos, int columnPos) const { return _matrix[rowPos][columnPos]; }

bool matrix::_generate(const size_t rows, const size_t columns) {
    std::mt19937 randEngine(std::random_device {}());
    std::uniform_real_distribution<double> randDistribution(0.1, 1000.0);

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < columns; c++) { _matrix[r][c] = randDistribution(randEngine); };
    };
    return true;
}

matrix matrix::_multiply(const matrix& matrix1, const matrix& matrix2) {
    const size_t R1 = matrix1.rows();
    const size_t R2 = matrix2.rows();
    const size_t C1 = matrix1.colmuns();
    const size_t C2 = matrix2.colmuns();
    if (R1 == 0 || R2 == 0 || C1 != R2) { throw std::runtime_error("invalid matrices"); }

    std::vector<std::vector<double>> result(R1, std::vector<double>(C2));
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < R2; k++) { result[i][j] += matrix1(i, k) * matrix2(k, j); }
        }
    }

    return matrix(result);
}