#include "../include/imeth/linear/matrix.hpp"
#include <stdexcept>
#include <cmath>

namespace imeth {

Matrix::Matrix(size_t rows, size_t cols)
    : m_data(rows, std::vector<double>(cols, 0.0)) {}

Matrix::Matrix(std::initializer_list<std::vector<double>> data)
    : m_data(data) {}

double& Matrix::operator()(size_t r, size_t c) {
    return m_data.at(r).at(c);
}

double Matrix::operator()(size_t r, size_t c) const {
    return m_data.at(r).at(c);
}

size_t Matrix::rows() const { return m_data.size(); }
size_t Matrix::cols() const { return m_data.empty() ? 0 : m_data[0].size(); }

Matrix Matrix::identity(size_t n) {
    Matrix I(n, n);
    for (size_t i = 0; i < n; ++i) I(i, i) = 1.0;
    return I;
}

Matrix Matrix::transpose() const {
    size_t r = rows(), c = cols();
    Matrix t(c, r);
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            t(j, i) = m_data[i][j];
    return t;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (cols() != rhs.rows())
        throw std::invalid_argument("Matrix dimensions mismatch for multiplication");

    Matrix result(rows(), rhs.cols());
    for (size_t i = 0; i < rows(); ++i)
        for (size_t j = 0; j < rhs.cols(); ++j)
            for (size_t k = 0; k < cols(); ++k)
                result(i, j) += m_data[i][k] * rhs(k, j);
    return result;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (rows() != rhs.rows() || cols() != rhs.cols())
        throw std::invalid_argument("Matrix dimensions mismatch for addition");

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i)
        for (size_t j = 0; j < cols(); ++j)
            result(i, j) = m_data[i][j] + rhs(i, j);
    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (rows() != rhs.rows() || cols() != rhs.cols())
        throw std::invalid_argument("Matrix dimensions mismatch for subtraction");

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i)
        for (size_t j = 0; j < cols(); ++j)
            result(i, j) = m_data[i][j] - rhs(i, j);
    return result;
}

Vector::Vector(size_t n) : m_data(n, 0.0) {}
Vector::Vector(std::initializer_list<double> data) : m_data(data) {}

double& Vector::operator[](size_t i) { return m_data.at(i); }
double Vector::operator[](size_t i) const { return m_data.at(i); }
size_t Vector::size() const { return m_data.size(); }

Vector Solver::gaussian_elimination(const Matrix& A, const Vector& b) {
    size_t n = A.rows();
    if (A.cols() != n || b.size() != n)
        throw std::invalid_argument("Matrix and vector dimension mismatch");

    Matrix M = A;
    Vector x = b;

    for (size_t i = 0; i < n; ++i) {
        double pivot = M(i, i);
        if (std::fabs(pivot) < 1e-12)
            throw std::runtime_error("Singular matrix");

        for (size_t j = i; j < n; ++j)
            M(i, j) /= pivot;
        x[i] /= pivot;

        for (size_t k = i + 1; k < n; ++k) {
            double factor = M(k, i);
            for (size_t j = i; j < n; ++j)
                M(k, j) -= factor * M(i, j);
            x[k] -= factor * x[i];
        }
    }

    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < (int)n; ++j)
            x[i] -= M(i, j) * x[j];

    return x;
}

Vector Solver::gauss_jordan(const Matrix& A, const Vector& b) {
    size_t n = A.rows();
    if (A.cols() != n || b.size() != n)
        throw std::invalid_argument("Matrix and vector dimension mismatch");

    Matrix M = A;
    Vector x = b;

    for (size_t i = 0; i < n; ++i) {
        double pivot = M(i, i);
        if (std::fabs(pivot) < 1e-12)
            throw std::runtime_error("Singular matrix");

        for (size_t j = 0; j < n; ++j)
            M(i, j) /= pivot;
        x[i] /= pivot;

        for (size_t k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = M(k, i);
            for (size_t j = 0; j < n; ++j)
                M(k, j) -= factor * M(i, j);
            x[k] -= factor * x[i];
        }
    }

    return x;
}

Vector Solver::lu_decomposition(const Matrix& A, const Vector& b) {
    size_t n = A.rows();
    if (A.cols() != n || b.size() != n)
        throw std::invalid_argument("Matrix and vector dimension mismatch");

    Matrix L(n, n), U = A;
    for (size_t i = 0; i < n; ++i) L(i, i) = 1.0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t k = i + 1; k < n; ++k) {
            double factor = U(k, i) / U(i, i);
            L(k, i) = factor;
            for (size_t j = i; j < n; ++j)
                U(k, j) -= factor * U(i, j);
        }
    }

    Vector y(n);
    for (size_t i = 0; i < n; ++i) {
        y[i] = b[i];
        for (size_t j = 0; j < i; ++j)
            y[i] -= L(i, j) * y[j];
    }

    Vector x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < (int)n; ++j)
            x[i] -= U(i, j) * x[j];
        x[i] /= U(i, i);
    }

    return x;
}

} // namespace imeth
