#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;

class matrix {
  public:
    // constructors
    matrix() = delete;
    matrix(const size_t rows, const size_t columns, bool random = true);
    matrix(const std::vector<std::vector<double>>& matrix);

    // methods
    void print();
    size_t rows() const noexcept;
    size_t colmuns() const noexcept;

    // operator overloads
    matrix operator*(const matrix& rhs);
    double operator()(int rowPos, int columnPos) const;

  private:
    // member vars
    const size_t _rows = 0;
    const size_t _columns = 0;
    std::vector<std::vector<double>> _matrix {};

    // methods
    bool _generate(const size_t rows, const size_t columns);
    matrix _multiply(const matrix& matrix1, const matrix& matrix2);
};