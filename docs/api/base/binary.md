# Binary

The binary chapter provides specialized functions for working with binary numbers (base 2), including bitwise operations that are essential in computer science.

## Overview

Binary is the foundation of computer systems. Every number in a computer is stored as binary (0s and 1s). This class helps you understand and work with binary numbers directly.

## Include

```c++
#include <imeth/base/binary.hpp>
```

## Conversion Functions

### FROM Decimal TO Binary

```c++
static std::string fromDecimal(int decimal);
```

**Examples:**
```c++
Binary::fromDecimal(10);     // "1010"
Binary::fromDecimal(42);     // "101010"
Binary::fromDecimal(255);    // "11111111"
Binary::fromDecimal(0);      // "0"
Binary::fromDecimal(-5);     // "-101"
```

### FROM Binary TO Decimal

```c++
static int toDecimal(const std::string& binary);
```

**Examples:**
```c++
Binary::toDecimal("1010");      // 10
Binary::toDecimal("101010");    // 42
Binary::toDecimal("11111111");  // 255
Binary::toDecimal("-101");      // -5
```

## Arithmetic Operations

```c++
static std::string add(const std::string& a, const std::string& b);
static std::string subtract(const std::string& a, const std::string& b);
static std::string multiply(const std::string& a, const std::string& b);
```

Perform basic math directly in binary.

**Examples:**
```c++
Binary::add("1010", "101");         // "1111" (10 + 5 = 15)
Binary::subtract("1100", "101");    // "111" (12 - 5 = 7)
Binary::multiply("101", "11");      // "1111" (5 × 3 = 15)
```

## Bitwise Operations

These operations work at the bit level and are fundamental to computer programming.

### AND Operation
```c++
static std::string bitwiseAND(const std::string& a, const std::string& b);
```

Returns 1 only when both bits are 1.

**Examples:**
```c++
Binary::bitwiseAND("1100", "1010");  // "1000"
//  1100
// &1010
// -----
//  1000
```

### OR Operation
```c++
static std::string bitwiseOR(const std::string& a, const std::string& b);
```

Returns 1 when at least one bit is 1.

**Examples:**
```c++
Binary::bitwiseOR("1100", "1010");   // "1110"
//  1100
// |1010
// -----
//  1110
```

### XOR Operation
```c++
static std::string bitwiseXOR(const std::string& a, const std::string& b);
```

Returns 1 only when bits are different.

**Examples:**
```c++
Binary::bitwiseXOR("1100", "1010");  // "110"
//  1100
// ^1010
// -----
//  0110
```

### NOT Operation
```c++
static std::string bitwiseNOT(const std::string& binary);
```

Flips all bits (0→1, 1→0).

**Examples:**
```c++
Binary::bitwiseNOT("1010");  // "0101"
Binary::bitwiseNOT("1111");  // "0000"
```

### Bit Shifting

```c++
static std::string leftShift(const std::string& binary, int positions);
static std::string rightShift(const std::string& binary, int positions);
```

Shift bits left or right. Left shift multiplies by 2, right shift divides by 2.

**Examples:**
```c++
Binary::leftShift("101", 2);   // "10100" (5 << 2 = 20)
Binary::rightShift("1100", 2); // "11" (12 >> 2 = 3)
```

## Utility Functions

### Validation

```c++
static bool isValid(const std::string& binary);
```

Check if a string contains only valid binary digits (0 and 1).

**Examples:**
```c++
Binary::isValid("1010");   // true
Binary::isValid("1012");   // false (contains '2')
Binary::isValid("abc");    // false
```

### Padding

```c++
static std::string padLeft(const std::string& binary, size_t length);
```

Add zeros to the left to reach a specific length.

**Examples:**
```c++
Binary::padLeft("101", 8);     // "00000101"
Binary::padLeft("1111", 8);    // "00001111"
Binary::padLeft("10101010", 4);// "10101010" (already longer)
```

### Counting Bits

```c++
static int countOnes(const std::string& binary);
static int countZeros(const std::string& binary);
```

Count the number of 1s or 0s in a binary number.

**Examples:**
```c++
Binary::countOnes("1010");    // 2
Binary::countZeros("1010");   // 2
Binary::countOnes("1111");    // 4
Binary::countZeros("0000");   // 4
```

## Real-World Examples

### Converting Your Age to Binary
```c++
int age = 15;
std::string binaryAge = Binary::fromDecimal(age);  // "1111"
std::cout << "I'm " << binaryAge << " years old in binary!\n";
```

### Checking if a Number is Even
```c++
std::string num = Binary::fromDecimal(42);  // "101010"
// If last bit is 0, the number is even
bool isEven = (num.back() == '0');  // true
```

### Simple Encryption with XOR
```c++
std::string message = "1010";
std::string key = "1100";
std::string encrypted = Binary::bitwiseXOR(message, key);  // "0110"
std::string decrypted = Binary::bitwiseXOR(encrypted, key);// "1010" (back to original!)
```

### Creating Bit Masks
```c++
// Create a mask with 4 ones
std::string mask = Binary::fromDecimal(15);  // "1111"

// Use AND to extract bits
std::string data = "10110101";
std::string result = Binary::bitwiseAND(data, Binary::padLeft(mask, 8));
// Gets the last 4 bits: "0101"
```

## Understanding Binary

- **Each digit** is called a "bit"
- **8 bits** make a "byte"
- **Right to left**: Each position is worth 2^n (1, 2, 4, 8, 16, 32, ...)

Example: `1011` = (1×8) + (0×4) + (1×2) + (1×1) = 8 + 0 + 2 + 1 = 11

## Tips

- Use `padLeft()` to make binary numbers the same length before comparing
- Bitwise operations are much faster than regular math in computers
- Left shift by n is the same as multiplying by 2^n
- Right shift by n is the same as dividing by 2^n (rounded down)
