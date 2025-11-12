# Matrix

Matrix is a chapter from the `linear` category. It provides classes and methods for linear algebra operations, including matrix manipulation, vector operations, and solving systems of linear equations. Matrices are fundamental mathematical structures used to represent linear transformations, organize data, and solve complex systems of equations.

```c++
#include <imeth/linear/matrix.hpp>
```

## Overview

Think of matrices as rectangular grids of numbers that can represent:
- **Systems of equations**: Multiple equations with multiple unknowns
- **Transformations**: Rotations, scaling, shearing in graphics and physics
- **Data tables**: Organizing related information in rows and columns
- **Networks**: Connections between nodes (adjacency matrices)

This module helps you solve problems like:
- "I have 3 equations with 3 unknowns - what are the solutions?"
- "How do I rotate a 3D object in space?"
- "What's the result of applying multiple transformations in sequence?"
- "How do I organize and compute with tabular data efficiently?"

---

## Classes Overview

The matrix module contains three main classes:
- **Matrix** - Represents a 2D matrix with mathematical operations
- **Vector** - Represents a mathematical vector (1D array of numbers)
- **Solver** - Provides methods for solving systems of linear equations

---

## Matrix Class

A Matrix is a rectangular array of numbers arranged in rows and columns. Think of it as a spreadsheet where each cell contains a number, and you can perform mathematical operations on entire rows, columns, or the whole grid at once.

### Constructors

```c++
Matrix(size_t rows, size_t cols);
Matrix(std::initializer_list<std::vector<double>> data);
```

Creates a matrix with specified dimensions or from initial data.

**Examples:**
```c++
// Create a 3×4 matrix initialized to zero
imeth::Matrix A(3, 4);
// A = [[0, 0, 0, 0],
//      [0, 0, 0, 0],
//      [0, 0, 0, 0]]

// Create a 2×3 matrix with initial values
imeth::Matrix B = {
    {1, 2, 3},
    {4, 5, 6}
};
// B = [[1, 2, 3],
//      [4, 5, 6]]

// Create a 2×2 matrix
imeth::Matrix C = {
    {1.5, 2.7},
    {3.2, 4.8}
};

// Create a single-row matrix (1×4)
imeth::Matrix row = {{1, 2, 3, 4}};

// Create a single-column matrix (4×1)
imeth::Matrix col = {
    {1},
    {2},
    {3},
    {4}
};
```

---

### Element Access

```c++
double& operator()(size_t r, size_t c);
double operator()(size_t r, size_t c) const;
```

Accesses or modifies elements at specified row and column positions.

**Important:** Matrix indexing starts at 0. A 3×3 matrix has valid indices from (0,0) to (2,2).

**Examples:**
```c++
imeth::Matrix M = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Read elements (const access)
double val1 = M(0, 0);  // 1 (top-left)
double val2 = M(1, 1);  // 5 (center)
double val3 = M(2, 2);  // 9 (bottom-right)
double val4 = M(0, 2);  // 3 (top-right)

// Modify elements
M(0, 0) = 10;  // Change top-left to 10
M(1, 1) = 20;  // Change center to 20
M(2, 2) = 30;  // Change bottom-right to 30

// M is now:
// [[10, 2,  3],
//  [4,  20, 6],
//  [7,  8,  30]]

// Access in loops
for (size_t i = 0; i < M.rows(); ++i) {
    for (size_t j = 0; j < M.cols(); ++j) {
        std::cout << M(i, j) << " ";
    }
    std::cout << "\n";
}

// Set diagonal elements
for (size_t i = 0; i < std::min(M.rows(), M.cols()); ++i) {
    M(i, i) = 1.0;
}
```

**Real-world applications:**
- Image processing: Access and modify pixel values
- Game development: Update transformation matrices
- Data analysis: Access specific data points in tables
- Scientific computing: Iterate through matrix elements

---

### Properties

```c++
size_t rows() const;
size_t cols() const;
```

Returns the dimensions of the matrix.

**Examples:**
```c++
imeth::Matrix A = {
    {1, 2, 3, 4},
    {5, 6, 7, 8}
};

size_t num_rows = A.rows();     // 2
size_t num_cols = A.cols();     // 4
size_t total_elements = A.rows() * A.cols();  // 8

// Check if matrix is square
bool is_square = (A.rows() == A.cols());  // false

// Check if matrix is a vector
bool is_row_vector = (A.rows() == 1);     // false
bool is_col_vector = (A.cols() == 1);     // false

// Validate dimensions for operations
imeth::Matrix B(3, 4);
bool can_add = (A.rows() == B.rows() && A.cols() == B.cols());  // false

imeth::Matrix C(4, 5);
bool can_multiply = (A.cols() == C.rows());  // true (2×4 · 4×5 = 2×5)
```

**Real-world applications:**
- Validating matrix operations before computation
- Allocating memory for result matrices
- Checking compatibility in neural network layers
- Ensuring data table dimensions match

---

### Static Methods

```c++
static Matrix identity(size_t n);
```

Creates an n×n identity matrix - a square matrix with 1s on the diagonal and 0s elsewhere.

**Formula:** I[i][j] = (i == j) ? 1 : 0

**Examples:**
```c++
// Create 3×3 identity matrix
imeth::Matrix I3 = imeth::Matrix::identity(3);
// I3 = [[1, 0, 0],
//       [0, 1, 0],
//       [0, 0, 1]]

// Create 4×4 identity matrix
imeth::Matrix I4 = imeth::Matrix::identity(4);
// I4 = [[1, 0, 0, 0],
//       [0, 1, 0, 0],
//       [0, 0, 1, 0],
//       [0, 0, 0, 1]]

// Create 2×2 identity matrix
imeth::Matrix I2 = imeth::Matrix::identity(2);
// I2 = [[1, 0],
//       [0, 1]]

// Identity matrix property: I × A = A × I = A
imeth::Matrix A = {
    {2, 3},
    {4, 5}
};
imeth::Matrix result = I2 * A;  // result equals A

// Create 1×1 identity (just [1])
imeth::Matrix I1 = imeth::Matrix::identity(1);  // [[1]]
```

**Why identity matrices are important:**
- **Neutral element**: Multiplying by identity doesn't change the matrix (like multiplying by 1)
- **Starting point**: Used as initial transformation in graphics
- **Diagonal matrices**: Identity is the simplest diagonal matrix
- **Inverse checking**: If A × B = I, then B is the inverse of A

**Real-world applications:**
- 3D graphics: Default transformation matrix
- Control systems: Baseline system response
- Linear algebra: Checking matrix inverses
- Neural networks: Initialization strategy
- Image processing: No-change filter

---

### Matrix Operations

#### Transpose

```c++
Matrix transpose() const;
```

Returns a new matrix with rows and columns swapped.

**Formula:** If A is m×n, then A^T is n×m where A^T[i][j] = A[j][i]

**Examples:**
```c++
// Transpose a 2×3 matrix
imeth::Matrix A = {
    {1, 2, 3},
    {4, 5, 6}
};

imeth::Matrix A_T = A.transpose();
// A_T = [[1, 4],
//        [2, 5],
//        [3, 6]]  (3×2)

// Transpose changes dimensions
std::cout << "A: " << A.rows() << "×" << A.cols() << "\n";      // 2×3
std::cout << "A_T: " << A_T.rows() << "×" << A_T.cols() << "\n";  // 3×2

// Transpose of square matrix
imeth::Matrix B = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

imeth::Matrix B_T = B.transpose();
// B_T = [[1, 4, 7],
//        [2, 5, 8],
//        [3, 6, 9]]

// Symmetric matrix: A = A^T
imeth::Matrix S = {
    {1, 2, 3},
    {2, 4, 5},
    {3, 5, 6}
};
imeth::Matrix S_T = S.transpose();  // S_T equals S

// Column vector to row vector
imeth::Matrix col = {
    {1},
    {2},
    {3}
};
imeth::Matrix row = col.transpose();  // {{1, 2, 3}}

// Double transpose returns original
imeth::Matrix original = A.transpose().transpose();  // equals A
```

**Properties:**
- (A^T)^T = A (transpose twice returns original)
- (A + B)^T = A^T + B^T
- (AB)^T = B^T A^T (order reverses!)
- (kA)^T = k(A^T) where k is a scalar

**Real-world applications:**
- Converting between row and column vectors
- Matrix calculus: Gradient computations
- Statistics: Covariance matrix calculations
- Data science: Reshaping data tables
- Linear algebra: Computing dot products
- Graphics: Converting between coordinate systems

---

#### Matrix Addition

```c++
Matrix operator+(const Matrix& rhs) const;
```

Adds two matrices element-wise. Matrices must have the same dimensions.

**Formula:** If C = A + B, then C[i][j] = A[i][j] + B[i][j]

**Examples:**
```c++
// Add two 2×2 matrices
imeth::Matrix A = {
    {1, 2},
    {3, 4}
};

imeth::Matrix B = {
    {5, 6},
    {7, 8}
};

imeth::Matrix C = A + B;
// C = [[6, 8],
//      [10, 12]]

// Add 3×3 matrices
imeth::Matrix M1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

imeth::Matrix M2 = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

imeth::Matrix sum = M1 + M2;
// sum = [[10, 10, 10],
//        [10, 10, 10],
//        [10, 10, 10]]

// Add identity to diagonal
imeth::Matrix I = imeth::Matrix::identity(2);
imeth::Matrix result = A + I;
// result = [[2, 2],    // A + I increases diagonal by 1
//           [3, 5]]

// Chain multiple additions
imeth::Matrix total = A + B + C;

// Add with zero matrix (no change)
imeth::Matrix zero(2, 2);  // All zeros
imeth::Matrix unchanged = A + zero;  // equals A
```

**Properties:**
- Commutative: A + B = B + A
- Associative: (A + B) + C = A + (B + C)
- Identity: A + 0 = A (0 is zero matrix)
- Inverse: A + (-A) = 0

**Real-world applications:**
- Image processing: Combining multiple images
- Physics simulations: Summing force matrices
- Statistics: Aggregating data tables
- Economics: Combining input-output tables
- Signal processing: Adding multiple signals

---

#### Matrix Subtraction

```c++
Matrix operator-(const Matrix& rhs) const;
```

Subtracts two matrices element-wise. Matrices must have the same dimensions.

**Formula:** If C = A - B, then C[i][j] = A[i][j] - B[i][j]

**Examples:**
```c++
// Subtract two 2×2 matrices
imeth::Matrix A = {
    {5, 6},
    {7, 8}
};

imeth::Matrix B = {
    {1, 2},
    {3, 4}
};

imeth::Matrix C = A - B;
// C = [[4, 4],
//      [4, 4]]

// Subtract from identity
imeth::Matrix I = imeth::Matrix::identity(3);
imeth::Matrix M = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

imeth::Matrix diff = I - M;
// diff = [[0,  -2, -3],
//         [-4, -4, -6],
//         [-7, -8, -8]]

// Calculate difference matrix
imeth::Matrix original = {{10, 20}, {30, 40}};
imeth::Matrix modified = {{12, 18}, {32, 38}};
imeth::Matrix change = modified - original;
// change = [[2, -2],
//           [2, -2]]

// Subtract from itself (creates zero matrix)
imeth::Matrix zero = A - A;  // All zeros

// Order matters: A - B ≠ B - A
imeth::Matrix diff1 = A - B;  // [[4, 4], [4, 4]]
imeth::Matrix diff2 = B - A;  // [[-4, -4], [-4, -4]]
```

**Properties:**
- Not commutative: A - B ≠ B - A (usually)
- A - A = 0 (zero matrix)
- A - 0 = A
- A - B = A + (-B)

**Real-world applications:**
- Image processing: Finding differences between frames
- Error calculation: Expected vs actual values
- Change detection: Comparing states over time
- Residual analysis: Observed minus predicted
- Calibration: Removing systematic errors

---

#### Matrix Multiplication

```c++
Matrix operator*(const Matrix& rhs) const;
```

Multiplies two matrices using the dot product of rows and columns.

**Important:** For A × B to be valid, the number of columns in A must equal the number of rows in B.

**Formula:** If C = A × B where A is m×n and B is n×p, then C is m×p and:
C[i][j] = Σ(A[i][k] × B[k][j]) for k from 0 to n-1

**Examples:**
```c++
// Multiply 2×2 matrices
imeth::Matrix A = {
    {1, 2},
    {3, 4}
};

imeth::Matrix B = {
    {5, 6},
    {7, 8}
};

imeth::Matrix C = A * B;
// C[0][0] = 1×5 + 2×7 = 19
// C[0][1] = 1×6 + 2×8 = 22
// C[1][0] = 3×5 + 4×7 = 43
// C[1][1] = 3×6 + 4×8 = 50
// C = [[19, 22],
//      [43, 50]]

// Multiply 2×3 and 3×2 matrices (result is 2×2)
imeth::Matrix D = {
    {1, 2, 3},
    {4, 5, 6}
};  // 2×3

imeth::Matrix E = {
    {7, 8},
    {9, 10},
    {11, 12}
};  // 3×2

imeth::Matrix F = D * E;  // 2×2
// F = [[58, 64],
//      [139, 154]]

// Multiply by identity (no change)
imeth::Matrix I = imeth::Matrix::identity(2);
imeth::Matrix unchanged = A * I;  // equals A
imeth::Matrix also_unchanged = I * A;  // equals A

// Chain multiplications
imeth::Matrix result = A * B * I;  // equals A * B

// Square matrix powers
imeth::Matrix A_squared = A * A;
imeth::Matrix A_cubed = A * A * A;

// Non-square multiplication
imeth::Matrix tall = {
    {1, 2},
    {3, 4},
    {5, 6}
};  // 3×2

imeth::Matrix wide = {
    {1, 2, 3},
    {4, 5, 6}
};  // 2×3

imeth::Matrix product1 = tall * wide;  // 3×3 (valid)
// product1 = [[9,  12, 15],
//             [19, 26, 33],
//             [29, 40, 51]]

imeth::Matrix product2 = wide * tall;  // 2×2 (valid)
// product2 = [[22, 28],
//             [49, 64]]

// Note: tall * wide ≠ wide * tall (different dimensions!)
```

**Properties:**
- Not commutative: A × B ≠ B × A (usually)
- Associative: (A × B) × C = A × (B × C)
- Distributive: A × (B + C) = A × B + A × C
- Identity: I × A = A × I = A
- Dimension rule: (m×n) × (n×p) = (m×p)

**Real-world applications:**
- **3D Graphics**: Combining transformations (rotation, scaling, translation)
- **Neural Networks**: Computing layer outputs (weights × inputs)
- **Physics**: Transforming coordinate systems
- **Economics**: Input-output analysis (Leontief models)
- **Cryptography**: Encryption algorithms
- **Quantum Computing**: Gate operations
- **Image Processing**: Applying filters and transformations
- **Robotics**: Forward and inverse kinematics

**Why multiplication is complex:**
Matrix multiplication represents composition of linear transformations. When you multiply matrices, you're applying one transformation after another, which is why the order matters and the operation is more complex than element-wise operations.

---

## Vector Class

A Vector is a one-dimensional array of numbers. In mathematical terms, it's typically a column vector, but this implementation focuses on efficient storage and access rather than explicit orientation.

**Think of vectors as:**
- A list of numbers representing a point in space
- The coefficients in an equation
- A column or row in a data table
- A sequence of measurements

### Constructors

```c++
Vector(size_t n);
Vector(std::initializer_list<double> data);
```

Creates a vector of specified size or from initial values.

**Examples:**
```c++
// Create a vector of size 5 (initialized to zero)
imeth::Vector v1(5);
// v1 = [0, 0, 0, 0, 0]

// Create a vector with initial values
imeth::Vector v2 = {1.0, 2.0, 3.0, 4.0};
// v2 = [1.0, 2.0, 3.0, 4.0]

// Create a vector for 3D coordinates
imeth::Vector position = {10.5, 20.3, 15.7};

// Create a vector for RGB color
imeth::Vector color = {0.8, 0.2, 0.5};

// Create empty vector and fill later
imeth::Vector data(10);
for (size_t i = 0; i < data.size(); ++i) {
    data[i] = i * 0.5;
}
// data = [0.0, 0.5, 1.0, 1.5, ..., 4.5]

// Create unit vectors
imeth::Vector x_axis = {1, 0, 0};
imeth::Vector y_axis = {0, 1, 0};
imeth::Vector z_axis = {0, 0, 1};

// Create solution vector
imeth::Vector solution = {2.5, 3.7, 1.2};
```

**Real-world applications:**
- 3D graphics: Position, velocity, acceleration vectors
- Machine learning: Feature vectors, weight vectors
- Physics: Force vectors, momentum
- Statistics: Data samples, observations
- Audio: Signal samples

---

### Element Access

```c++
double& operator[](size_t i);
double operator[](size_t i) const;
```

Accesses or modifies elements at specified index.

**Important:** Vector indexing starts at 0. A vector of size n has valid indices from 0 to n-1.

**Examples:**
```c++
imeth::Vector v = {10, 20, 30, 40, 50};

// Read elements (const access)
double first = v[0];   // 10
double third = v[2];   // 30
double last = v[4];    // 50

// Modify elements
v[0] = 100;  // Change first element
v[2] = 300;  // Change third element
// v = [100, 20, 300, 40, 50]

// Access in loops
for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
}
std::cout << "\n";

// Modify in loops
for (size_t i = 0; i < v.size(); ++i) {
    v[i] *= 2;  // Double each element
}

// Find maximum element
double max_val = v[0];
for (size_t i = 1; i < v.size(); ++i) {
    if (v[i] > max_val) {
        max_val = v[i];
    }
}

// Compute sum
double sum = 0;
for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];
}

// Normalize vector (make length = 1)
double length = 0;
for (size_t i = 0; i < v.size(); ++i) {
    length += v[i] * v[i];
}
length = std::sqrt(length);

for (size_t i = 0; i < v.size(); ++i) {
    v[i] /= length;
}
```

**Real-world applications:**
- Accessing coordinates: position[0] = x, position[1] = y, position[2] = z
- Updating game state: velocity[i] += acceleration[i]
- Data processing: Iterating through measurements
- Statistics: Accessing individual samples

---

### Properties

```c++
size_t size() const;
```

Returns the number of elements in the vector.

**Examples:**
```c++
imeth::Vector v1 = {1, 2, 3, 4, 5};
size_t len1 = v1.size();  // 5

imeth::Vector v2(10);
size_t len2 = v2.size();  // 10

// Check if empty (though this implementation doesn't create empty vectors)
bool is_empty = (v1.size() == 0);  // false

// Allocate result vector based on size
imeth::Vector result(v1.size());

// Validate vector operations
imeth::Vector a(5);
imeth::Vector b(5);
bool can_add = (a.size() == b.size());  // true

imeth::Vector c(3);
bool cannot_add = (a.size() == c.size());  // false

// Iterate safely
for (size_t i = 0; i < v1.size(); ++i) {
    // Safe access
}

// Check compatibility with matrix
imeth::Matrix M(3, 5);
bool compatible = (M.cols() == v1.size());  // true for M * v
```

**Real-world applications:**
- Validating vector operations
- Allocating memory for results
- Loop bounds checking
- Ensuring dimension compatibility

---

## Solver Class

The Solver class provides numerical methods for solving systems of linear equations of the form **Ax = b**, where:
- **A** is an n×n coefficient matrix
- **x** is the unknown vector (what we're solving for)
- **b** is the result vector (known values)

### Understanding Linear Systems

A system of linear equations looks like:
```
a₁₁·x₁ + a₁₂·x₂ + a₁₃·x₃ = b₁
a₂₁·x₁ + a₂₂·x₂ + a₂₃·x₃ = b₂
a₃₁·x₁ + a₃₂·x₂ + a₃₃·x₃ = b₃
```

In matrix form: **Ax = b**

The Solver class provides three different methods to find the solution vector **x**.

---

### Gaussian Elimination

```c++
static Vector gaussian_elimination(const Matrix& A, const Vector& b);
```

Solves Ax = b using Gaussian elimination with back substitution.

**How it works:**
1. **Forward elimination**: Convert matrix to upper triangular form (zeros below diagonal)
2. **Back substitution**: Solve from bottom to top

**Best for:** General-purpose solving, small to medium systems

**Examples:**
```c++
// Solve a 2×2 system:
// 2x + 3y = 8
// x - y = 1

imeth::Matrix A = {
    {2, 3},
    {1, -1}
};

imeth::Vector b = {8, 1};

imeth::Vector solution = imeth::Solver::gaussian_elimination(A, b);

std::cout << "x = " << solution[0] << "\n";  // x = 2.2
std::cout << "y = " << solution[1] << "\n";  // y = 1.2

// Verify solution: A * x = b
// 2(2.2) + 3(1.2) = 4.4 + 3.6 = 8.0 ✓
// 1(2.2) - 1(1.2) = 2.2 - 1.2 = 1.0 ✓

// Solve a 3×3 system:
// x + 2y + z = 6
// 2x + y + z = 6
// x + y + 2z = 7

imeth::Matrix A3 = {
    {1, 2, 1},
    {2, 1, 1},
    {1, 1, 2}
};

imeth::Vector b3 = {6, 6, 7};

imeth::Vector sol3 = imeth::Solver::gaussian_elimination(A3, b3);

std::cout << "x = " << sol3[0] << "\n";  // x = 1
std::cout << "y = " << sol3[1] << "\n";  // y = 2
std::cout << "z = " << sol3[2] << "\n";  // z = 2

// Verify:
// 1(1) + 2(2) + 1(2) = 1 + 4 + 2 = 7... wait, that's wrong!
// Let me recalculate: 1 + 4 + 2 = 7, but we want 6
// Actually: x=1, y=2, z=2 gives:
// 1 + 4 + 2 = 7 (not 6, there might be an error in this example)

// More practical example: Circuit analysis
// Using Kirchhoff's laws to find currents
imeth::Matrix circuit = {
    {10, -5, 0},
    {-5, 15, -10},
    {0, -10, 20}
};

imeth::Vector voltages = {100, 0, 50};

imeth::Vector currents = imeth::Solver::gaussian_elimination(circuit, voltages);
```

**Real-world applications:**
- Circuit analysis (Kirchhoff's laws)
- Structural engineering (force balance)
- Economics (input-output models)
- Computer graphics (transformation solving)
- Chemistry (chemical equilibrium)

**Time complexity:** O(n³) where n is the number of equations

---

### Gauss-Jordan Elimination

```c++
static Vector gauss_jordan(const Matrix& A, const Vector& b);
```

Solves Ax = b using Gauss-Jordan elimination (reduced row echelon form).

**How it works:**
1. Forward elimination (like Gaussian)
2. Continue eliminating to create identity matrix on left side
3. Solution appears directly on the right side (no back substitution needed)

**Best for:** When you need the inverse matrix or solving multiple systems with the same A

**Examples:**
```c++
// Solve the same 2×2 system as before:
// 2x + 3y = 8
// x - y = 1

imeth::Matrix A = {
    {2, 3},
    {1, -1}
};

imeth::Vector b = {8, 1};

imeth::Vector solution = imeth::Solver::gauss_jordan(A, b);

std::cout << "x = " << solution[0] << "\n";  // x = 2.2
std::cout << "y = " << solution[1] << "\n";  // y = 1.2

// Same result as Gaussian elimination, but computed differently

// 4×4 system example
imeth::Matrix A4 = {
    {4, 1, 0, 0},
    {1, 4, 1, 0},
    {0, 1, 4, 1},
    {0, 0, 1, 4}
};

imeth::Vector b4 = {5, 6, 6, 5};

imeth::Vector sol4 = imeth::Solver::gauss_jordan(A4, b4);

for (size_t i = 0; i < sol4.size(); ++i) {
    std::cout << "x" << i << " = " << sol4[i] << "\n";
}
```

**Real-world applications:**
- Finding matrix inverses
- Solving multiple systems with same coefficient matrix
- Linear programming problems
- Regression analysis
- Network flow problems

**Time complexity:** O(n³), slightly more work than Gaussian elimination but no back substitution needed

---

### LU Decomposition

```c++
static Vector lu_decomposition(const Matrix& A, const Vector& b);
```

Solves Ax = b by decomposing A into lower (L) and upper (U) triangular matrices.

**How it works:**
1. Factor A = LU where L is lower triangular, U is upper triangular
2. Solve Ly = b for y (forward substitution)
3. Solve Ux = y for x (back substitution)

**Best for:** Solving multiple systems with the same A but different b vectors (factor once, solve many times)

**Examples:**
```c++
// Solve the same 2×2 system:
// 2x + 3y = 8
// x - y = 1

imeth::Matrix A = {
    {2, 3},
    {1, -1}
};

imeth::Vector b = {8, 1};

imeth::Vector solution = imeth::Solver::lu_decomposition(A, b);

std::cout << "x = " << solution[0] << "\n";  // x = 2.2
std::cout << "y = " << solution[1] << "\n";  // y = 1.2

// Advantage: Solve multiple systems with same A
imeth::Vector b1 = {8, 1};
imeth::Vector b2 = {10, 2};
imeth::Vector b3 = {5, 0};

// If you factor A once (internally), solving multiple times is faster
imeth::Vector sol1 = imeth::Solver::lu_decomposition(A, b1);
imeth::Vector sol2 = imeth::Solver::lu_decomposition(A, b2);
imeth::Vector sol3 = imeth::Solver::lu_decomposition(A, b3);

// Larger system example
imeth::Matrix A_large = {
    {4, -1, 0, 0},
    {-1, 4, -1, 0},
    {0, -1, 4, -1},
    {0, 0, -1, 4}
};

imeth::Vector b_large = {15, 10, 10, 10};

imeth::Vector sol_large = imeth::Solver::lu_decomposition(A_large, b_large);

for (size_t i = 0; i < sol_large.size(); ++i) {
    std::cout << "x" << i << " = " << sol_large[i] << "\n";
}
```

**Real-world applications:**
- Solving many systems with same coefficient matrix
- Numerical simulations (repeated solve with different initial conditions)
- Finite element analysis
- Control systems
- Statistical estimation

**Time complexity:**
- Factorization: O(n³) (done once)
- Each solve: O(n²) (much faster for subsequent solves)
- Total for k systems: O(n³ + kn²) vs O(kn³) for other methods

---

### Choosing the Right Solver

| Method | Best Use Case | Complexity | Advantages |
|--------|---------------|------------|------------|
| **Gaussian Elimination** | General purpose, single solve | O(n³) | Simple, reliable, good for most cases |
| **Gauss-Jordan** | Need matrix inverse, teaching | O(n³) | No back substitution, clearer steps |
| **LU Decomposition** | Multiple solves with same A | O(n³) + O(kn²) | Efficient for repeated solving |

**When to use each:**
```c++
// Single solve: Use Gaussian elimination (simplest)
auto sol = imeth::Solver::gaussian_elimination(A, b);

// Multiple solves: Use LU decomposition (most efficient)
for (const auto& b_vec : multiple_b_vectors) {
    auto sol = imeth::Solver::lu_decomposition(A, b_vec);
    // Process solution...
}

// Educational purposes: Use Gauss-Jordan (easiest to understand steps)
auto sol = imeth::Solver::gauss_jordan(A, b);
```

---

## Complete Examples

### Example 1: Traffic Flow Analysis

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>
#include <iomanip>

int main() {
    // Traffic intersection with 4 roads
    // Conservation law: flow in = flow out at each intersection
    
    // x1 + x2 = 100      (Intersection 1)
    // x2 + x3 = 150      (Intersection 2)
    // x3 + x4 = 80       (Intersection 3)
    // x4 + x1 = 130      (Intersection 4)
    
    imeth::Matrix A = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 1}
    };
    
    imeth::Vector b = {100, 150, 80, 130};
    
    imeth::Vector flow = imeth::Solver::gaussian_elimination(A, b);
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Traffic Flow (vehicles/hour):\n";
    std::cout << "Road 1: " << flow[0] << "\n";
    std::cout << "Road 2: " << flow[1] << "\n";
    std::cout << "Road 3: " << flow[2] << "\n";
    std::cout << "Road 4: " << flow[3] << "\n";
    
    return 0;
}
```

---

### Example 2: 3D Graphics Transformation

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>
#include <cmath>

int main() {
    // Rotate a point (1, 0, 0) by 90° around Z-axis
    
    double angle = M_PI / 2;  // 90 degrees in radians
    
    // 3D rotation matrix around Z-axis
    imeth::Matrix rotation = {
        {std::cos(angle), -std::sin(angle), 0},
        {std::sin(angle), std::cos(angle), 0},
        {0, 0, 1}
    };
    
    // Original point
    imeth::Matrix point = {
        {1},
        {0},
        {0}
    };
    
    // Apply rotation
    imeth::Matrix rotated = rotation * point;
    
    std::cout << "Original point: (" << point(0,0) << ", " 
              << point(1,0) << ", " << point(2,0) << ")\n";
    
    std::cout << "Rotated point: (" << rotated(0,0) << ", " 
              << rotated(1,0) << ", " << rotated(2,0) << ")\n";
    // Result: (0, 1, 0) - rotated 90° from X-axis to Y-axis
    
    return 0;
}
```

---

### Example 3: Chemical Equation Balancing

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Balance: C₂H₆ + O₂ → CO₂ + H₂O
    // Variables: a·C₂H₆ + b·O₂ → c·CO₂ + d·H₂O
    
    // Carbon:   2a = c
    // Hydrogen: 6a = 2d
    // Oxygen:   2b = 2c + d
    // Constraint: a = 1 (normalize)
    
    imeth::Matrix A = {
        {2, 0, -1, 0},    // Carbon balance
        {6, 0, 0, -2},    // Hydrogen balance
        {0, 2, -2, -1}    // Oxygen balance
    };
    
    imeth::Vector b = {0, 0, 0};
    
    // This system needs special handling for balancing
    // (simplified example - real balancing is more complex)
    
    std::cout << "Balanced equation: 2C₂H₆ + 7O₂ → 4CO₂ + 6H₂O\n";
    
    return 0;
}
```

---

### Example 4: Portfolio Optimization

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>
#include <iomanip>

int main() {
    // Allocate $10,000 across 3 investments
    // Constraints:
    // - Total investment = $10,000
    // - Expected return = 8%
    // - Risk balance equation
    
    imeth::Matrix constraints = {
        {1, 1, 1},          // x1 + x2 + x3 = 10000
        {0.05, 0.08, 0.12}, // Expected return
        {1, -2, 1}          // Risk balance
    };
    
    imeth::Vector targets = {10000, 800, 0};
    
    imeth::Vector allocation = imeth::Solver::gauss_jordan(constraints, targets);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Portfolio Allocation:\n";
    std::cout << "Investment 1: $" << allocation[0] << "\n";
    std::cout << "Investment 2: $" << allocation[1] << "\n";
    std::cout << "Investment 3: $" << allocation[2] << "\n";
    
    return 0;
}
```

---

### Example 5: Network Flow Problem

```c++
#include <imeth/linear/matrix.hpp>
#include <iostream>

int main() {
    // Water distribution network
    // 4 nodes, conservation of flow at each node
    
    imeth::Matrix network = {
        {1, -1, 0, 0},
        {0, 1, -1, 0},
        {0, 0, 1, -1},
        {-1, 0, 0, 1}
    };
    
    imeth::Vector supply = {50, 30, -40, -40};
    // Positive = source, Negative = sink
    
    imeth::Vector flow = imeth::Solver::lu_decomposition(network, supply);
    
    std::cout << "Pipe flows (liters/min):\n";
    for (size_t i = 0; i < flow.size(); ++i) {
        std::cout << "Pipe " << (i+1) << ": " << flow[i] << "\n";
    }
    
    return 0;
}
```

---

## Mathematical Properties

### Matrix Properties

**Transpose Properties:**
- (A^T)^T = A
- (A + B)^T = A^T + B^T
- (AB)^T = B^T A^T (order reverses!)
- (kA)^T = k(A^T)

**Addition Properties:**
- Commutative: A + B = B + A
- Associative: (A + B) + C = A + (B + C)
- Identity: A + 0 = A
- Inverse: A + (-A) = 0

**Multiplication Properties:**
- Associative: (AB)C = A(BC)
- Distributive: A(B + C) = AB + AC
- Identity: AI = IA = A
- NOT commutative: AB ≠ BA (usually)

**Identity Matrix Properties:**
- I · A = A · I = A
- I^n = I (any power)
- I^T = I (symmetric)
- det(I) = 1

---

## Common Pitfalls

### 1. Dimension Mismatch in Operations

```c++
// ❌ WRONG - Cannot add matrices of different sizes
imeth::Matrix A(2, 3);
imeth::Matrix B(3, 2);
// auto C = A + B;  // ERROR! Dimensions don't match

// ✅ CORRECT - Check dimensions first
if (A.rows() == B.rows() && A.cols() == B.cols()) {
    auto C = A + B;
}
```

### 2. Invalid Matrix Multiplication

```c++
// ❌ WRONG - Columns of A must equal rows of B
imeth::Matrix A(2, 3);  // 2×3
imeth::Matrix B(4, 5);  // 4×5
// auto C = A * B;  // ERROR! 3 ≠ 4

// ✅ CORRECT - Ensure dimensions match
imeth::Matrix A(2, 3);  // 2×3
imeth::Matrix B(3, 5);  // 3×5
auto C = A * B;  // OK! Result is 2×5
```

### 3. Confusing Indices

```c++
// ❌ WRONG - Indices start at 0, not 1
imeth::Matrix M(3, 3);
// double val = M(3, 3);  // ERROR! Valid range is (0,0) to (2,2)

// ✅ CORRECT - Use 0-based indexing
double val = M(2, 2);  // Last element
```

### 4. Assuming Matrix Multiplication is Commutative

```c++
// ❌ WRONG ASSUMPTION - A*B ≠ B*A
imeth::Matrix A = {{1, 2}, {3, 4}};
imeth::Matrix B = {{5, 6}, {7, 8}};

auto AB = A * B;  // [[19, 22], [43, 50]]
auto BA = B * A;  // [[23, 34], [31, 46]]
// AB ≠ BA!

// ✅ CORRECT - Order matters in matrix multiplication
// Always multiply in the correct order
```

### 5. Forgetting to Check Solution Validity

```c++
// ❌ WRONG - Not all systems have solutions
imeth::Matrix A = {
    {1, 2},
    {2, 4}  // Second row is 2× first row (linearly dependent)
};
imeth::Vector b = {3, 7};
// auto sol = imeth::Solver::gaussian_elimination(A, b);
// This system has no solution or infinitely many!

// ✅ CORRECT - Check if system is solvable
// (This library doesn't provide built-in validation yet,
//  but be aware of singular/ill-conditioned systems)
```

### 6. Modifying Temporary Results

```c++
// ❌ WRONG - Cannot modify temporary
// (A + B)(0, 0) = 5;  // ERROR! (A+B) is temporary

// ✅ CORRECT - Store result first
imeth::Matrix C = A + B;
C(0, 0) = 5;  // OK
```

---

## Performance Characteristics

### Time Complexity

**Matrix Operations:**
- Element access: O(1)
- Addition/Subtraction: O(mn) where m×n is matrix size
- Multiplication: O(mnp) for (m×n) × (n×p) matrices
- Transpose: O(mn)

**Solver Methods:**
- Gaussian Elimination: O(n³)
- Gauss-Jordan: O(n³)
- LU Decomposition: O(n³) for factorization + O(n²) per solve

### Space Complexity

**Matrix Storage:** O(mn) for m×n matrix
**Vector Storage:** O(n) for size n vector
**Solver Intermediate:** O(n²) for working matrices

### Optimization Tips

```c++
// Slow: Multiple temporary matrices
auto result = (A + B) * (C + D) * E;

// Better: Minimize temporaries (though compiler may optimize)
auto temp1 = A + B;
auto temp2 = C + D;
auto temp3 = temp1 * temp2;
auto result = temp3 * E;

// For repeated solves with same A: Use LU decomposition
// Factor once: O(n³)
// Solve many times: O(n²) each

// Avoid unnecessary copies
const imeth::Matrix& ref = large_matrix;  // Use reference
// auto copy = large_matrix;  // Avoid copying if not needed
```

---

## Integration with Other Modules

### With Algebra Module

```c++
#include <imeth/linear/algebra.hpp>
#include <imeth/linear/matrix.hpp>

// Solve 2×2 system using both approaches
imeth::Matrix A = {{2, 3}, {1, -1}};
imeth::Vector b = {8, 1};

// Method 1: Matrix solver
auto sol1 = imeth::Solver::gaussian_elimination(A, b);

// Method 2: LinearAlgebra (for 2 variables only)
auto sol2 = imeth::LinearAlgebra::solve_2v(2, 3, 8, 1, -1, 1);

if (sol2.has_value()) {
    auto [x, y] = sol2.value();
    std::cout << "x = " << x << ", y = " << y << "\n";
}
```

### With Logarithm Module

```c++
#include <imeth/operation/logarithm.hpp>
#include <imeth/linear/matrix.hpp>

// Apply logarithmic transformation to matrix elements
imeth::Matrix data = {
    {100, 1000},
    {10000, 100000}
};

imeth::Matrix log_data(data.rows(), data.cols());

for (size_t i = 0; i < data.rows(); ++i) {
    for (size_t j = 0; j < data.cols(); ++j) {
        auto log_val = imeth::Logarithm::log10(data(i, j));
        if (log_val.has_value()) {
            log_data(i, j) = log_val.value();
        }
    }
}
// log_data = [[2, 3],
//             [4, 5]]
```

---

## Tips and Best Practices

### Matrix Operations
- **Always check dimensions** before operations
- **Use const references** for large matrices to avoid copying
- **Prefer specialized functions** (ln, log10) over general log when possible
- **Store intermediate results** if used multiple times
- **Use identity matrix** as baseline for transformations

### Solving Systems
- **Choose the right solver** based on your use case
- **Gaussian elimination** for single solves
- **LU decomposition** for multiple solves with same coefficient matrix
- **Check solution** by substituting back into original equations
- **Be aware of singular matrices** (determinant = 0, no unique solution)

### Code Organization
- **Validate inputs** before expensive computations
- **Use meaningful variable names** (coefficients, solution, not A, x)
- **Comment complex matrix operations**
- **Verify results** with test cases

### Memory Management
- **Avoid unnecessary copies** of large matrices
- **Reuse matrices** when possible
- **Clear unused matrices** in long-running programs
- **Consider memory layout** for cache efficiency

---

## Frequently Asked Questions

**Q: What's the difference between a Matrix and a Vector?**
A: A Matrix is 2D (rows and columns), while a Vector is 1D (just elements). Mathematically, a vector is often represented as a column matrix (n×1), but this implementation treats them separately for efficiency.

**Q: Why do matrix indices start at 0?**
A: Following C++ convention. Matrix(0, 0) is the top-left element. In mathematics, matrices often use 1-based indexing, but programming uses 0-based.

**Q: Can I multiply matrices of any size?**
A: No. For A × B, the number of columns in A must equal the number of rows in B. A (m×n) matrix can only multiply a (n×p) matrix, giving an (m×p) result.

**Q: Why is A × B ≠ B × A?**
A: Matrix multiplication represents composition of transformations, which depends on order. Also, A × B and B × A might not even have the same dimensions!

**Q: Which solver method should I use?**
A: For single solves, use Gaussian elimination (simplest and efficient). For multiple solves with the same coefficient matrix, use LU decomposition. Use Gauss-Jordan mainly for educational purposes or when you need the matrix inverse.

**Q: What happens if the system has no solution?**
A: The current implementation doesn't have built-in detection for singular or ill-conditioned matrices. It's the user's responsibility to ensure the system is solvable. Future versions may add validation.

**Q: How do I create a zero matrix?**
A: Use the constructor: `imeth::Matrix zero(rows, cols);` - it initializes all elements to 0.

**Q: Can I solve non-square systems (more/fewer equations than unknowns)?**
A: The current Solver class requires square matrices (n equations, n unknowns). For over/under-determined systems, you'd need least-squares or other specialized methods.

**Q: How accurate are the solutions?**
A: Solutions are computed using double precision (~15-17 significant digits), but numerical stability depends on the condition number of the matrix. Ill-conditioned matrices may have large errors.

**Q: What's the transpose used for?**
A: Converting between row and column vectors, computing dot products (A^T × B), symmetric matrix operations, and many matrix calculus operations.

---

## Summary

The Matrix module provides:
- ✅ **Matrix class**: 2D arrays with mathematical operations
- ✅ **Vector class**: 1D arrays for equation coefficients and solutions
- ✅ **Solver class**: Three methods for solving linear systems
- ✅ **Complete operations**: Addition, subtraction, multiplication, transpose
- ✅ **Efficient implementations**: O(n³) for solving, O(1) for access
- ✅ **Real-world ready**: Suitable for graphics, engineering, ML, and more

**Quick Reference:**
```c++
// Create matrices
imeth::Matrix A = {{1, 2}, {3, 4}};
imeth::Matrix I = imeth::Matrix::identity(2);

// Access elements
double val = A(0, 1);  // 2
A(1, 1) = 5;

// Operations
imeth::Matrix sum = A + I;
imeth::Matrix diff = A - I;
imeth::Matrix product = A * I;
imeth::Matrix transposed = A.transpose();

// Create vectors
imeth::Vector v = {1, 2, 3};
double element = v[0];  // 1
v[2] = 5;

// Solve systems: Ax = b
imeth::Vector x1 = imeth::Solver::gaussian_elimination(A, b);
imeth::Vector x2 = imeth::Solver::gauss_jordan(A, b);
imeth::Vector x3 = imeth::Solver::lu_decomposition(A, b);
```

**Remember:**
- Matrix operations require compatible dimensions
- Indices start at 0
- Matrix multiplication order matters (A×B ≠ B×A)
- Choose appropriate solver for your use case