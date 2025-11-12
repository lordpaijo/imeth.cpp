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

- **Choose the right base**: Use ln for calculus, log₁₀ for science/engineering, log₂ for computer science
- **Always validate input**: Check for negative numbers and zero before computation
- **Use std::optional properly**: Always check `has_value()` before accessing the result
- **Understand the domain**: Logarithms only work for positive numbers
- **Performance consideration**: `ln` is typically fastest, other bases use conversion
- **Precision**: Results are accurate to double precision (~15 decimal places)
- **Avoid unnecessary conversions**: Use the specific function (ln, log10, log2) instead of converting from log()

---

## Common Pitfalls

### 1. Forgetting to Check std::optional

```c++
// ❌ WRONG - May crash if result is nullopt
auto result = imeth::Logarithm::log(2, -8);
std::cout << result.value() << "\n";  // CRASH!

// ✅ CORRECT
auto result = imeth::Logarithm::log(2, -8);
if (result.has_value()) {
    std::cout << result.value() << "\n";
} else {
    std::cerr << "Invalid input\n";
}
```

### 2. Using Wrong Base

```c++
// ❌ WRONG - Using natural log for pH calculation
auto pH = -imeth::Logarithm::ln(0.001);  // Wrong! pH uses base 10

// ✅ CORRECT
auto log_h = imeth::Logarithm::log10(0.001);
if (log_h.has_value()) {
    double pH = -log_h.value();  // pH = 3.0
}
```

### 3. Confusion Between log() and solve_exponential()

```c++
// Both compute the same thing but have different semantic meaning:

// When you think: "log₂(8) = ?"
auto result1 = imeth::Logarithm::log(2, 8);  // 3.0

// When you think: "2^x = 8, solve for x"
auto result2 = imeth::Logarithm::solve_exponential(2, 8);  // 3.0

// Use the one that matches your mental model!
```

### 4. Base 1 Error

```c++
// ❌ WRONG - Base cannot be 1
auto result = imeth::Logarithm::log(1, 100);  // nullopt!
// log₁(x) is undefined because 1^n = 1 for all n

// ✅ CORRECT - Use a valid base
auto result = imeth::Logarithm::log(10, 100);  // 2.0
```

### 5. Negative or Zero Input

```c++
// ❌ WRONG - Logarithm undefined for non-positive numbers
auto result1 = imeth::Logarithm::log10(0);    // nullopt
auto result2 = imeth::Logarithm::ln(-5);      // nullopt

// ✅ CORRECT - Ensure positive input
double value = -5;
if (value > 0) {
    auto result = imeth::Logarithm::ln(value);
}
```

---

## Performance Characteristics

### Time Complexity
All logarithm operations: **O(1)** - constant time

The functions use optimized math library implementations:
- `ln()`: Direct call to `std::log()`
- `log10()`: Direct call to `std::log10()`
- `log2()`: Direct call to `std::log2()`
- `log()`: Uses change of base formula: `ln(value) / ln(base)`
- `solve_exponential()`: Alias for `log()`
- `change_base()`: Uses formula: `log_old(value) / log_old(new_base)`

### Space Complexity
**O(1)** - constant space (only stores the result)

### Relative Performance
```
Fastest:    ln()         ≈ 1.0x (baseline)
Fast:       log10()      ≈ 1.1x
Fast:       log2()       ≈ 1.1x
Moderate:   log()        ≈ 1.5x (requires division)
Moderate:   change_base()≈ 2.0x (requires two logarithms)
```

**Performance tip**: If you need many logarithms with the same base, consider converting once:
```c++
// Slow: Computing log₃ many times
for (double val : values) {
    auto result = imeth::Logarithm::log(3, val);
    // Uses log(val) / log(3) each time
}

// Faster: Precompute the denominator
auto log_3 = imeth::Logarithm::ln(3);
if (log_3.has_value()) {
    double ln_3 = log_3.value();
    for (double val : values) {
        auto ln_val = imeth::Logarithm::ln(val);
        if (ln_val.has_value()) {
            double result = ln_val.value() / ln_3;
            // More efficient!
        }
    }
}
```

---

## Mathematical Background

### What is a Logarithm?

A logarithm answers the question: **"What exponent do I need?"**

Given: **base^? = value**
Answer: **? = log_base(value)**

**Visual understanding:**
```
Exponential:  2¹ = 2,   2² = 4,   2³ = 8,   2⁴ = 16
Logarithm:    log₂(2) = 1,  log₂(4) = 2,  log₂(8) = 3,  log₂(16) = 4
```

The logarithm is the **inverse operation** of exponentiation:
- Exponentiation: base^x = value
- Logarithm: x = log_base(value)

### Why Are Logarithms Useful?

1. **Turn multiplication into addition**
  - log(a × b) = log(a) + log(b)
  - Makes complex calculations simpler

2. **Turn division into subtraction**
  - log(a / b) = log(a) - log(b)

3. **Turn exponentiation into multiplication**
  - log(a^n) = n × log(a)

4. **Handle very large numbers**
  - log₁₀(1,000,000,000) = 9 (much easier to work with)

5. **Solve exponential equations**
  - If 2^x = 100, then x = log₂(100) ≈ 6.64

### The Three Important Bases

**Base e (Natural Logarithm - ln)**
- **e ≈ 2.71828...**
- Used in: calculus, continuous growth, physics
- Special property: derivative of e^x is e^x
- Most fundamental in mathematics

**Base 10 (Common Logarithm - log₁₀)**
- Matches our decimal number system
- Used in: chemistry (pH), physics (decibels), seismology (Richter scale)
- Easy to understand orders of magnitude

**Base 2 (Binary Logarithm - log₂)**
- Matches binary computer system
- Used in: computer science, information theory, algorithm analysis
- Answers: "How many bits?" or "How many times do I halve/double?"

---

## Relationship to Other Operations

### Logarithm ↔ Exponentiation
```c++
// These are inverses of each other
double x = 3.0;
double base = 2.0;

// Exponentiation: 2^3 = 8
double value = imeth::Arithmethic::power(base, x);  // 8.0

// Logarithm: log₂(8) = 3
auto result = imeth::Logarithm::log(base, value);  // 3.0
```

### Logarithm ↔ Root
```c++
// √x is the same as x^(1/2)
// Which means: log(√x) = log(x^(1/2)) = (1/2) × log(x)

double x = 16.0;

// Square root
double sqrt_x = std::sqrt(x);  // 4.0

// Using logarithm
auto log_x = imeth::Logarithm::log2(x);      // 4.0
if (log_x.has_value()) {
    double half_log = log_x.value() / 2.0;   // 2.0
    // 2^2 = 4, which is √16
}
```

---

## Integration with Other Modules

### With Exponential Operations
```c++
#include <imeth/operation/logarithm.hpp>
#include <cmath>

// Compound interest: A = P × e^(rt)
// To find time t when A is known: t = ln(A/P) / r

double principal = 1000.0;
double amount = 2000.0;
double rate = 0.05;

double ratio = amount / principal;
auto ln_ratio = imeth::Logarithm::ln(ratio);

if (ln_ratio.has_value()) {
    double time = ln_ratio.value() / rate;
    std::cout << "Time to double: " << time << " years\n";
}
```

### With Trigonometry (Advanced)
```c++
// Logarithms can solve exponential trigonometric equations
// Example: e^x = 1 + sin(x), solve numerically using logarithms
```

### With Statistics
```c++
// Log-normal distribution
// Log transformation for skewed data
auto log_data = imeth::Logarithm::ln(data_point);
```

---

## Frequently Asked Questions

**Q: Why does my calculator show "Math Error" for log(-5)?**
A: Logarithms are only defined for positive numbers. This library returns `std::nullopt` for invalid inputs instead of crashing.

**Q: What's the difference between ln, log, and log₁₀?**
A:
- `ln` = natural logarithm (base e ≈ 2.718)
- `log10` = common logarithm (base 10)
- `log` = general logarithm (any base you specify)

**Q: Why do I need logarithms if I have exponentiation?**
A: Logarithms solve the inverse problem. If you know 2^x = 100 and need to find x, you use logarithms: x = log₂(100).

**Q: Can I compute logarithm of zero?**
A: No, log(0) approaches negative infinity but is undefined. The function returns `std::nullopt`.

**Q: Why is log₁(anything) undefined?**
A: Because 1^x = 1 for all x. There's no unique answer to "1 to what power equals 5?"

**Q: How accurate are these functions?**
A: Accurate to double precision (~15-17 significant decimal digits).

**Q: Which is faster: ln(), log10(), or log()?**
A: `ln()` and `log10()` are slightly faster because they're direct library calls. `log()` requires an additional division.

**Q: Can I use this for complex numbers?**
A: No, this library only supports real numbers (double). Complex logarithms require a different implementation.

**Q: What's the relationship between log₂ and bits?**
A: log₂(n) tells you how many bits are needed to represent n different values (rounded up).

---
