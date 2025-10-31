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
static std::string decimalToBinary(int decimal);
static std::string decimalToTrinary(int decimal);
static std::string decimalToOctal(int decimal);
static std::string decimalToHexadecimal(int decimal);
static std::string decimalToBase(int decimal, int base);
```

**Examples:**
```c++
Base::decimalToBinary(42);        // "101010"
Base::decimalToTrinary(42);       // "1120"
Base::decimalToOctal(42);         // "52"
Base::decimalToHexadecimal(42);   // "2A"
Base::decimalToBase(42, 5);       // "132" (base 5)
Base::decimalToBase(100, 12);     // "84" (base 12)
```

### FROM Other Bases TO Decimal

```c++
static int binaryToDecimal(const std::string& binary);
static int trinaryToDecimal(const std::string& trinary);
static int octalToDecimal(const std::string& octal);
static int hexadecimalToDecimal(const std::string& hex);
static int baseToDecimal(const std::string& number, int base);
```

**Examples:**
```c++
Base::binaryToDecimal("101010");      // 42
Base::trinaryToDecimal("1120");       // 42
Base::octalToDecimal("52");           // 42
Base::hexadecimalToDecimal("2A");     // 42
Base::baseToDecimal("132", 5);        // 42 (from base 5)
Base::baseToDecimal("84", 12);        // 100 (from base 12)
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
static std::string addInBase(const std::string& num1, const std::string& num2, int base);
static std::string subtractInBase(const std::string& num1, const std::string& num2, int base);
static std::string multiplyInBase(const std::string& num1, const std::string& num2, int base);
```

Perform arithmetic operations directly in any base.

**Examples:**
```c++
Base::addInBase("1010", "1100", 2);      // "10110" (binary addition)
Base::addInBase("12", "23", 5);          // "40" (base 5 addition)
Base::multiplyInBase("12", "3", 8);      // "36" (octal multiplication)
Base::subtractInBase("100", "11", 3);    // "12" (trinary subtraction)
```

## Utility Functions

### Validation

```c++
static bool isValidInBase(const std::string& number, int base);
```

Check if a string is a valid number in a given base.

**Examples:**
```c++
Base::isValidInBase("123", 3);     // false (3 is not valid in base 3)
Base::isValidInBase("123", 5);     // true
Base::isValidInBase("FF", 16);     // true
Base::isValidInBase("GG", 16);     // false (G is not valid in hex)
```

### Case Conversion

```c++
static std::string toUpperCase(const std::string& str);
```

Convert a base string to uppercase (useful for bases > 10).

**Examples:**
```c++
Base::toUpperCase("2a");    // "2A"
Base::toUpperCase("abc");   // "ABC"
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
std::string base7 = Base::decimalToBase(100, 7);   // "202"
int decimal = Base::baseToDecimal("202", 7);       // 100
```

### Base Arithmetic
```c++
// Do math without converting to decimal
std::string result = Base::addInBase("1234", "567", 8);  // "2023" (in octal)
```

## Notes

- For bases > 10, letters A-Z represent digits 10-35
- Letter case doesn't matter for input (both "2a" and "2A" work)
- Negative numbers are supported (prefix with '-')
- For specialized features (like bitwise operations in binary), use the dedicated classes: `Binary`, `Octal`, or `Hexadecimal`
