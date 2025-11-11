# Logarithm

Logarithm is the second chapter from the `operation` category. It provides methods and functions for logarithmic operations, including common logarithms, natural logarithms, exponential equation solving, and base conversions. Logarithms are the inverse of exponential functions and are essential for solving problems involving exponential growth, decay, and scale transformations.

```c++
#include <imeth/operation/logarithm.hpp>
```

## Overview

Logarithms answer the question: "To what power must we raise a base to get a certain value?" This module helps you solve problems like:
- "2 raised to what power equals 8?" (Answer: 3, because 2³ = 8)
- "How many times must I double something to reach 1000?"
- "What's the pH of this solution?" (uses log₁₀)
- "How many bits do I need to represent this number?" (uses log₂)

---

## Return Value Convention

**IMPORTANT:** All logarithm functions return `std::optional<double>` for safe error handling.

```c++
auto result = imeth::Logarithm::log(2, 8);
if (result.has_value()) {
    std::cout << "Result: " << result.value() << "\n";
} else {
    std::cout << "Invalid input\n";
}
```

Functions return `std::nullopt` when:
- `value ≤ 0` (logarithm undefined for non-positive numbers)
- `base ≤ 0` (invalid base)
- `base = 1` (would cause division by zero)

---

## Logarithm Functions

### General Logarithm

```c++
std::optional<double> log(double base, double value);
```

Computes log_base(value) - the power to which base must be raised to get value.

**Formula:** If base^x = value, then log_base(value) = x

**Examples:**
```c++
auto result1 = imeth::Logarithm::log(2, 8);
// result1.value() = 3.0 (because 2³ = 8)

auto result2 = imeth::Logarithm::log(10, 100);
// result2.value() = 2.0 (because 10² = 100)

auto result3 = imeth::Logarithm::log(5, 125);
// result3.value() = 3.0 (because 5³ = 125)

auto result4 = imeth::Logarithm::log(3, 27);
// result4.value() = 3.0 (because 3³ = 27)

// Invalid cases
auto invalid1 = imeth::Logarithm::log(2, -5);
// invalid1.has_value() = false (negative value)

auto invalid2 = imeth::Logarithm::log(1, 10);
// invalid2.has_value() = false (base cannot be 1)

auto invalid3 = imeth::Logarithm::log(-2, 8);
// invalid3.has_value() = false (negative base)
```

**Real-world applications:**
- Database indexing complexity analysis
- Algorithm time complexity calculations
- Custom scale conversions
- Financial compound interest calculations

---

### Natural Logarithm (ln)

```c++
std::optional<double> ln(double value);
```

Computes the natural logarithm (base e ≈ 2.71828) - the most fundamental logarithm in mathematics.

**Formula:** ln(value) = log_e(value)

**Examples:**
```c++
auto result1 = imeth::Logarithm::ln(2.718281828);
// result1.value() ≈ 1.0 (ln(e) = 1)

auto result2 = imeth::Logarithm::ln(1);
// result2.value() = 0.0 (ln(1) = 0, because e⁰ = 1)

auto result3 = imeth::Logarithm::ln(7.389056);
// result3.value() ≈ 2.0 (ln(e²) = 2)

auto result4 = imeth::Logarithm::ln(20.085537);
// result4.value() ≈ 3.0 (ln(e³) = 3)

auto result5 = imeth::Logarithm::ln(0.367879);
// result5.value() ≈ -1.0 (ln(e⁻¹) = -1)

// Invalid case
auto invalid = imeth::Logarithm::ln(0);
// invalid.has_value() = false (ln(0) is undefined)
```

**Real-world applications:**
- Continuous compound interest: A = Pe^(rt), solve for t using ln
- Population growth models: P(t) = P₀e^(kt)
- Radioactive decay calculations
- Information theory and entropy
- Normal distribution calculations in statistics
- Chemical reaction rates (Arrhenius equation)
- Machine learning loss functions

**Why natural logarithm?**
The natural logarithm has unique mathematical properties:
- Derivative of ln(x) is 1/x (simplest)
- Integral of 1/x is ln(x)
- Area under curve 1/x from 1 to e equals 1

---

### Common Logarithm (log₁₀)

```c++
std::optional<double> log10(double value);
```

Computes the common logarithm (base 10) - widely used in science and engineering.

**Formula:** log₁₀(value) = log_10(value)

**Examples:**
```c++
auto result1 = imeth::Logarithm::log10(10);
// result1.value() = 1.0 (10¹ = 10)

auto result2 = imeth::Logarithm::log10(100);
// result2.value() = 2.0 (10² = 100)

auto result3 = imeth::Logarithm::log10(1000);
// result3.value() = 3.0 (10³ = 1000)

auto result4 = imeth::Logarithm::log10(1);
// result4.value() = 0.0 (10⁰ = 1)

auto result5 = imeth::Logarithm::log10(0.01);
// result5.value() = -2.0 (10⁻² = 0.01)

auto result6 = imeth::Logarithm::log10(50);
// result6.value() ≈ 1.699 (10^1.699 ≈ 50)
```

**Real-world applications:**
- **pH calculations**: pH = -log₁₀[H⁺] concentration
  - pH 7 (neutral): [H⁺] = 10⁻⁷
  - pH 3 (acidic): [H⁺] = 10⁻³
- **Decibel scale**: dB = 10·log₁₀(P/P₀)
  - Sound intensity measurements
  - Signal strength in telecommunications
- **Richter scale**: Earthquake magnitude
- **Star magnitude**: Brightness of celestial objects
- **Scientific notation**: Counting orders of magnitude
- **Slide rule calculations**: Historical computing

**Why base 10?**
Base 10 is intuitive for humans because:
- We use decimal number system
- Easy to count orders of magnitude
- Powers of 10 are easy to visualize

---

### Binary Logarithm (log₂)

```c++
std::optional<double> log2(double value);
```

Computes the binary logarithm (base 2) - fundamental in computer science.

**Formula:** log₂(value) = log_2(value)

**Examples:**
```c++
auto result1 = imeth::Logarithm::log2(2);
// result1.value() = 1.0 (2¹ = 2)

auto result2 = imeth::Logarithm::log2(8);
// result2.value() = 3.0 (2³ = 8)

auto result3 = imeth::Logarithm::log2(16);
// result3.value() = 4.0 (2⁴ = 16)

auto result4 = imeth::Logarithm::log2(1024);
// result4.value() = 10.0 (2¹⁰ = 1024)

auto result5 = imeth::Logarithm::log2(1);
// result5.value() = 0.0 (2⁰ = 1)

auto result6 = imeth::Logarithm::log2(0.5);
// result6.value() = -1.0 (2⁻¹ = 0.5)

auto result7 = imeth::Logarithm::log2(32);
// result7.value() = 5.0 (2⁵ = 32)
```

**Real-world applications:**
- **Bit calculations**: How many bits to represent n values?
  - 256 values = log₂(256) = 8 bits
  - 1024 values = log₂(1024) = 10 bits
- **Algorithm complexity**: Binary search is O(log₂(n))
- **Tree depth**: Binary tree with n nodes has depth ≈ log₂(n)
- **Information theory**: Entropy and information content
- **Audio processing**: Octaves in music (frequency doubling)
- **Image compression**: JPEG, PNG compression ratios
- **Network protocols**: Packet size calculations
- **Memory addressing**: Address space calculations

**Why base 2?**
Base 2 is natural for computers because:
- Binary system (0 and 1)
- Powers of 2 in memory (KB, MB, GB)
- Bit-level operations

---

## Exponential Equations

### Solve Exponential

```c++
std::optional<double> solve_exponential(double base, double value);
```

Solves the exponential equation: base^x = value for x.

This is equivalent to computing log_base(value), but the function name makes the intent clearer when solving equations.

**Formula:** If base^x = value, then x = log_base(value)

**Examples:**
```c++
// Solve: 2^x = 8
auto x1 = imeth::Logarithm::solve_exponential(2, 8);
// x1.value() = 3.0 (because 2³ = 8)

// Solve: 2^x = 32
auto x2 = imeth::Logarithm::solve_exponential(2, 32);
// x2.value() = 5.0 (because 2⁵ = 32)

// Solve: 10^x = 1000
auto x3 = imeth::Logarithm::solve_exponential(10, 1000);
// x3.value() = 3.0 (because 10³ = 1000)

// Solve: 3^x = 81
auto x4 = imeth::Logarithm::solve_exponential(3, 81);
// x4.value() = 4.0 (because 3⁴ = 81)

// Solve: 5^x = 125
auto x5 = imeth::Logarithm::solve_exponential(5, 125);
// x5.value() = 3.0 (because 5³ = 125)

// Solve: 2^x = 1
auto x6 = imeth::Logarithm::solve_exponential(2, 1);
// x6.value() = 0.0 (because 2⁰ = 1)

// Solve: e^x = 20
auto x7 = imeth::Logarithm::solve_exponential(2.718281828, 20);
// x7.value() ≈ 2.996 (because e^2.996 ≈ 20)
```

**Real-world applications:**
- **Compound interest**: How long until money doubles?
  - Solve: (1.05)^t = 2 → t = log₁.₀₅(2) ≈ 14.2 years at 5% interest
- **Population growth**: When will population reach target?
  - Solve: P₀(1.02)^t = 2P₀ → t = log₁.₀₂(2) ≈ 35 years at 2% growth
- **Radioactive decay**: How long for half-life?
  - Solve: (0.5)^t = 0.25 → t = 2 half-lives
- **Moore's Law**: When will transistor count reach target?
- **Pandemic modeling**: Infection doubling time
- **Battery discharge**: Time to reach certain voltage
- **Chemical reactions**: Time to completion

---

## Base Conversion

### Change Base

```c++
std::optional<double> change_base(double value, double old_base, double new_base);
```

Converts a logarithm from one base to another using the change of base formula.

**Formula:** log_new(value) = log_old(value) / log_old(new_base)

Or equivalently: log_b(x) = log_a(x) / log_a(b)

**Examples:**
```c++
// Convert log₂(8) to base 10
auto result1 = imeth::Logarithm::change_base(8, 2, 10);
// result1.value() ≈ 0.903 (log₁₀(8))

// Convert log₁₀(100) to base 2
auto result2 = imeth::Logarithm::change_base(100, 10, 2);
// result2.value() ≈ 6.644 (log₂(100))

// Convert log₅(25) to base 3
auto result3 = imeth::Logarithm::change_base(25, 5, 3);
// result3.value() ≈ 2.930 (log₃(25))

// Convert ln(e²) to base 10
auto result4 = imeth::Logarithm::change_base(7.389, 2.718281828, 10);
// result4.value() ≈ 0.869 (log₁₀(e²))

// Verify: log₂(8) = 3, converting to base 10
auto verify = imeth::Logarithm::change_base(8, 2, 10);
// First compute: log₁₀(8) ≈ 0.903
// Verify: log₂(8) = log₁₀(8) / log₁₀(2) = 0.903 / 0.301 ≈ 3.0
```

**Real-world applications:**
- **Calculator conversions**: Most calculators only have ln and log₁₀
  - To compute log₂(100): Use log₁₀(100) / log₁₀(2)
- **Algorithm analysis**: Converting between different complexity bases
- **Information theory**: Converting between different entropy bases
- **Scientific calculations**: Adapting formulas to available tools
- **Database queries**: Converting between different logarithmic scales

**Why change base?**
- Your calculator might only have certain bases (usually 10 and e)
- Different fields prefer different bases
- Mathematical proofs often use natural logarithm
- Computer science uses base 2
- General science uses base 10

---

## Mathematical Properties

The logarithm functions implement standard mathematical properties:

### Product Rule
**log(xy) = log(x) + log(y)**

```c++
// Instead of log(100 × 1000)
auto direct = imeth::Logarithm::log10(100000);  // 5.0

// Can compute as log(100) + log(1000)
auto log_100 = imeth::Logarithm::log10(100);    // 2.0
auto log_1000 = imeth::Logarithm::log10(1000);  // 3.0
// Sum: 2.0 + 3.0 = 5.0
```

**Real-world:** Multiplying very large numbers (astronomy, particle physics)

---

### Quotient Rule
**log(x/y) = log(x) - log(y)**

```c++
// Instead of log(1000 / 10)
auto direct = imeth::Logarithm::log10(100);     // 2.0

// Can compute as log(1000) - log(10)
auto log_1000 = imeth::Logarithm::log10(1000);  // 3.0
auto log_10 = imeth::Logarithm::log10(10);      // 1.0
// Difference: 3.0 - 1.0 = 2.0
```

**Real-world:** Simplifying division problems, slide rule calculations

---

### Power Rule
**log(x^n) = n · log(x)**

```c++
// Instead of log(2^10)
auto direct = imeth::Logarithm::log2(1024);     // 10.0

// Can compute as 10 × log(2)
auto log_2 = imeth::Logarithm::log2(2);         // 1.0
// Product: 10 × 1.0 = 10.0
```

**Real-world:** Exponential growth calculations, compound interest

---

### Change of Base Formula
**log_b(x) = log_a(x) / log_a(b)**

```c++
// Compute log₂(8) using base 10
auto log_8 = imeth::Logarithm::log10(8);        // 0.903
auto log_2 = imeth::Logarithm::log10(2);        // 0.301
// Division: 0.903 / 0.301 ≈ 3.0

// Or use the built-in function
auto result = imeth::Logarithm::change_base(8, 2, 10);  // 0.903
```

**Real-world:** When your calculator doesn't have the base you need

---

### Identity Properties
```c++
// log_b(b) = 1
auto log_e_e = imeth::Logarithm::ln(2.718281828);       // 1.0
auto log_10_10 = imeth::Logarithm::log10(10);           // 1.0
auto log_2_2 = imeth::Logarithm::log2(2);               // 1.0

// log_b(1) = 0 (for any base)
auto log_10_1 = imeth::Logarithm::log10(1);             // 0.0
auto ln_1 = imeth::Logarithm::ln(1);                    // 0.0
auto log_2_1 = imeth::Logarithm::log2(1);               // 0.0

// log_b(b^x) = x
auto result = imeth::Logarithm::log2(8);                // 3.0 (because 2³ = 8)

// b^(log_b(x)) = x
// If log₂(8) = 3, then 2³ = 8
```

---

## Complete Examples

### Example 1: Compound Interest Calculator

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>
#include <iomanip>

int main() {
    double principal = 1000.0;      // Initial amount
    double rate = 0.05;             // 5% annual interest
    double target = 2000.0;         // Want to double money

    // Solve: principal × (1 + rate)^t = target
    // (1.05)^t = 2
    // t = log₁.₀₅(2)

    double growth_factor = 1.0 + rate;
    double multiplier = target / principal;

    auto years = imeth::Logarithm::solve_exponential(growth_factor, multiplier);

    if (years.has_value()) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "To turn $" << principal << " into $" << target
                  << " at " << (rate * 100) << "% interest:\n";
        std::cout << "Time needed: " << years.value() << " years\n";
    }

    return 0;
}
// Output: Time needed: 14.21 years
```

---

### Example 2: pH Calculator (Chemistry)

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>
#include <iomanip>

int main() {
    // pH = -log₁₀[H⁺]
    double hydrogen_concentration = 0.001;  // mol/L

    auto log_h = imeth::Logarithm::log10(hydrogen_concentration);

    if (log_h.has_value()) {
        double pH = -log_h.value();

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "[H⁺] = " << hydrogen_concentration << " mol/L\n";
        std::cout << "pH = " << pH << "\n";

        if (pH < 7) {
            std::cout << "Solution is acidic\n";
        } else if (pH > 7) {
            std::cout << "Solution is basic\n";
        } else {
            std::cout << "Solution is neutral\n";
        }
    }

    return 0;
}
// Output: pH = 3.00, Solution is acidic
```

---

### Example 3: Bit Calculations (Computer Science)

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>
#include <cmath>

int main() {
    int num_values = 1000;

    // How many bits needed to represent 1000 different values?
    auto bits_needed = imeth::Logarithm::log2(num_values);

    if (bits_needed.has_value()) {
        int bits = static_cast<int>(std::ceil(bits_needed.value()));
        int max_values = static_cast<int>(std::pow(2, bits));

        std::cout << "To represent " << num_values << " values:\n";
        std::cout << "Bits needed (exact): " << bits_needed.value() << "\n";
        std::cout << "Bits needed (rounded): " << bits << " bits\n";
        std::cout << "Max values with " << bits << " bits: "
                  << max_values << "\n";
    }

    return 0;
}
// Output: Bits needed: 10 bits (can represent up to 1024 values)
```

### Example 4: Algorithm Complexity Analysis

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>
#include <iomanip>

int main() {
    std::vector<int> data_sizes = {100, 1000, 10000, 100000, 1000000};

    std::cout << std::setw(12) << "Data Size"
              << std::setw(15) << "Linear O(n)"
              << std::setw(20) << "Logarithmic O(log n)"
              << std::setw(20) << "Linearithmic O(n log n)\n";
    std::cout << std::string(67, '-') << "\n";

    for (int n : data_sizes) {
        auto log_n = imeth::Logarithm::log2(n);

        if (log_n.has_value()) {
            std::cout << std::setw(12) << n
                      << std::setw(15) << n
                      << std::setw(20) << std::fixed << std::setprecision(2)
                      << log_n.value()
                      << std::setw(20) << (n * log_n.value()) << "\n";
        }
    }

    return 0;
}
// Shows how logarithmic algorithms scale much better than linear
```

---

### Example 8: Base Conversion for Calculator

```c++
#include <imeth/operation/logarithm.hpp>
#include <iostream>
#include <iomanip>

int main() {
    // Most calculators only have ln and log₁₀
    // To compute log₃(27), use change of base

    double value = 27;
    double desired_base = 3;

    // Method 1: Using change_base
    auto result1 = imeth::Logarithm::change_base(value, desired_base, 10);

    // Method 2: Manual calculation
    auto log10_val = imeth::Logarithm::log10(value);
    auto log10_base = imeth::Logarithm::log10(desired_base);

    if (log10_val.has_value() && log10_base.has_value()) {
        double result2 = log10_val.value() / log10_base.value();

        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Computing log₃(27):\n";
        std::cout << "Using change_base: " << result1.value() << "\n";
        std::cout << "Manual calculation: " << result2 << "\n";
        std::cout << "Verification: 3³ = " << std::pow(3, result2) << "\n";
    }

    return 0;
}
// Output: log₃(27) = 3.0 (because 3³ = 27)
```

---

## Error Handling Best Practices

Always check if the result has a value before using it:

```c++
// Good practice
auto result = imeth::Logarithm::log(2, 8);
if (result.has_value()) {
    std::cout << "Result: " << result.value() << "\n";
} else {
    std::cerr << "Error: Invalid input for logarithm\n";
}

// Alternative with default value
auto result = imeth::Logarithm::log(2, 8);
double value = result.value_or(0.0);  // Returns 0.0 if invalid

// Compact check
if (auto result = imeth::Logarithm::log(2, 8)) {
    std::cout << "Result: " << *result << "\n";
}
```

**Common error scenarios:**
```c++
// Negative value
auto err1 = imeth::Logarithm::log10(-5);    // nullopt

// Zero value
auto err2 = imeth::Logarithm::ln(0);        // nullopt

// Invalid base (≤ 0)
auto err3 = imeth::Logarithm::log(-2, 8);   // nullopt

// Base = 1 (undefined)
auto err4 = imeth::Logarithm::log(1, 10);   // nullopt
```

---

## Tips

- **Choose the right base**: Use ln for calculus, log₁
