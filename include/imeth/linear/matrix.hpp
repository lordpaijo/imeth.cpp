#pragma once
#include <vector>
#include <initializer_list>

namespace imeth {
class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    Matrix(std::initializer_list<std::vector<double>> data);

    double& operator()(size_t r, size_t c);
    double operator()(size_t r, size_t c) const;

    size_t rows() const;
    size_t cols() const;

    static Matrix identity(size_t n);

    Matrix transpose() const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;

private:
    std::vector<std::vector<double>> m_data;
};

class Vector {
public:
    Vector(size_t n);
    Vector(std::initializer_list<double> data);

    double& operator[](size_t i);
    double operator[](size_t i) const;

    size_t size() const;

private:
    std::vector<double> m_data;
};

class Solver {
public:
    static Vector gaussian_elimination(const Matrix& A, const Vector& b);
    static Vector gauss_jordan(const Matrix& A, const Vector& b);
    static Vector lu_decomposition(const Matrix& A, const Vector& b);
};

} // namespace imeth
