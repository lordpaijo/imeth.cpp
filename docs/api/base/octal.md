# Octal

The `Octal` class provides functions for working with octal numbers (base 8). Octal is commonly used in computing, especially in Unix/Linux file permissions.

## Overview

Octal uses digits 0-7. It's a convenient way to represent binary numbers because each octal digit represents exactly 3 binary digits (bits). For example, octal `7` = binary `111`.

## Include

```c++
#include <imeth/base/octal.hpp>
```

## Conversion Functions

### FROM Decimal TO Octal

```c++
static std::string fromDecimal(int decimal);
```

**Examples:**
```c++
Octal::fromDecimal(8);       // "10"
Octal::fromDecimal(64);      // "100"
Octal::fromDecimal(42);      // "52"
Octal::fromDecimal(255);     // "377"
Octal::fromDecimal(0);       // "0"
Octal::fromDecimal(-10);     // "-12"
```

### FROM Octal TO Decimal

```c++
static int toDecimal(const std::string& octal);
```

**Examples:**
```c++
Octal::toDecimal("10");      // 8
Octal::toDecimal("100");     // 64
Octal::toDecimal("52");      // 42
Octal::toDecimal("377");     // 255
Octal::toDecimal("-12");     // -10
```

## Arithmetic Operations

```c++
static std::string add(const std::string& a, const std::string& b);
static std::string subtract(const std::string& a, const std::string& b);
static std::string multiply(const std::string& a, const std::string& b);
```

Perform basic math directly in octal.

**Examples:**
```c++
Octal::add("12", "5");           // "17" (10 + 5 = 15 in decimal)
Octal::subtract("20", "7");      // "11" (16 - 7 = 9 in decimal)
Octal::multiply("7", "7");       // "61" (7 × 7 = 49 in decimal)
Octal::add("77", "1");           // "100" (63 + 1 = 64 in decimal)
```

## Utility Functions

### Validation

```c++
static bool isValid(const std::string& octal);
```

Check if a string contains only valid octal digits (0-7).

**Examples:**
```c++
Octal::isValid("1234567");   // true
Octal::isValid("123");       // true
Octal::isValid("789");       // false (8 and 9 are not octal digits)
Octal::isValid("abc");       // false
```

### Padding

```c++
static std::string padLeft(const std::string& octal, size_t length);
```

Add zeros to the left to reach a specific length.

**Examples:**
```c++
Octal::padLeft("12", 4);     // "0012"
Octal::padLeft("777", 4);    // "0777"
Octal::padLeft("1234", 3);   // "1234" (already longer)
```

## Real-World Examples

### Unix/Linux File Permissions

File permissions in Unix/Linux are often shown in octal!

```c++
// rwxr-xr-x = 755 in octal
// rwx = 111 (binary) = 7 (octal) - owner can read, write, execute
// r-x = 101 (binary) = 5 (octal) - group can read and execute
// r-x = 101 (binary) = 5 (octal) - others can read and execute

std::string permissions = "755";
int decimal = Octal::toDecimal(permissions);  // 493
std::cout << "Decimal value: " << decimal << "\n";
```

### Binary to Octal Conversion

Since 3 binary digits = 1 octal digit, octal is a compact way to write binary:

```
Binary:  111 101 010
Octal:    7   5   2
```

```c++
// If you have binary "111101010"
// Group into 3s: 111 101 010
// Each group: 7, 5, 2
// Result: 752 in octal

int decimal = Binary::toDecimal("111101010");  // 490
std::string octal = Octal::fromDecimal(decimal);  // "752"
```

### Counting in Octal

```c++
// Octal counting: 0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, ..., 17, 20
for (int i = 0; i <= 20; ++i) {
    std::cout << i << " = " << Octal::fromDecimal(i) << " (octal)\n";
}
// Output:
// 0 = 0 (octal)
// 1 = 1 (octal)
// ...
// 7 = 7 (octal)
// 8 = 10 (octal)
// 9 = 11 (octal)
// ...
```

## Understanding Octal

- **Each digit** can be 0-7 (no 8 or 9!)
- **Right to left**: Each position is worth 8^n (1, 8, 64, 512, ...)

Example: `52` in octal = (5×8) + (2×1) = 40 + 2 = 42 in decimal

### Why Use Octal?

1. **Compact Binary**: 3 binary digits = 1 octal digit
2. **File Permissions**: Standard in Unix/Linux systems
3. **Historical**: Used in older computer systems
4. **Easier to Read**: Than long binary strings

## Octal Addition Example

```
  47
+ 35
----
 104
```

How it works:
- 7 + 5 = 12 (decimal) = 14 (octal), write 4, carry 1
- 4 + 3 + 1 (carry) = 8 (decimal) = 10 (octal), write 0, carry 1
- Result: 104 (octal)

```c++
Octal::add("47", "35");  // "104"
```

## Tips

- Remember: digits only go up to 7!
- When you see "10" in octal, it means 8 in decimal
- Octal is great for grouping binary numbers
- In C++, you can write octal literals with a leading 0: `int x = 052;` (equals 42 in decimal)
