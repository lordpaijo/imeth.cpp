# Base

The base chapter can be found in the `base` category. It provides functions for converting numbers between different bases (2-36).

## Overview

The `Base` class is a general-purpose base converter that works with any base from 2 (binary) to 36 (using digits 0-9 and letters A-Z). This is useful when you need to work with unusual bases or want a single interface for all conversions.

## Include

```c++
#include <imeth/base/base.hpp>
```

## Conversion Functions

### FROM Decimal TO Other Bases

```c++
static std::string decimal_to_binary(int decimal);
static std::string decimal_to_trinary(int decimal);
static std::string decimal_to_octal(int decimal);
static std::string decimal_to_hexadecimal(int decimal);
static std::string decimal_to_base(int decimal, int base);
```

**Examples:**
```c++
Base::decimal_to_binary(42);        // "101010"
Base::decimal_to_trinary(42);       // "1120"
Base::decimal_to_octal(42);         // "52"
Base::decimal_to_hexadecimal(42);   // "2A"
Base::decimal_to_base(42, 5);       // "132" (base 5)
Base::decimal_to_base(100, 12);     // "84" (base 12)
```

### FROM Other Bases TO Decimal

```c++
static int binary_to_decimal(const std::string& binary);
static int trinary_to_decimal(const std::string& trinary);
static int octal-to_decimal(const std::string& octal);
static int hexadecimal_to_decimal(const std::string& hex);
static int base_to_decimal(const std::string& number, int base);
```

**Examples:**
```c++
Base::binary_to_decimal("101010");      // 42
Base::trinary_to_decimal("1120");       // 42
Base::octal-to_decimal("52");           // 42
Base::hexadecimal_to_decimal("2A");     // 42
Base::base_to_decimal("132", 5);        // 42 (from base 5)
Base::base_to_decimal("84", 12);        // 100 (from base 12)
```

## Direct Base-to-Base Conversion

```c++
static std::string convert(const std::string& number, int fromBase, int toBase);
```

Convert directly between any two bases without manually going through decimal.

**Examples:**
```c++
Base::convert("101010", 2, 16);   // "2A" (binary to hex)
Base::convert("FF", 16, 2);       // "11111111" (hex to binary)
Base::convert("52", 8, 3);        // "1120" (octal to trinary)
Base::convert("123", 5, 12);      // "32" (base 5 to base 12)
```

## Arithmetic in Different Bases

```c++
static std::string add_in_base(const std::string& num1, const std::string& num2, int base);
static std::string substract_in_base(const std::string& num1, const std::string& num2, int base);
static std::string multiply_in_base(const std::string& num1, const std::string& num2, int base);
```

Perform arithmetic operations directly in any base.

**Examples:**
```c++
Base::add_in_base("1010", "1100", 2);      // "10110" (binary addition)
Base::add_in_base("12", "23", 5);          // "40" (base 5 addition)
Base::multiply_in_base("12", "3", 8);      // "36" (octal multiplication)
Base::substract_in_base("100", "11", 3);    // "12" (trinary subtraction)
```

## Utility Functions

### Validation

```c++
static bool is_valid_in_base(const std::string& number, int base);
```

Check if a string is a valid number in a given base.

**Examples:**
```c++
Base::is_valid_in_base("123", 3);     // false (3 is not valid in base 3)
Base::is_valid_in_base("123", 5);     // true
Base::is_valid_in_base("FF", 16);     // true
Base::is_valid_in_base("GG", 16);     // false (G is not valid in hex)
```

### Case Conversion

```c++
static std::string to_upper_case(const std::string& str);
```

Convert a base string to uppercase (useful for bases > 10).

**Examples:**
```c++
Base::to_upper_case("2a");    // "2A"
Base::to_upper_case("abc");   // "ABC"
```

## Supported Bases

- **Base 2 (Binary)**: Digits 0-1
- **Base 3 (Trinary)**: Digits 0-2
- **Base 8 (Octal)**: Digits 0-7
- **Base 10 (Decimal)**: Digits 0-9
- **Base 16 (Hexadecimal)**: Digits 0-9, A-F
- **Base 12 (Duodecimal)**: Digits 0-9, A-B
- **Base 36 (Maximum)**: Digits 0-9, A-Z

## Common Use Cases

### Computer Science
```c++
// Converting between common computer bases
std::string hex = Base::convert("11111111", 2, 16);  // "FF"
std::string octal = Base::convert("FF", 16, 8);       // "377"
```

### Custom Bases
```c++
// Working with unusual bases
std::string base7 = Base::decimal_to_base(100, 7);   // "202"
int decimal = Base::base_to_decimal("202", 7);       // 100
```

### Base Arithmetic
```c++
// Do math without converting to decimal
std::string result = Base::add_in_base("1234", "567", 8);  // "2023" (in octal)
```

## Notes

- For bases > 10, letters A-Z represent digits 10-35
- Letter case doesn't matter for input (both "2a" and "2A" work)
- Negative numbers are supported (prefix with '-')
- For specialized features (like bitwise operations in binary), use the dedicated classes: `Binary`, `Octal`, or `Hexadecimal`
