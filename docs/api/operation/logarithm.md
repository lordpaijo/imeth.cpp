# Logarithm

Logarithm is the second chapter that can be found from the `operation` category. It provides methods and functions to operate logarithmic operations, including common logarithms, natural logarithms, exponential equation solving, and base conversions.

```cpp
#include <imeth/operation/logarithm.hpp>
```

## Features

### Logarithm Functions
- `log(double base, double value) → std::optional<double>` - Computes log_base(value) with arbitrary base
- `ln(double value) → std::optional<double>` - Natural logarithm (base e)
- `log10(double value) → std::optional<double>` - Common logarithm (base 10)
- `log2(double value) → std::optional<double>` - Binary logarithm (base 2)

### Exponential Equations
- `solve_exponential(double base, double value) → std::optional<double>` - Solves base^x = value for x

### Base Conversion
- `change_base(double value, double old_base, double new_base) → std::optional<double>` - Converts logarithm from one base to another using the change of base formula

## Return Values

All methods return `std::optional<double>`:
- Contains a value if the operation is valid
- Returns `std::nullopt` if:
  - `value ≤ 0` (logarithm undefined for non-positive numbers)
  - `base ≤ 0` (invalid base)
  - `base = 1` (division by zero in change of base formula)

## Example Usage

```cpp
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

## More Examples

```cpp
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

## Mathematical Properties

The logarithm functions implement standard mathematical properties:
- **Product rule**: log(xy) = log(x) + log(y)
- **Quotient rule**: log(x/y) = log(x) - log(y)
- **Power rule**: log(x^n) = n·log(x)
- **Change of base**: log_b(x) = log_a(x) / log_a(b)
