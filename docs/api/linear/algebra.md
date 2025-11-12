# Algebra

The algebra chapter provides essential tools for solving linear and quadratic equations. This module is fundamental for mathematical computations involving equations with one or two variables, and quadratic problems.

```c++
#include <imeth/linear/algebra.hpp>
```

## Overview

Algebra is the mathematics of solving equations. This module helps you answer questions like:
- "What value of x makes this equation true?"
- "Where do these two lines intersect?"
- "What are the roots of this quadratic equation?"

---

## LinearAlgebra

Provides methods for solving linear equations in one or two variables.

### Single Variable Linear Equations

```c++
static std::optional<double> solve_1v(double a, double b);
```

Solves equations of the form ax + b = 0 for x.

**Formula:** x = -b/a (when a ≠ 0)

**Examples:**
```c++
// Solve: 2x + 6 = 0
auto result = imeth::LinearAlgebra::solve_1v(2, 6);
if (result.has_value()) {
    std::cout << "x = " << result.value() << "\n";  // x = -3
}

// Solve: 5x - 15 = 0
auto x = imeth::LinearAlgebra::solve_1v(5, -15);  // x = 3

// No solution case: 0x + 5 = 0
auto no_solution = imeth::LinearAlgebra::solve_1v(0, 5);
if (!no_solution.has_value()) {
    std::cout << "No solution exists\n";
}
```

**Real-world:**
- Simple cost equations: "If total cost = 2x + 6, when is cost zero?"
- Distance problems: "At what time does position equal zero?"
- Break-even analysis

**Returns:** `std::optional<double>` containing the solution, or `std::nullopt` if no solution exists (when a = 0 and b ≠ 0)

---

### System of Two Linear Equations

```c++
static std::optional<std::pair<double, double>> solve_2v(
    double a1, double b1, double c1,
    double a2, double b2, double c2
);
```

Solves systems of two linear equations with two variables:
```
a1·x + b1·y = c1
a2·x + b2·y = c2
```

**Examples:**
```c++
// Solve system:
// 2x + 3y = 8
// x - y = 1
auto system = imeth::LinearAlgebra::solve_2v(2, 3, 8, 1, -1, 1);
if (system.has_value()) {
    auto [x, y] = system.value();
    std::cout << "x = " << x << ", y = " << y << "\n";  // x = 2.2, y = 1.2
}

// Solve system:
// 3x + 2y = 7
// 2x + y = 4
auto result = imeth::LinearAlgebra::solve_2v(3, 2, 7, 2, 1, 4);  // x = 1, y = 2

// Parallel lines (no solution)
// x + y = 1
// x + y = 2
auto parallel = imeth::LinearAlgebra::solve_2v(1, 1, 1, 1, 1, 2);
if (!parallel.has_value()) {
    std::cout << "No solution (parallel lines)\n";
}

// Infinite solutions (same line)
// 2x + 4y = 6
// x + 2y = 3
auto infinite = imeth::LinearAlgebra::solve_2v(2, 4, 6, 1, 2, 3);
if (!infinite.has_value()) {
    std::cout << "Infinite solutions (same line)\n";
}
```

**Real-world:**
- Finding intersection points of two lines
- Supply and demand equilibrium
- Mixture problems (two unknowns)
- Resource allocation with constraints

**Returns:** `std::optional<std::pair<double, double>>` containing (x, y) if a unique solution exists, or `std::nullopt` if the system has no solution or infinitely many solutions

---

## QuadraticEquation

Solves quadratic equations of the form ax² + bx + c = 0 using the quadratic formula.

### Solution Type

```c++
using Solution = std::variant<std::monostate, double, std::pair<double, double>>;
```

The `Solution` type represents three possible outcomes:
- `std::monostate` - No real solutions (complex roots, discriminant < 0)
- `double` - One solution / repeated root (discriminant = 0)
- `std::pair<double, double>` - Two distinct real solutions (discriminant > 0), ordered ascending

---

### Solving Quadratic Equations

```c++
static Solution solve(double a, double b, double c);
```

Solves equations of the form ax² + bx + c = 0.

**Formula:** x = (-b ± √(b² - 4ac)) / 2a

**Discriminant:** Δ = b² - 4ac
- Δ > 0: Two distinct real roots
- Δ = 0: One repeated root
- Δ < 0: Two complex conjugate roots (no real solutions)

**Examples:**

#### Two Distinct Solutions
```c++
// Solve: x² - 5x + 6 = 0
// Factors as: (x - 2)(x - 3) = 0
auto result = imeth::QuadraticEquation::solve(1, -5, 6);

if (std::holds_alternative<std::pair<double, double>>(result)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(result);
    std::cout << "Two solutions: x1 = " << x1 << ", x2 = " << x2 << "\n";
    // Output: x1 = 2, x2 = 3
}

// Solve: x² - 7x + 10 = 0
auto roots = imeth::QuadraticEquation::solve(1, -7, 10);  // x1 = 2, x2 = 5

// Solve: 2x² + 5x - 3 = 0
auto result2 = imeth::QuadraticEquation::solve(2, 5, -3);  // x1 = -3, x2 = 0.5
```

#### One Repeated Root
```c++
// Solve: x² - 4x + 4 = 0
// Factors as: (x - 2)² = 0
auto repeated = imeth::QuadraticEquation::solve(1, -4, 4);

if (std::holds_alternative<double>(repeated)) {
    double x = std::get<double>(repeated);
    std::cout << "Repeated root: x = " << x << "\n";  // x = 2
}

// Solve: x² + 6x + 9 = 0  →  (x + 3)² = 0
auto root = imeth::QuadraticEquation::solve(1, 6, 9);  // x = -3
```

#### No Real Solutions
```c++
// Solve: x² + x + 1 = 0
auto no_real = imeth::QuadraticEquation::solve(1, 1, 1);

if (std::holds_alternative<std::monostate>(no_real)) {
    std::cout << "No real solutions (complex roots)\n";
}

// Solve: x² + 4x + 5 = 0
auto complex = imeth::QuadraticEquation::solve(1, 4, 5);  // No real roots
```

#### Negative Leading Coefficient
```c++
// Solve: -x² + 4x - 3 = 0
// Equivalent to: x² - 4x + 3 = 0
auto negative_a = imeth::QuadraticEquation::solve(-1, 4, -3);

if (std::holds_alternative<std::pair<double, double>>(negative_a)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(negative_a);
    std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";  // x1 = 1, x2 = 3
}
```

#### Degenerate Case (Linear Equation)
```c++
// When a = 0, equation becomes linear: bx + c = 0
// Solve: 0x² + 3x - 6 = 0  →  3x - 6 = 0
auto linear = imeth::QuadraticEquation::solve(0, 3, -6);  // x = 2
```

---

### Verification and Usage

```c++
// Verify a solution
auto solutions = imeth::QuadraticEquation::solve(1, -3, 2);
if (std::holds_alternative<std::pair<double, double>>(solutions)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(solutions);
    
    // Verify: x² - 3x + 2 = 0 when x = x1
    double check = x1 * x1 - 3 * x1 + 2;
    std::cout << "Verification: " << check << "\n";  // ≈ 0
    
    // Check second root
    double check2 = x2 * x2 - 3 * x2 + 2;
    std::cout << "Verification: " << check2 << "\n";  // ≈ 0
}

// Pattern matching all solution types
auto result = imeth::QuadraticEquation::solve(2, -4, 2);
if (std::holds_alternative<std::pair<double, double>>(result)) {
    auto [x1, x2] = std::get<std::pair<double, double>>(result);
    std::cout << "Two solutions: " << x1 << ", " << x2 << "\n";
}
else if (std::holds_alternative<double>(result)) {
    double x = std::get<double>(result);
    std::cout << "One solution: " << x << "\n";
}
else {
    std::cout << "No real solutions\n";
}
```

**Real-world:**
- Projectile motion (height vs. time)
- Area and optimization problems
- Physics problems (acceleration, velocity)
- Economics (profit maximization)
- Engineering (beam deflection, circuit analysis)

**Returns:**
- `std::monostate` if no real solutions exist
- `double` if one repeated root exists
- `std::pair<double, double>` if two distinct solutions exist (ordered ascending)

---

## Complete Example

```c++
#include <imeth/linear/algebra.hpp>
#include <iostream>
#include <variant>

int main() {
    using namespace imeth;
    
    // Single variable linear equation
    std::cout << "=== Linear Equation (1 variable) ===\n";
    auto linear1 = LinearAlgebra::solve_1v(2, 6);
    if (linear1.has_value()) {
        std::cout << "2x + 6 = 0, x = " << linear1.value() << "\n";  // x = -3
    }
    
    // System of linear equations
    std::cout << "\n=== System of Linear Equations ===\n";
    auto system = LinearAlgebra::solve_2v(2, 3, 8, 1, -1, 1);
    if (system.has_value()) {
        auto [x, y] = system.value();
        std::cout << "System solution: x = " << x << ", y = " << y << "\n";
    }
    
    // Quadratic with two solutions
    std::cout << "\n=== Quadratic Equations ===\n";
    auto quad1 = QuadraticEquation::solve(1, -5, 6);
    if (std::holds_alternative<std::pair<double, double>>(quad1)) {
        auto [x1, x2] = std::get<std::pair<double, double>>(quad1);
        std::cout << "x² - 5x + 6 = 0: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
    
    // Quadratic with repeated root
    auto quad2 = QuadraticEquation::solve(1, -4, 4);
    if (std::holds_alternative<double>(quad2)) {
        double x = std::get<double>(quad2);
        std::cout << "x² - 4x + 4 = 0: x = " << x << " (repeated)\n";
    }
    
    // Quadratic with no real solutions
    auto quad3 = QuadraticEquation::solve(1, 1, 1);
    if (std::holds_alternative<std::monostate>(quad3)) {
        std::cout << "x² + x + 1 = 0: No real solutions\n";
    }
    
    // Real-world problem: Projectile motion
    std::cout << "\n=== Projectile Motion Example ===\n";
    // Height equation: h(t) = -4.9t² + 20t + 2
    // Find when projectile hits ground (h = 0)
    auto time = QuadraticEquation::solve(-4.9, 20, 2);
    if (std::holds_alternative<std::pair<double, double>>(time)) {
        auto [t1, t2] = std::get<std::pair<double, double>>(time);
        std::cout << "Projectile hits ground at t = " << t2 << " seconds\n";
    }
    
    return 0;
}
```

---

## Tips

- **Linear vs Quadratic**: Linear equations have at most one solution; quadratic equations can have 0, 1, or 2 real solutions
- **Check for nullopt**: Always verify `has_value()` before accessing `std::optional` results
- **Discriminant**: For quadratics, check discriminant (b² - 4ac) to predict number of solutions before solving
- **Solution Order**: When two solutions exist, they're always returned in ascending order (smaller first)
- **Degenerate Cases**: Handle edge cases where a = 0 (linear instead of quadratic)
- **Verification**: Test solutions by substituting back into original equation

---

## Quick Reference

| Problem Type | Function | Example Use Case |
|-------------|----------|------------------|
| Linear (1 var) | `LinearAlgebra::solve_1v(a, b)` | Cost equations, simple physics |
| Linear system | `LinearAlgebra::solve_2v(...)` | Line intersections, supply/demand |
| Quadratic | `QuadraticEquation::solve(a, b, c)` | Projectile motion, area problems |

| Discriminant | Result Type | Meaning |
|--------------|-------------|---------|
| Δ > 0 | `std::pair<double, double>` | Two distinct real roots |
| Δ = 0 | `double` | One repeated root |
| Δ < 0 | `std::monostate` | No real roots (complex) |

---

## Mathematical Background

### Linear Equations (1 variable)
- **Form:** ax + b = 0
- **Solution:** x = -b/a (when a ≠ 0)
- **No solution when:** a = 0 and b ≠ 0

### System of Linear Equations (2 variables)
- **Form:** Two equations with two unknowns
- **Methods:** Elimination, substitution, matrix methods
- **Unique solution when:** Lines intersect at one point
- **No solution when:** Lines are parallel
- **Infinite solutions when:** Lines coincide (same line)

### Quadratic Equations
- **Form:** ax² + bx + c = 0
- **Quadratic Formula:** x = (-b ± √Δ) / 2a
- **Discriminant:** Δ = b² - 4ac
  - Δ > 0: Two distinct real roots
  - Δ = 0: One repeated root (perfect square)
  - Δ < 0: Two complex conjugate roots
- **Factored Form:** a(x - r₁)(x - r₂) = 0, where r₁ and r₂ are roots