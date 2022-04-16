#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;

/**
 * @brief represents a mathematical matrix
 */
class matrix {
  public:
    // constructors
    matrix() = delete;

    /**
     * @brief construct a new matrix object
     *
     * @param rows number of rows
     * @param columns number of columns
     * @param random flag to indicate random generation of matrix elements
     */
    matrix(const size_t rows, const size_t columns, bool random = true);

    /**
     * @brief construct a new matrix object
     *
     * @param matrix matrix elements
     */
    matrix(const std::vector<std::vector<double>>& matrix);

    // methods
    /**
     * @brief print the matrix to `std::cout`
     */
    void print();

    /**
     * @brief get number of rows
     *
     * @return size_t number of rows
     */
    size_t rows() const noexcept;

    /**
     * @brief get number of columns
     *
     * @return size_t number of columns
     */
    size_t colmuns() const noexcept;

    // operator overloads
    /**
     * @brief multiply matrices
     *
     * @param rhs matrix to multiply with
     * @return matrix resultant matrix
     */
    matrix operator*(const matrix& rhs);

    /**
     * @brief get an element
     *
     * @param rowPos row number of the element
     * @param columnPos column number of the element
     * @return double element
     */
    double operator()(int rowPos, int columnPos) const;

  private:
    // member vars
    const size_t _rows = 0;
    const size_t _columns = 0;
    std::vector<std::vector<double>> _matrix {};

    // methods

    /**
     * @brief fill the matrix random numbers
     *
     * @param rows number of rows
     * @param columns number of columns
     * @return true if matrix was filled successfully
     * @return false if filling the matrix failed
     */
    bool _generate(const size_t rows, const size_t columns);

    /**
     * @brief multiply two matrices
     *
     * @param matrix1 matrix 1
     * @param matrix2 matrix 2
     * @return matrix resultant matrix
     */
    matrix _multiply(const matrix& matrix1, const matrix& matrix2);
};