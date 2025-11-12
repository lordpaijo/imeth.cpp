# Matrix

The matrix chapter provides classes and methods for linear algebra operations, including matrix manipulation, vector operations, and solving systems of linear equations.

```c++
#include <imeth/linear/matrix.hpp>
```

## Overview

Matrices are rectangular grids of numbers that represent:
- Systems of equations with multiple unknowns
- Transformations (rotations, scaling) in graphics and physics
- Data tables and organized information
- Network connections (adjacency matrices)

This module helps you solve problems like:
- "I have 3 equations with 3 unknowns - what are the solutions?"
- "How do I rotate a 3D object in space?"
- "What's the result of applying multiple transformations?"

---

## Classes Overview

The matrix module contains three main classes:
- **Matrix** - 2D matrix with mathematical operations
- **Vector** - 1D array of numbers
- **Solver** - Methods for solving systems of linear equations

---

## Matrix Class

A rectangular array of numbers arranged in rows and columns.

### Constructors

```c++
Matrix(size_t rows, size_t cols);
Matrix(std::initializer_list<std::vector<double>> data);
```

**Examples:**
```c++
// Create 3×4 zero matrix
imeth::Matrix A(3, 4);

// Create matrix with values
imeth::Matrix B = {
    {1, 2, 3},
    {4, 5, 6}
};

// Single-row matrix
imeth::Matrix row = {{1, 2, 3, 4}};

// Single-column matrix
imeth::Matrix col = {{1}, {2}, {3}, {4}};
```

---

### Element Access

```c++
double& operator()(size_t r, size_t c);
double operator()(size_t r, size_t c) const;
```

Access or modify elements at row r, column c (0-indexed).

**Examples:**
```c++
imeth::Matrix M = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

double val = M(0, 0);  // 1 (top-left)
M(1, 1) = 20;          // Modify center

// Loop through elements
for (size_t i = 0; i < M.rows(); ++i) {
    for (size_t j = 0; j < M.cols(); ++j) {
        std::cout << M(i, j) << " ";
    }
}

// Set diagonal to 1
for (size_t i = 0; i < std::min(M.rows(), M.cols()); ++i) {
    M(i, i) = 1.0;
}
```

**Real-world:** Image processing, data analysis, game transformations

---

### Properties

```c++
size_t rows() const;
size_t cols() const;
```

**Examples:**
```c++
imeth::Matrix A(3, 4);
size_t r = A.rows();  // 3
size_t c = A.cols();  // 4

// Check if square
bool is_square = (A.rows() == A.cols());

// Validate operations
bool can_multiply = (A.cols() == B.rows());
```

---

### Identity Matrix

```c++
static Matrix identity(size_t n);
```

Creates n×n identity matrix with 1s on diagonal, 0s elsewhere.

**Examples:**
```c++
imeth::Matrix I3 = imeth::Matrix::identity(3);
// [[1, 0, 0],
//  [0, 1, 0],
//  [0, 0, 1]]

// Identity property: I × A = A × I = A
imeth::Matrix A = {{2, 3}, {4, 5}};
imeth::Matrix I2 = imeth::Matrix::identity(2);
imeth::Matrix result = I2 * A;  // equals A
```

**Real-world:** Default transformations, checking matrix inverses, initialization

---

### Transpose

```c++
Matrix transpose() const;
```

Returns matrix with rows and columns swapped.

**Formula:** A^T[i][j] = A[j][i]

**Examples:**
```c++
imeth::Matrix A = {
    {1, 2, 3},
    {4, 5, 6}
};  // 2×3

imeth::Matrix A_T = A.transpose();
// [[1, 4],
//  [2, 5],
//  [3, 6]]  (3×2)

// Column vector to row vector
imeth::Matrix col = {{1}, {2}, {3}};
imeth::Matrix row = col.transpose();  // {{1, 2, 3}}

// Double transpose returns original
imeth::Matrix original = A.transpose().transpose();  // equals A
```

**Properties:**
- (A^T)^T = A
- (A + B)^T = A^T + B^T
- (AB)^T = B^T A^T

**Real-world:** Converting vector formats, matrix calculus, covariance matrices

---

### Addition

```c++
Matrix operator+(const Matrix& rhs) const;
```

Element-wise addition. Matrices must have same dimensions.

**Examples:**
```c++
imeth::Matrix A = {{1, 2}, {3, 4}};
imeth::Matrix B = {{5, 6}, {7, 8}};

imeth::Matrix C = A + B;
// [[6, 8],
//  [10, 12]]

// Add identity to diagonal
imeth::Matrix I = imeth::Matrix::identity(2);
imeth::Matrix result = A + I;
// [[2, 2],
//  [3, 5]]

// Chain additions
imeth::Matrix total = A + B + C;
```

**Properties:** Commutative, associative, A + 0 = A

**Real-world:** Image blending, summing force matrices, aggregating data

---

### Subtraction

```c++
Matrix operator-(const Matrix& rhs) const;
```

Element-wise subtraction. Matrices must have same dimensions.

**Examples:**
```c++
imeth::Matrix A = {{5, 6}, {7, 8}};
imeth::Matrix B = {{1, 2}, {3, 4}};

imeth::Matrix C = A - B;
// [[4, 4],
//  [4, 4]]

// Calculate change
imeth::Matrix original = {{10, 20}, {30, 40}};
imeth::Matrix modified = {{12, 18}, {32, 38}};
imeth::Matrix change = modified - original;

// Subtract from itself
imeth::Matrix zero = A - A;  // All zeros
```

**Real-world:** Frame differences in video, error calculation, change detection

---

### Multiplication

```c++
Matrix operator*(const Matrix& rhs) const;
```

Matrix multiplication using dot product of rows and columns.

**Rule:** A.cols() must equal B.rows() for A × B

**Formula:** C[i][j] = Σ(A[i][k] × B[k][j])

**Examples:**
```c++
imeth::Matrix A = {{1, 2}, {3, 4}};
imeth::Matrix B = {{5, 6}, {7, 8}};

imeth::Matrix C = A * B;
// C[0][0] = 1×5 + 2×7 = 19
// C[0][1] = 1×6 + 2×8 = 22
// [[19, 22],
//  [43, 50]]

// Multiply 2×3 and 3×2 → 2×2
imeth::Matrix D = {{1, 2, 3}, {4, 5, 6}};
imeth::Matrix E = {{7, 8}, {9, 10}, {11, 12}};
imeth::Matrix F = D * E;  // [[58, 64], [139, 154]]

// Identity property
imeth::Matrix I = imeth::Matrix::identity(2);
imeth::Matrix unchanged = A * I;  // equals A

// Matrix powers
imeth::Matrix A_squared = A * A;
```

**Properties:**
- NOT commutative: A × B ≠ B × A
- Associative: (AB)C = A(BC)
- Distributive: A(B + C) = AB + AC
- Dimension rule: (m×n) × (n×p) = (m×p)

**Real-world:** 3D graphics transformations, neural networks, coordinate systems

---

## Vector Class

One-dimensional array of numbers.

### Constructors

```c++
Vector(size_t n);
Vector(std::initializer_list<double> data);
```

**Examples:**
```c++
// Size 5, initialized to zero
imeth::Vector v1(5);

// With initial values
imeth::Vector v2 = {1.0, 2.0, 3.0, 4.0};

// 3D position vector
imeth::Vector position = {10.5, 20.3, 15.7};

// Unit vectors
imeth::Vector x_axis = {1, 0, 0};
imeth::Vector y_axis = {0, 1, 0};
imeth::Vector z_axis = {0, 0, 1};
```

**Real-world:** Coordinates, velocities, feature vectors, data samples

---

### Element Access

```c++
double& operator[](size_t i);
double operator[](size_t i) const;
```

Access element at index i (0-indexed).

**Examples:**
```c++
imeth::Vector v = {10, 20, 30, 40, 50};

double first = v[0];   // 10
v[2] = 300;            // Modify

// Iterate
for (size_t i = 0; i < v.size(); ++i) {
    v[i] *= 2;  // Double each element
}

// Find maximum
double max_val = v[0];
for (size_t i = 1; i < v.size(); ++i) {
    if (v[i] > max_val) max_val = v[i];
}

// Compute sum
double sum = 0;
for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];
}
```

---

### Properties

```c++
size_t size() const;
```

Returns number of elements.

**Examples:**
```c++
imeth::Vector v = {1, 2, 3, 4, 5};
size_t len = v.size();  // 5

// Validate operations
bool can_add = (a.size() == b.size());

// Check matrix compatibility
bool compatible = (M.cols() == v.size());
```

---

## Solver Class

Solves systems of linear equations: **Ax = b**

Where:
- **A** is n×n coefficient matrix
- **x** is unknown vector
- **b** is result vector

---

### Gaussian Elimination

```c++
static Vector gaussian_elimination(const Matrix& A, const Vector& b);
```

Forward elimination + back substitution.

**Examples:**
```c++
// Solve: 2x + 3y = 8
//        x - y = 1

imeth::Matrix A = {{2, 3}, {1, -1}};
imeth::Vector b = {8, 1};

imeth::Vector sol = imeth::Solver::gaussian_elimination(A, b);
// x = 2.2, y = 1.2

// 3×3 system
imeth::Matrix A3 = {
    {1, 2, 1},
    {2, 1, 1},
    {1, 1, 2}
};
imeth::Vector b3 = {6, 6, 7};
imeth::Vector sol3 = imeth::Solver::gaussian_elimination(A3, b3);
```

**Best for:** General purpose, single solve

**Real-world:** Circuit analysis, structural engineering, economics

**Complexity:** O(n³)

---

### Gauss-Jordan Elimination

```c++
static Vector gauss_jordan(const Matrix& A, const Vector& b);
```

Reduces to identity matrix (no back substitution needed).

**Examples:**
```c++
imeth::Matrix A = {{2, 3}, {1, -1}};
imeth::Vector b = {8, 1};

imeth::Vector sol = imeth::Solver::gauss_jordan(A, b);
// x = 2.2, y = 1.2

// 4×4 system
imeth::Matrix A4 = {
    {4, 1, 0, 0},
    {1, 4, 1, 0},
    {0, 1, 4, 1},
    {0, 0, 1, 4}
};
imeth::Vector b4 = {5, 6, 6, 5};
imeth::Vector sol4 = imeth::Solver::gauss_jordan(A4, b4);
```

**Best for:** Finding inverses, multiple systems

**Real-world:** Linear programming, regression analysis

**Complexity:** O(n³)

---

### LU Decomposition

```c++
static Vector lu_decomposition(const Matrix& A, const Vector& b);
```

Factors A = LU, then solves Ly = b and Ux = y.

**Examples:**
```c++
imeth::Matrix A = {{2, 3}, {1, -1}};
imeth::Vector b = {8, 1};

imeth::Vector sol = imeth::Solver::lu_decomposition(A, b);
// x = 2.2, y = 1.2

// Multiple solves with same A (efficient!)
imeth::Vector b1 = {8, 1};
imeth::Vector b2 = {10, 2};
imeth::Vector b3 = {5, 0};

imeth::Vector sol1 = imeth::Solver::lu_decomposition(A, b1);
imeth::Vector sol2 = imeth::Solver::lu_decomposition(A, b2);
imeth::Vector sol3 = imeth::Solver::lu_decomposition(A, b3);
```

**Best for:** Multiple solves with same coefficient matrix

**Real-world:** Simulations, finite element analysis, control systems

**Complexity:** O(n³) factorization + O(n²) per solve

---

## Solver Comparison

| Method | Best Use | Complexity | Advantage |
|--------|----------|------------|-----------|
| **Gaussian** | Single solve | O(n³) | Simple, reliable |
| **Gauss-Jordan** | Need inverse | O(n³) | No back substitution |
| **LU** | Multiple solves | O(n³) + O(kn²) | Efficient for k solves |

---

## Complete Examples

### Traffic Flow Analysis

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Conservation law: flow in = flow out
    // x1 + x2 = 100
    // x2 + x3 = 150
    // x3 + x4 = 80
    // x4 + x1 = 130
    
    imeth::Matrix A = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 1}
    };
    
    imeth::Vector b = {100, 150, 80, 130};
    imeth::Vector flow = imeth::Solver::gaussian_elimination(A, b);
    
    std::cout << "Road flows (vehicles/hour):\n";
    for (size_t i = 0; i < flow.size(); ++i) {
        std::cout << "Road " << i+1 << ": " << flow[i] << "\n";
    }
    
    return 0;
}
```

---

### 3D Rotation

```c++
#include <imeth/linear/matrix.hpp>
#include <cmath>

int main() {
    // Rotate point (1,0,0) by 90° around Z-axis
    double angle = M_PI / 2;
    
    imeth::Matrix rotation = {
        {std::cos(angle), -std::sin(angle), 0},
        {std::sin(angle), std::cos(angle), 0},
        {0, 0, 1}
    };
    
    imeth::Matrix point = {{1}, {0}, {0}};
    imeth::Matrix rotated = rotation * point;
    
    std::cout << "Rotated: (" << rotated(0,0) << ", " 
              << rotated(1,0) << ", " << rotated(2,0) << ")\n";
    // Result: (0, 1, 0)
    
    return 0;
}
```

---

### Portfolio Optimization

```c++
#include <imeth/linear/matrix.hpp>

int main() {
    // Allocate $10,000 across 3 investments
    imeth::Matrix constraints = {
        {1, 1, 1},          // Total = $10,000
        {0.05, 0.08, 0.12}, // Expected return 8%
        {1, -2, 1}          // Risk balance
    };
    
    imeth::Vector targets = {10000, 800, 0};
    imeth::Vector allocation = imeth::Solver::gauss_jordan(constraints, targets);
    
    std::cout << "Allocation:\n";
    for (size_t i = 0; i < allocation.size(); ++i) {
        std::cout << "Investment " << i+1 << ": $" << allocation[i] << "\n";
    }
    
    return 0;
}
```

---

## Tips

- **Dimension compatibility**: Check before operations (A.cols() == B.rows() for multiplication)
- **Zero-based indexing**: Valid indices for 3×3 matrix are (0,0) to (2,2)
- **Order matters**: A × B ≠ B × A for matrix multiplication
- **Choose solver wisely**: Gaussian for one solve, LU for multiple solves
- **Verify solutions**: Substitute back into original equations
- **Identity baseline**: Use I as starting point for transformations

---

## Quick Reference

| Operation | Syntax | Requirement |
|-----------|--------|-------------|
| Create matrix | `Matrix A(m, n)` or `{{...}}` | - |
| Access element | `A(i, j)` | 0 ≤ i < rows, 0 ≤ j < cols |
| Add/Subtract | `A + B`, `A - B` | Same dimensions |
| Multiply | `A * B` | A.cols() == B.rows() |
| Transpose | `A.transpose()` | - |
| Identity | `Matrix::identity(n)` | Square n×n |
| Solve system | `Solver::gaussian_elimination(A, b)` | Square matrix A |

**Properties:**
- Addition: Commutative, associative
- Multiplication: Associative, NOT commutative
- Transpose: (A^T)^T = A, (AB)^T = B^T A^T
- Identity: I × A = A × I = A

**Complexity:**
- Element access: O(1)
- Add/Subtract: O(mn)
- Multiply: O(mnp) for (m×n) × (n×p)
- Solve: O(n³)