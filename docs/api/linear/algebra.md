# Algebra

Ah, yes, algebra, my favorite subject. This chapter exists in the `linear` category and provides tools for solving linear equations, systems of linear equations, and quadratic equations.

```cpp
#include <imeth/linear/algebra.hpp>
```

## Classes

The algebra module contains two main classes:
- **`LinearAlgebra`** - Solves linear equations and systems of linear equations
- **`QuadraticEquation`** - Solves quadratic equations using the quadratic formula

---

## LinearAlgebra

Provides methods for solving linear equations in one or two variables.

### Features

#### Single Variable Linear Equations
- `solve_1v(double a, double b) → std::optional<double>` - Solves ax + b = 0 for x
  - Returns `std::nullopt` if no solution exists (when a = 0 and b ≠ 0)

#### System of Two Linear Equations
- `solve_2v(double a1, double b1, double c1, double a2, double b2, double c2) → std::optional<std::pair<double, double>>` - Solves the system:
  ```
  a1·x + b1·y = c1
  a2·x + b2·y = c2
  ```
  - Returns `std::pair<double, double>` containing (x, y) if a unique solution exists
  - Returns `std::nullopt` if the system has no solution or infinitely many solutions

### Example Usage

```cpp
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

## QuadraticEquation

Solves quadratic equations of the form ax² + bx + c = 0 using the quadratic formula.

### Features

#### Solution Type
```cpp
using Solution = std::variant<std::monostate, double, std::pair<double, double>>;
```

The `Solution` type can represent three possible outcomes:
- `std::monostate` - No real solutions (complex roots, discriminant < 0)
- `double` - One solution / repeated root (discriminant = 0)
- `std::pair<double, double>` - Two distinct real solutions (discriminant > 0), where first ≤ second

#### Solving Quadratic Equations
- `solve(double a, double b, double c) → Solution` - Solves ax² + bx + c = 0
  - Uses the quadratic formula: x = (-b ± √(b² - 4ac)) / 2a
  - Handles degenerate cases (when a = 0, reduces to linear equation)
  - Returns solutions in ascending order when two solutions exist

### Example Usage

```cpp
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

### More Examples

```cpp
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

## Mathematical Background

### Linear Equations (1 variable)
- Form: ax + b = 0
- Solution: x = -b/a (when a ≠ 0)

### System of Linear Equations (2 variables)
- Uses elimination or substitution methods
- Determines if system has unique solution, no solution, or infinite solutions

### Quadratic Equations
- Form: ax² + bx + c = 0
- Discriminant: Δ = b² - 4ac
  - Δ > 0: Two distinct real roots
  - Δ = 0: One repeated root
  - Δ < 0: Two complex conjugate roots (no real solutions)
- Quadratic formula: x = (-b ± √Δ) / 2a
