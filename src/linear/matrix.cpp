#include "../include/imeth/linear/matrix.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <stdexcept>

namespace imeth {

Matrix::Matrix(size_t rows, size_t cols)
    : m_data(rows * cols, 0.0), m_rows(rows), m_cols(cols) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> data)
    : m_rows(data.size()), m_cols(data.size() > 0 ? data.begin()->size() : 0) {
    m_data.reserve(m_rows * m_cols);
    for (const auto& row : data) {
        if (row.size() != m_cols)
            throw std::invalid_argument("All rows must have the same number of columns");
        for (double val : row)
            m_data.push_back(val);
    }
}

double& Matrix::operator()(size_t r, size_t c) {
    if (r >= m_rows || c >= m_cols)
        throw std::out_of_range("Matrix index out of range");
    return m_data[r * m_cols + c];
}

double Matrix::operator()(size_t r, size_t c) const {
    if (r >= m_rows || c >= m_cols)
        throw std::out_of_range("Matrix index out of range");
    return m_data[r * m_cols + c];
}

size_t Matrix::rows() const { return m_rows; }
size_t Matrix::cols() const { return m_cols; }

Matrix Matrix::identity(size_t n) {
    Matrix I(n, n);
    for (size_t i = 0; i < n; ++i)
        I(i, i) = 1.0;
    return I;
}

Matrix Matrix::transpose() const {
    Matrix t(m_cols, m_rows);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            t(j, i) = (*this)(i, j);
    return t;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (m_cols != rhs.m_rows)
        throw std::invalid_argument("Matrix dimensions mismatch for multiplication");

    Matrix result(m_rows, rhs.m_cols);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < rhs.m_cols; ++j)
            for (size_t k = 0; k < m_cols; ++k)
                result(i, j) += (*this)(i, k) * rhs(k, j);
    return result;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
        throw std::invalid_argument("Matrix dimensions mismatch for addition");

    Matrix result(m_rows, m_cols);
    for (size_t i = 0; i < m_data.size(); ++i)
        result.m_data[i] = m_data[i] + rhs.m_data[i];
    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
        throw std::invalid_argument("Matrix dimensions mismatch for subtraction");

    Matrix result(m_rows, m_cols);
    for (size_t i = 0; i < m_data.size(); ++i)
        result.m_data[i] = m_data[i] - rhs.m_data[i];
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
        if (imeth::Arithmetic::absolute(pivot) < 1e-12)
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
        if (imeth::Arithmetic::absolute(pivot) < 1e-12)
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