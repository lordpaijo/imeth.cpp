# Arithmetic

The arithmetic chapter is the first chapter from the `operation` category. It provides a comprehensive collection of arithmetic operations and mathematical utilities, ranging from basic operations to statistical functions, number theory, and practical calculations.

```c++
#include <imeth/operation/arithmetic.hpp>
```

## Features

### Basic Operations
- `add(double a, double b) → double` - Standard addition
- `subtract(double a, double b) → double` - Standard subtraction
- `multiply(double a, double b) → double` - Standard multiplication
- `divide(double a, double b) → double` - Standard division

### Power and Roots
- `power(double base, int exponent) → double` - Raises base to an integer exponent
- `squareRoot(double n) → double` - Computes √n
- `cubeRoot(double n) → double` - Computes ∛n

### Absolute Value and Sign
- `absolute(double n) → double` - Returns |n|
- `sign(double n) → int` - Returns -1 for negative, 0 for zero, 1 for positive

### Remainders and Divisibility
- `remainder(int a, int b) → int` - Integer remainder of a ÷ b
- `isDivisible(int a, int b) → bool` - Checks if a is divisible by b

### Percentages
- `percentOf(double percent, double total) → double` - Calculates percent% of total
- `whatPercent(double part, double total) → double` - Finds what percent part is of total
- `percentIncrease(double original, double newValue) → double` - Calculates percentage increase
- `percentDecrease(double original, double newValue) → double` - Calculates percentage decrease

### Averages and Statistics
- `average(const std::vector<double>& numbers) → double` - Mean of a vector of numbers
- `sum(const std::vector<double>& numbers) → double` - Total sum
- `minimum(const std::vector<double>& numbers) → double` - Minimum value
- `maximum(const std::vector<double>& numbers) → double` - Maximum value
- `range(const std::vector<double>& numbers) → double` - Difference between max and min
- `median(std::vector<double> numbers) → double` - Middle value (sorts the data)

### Fractions
- `addFractions(double num1, double den1, double num2, double den2) → double` - Adds two fractions
- `subtractFractions(double num1, double den1, double num2, double den2) → double` - Subtracts fractions
- `multiplyFractions(double num1, double den1, double num2, double den2) → double` - Multiplies fractions
- `divideFractions(double num1, double den1, double num2, double den2) → double` - Divides fractions

### Rounding
- `roundToNearest(double n) → double` - Rounds to nearest integer
- `roundUp(double n) → double` - Ceiling function
- `roundDown(double n) → double` - Floor function
- `roundToDecimalPlaces(double n, int places) → double` - Rounds to specified decimal places

### Number Properties
- `isEven(int n) → bool` - Checks if even
- `isOdd(int n) → bool` - Checks if odd
- `isPrime(int n) → bool` - Tests for primality
- `greatestCommonDivisor(int a, int b) → int` - GCD of two integers
- `leastCommonMultiple(int a, int b) → int` - LCM of two integers

### Geometry
- `distance2D(double x1, double y1, double x2, double y2) → double` - Euclidean distance between two points
- `pythagorean(double a, double b) → double` - Calculates hypotenuse using Pythagorean theorem

### Conversions
- `celsiusToFahrenheit(double celsius) → double` - Temperature conversion C → F
- `fahrenheitToCelsius(double fahrenheit) → double` - Temperature conversion F → C

### Finance
- `simpleInterest(double principal, double rate, double time) → double` - Calculates simple interest

## Example Usage

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    double a, b;
    char op;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter operation (e.g., 5 + 3): ";
    std::cin >> a >> op >> b;

    double result;
    switch(op) {
        case '+':
            result = imeth::Arithmetic::add(a, b);
            break;
        case '-':
            result = imeth::Arithmetic::subtract(a, b);
            break;
        case '*':
            result = imeth::Arithmetic::multiply(a, b);
            break;
        case '/':
            result = imeth::Arithmetic::divide(a, b);
            break;
        default:
            std::cout << "Invalid operator!\n";
            return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
```

## More Examples

```c++
// Statistical calculations
std::vector<double> grades = {85.5, 92.0, 78.5, 95.0, 88.0};
double avg = imeth::Arithmetic::average(grades);      // 87.8
double med = imeth::Arithmetic::median(grades);        // 88.0
double minGrade = imeth::Arithmetic::minimum(grades);  // 78.5

// Number theory
int gcd = imeth::Arithmetic::greatestCommonDivisor(48, 18);  // 6
bool prime = imeth::Arithmetic::isPrime(17);                  // true

// Percentage calculations
double discount = imeth::Arithmetic::percentOf(20, 100.0);    // 20.0
double increase = imeth::Arithmetic::percentIncrease(50, 75); // 50.0

// Geometry
double dist = imeth::Arithmetic::distance2D(0, 0, 3, 4);      // 5.0
double hyp = imeth::Arithmetic::pythagorean(3, 4);            // 5.0

// Temperature conversion
double fahrenheit = imeth::Arithmetic::celsiusToFahrenheit(25); // 77.0
```
