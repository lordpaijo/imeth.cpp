# Matrix

I genuinely don't know what matrix or vector is (besides them being a dynamic alternative for arrays in C++). I mean, what do you expect from a 9th grader?
But, here the chapter `matrix.hpp`, exists...

```cpp
#include <imeth/linear/matrix.hpp>
```

## Classes

The matrix module contains three main classes:
- **Matrix** - Represents a 2D matrix and provides matrix operations
- **Vector** - Represents a mathematical vector (1D array of numbers)
- **Solver** - Provides methods for solving systems of linear equations

---

## Matrix

A 2D array of numbers that supports mathematical operations like addition, multiplication, and transposition.

### Constructors

- `Matrix(size_t rows, size_t cols)` - Creates a matrix with specified dimensions (initialized to zero)
- `Matrix(std::initializer_list<std::vector<double>> data)` - Creates a matrix from a list of rows

### Element Access

- `operator()(size_t r, size_t c) → double&` - Accesses element at row r, column c (modifiable)
- `operator()(size_t r, size_t c) const → double` - Accesses element at row r, column c (read-only)

### Properties

- `rows() const → size_t` - Returns the number of rows
- `cols() const → size_t` - Returns the number of columns

### Static Methods

- `identity(size_t n) → Matrix` - Creates an n×n identity matrix (1s on diagonal, 0s elsewhere)

### Operations

- `transpose() const → Matrix` - Returns the transpose (rows ↔ columns)
- `operator*(const Matrix& rhs) const → Matrix` - Matrix multiplication
- `operator+(const Matrix& rhs) const → Matrix` - Matrix addition
- `operator-(const Matrix& rhs) const → Matrix` - Matrix subtraction

### Example Usage

```cpp
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Create a 2×3 matrix
    imeth::Matrix A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "Matrix A is " << A.rows() << "×" << A.cols() << "\n";

    // Access elements
    std::cout << "A(0,0) = " << A(0, 0) << "\n";  // 1
    std::cout << "A(1,2) = " << A(1, 2) << "\n";  // 6

    // Modify element
    A(0, 0) = 10;

    // Transpose
    imeth::Matrix A_T = A.transpose();
    std::cout << "Transpose is " << A_T.rows() << "×" << A_T.cols() << "\n";  // 3×2

    // Create identity matrix
    imeth::Matrix I = imeth::Matrix::identity(3);
    // I = [[1, 0, 0],
    //      [0, 1, 0],
    //      [0, 0, 1]]

    return 0;
}
```

### More Examples

```cpp
// Matrix addition
imeth::Matrix A = {{1, 2}, {3, 4}};
imeth::Matrix B = {{5, 6}, {7, 8}};
imeth::Matrix C = A + B;  // {{6, 8}, {10, 12}}

// Matrix multiplication
imeth::Matrix D = {{1, 2}, {3, 4}};
imeth::Matrix E = {{2, 0}, {1, 2}};
imeth::Matrix F = D * E;  // {{4, 4}, {10, 8}}

// Matrix subtraction
imeth::Matrix G = B - A;  // {{4, 4}, {4, 4}}
```

---

## Vector

A 1D array of numbers (essentially a column vector in mathematical terms).

### Constructors

- `Vector(size_t n)` - Creates a vector of size n (initialized to zero)
- `Vector(std::initializer_list<double> data)` - Creates a vector from a list of values

### Element Access

- `operator[](size_t i) → double&` - Accesses element at index i (modifiable)
- `operator[](size_t i) const → double` - Accesses element at index i (read-only)

### Properties

- `size() const → size_t` - Returns the number of elements

### Example Usage

```cpp
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Create a vector
    imeth::Vector v = {1.0, 2.0, 3.0, 4.0};

    std::cout << "Vector size: " << v.size() << "\n";  // 4

    // Access elements
    std::cout << "v[0] = " << v[0] << "\n";  // 1.0
    std::cout << "v[2] = " << v[2] << "\n";  // 3.0

    // Modify element
    v[1] = 5.0;

    // Create empty vector and fill it
    imeth::Vector u(5);
    for (size_t i = 0; i < u.size(); ++i) {
        u[i] = i * 2.0;
    }

    return 0;
}
```

---

## Solver

Provides numerical methods for solving systems of linear equations Ax = b, where A is a matrix, x is the unknown vector, and b is the result vector.

### Methods

- `gaussian_elimination(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using Gaussian elimination with back substitution
- `gauss_jordan(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using Gauss-Jordan elimination (reduced row echelon form)
- `lu_decomposition(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using LU decomposition (factors A = LU)

### Example Usage

```cpp
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Solve the system:
    // 2x + 3y = 8
    // x - y = 1

    imeth::Matrix A = {
        {2, 3},
        {1, -1}
    };

    imeth::Vector b = {8, 1};

    // Method 1: Gaussian elimination
    imeth::Vector x1 = imeth::Solver::gaussian_elimination(A, b);
    std::cout << "Solution (Gaussian): x = " << x1[0] << ", y = " << x1[1] << "\n";

    // Method 2: Gauss-Jordan
    imeth::Vector x2 = imeth::Solver::gauss_jordan(A, b);
    std::cout << "Solution (Gauss-Jordan): x = " << x2[0] << ", y = " << x2[1] << "\n";

    // Method 3: LU decomposition
    imeth::Vector x3 = imeth::Solver::lu_decomposition(A, b);
    std::cout << "Solution (LU): x = " << x3[0] << ", y = " << x3[1] << "\n";

    return 0;
}
```

### More Examples

```cpp
// Solve a 3×3 system:
// x + 2y + z = 6
// 2x + y + z = 6
// x + y + 2z = 7

imeth::Matrix A = {
    {1, 2, 1},
    {2, 1, 1},
    {1, 1, 2}
};

imeth::Vector b = {6, 6, 7};

imeth::Vector solution = imeth::Solver::gaussian_elimination(A, b);

std::cout << "x = " << solution[0] << "\n";  // x = 1
std::cout << "y = " << solution[1] << "\n";  // y = 2
std::cout << "z = " << solution[2] << "\n";  // z = 2

// Verify solution: A * x = b
for (size_t i = 0; i < A.rows(); ++i) {
    double result = 0;
    for (size_t j = 0; j < A.cols(); ++j) {
        result += A(i, j) * solution[j];
    }
    std::cout << "Row " << i << " check: " << result << " = " << b[i] << "\n";
}
```

## Mathematical Background

**Matrix** - A rectangular array of numbers arranged in rows and columns. Matrices are used to represent linear transformations and systems of equations.

**Vector** - A one-dimensional array of numbers. In this context, it represents either the coefficients on the right side of equations (vector b) or the solution values (vector x).

**System of Linear Equations** - Multiple equations like:
```
a₁₁x₁ + a₁₂x₂ + ... = b₁
a₂₁x₁ + a₂₂x₂ + ... = b₂
...
```

**Solving Methods:**
- **Gaussian Elimination** - Transforms the system to upper triangular form, then uses back substitution
- **Gauss-Jordan** - Reduces the matrix to reduced row echelon form (identity matrix)
- **LU Decomposition** - Factors matrix A into lower (L) and upper (U) triangular matrices
