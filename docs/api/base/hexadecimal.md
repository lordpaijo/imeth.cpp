# Hexadecimal

The hexadecimal chapter provides functions for working with hexadecimal numbers (base 16). Hex is widely used in computing for colors, memory addresses, and more.

## Overview

Hexadecimal (hex) uses 16 digits: 0-9 and A-F (where A=10, B=11, C=12, D=13, E=14, F=15). It's popular because each hex digit represents exactly 4 binary digits (bits).

## Include

```c++
#include <imeth/base/hexadecimal.hpp>
```

## Conversion Functions

### FROM Decimal TO Hexadecimal

```c++
static std::string from_decimal(int decimal);
```

**Examples:**
```c++
Hexadecimal::from_decimal(10);      // "A"
Hexadecimal::from_decimal(15);      // "F"
Hexadecimal::from_decimal(16);      // "10"
Hexadecimal::from_decimal(255);     // "FF"
Hexadecimal::from_decimal(42);      // "2A"
Hexadecimal::from_decimal(4096);    // "1000"
Hexadecimal::from_decimal(-10);     // "-A"
```

### FROM Hexadecimal TO Decimal

```c++
static int to_decimal(const std::string& hex);
```

**Examples:**
```c++
Hexadecimal::to_decimal("A");       // 10
Hexadecimal::to_decimal("F");       // 15
Hexadecimal::to_decimal("10");      // 16
Hexadecimal::to_decimal("FF");      // 255
Hexadecimal::to_decimal("2A");      // 42
Hexadecimal::to_decimal("1000");    // 4096
Hexadecimal::to_decimal("ff");      // 255 (case insensitive)
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
static bool is_valid(const std::string& hex);
```

Check if a string contains only valid hexadecimal digits (0-9, A-F).

**Examples:**
```c++
Hexadecimal::is_valid("1234");      // true
Hexadecimal::is_valid("ABCDEF");    // true
Hexadecimal::is_valid("FF00");      // true
Hexadecimal::is_valid("GHI");       // false (G, H, I are not hex digits)
Hexadecimal::is_valid("ff");        // true (case insensitive)
```

### Case Conversion

```c++
static std::string to_upper_case(const std::string& hex);
static std::string to_lower_case(const std::string& hex);
```

Convert hex strings between upper and lowercase.

**Examples:**
```c++
Hexadecimal::to_upper_case("2a");    // "2A"
Hexadecimal::to_upper_case("ff");    // "FF"
Hexadecimal::to_lower_case("2A");    // "2a"
Hexadecimal::to_lower_case("FF");    // "ff"
```

### Padding

```c++
static std::string pad_left(const std::string& hex, size_t length);
```

Add zeros to the left to reach a specific length.

**Examples:**
```c++
Hexadecimal::pad_left("FF", 4);     // "00FF"
Hexadecimal::pad_left("A", 2);      // "0A"
Hexadecimal::pad_left("1234", 3);   // "1234" (already longer)
```

## Real-World Examples

### RGB Colors

Colors on screens are often represented in hex!

```c++
// RGB color: Red=255, Green=128, Blue=64
std::string red = Hexadecimal::from_decimal(255);    // "FF"
std::string green = Hexadecimal::from_decimal(128);  // "80"
std::string blue = Hexadecimal::from_decimal(64);    // "40"

std::string color = red + green + blue;  // "FF8040"
std::cout << "Color code: #" << color << "\n";  // #FF8040
```

### Converting Hex Color Codes

```c++
// Parse color #A1B2C3
std::string hexColor = "A1B2C3";

int red = Hexadecimal::to_decimal(hexColor.substr(0, 2));    // 161
int green = Hexadecimal::to_decimal(hexColor.substr(2, 2));  // 178
int blue = Hexadecimal::to_decimal(hexColor.substr(4, 2));   // 195

std::cout << "RGB(" << red << ", " << green << ", " << blue << ")\n";
```

### Memory Addresses

Computer memory addresses are shown in hex:

```c++
// A typical memory address
std::string address = "7FFF5C";
int decimal = Hexadecimal::to_decimal(address);  // 8388444
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

int decimal = Binary::to_decimal("111110100101");  // 4005
std::string hex = Hexadecimal::from_decimal(decimal);  // "FA5"
```

### Common Hex Values

```c++
// Powers of 16
Hexadecimal::from_decimal(16);      // "10"
Hexadecimal::from_decimal(256);     // "100"
Hexadecimal::from_decimal(4096);    // "1000"

// Max values
Hexadecimal::from_decimal(255);     // "FF" (max 8-bit value)
Hexadecimal::from_decimal(65535);   // "FFFF" (max 16-bit value)
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
    std::cout << i << " = " << Hexadecimal::from_decimal(i) << " (hex)\n";
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
Hexadecimal::to_decimal("F");       // 15 (max 4 bits)
Hexadecimal::to_decimal("FF");      // 255 (max 8 bits / 1 byte)
Hexadecimal::to_decimal("FFF");     // 4095 (max 12 bits)
Hexadecimal::to_decimal("FFFF");    // 65535 (max 16 bits / 2 bytes)
```
