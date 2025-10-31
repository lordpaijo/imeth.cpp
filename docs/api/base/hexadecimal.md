# Hexadecimal

The `Hexadecimal` class provides functions for working with hexadecimal numbers (base 16). Hex is widely used in computing for colors, memory addresses, and more.

## Overview

Hexadecimal (hex) uses 16 digits: 0-9 and A-F (where A=10, B=11, C=12, D=13, E=14, F=15). It's popular because each hex digit represents exactly 4 binary digits (bits).

## Include

```c++
#include <imeth/base/hexadecimal.hpp>
```

## Conversion Functions

### FROM Decimal TO Hexadecimal

```c++
static std::string fromDecimal(int decimal);
```

**Examples:**
```c++
Hexadecimal::fromDecimal(10);      // "A"
Hexadecimal::fromDecimal(15);      // "F"
Hexadecimal::fromDecimal(16);      // "10"
Hexadecimal::fromDecimal(255);     // "FF"
Hexadecimal::fromDecimal(42);      // "2A"
Hexadecimal::fromDecimal(4096);    // "1000"
Hexadecimal::fromDecimal(-10);     // "-A"
```

### FROM Hexadecimal TO Decimal

```c++
static int toDecimal(const std::string& hex);
```

**Examples:**
```c++
Hexadecimal::toDecimal("A");       // 10
Hexadecimal::toDecimal("F");       // 15
Hexadecimal::toDecimal("10");      // 16
Hexadecimal::toDecimal("FF");      // 255
Hexadecimal::toDecimal("2A");      // 42
Hexadecimal::toDecimal("1000");    // 4096
Hexadecimal::toDecimal("ff");      // 255 (case insensitive)
```

## Arithmetic Operations

```c++
static std::string add(const std::string& a, const std::string& b);
static std::string subtract(const std::string& a, const std::string& b);
static std::string multiply(const std::string& a, const std::string& b);
```

Perform basic math directly in hexadecimal.

**Examples:**
```c++
Hexadecimal::add("A", "5");          // "F" (10 + 5 = 15)
Hexadecimal::add("FF", "1");         // "100" (255 + 1 = 256)
Hexadecimal::subtract("20", "A");    // "16" (32 - 10 = 22)
Hexadecimal::multiply("10", "10");   // "100" (16 × 16 = 256)
```

## Utility Functions

### Validation

```c++
static bool isValid(const std::string& hex);
```

Check if a string contains only valid hexadecimal digits (0-9, A-F).

**Examples:**
```c++
Hexadecimal::isValid("1234");      // true
Hexadecimal::isValid("ABCDEF");    // true
Hexadecimal::isValid("FF00");      // true
Hexadecimal::isValid("GHI");       // false (G, H, I are not hex digits)
Hexadecimal::isValid("ff");        // true (case insensitive)
```

### Case Conversion

```c++
static std::string toUpperCase(const std::string& hex);
static std::string toLowerCase(const std::string& hex);
```

Convert hex strings between upper and lowercase.

**Examples:**
```c++
Hexadecimal::toUpperCase("2a");    // "2A"
Hexadecimal::toUpperCase("ff");    // "FF"
Hexadecimal::toLowerCase("2A");    // "2a"
Hexadecimal::toLowerCase("FF");    // "ff"
```

### Padding

```c++
static std::string padLeft(const std::string& hex, size_t length);
```

Add zeros to the left to reach a specific length.

**Examples:**
```c++
Hexadecimal::padLeft("FF", 4);     // "00FF"
Hexadecimal::padLeft("A", 2);      // "0A"
Hexadecimal::padLeft("1234", 3);   // "1234" (already longer)
```

## Real-World Examples

### RGB Colors

Colors on screens are often represented in hex!

```c++
// RGB color: Red=255, Green=128, Blue=64
std::string red = Hexadecimal::fromDecimal(255);    // "FF"
std::string green = Hexadecimal::fromDecimal(128);  // "80"
std::string blue = Hexadecimal::fromDecimal(64);    // "40"

std::string color = red + green + blue;  // "FF8040"
std::cout << "Color code: #" << color << "\n";  // #FF8040
```

### Converting Hex Color Codes

```c++
// Parse color #A1B2C3
std::string hexColor = "A1B2C3";

int red = Hexadecimal::toDecimal(hexColor.substr(0, 2));    // 161
int green = Hexadecimal::toDecimal(hexColor.substr(2, 2));  // 178
int blue = Hexadecimal::toDecimal(hexColor.substr(4, 2));   // 195

std::cout << "RGB(" << red << ", " << green << ", " << blue << ")\n";
```

### Memory Addresses

Computer memory addresses are shown in hex:

```c++
// A typical memory address
std::string address = "7FFF5C";
int decimal = Hexadecimal::toDecimal(address);  // 8388444
std::cout << "Memory location: 0x" << address << "\n";
```

### Binary to Hex Conversion

Since 4 binary digits = 1 hex digit, hex is a compact way to write binary:

```
Binary:  1111 1010 0101
Hex:       F    A    5
```

```c++
// If you have binary "111110100101"
// Group into 4s: 1111 1010 0101
// Each group: F, A, 5
// Result: FA5 in hex

int decimal = Binary::toDecimal("111110100101");  // 4005
std::string hex = Hexadecimal::fromDecimal(decimal);  // "FA5"
```

### Common Hex Values

```c++
// Powers of 16
Hexadecimal::fromDecimal(16);      // "10"
Hexadecimal::fromDecimal(256);     // "100"
Hexadecimal::fromDecimal(4096);    // "1000"

// Max values
Hexadecimal::fromDecimal(255);     // "FF" (max 8-bit value)
Hexadecimal::fromDecimal(65535);   // "FFFF" (max 16-bit value)
```

## Understanding Hexadecimal

- **16 digits**: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
- **A through F**: A=10, B=11, C=12, D=13, E=14, F=15
- **Right to left**: Each position is worth 16^n (1, 16, 256, 4096, ...)

Example: `2A` in hex = (2×16) + (10×1) = 32 + 10 = 42 in decimal

### Why Use Hexadecimal?

1. **Compact Binary**: 4 binary digits = 1 hex digit
2. **Colors**: Web colors use hex (#FF0000 = red)
3. **Memory**: Addresses and data dumps
4. **File Formats**: Image files, network packets
5. **Easier to Read**: Than long binary strings

## Hex Counting

```
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, 10, 11, 12, ..., 1F, 20, ...
```

```c++
// Count from 0 to 20 in hex
for (int i = 0; i <= 20; ++i) {
    std::cout << i << " = " << Hexadecimal::fromDecimal(i) << " (hex)\n";
}
// Output includes:
// 10 = A (hex)
// 15 = F (hex)
// 16 = 10 (hex)
// 20 = 14 (hex)
```

## Hex Addition Example

```
  2A
+ 1F
----
  49
```

How it works:
- A + F = 10 + 15 = 25 (decimal) = 19 (hex), write 9, carry 1
- 2 + 1 + 1 (carry) = 4
- Result: 49 (hex) = 73 (decimal)

```c++
Hexadecimal::add("2A", "1F");  // "49"
```

## Tips

- Both uppercase and lowercase work: "FF" and "ff" are the same
- Use `padLeft()` to format numbers: `padLeft("A", 2)` gives "0A"
- Hex is everywhere in web development (colors!)
- In C++, you can write hex literals with 0x: `int x = 0x2A;` (equals 42)
- Two hex digits = one byte (8 bits)

## Common Hex Patterns

```c++
// All F's are special
Hexadecimal::toDecimal("F");       // 15 (max 4 bits)
Hexadecimal::toDecimal("FF");      // 255 (max 8 bits / 1 byte)
Hexadecimal::toDecimal("FFF");     // 4095 (max 12 bits)
Hexadecimal::toDecimal("FFFF");    // 65535 (max 16 bits / 2 bytes)
```
