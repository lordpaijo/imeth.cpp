# imeth
The stupid imeth can be concluded into two translation:
  * **I + METH** – Because I'm high on math equations like a guy high on meth.
  * **IYAN + METH** Because Iyan (the original author) is high on math like a guy high on meth.
Even though both still share the same equal meaning.

Imeth is a lightweight C++ math library for exploring computational mathematics while testing the limit of author's C++ skill (and sanity).
It's a high modular-designed library, making it very likely to have so many branches and abstractions just to get a method done. Though the author believes
that modularity is the key to success. At least in his mind and his dream, it is.

## Why imeth?
When asked, "why?", it's not about the matter, **"why do I use imeth?"**. Instead, it's preferable to say that the real question is, **"why do I make imeth?"**.
No one, at least a sane being, is stupid enough to use imeth. Not even for fun I'd like to call them, sane, because someone who's sane will never hear the
name imeth in their life. Someone who's **insane** however, will.

Apart from so, imeth is meant to be entirely an **experiment that made public**. It can be interpreted as a CIA trick to make propaganda so that they can control the
world if they haven't. Or as **a funny silly project to practice the author's skill** while he learns C++ in his young age.

To me, **I'm not developing imeth to be productive**. It's more of **an experiment that I think I'd like to accomplish**.

## Features
Imeth comes with plenty handy features that I'd like point out:
- **Arithmetic Operations**: Basic arithmetic calculations
- **Linear Algebra**: Equation solving, matrix operations, and more
- **Factoring Quadratic Equation**: Methods to factor quadratic equations
- **Geometric Calculations**: 2D and 3D geometric operations
- **Base Conversions and Operations**: Convert and operate on numbers between different bases
- **Modular Design**: Clean, organized API with namespace separation
- **Simple API**: Clean interfaces for complex math
My favorite one is the linear algebra, especially the linear equation with variables. Which I think will be the best and will be the overglazed feature, by me.

## Installation
### Dependencies
- **C++20 Compatible Compilers**
- **CMake V3.15+**
- **Git**
### Clone the Repository
```shell
git clone https://github.com/lordpaijo/imeth.cpp imeth
cd imeth
```
### Build and Install with CMake
#### Linux/MacOS
```sh
mkdir build && cd build
cmake ..
make -j
sudo make install
```
This will install:
- Library: `/usr/local/lib/libimeth.a`
- Headers: `/usr/local/include/imeth/`
- CMake config: `/usr/local/lib/cmake/imeth/`
#### Windows
Using Visual Studio:
```sh
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
cmake --install . --config Release
```
Or using MinGW:
```sh
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j
mingw32-make install
```

## Usage

### Using with CMake (Recommended)

In your project's `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

# Find the installed imeth library
find_package(imeth REQUIRED)

add_executable(my_app main.cpp)

# Link against imeth
target_link_libraries(my_app PRIVATE imeth::imeth)
```

Then build:
```sh
cmake -B build
cmake --build build
```

### Using with Compiler Directly

After installation, compile your code with:

```sh
# Using g++
g++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program

# Using clang++
clang++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program
```

## Quick Start
You can start building an app using imeth by including a _category_ and its _chapter_ in your code like this:
```cpp
#include <imeth/linear/algebra.hpp>
```
Then start using the methods imported from the header like this:
```c++
int main() {
    // Solve: 2x + 4 = 0
    // Solution: x = -2
    auto solution = imeth::LinearAlgebra::solve_1v(2, 4);

    if (solution) {
        std::cout << "Solution: x = " << *solution << "\n";
    } else {
        std::cout << "No solution exists\n";
    }

    return 0;
}
```

## API
Imeth is a modular library divided into namespaces and classes. I mention the term _category_ and _chapter_ previously, they are simply my way to say
 a `branch` and a `header`. A category can be consisted of many chapters, just like a `branch` consisting many `headers`. Thus, imeth is a compilation of mathematical
categories and their chapters, which of course include their operations.


Let's take a look at another example, let's make a program to solve linear equation of two variables using imeth:
```c++
#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve:
    //   2x + 3y = 8
    //   4x - 2y = 0
    // Solution: x = 1, y = 2

    auto solution = imeth::LinearAlgebra::solve_2v(2, 3, 8,    // First equation coefficients
                                                   4, -2, 0);  // Second equation coefficients

    if (solution) {
        std::cout << "Solution: x = " << solution->first
                  << ", y = " << solution->second << "\n";
    } else {
        std::cout << "No unique solution exists\n";
    }

    return 0;
}
```
Here, I call the library `imeth`, then the category `linear`, and then the chapter `algebra.hpp`.


What I'm really doing is, I'm importing the methods from the algebra chapter (header file, `algebra.hpp`) from the linear category (`linear/`) of the
imeth library (`imeth/`). Which will probably sound very confusing, but anyway, here's a list of the currently available categories:

| Category | Description |
| --- | --- |
| `<imeth/linear>` | Linear equations and operations |
| `<imeth/operation>` | Bunch of general mathematical operations |
| `<imeth/geometry>` | Geometric shape calculations |
| `<imeth/base>` | Base conversions and operations |

Each category has their own chapters. And chapters are the actual APIs that you are going to use. Here, I am going to start sorting them by how often I think
they will be used from this library.

### Arithmetic
The arithmetic chapter is the first chapter from the `operation` category. It provides a comprehensive collection of arithmetic operations and mathematical utilities, ranging from basic operations to statistical functions, number theory, and practical calculations.

It can be found here:
```c++
#include <imeth/operation/arithmetic.hpp>
```

#### Features

**Basic Operations**
- `add(double a, double b) → double` - Standard addition
- `subtract(double a, double b) → double` - Standard subtraction
- `multiply(double a, double b) → double` - Standard multiplication
- `divide(double a, double b) → double` - Standard division

**Power and Roots**
- `power(double base, int exponent) → double` - Raises base to an integer exponent
- `squareRoot(double n) → double` - Computes √n
- `cubeRoot(double n) → double` - Computes ∛n

**Absolute Value and Sign**
- `absolute(double n) → double` - Returns |n|
- `sign(double n) → int` - Returns -1 for negative, 0 for zero, 1 for positive

**Remainders and Divisibility**
- `remainder(int a, int b) → int` - Integer remainder of a ÷ b
- `isDivisible(int a, int b) → bool` - Checks if a is divisible by b

**Percentages**
- `percentOf(double percent, double total) → double` - Calculates percent% of total
- `whatPercent(double part, double total) → double` - Finds what percent part is of total
- `percentIncrease(double original, double newValue) → double` - Calculates percentage increase
- `percentDecrease(double original, double newValue) → double` - Calculates percentage decrease

**Averages and Statistics**
- `average(const std::vector<double>& numbers) → double` - Mean of a vector of numbers
- `sum(const std::vector<double>& numbers) → double` - Total sum
- `minimum(const std::vector<double>& numbers) → double` - Minimum value
- `maximum(const std::vector<double>& numbers) → double` - Maximum value
- `range(const std::vector<double>& numbers) → double` - Difference between max and min
- `median(std::vector<double> numbers) → double` - Middle value (sorts the data)

**Fractions**
- `addFractions(double num1, double den1, double num2, double den2) → double` - Adds two fractions
- `subtractFractions(double num1, double den1, double num2, double den2) → double` - Subtracts fractions
- `multiplyFractions(double num1, double den1, double num2, double den2) → double` - Multiplies fractions
- `divideFractions(double num1, double den1, double num2, double den2) → double` - Divides fractions

**Rounding**
- `roundToNearest(double n) → double` - Rounds to nearest integer
- `roundUp(double n) → double` - Ceiling function
- `roundDown(double n) → double` - Floor function
- `roundToDecimalPlaces(double n, int places) → double` - Rounds to specified decimal places

**Number Properties**
- `isEven(int n) → bool` - Checks if even
- `isOdd(int n) → bool` - Checks if odd
- `isPrime(int n) → bool` - Tests for primality
- `greatestCommonDivisor(int a, int b) → int` - GCD of two integers
- `leastCommonMultiple(int a, int b) → int` - LCM of two integers

**Geometry**
- `distance2D(double x1, double y1, double x2, double y2) → double` - Euclidean distance between two points
- `pythagorean(double a, double b) → double` - Calculates hypotenuse using Pythagorean theorem

**Conversions**
- `celsiusToFahrenheit(double celsius) → double` - Temperature conversion C → F
- `fahrenheitToCelsius(double fahrenheit) → double` - Temperature conversion F → C

**Finance**
- `simpleInterest(double principal, double rate, double time) → double` - Calculates simple interest

#### Example Usage

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    double a, b;
    char op;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter operation (e.g., 5 + 3): ";
    std::cin >> a >> op >> b;

    double result;
    switch(op) {
        case '+':
            result = imeth::Arithmetic::add(a, b);
            break;
        case '-':
            result = imeth::Arithmetic::subtract(a, b);
            break;
        case '*':
            result = imeth::Arithmetic::multiply(a, b);
            break;
        case '/':
            result = imeth::Arithmetic::divide(a, b);
            break;
        default:
            std::cout << "Invalid operator!\n";
            return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
```

#### More Examples

```c++
// Statistical calculations
std::vector<double> grades = {85.5, 92.0, 78.5, 95.0, 88.0};
double avg = imeth::Arithmetic::average(grades);      // 87.8
double med = imeth::Arithmetic::median(grades);        // 88.0
double minGrade = imeth::Arithmetic::minimum(grades);  // 78.5

// Number theory
int gcd = imeth::Arithmetic::greatestCommonDivisor(48, 18);  // 6
bool prime = imeth::Arithmetic::isPrime(17);                  // true

// Percentage calculations
double discount = imeth::Arithmetic::percentOf(20, 100.0);    // 20.0
double increase = imeth::Arithmetic::percentIncrease(50, 75); // 50.0

// Geometry
double dist = imeth::Arithmetic::distance2D(0, 0, 3, 4);      // 5.0
double hyp = imeth::Arithmetic::pythagorean(3, 4);            // 5.0

// Temperature conversion
double fahrenheit = imeth::Arithmetic::celsiusToFahrenheit(25); // 77.0
```

### Logarithm
Logarithm is the second chapter that can be found from the `operation` category. It provides methods and functions to operate logarithmic operations, including common logarithms, natural logarithms, exponential equation solving, and base conversions.

It can be found here:
```c++
#include <imeth/operation/logarithm.hpp>
```

#### Features

**Logarithm Functions**
- `log(double base, double value) → std::optional<double>` - Computes log_base(value) with arbitrary base
- `ln(double value) → std::optional<double>` - Natural logarithm (base e)
- `log10(double value) → std::optional<double>` - Common logarithm (base 10)
- `log2(double value) → std::optional<double>` - Binary logarithm (base 2)

**Exponential Equations**
- `solve_exponential(double base, double value) → std::optional<double>` - Solves base^x = value for x

**Base Conversion**
- `change_base(double value, double old_base, double new_base) → std::optional<double>` - Converts logarithm from one base to another using the change of base formula

#### Return Values

All methods return `std::optional<double>`:
- Contains a value if the operation is valid
- Returns `std::nullopt` if:
 - `value ≤ 0` (logarithm undefined for non-positive numbers)
 - `base ≤ 0` (invalid base)
 - `base = 1` (division by zero in change of base formula)

#### Example Usage

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>

int main() {
    // Basic logarithms
    auto result = imeth::Logarithm::log(2, 8);
    if (result.has_value()) {
        std::cout << "log_2(8) = " << result.value() << "\n";  // 3.0
    }

    // Natural logarithm
    auto ln_result = imeth::Logarithm::ln(2.718281828);
    if (ln_result.has_value()) {
        std::cout << "ln(e) ≈ " << ln_result.value() << "\n";  // ≈ 1.0
    }

    // Common logarithm
    auto log10_result = imeth::Logarithm::log10(1000);
    if (log10_result.has_value()) {
        std::cout << "log_10(1000) = " << log10_result.value() << "\n";  // 3.0
    }

    // Binary logarithm
    auto log2_result = imeth::Logarithm::log2(16);
    if (log2_result.has_value()) {
        std::cout << "log_2(16) = " << log2_result.value() << "\n";  // 4.0
    }

    return 0;
}
```

#### More Examples

```c++
// Solving exponential equations
// Solve: 2^x = 32
auto x = imeth::Logarithm::solve_exponential(2, 32);
if (x.has_value()) {
    std::cout << "x = " << x.value() << "\n";  // 5.0
}

// Solve: 10^x = 1000
auto x2 = imeth::Logarithm::solve_exponential(10, 1000);
if (x2.has_value()) {
    std::cout << "x = " << x2.value() << "\n";  // 3.0
}

// Change of base
// Convert log_2(8) to base 10
auto converted = imeth::Logarithm::change_base(8, 2, 10);
if (converted.has_value()) {
    std::cout << "log_10(8) = " << converted.value() << "\n";  // ≈ 0.903
}

// Error handling
auto invalid = imeth::Logarithm::log(2, -5);
if (!invalid.has_value()) {
    std::cout << "Cannot compute logarithm of negative number\n";
}

auto invalid_base = imeth::Logarithm::log(1, 10);
if (!invalid_base.has_value()) {
    std::cout << "Base cannot be 1\n";
}
```

#### Mathematical Properties

The logarithm functions implement standard mathematical properties:
- **Product rule**: log(xy) = log(x) + log(y)
- **Quotient rule**: log(x/y) = log(x) - log(y)
- **Power rule**: log(x^n) = n·log(x)
- **Change of base**: log_b(x) = log_a(x) / log_a(b)

### Algebra
Ah, yes, algebra, my favorite subject. This chapter exists in the `linear` category and provides tools for solving linear equations, systems of linear equations, and quadratic equations.

It can be found here:
```c++
#include <imeth/linear/algebra.hpp>
```

#### Classes

The algebra module contains two main classes:
- **`LinearAlgebra`** - Solves linear equations and systems of linear equations
- **`QuadraticEquation`** - Solves quadratic equations using the quadratic formula

---

### `LinearAlgebra`

Provides methods for solving linear equations in one or two variables.

#### Features

**Single Variable Linear Equations**
- `solve_1v(double a, double b) → std::optional<double>` - Solves ax + b = 0 for x
 - Returns `std::nullopt` if no solution exists (when a = 0 and b ≠ 0)

**System of Two Linear Equations**
- `solve_2v(double a1, double b1, double c1, double a2, double b2, double c2) → std::optional<std::pair<double, double>>` - Solves the system:
  ```
  a1·x + b1·y = c1
  a2·x + b2·y = c2
  ```
 - Returns `std::pair<double, double>` containing (x, y) if a unique solution exists
 - Returns `std::nullopt` if the system has no solution or infinitely many solutions

#### Example Usage

```c++
#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve: 2x + 6 = 0
    auto result = imeth::LinearAlgebra::solve_1v(2, 6);
    if (result.has_value()) {
        std::cout << "x = " << result.value() << "\n";  // x = -3
    }

    // Solve system:
    // 2x + 3y = 8
    // x - y = 1
    auto system = imeth::LinearAlgebra::solve_2v(2, 3, 8, 1, -1, 1);
    if (system.has_value()) {
        auto [x, y] = system.value();
        std::cout << "x = " << x << ", y = " << y << "\n";  // x = 2.2, y = 1.2
    }

    return 0;
}
```

---

### `QuadraticEquation`

Solves quadratic equations of the form ax² + bx + c = 0 using the quadratic formula.

#### Features

**Solution Type**
```c++
using Solution = std::variant<std::monostate, double, std::pair<double, double>>;
```

The `Solution` type can represent three possible outcomes:
- `std::monostate` - No real solutions (complex roots, discriminant < 0)
- `double` - One solution / repeated root (discriminant = 0)
- `std::pair<double, double>` - Two distinct real solutions (discriminant > 0), where first ≤ second

**Solving Quadratic Equations**
- `solve(double a, double b, double c) → Solution` - Solves ax² + bx + c = 0
 - Uses the quadratic formula: x = (-b ± √(b² - 4ac)) / 2a
 - Handles degenerate cases (when a = 0, reduces to linear equation)
 - Returns solutions in ascending order when two solutions exist

#### Example Usage

```c++
#include <imeth/linear/algebra.hpp>
#include <iostream>
#include <variant>

int main() {
    // Solve: x² - 5x + 6 = 0
    // Factors as: (x - 2)(x - 3) = 0
    auto result = imeth::QuadraticEquation::solve(1, -5, 6);

    if (std::holds_alternative<std::pair<double, double>>(result)) {
        auto [x1, x2] = std::get<std::pair<double, double>>(result);
        std::cout << "Two solutions: x1 = " << x1 << ", x2 = " << x2 << "\n";
        // Output: x1 = 2, x2 = 3
    }
    else if (std::holds_alternative<double>(result)) {
        double x = std::get<double>(result);
        std::cout << "One solution: x = " << x << "\n";
    }
    else {
        std::cout << "No real solutions (complex roots)\n";
    }

    return 0;
}
```

#### More Examples

```c++
// Repeated root (discriminant = 0)
// Solve: x² - 4x + 4 = 0  →  (x - 2)² = 0
auto repeated = imeth::QuadraticEquation::solve(1, -4, 4);
if (std::holds_alternative<double>(repeated)) {
    double x = std::get<double>(repeated);
    std::cout << "Repeated root: x = " << x << "\n";  // x = 2
}

// No real solutions (discriminant < 0)
// Solve: x² + x + 1 = 0
auto no_real = imeth::QuadraticEquation::solve(1, 1, 1);
if (std::holds_alternative<std::monostate>(no_real)) {
    std::cout << "No real solutions\n";
}

// Negative leading coefficient
// Solve: -x² + 4x - 3 = 0  →  x² - 4x + 3 = 0
auto negative_a = imeth::QuadraticEquation::solve(-1, 4, -3);
if (std::holds_alternative<std::pair<double, double>>(negative_a)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(negative_a);
    std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";  // x1 = 1, x2 = 3
}

// Working with LinearAlgebra and QuadraticEquation together
// Check if a value is a solution
auto solutions = imeth::QuadraticEquation::solve(1, -3, 2);
if (std::holds_alternative<std::pair<double, double>>(solutions)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(solutions);
    // Verify: x² - 3x + 2 = 0 when x = x1
    double check = x1 * x1 - 3 * x1 + 2;
    std::cout << "Verification: " << check << "\n";  // ≈ 0
}
```

#### Mathematical Background

**Linear Equations (1 variable)**
- Form: ax + b = 0
- Solution: x = -b/a (when a ≠ 0)

**System of Linear Equations (2 variables)**
- Uses elimination or substitution methods
- Determines if system has unique solution, no solution, or infinite solutions

**Quadratic Equations**
- Form: ax² + bx + c = 0
- Discriminant: Δ = b² - 4ac
 - Δ > 0: Two distinct real roots
 - Δ = 0: One repeated root
 - Δ < 0: Two complex conjugate roots (no real solutions)
- Quadratic formula: x = (-b ± √Δ) / 2a

### Matrix
I genuinely don't know what matrix or vector is (besides them being a dynamic alternative for arrays in C++). I mean, what do you expect from a 9th grader?
But, here the chapter `matrix.hpp`, exists...

It can be found here:
```c++
#include <imeth/linear/matrix.hpp>
```

#### Classes

The matrix module contains three main classes:
- **Matrix** - Represents a 2D matrix and provides matrix operations
- **Vector** - Represents a mathematical vector (1D array of numbers)
- **Solver** - Provides methods for solving systems of linear equations

---

### Matrix

A 2D array of numbers that supports mathematical operations like addition, multiplication, and transposition.

#### Constructors

- `Matrix(size_t rows, size_t cols)` - Creates a matrix with specified dimensions (initialized to zero)
- `Matrix(std::initializer_list<std::vector<double>> data)` - Creates a matrix from a list of rows

#### Element Access

- `operator()(size_t r, size_t c) → double&` - Accesses element at row r, column c (modifiable)
- `operator()(size_t r, size_t c) const → double` - Accesses element at row r, column c (read-only)

#### Properties

- `rows() const → size_t` - Returns the number of rows
- `cols() const → size_t` - Returns the number of columns

#### Static Methods

- `identity(size_t n) → Matrix` - Creates an n×n identity matrix (1s on diagonal, 0s elsewhere)

#### Operations

- `transpose() const → Matrix` - Returns the transpose (rows ↔ columns)
- `operator*(const Matrix& rhs) const → Matrix` - Matrix multiplication
- `operator+(const Matrix& rhs) const → Matrix` - Matrix addition
- `operator-(const Matrix& rhs) const → Matrix` - Matrix subtraction

#### Example Usage

```c++
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

#### More Examples

```c++
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

### Vector

A 1D array of numbers (essentially a column vector in mathematical terms).

#### Constructors

- `Vector(size_t n)` - Creates a vector of size n (initialized to zero)
- `Vector(std::initializer_list<double> data)` - Creates a vector from a list of values

#### Element Access

- `operator[](size_t i) → double&` - Accesses element at index i (modifiable)
- `operator[](size_t i) const → double` - Accesses element at index i (read-only)

#### Properties

- `size() const → size_t` - Returns the number of elements

#### Example Usage

```c++
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

### Solver

Provides numerical methods for solving systems of linear equations Ax = b, where A is a matrix, x is the unknown vector, and b is the result vector.

#### Methods

- `gaussian_elimination(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using Gaussian elimination with back substitution
- `gauss_jordan(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using Gauss-Jordan elimination (reduced row echelon form)
- `lu_decomposition(const Matrix& A, const Vector& b) → Vector` - Solves Ax = b using LU decomposition (factors A = LU)

#### Example Usage

```c++
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

#### More Examples

```c++
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

#### Mathematical Background

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