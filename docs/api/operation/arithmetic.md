# Arithmetic

The arithmetic chapter is the first chapter from the `operation` category. It provides a comprehensive collection of arithmetic operations and mathematical utilities, ranging from basic operations to statistical functions, number theory, and practical calculations.

```c++
#include <imeth/operation/arithmetic.hpp>
```

## Overview

Arithmetic is the foundation of mathematics. This module helps you answer questions like:
- "What's the average of these test scores?"
- "Is this number prime?"
- "How much is 15% of $200?"
- "What's the distance between two points?"

---

## Basic Operations

### Addition

```c++
double add(double a, double b);
```

Standard addition of two numbers.

**Examples:**
```c++
add(5.0, 3.0);      // 8.0
add(-10.5, 7.2);    // -3.3
add(100, 250);      // 350.0
```

**Real-world:** Calculating totals, summing prices, combining quantities.

---

### Subtraction

```c++
double subtract(double a, double b);
```

Standard subtraction - computes a - b.

**Examples:**
```c++
subtract(10.0, 3.0);    // 7.0
subtract(5.5, 8.2);     // -2.7
subtract(100, 45);      // 55.0
```

**Real-world:** Finding differences, calculating change, determining deficits.

---

### Multiplication

```c++
double multiply(double a, double b);
```

Standard multiplication of two numbers.

**Examples:**
```c++
multiply(5.0, 3.0);     // 15.0
multiply(-4.0, 2.5);    // -10.0
multiply(12, 0.5);      // 6.0
```

**Real-world:** Scaling quantities, calculating areas, price × quantity.

---

### Division

```c++
double divide(double a, double b);
```

Standard division - computes a ÷ b.

**Examples:**
```c++
divide(10.0, 2.0);      // 5.0
divide(7.0, 2.0);       // 3.5
divide(100, 3);         // 33.333...
```

**Real-world:** Splitting bills, calculating rates, finding averages.

**Note:** Division by zero will cause an error.

---

## Power and Roots

### Power

```c++
double power(double base, int exponent);
```

Raises base to an integer exponent.

**Examples:**
```c++
power(2, 3);        // 8.0 (2³)
power(5, 2);        // 25.0 (5²)
power(10, 0);       // 1.0 (anything⁰ = 1)
power(2, -2);       // 0.25 (2⁻² = 1/4)
```

**Real-world:** Compound interest, exponential growth, area/volume calculations.

---

### Square Root

```c++
double square_root(double n);
```

Computes the square root (√n).

**Examples:**
```c++
square_root(9);      // 3.0
square_root(25);     // 5.0
square_root(2);      // 1.414...
square_root(100);    // 10.0
```

**Real-world:** Pythagorean theorem, standard deviation, geometric calculations.

---

### Cube Root

```c++
double cube_root(double n);
```

Computes the cube root (∛n).

**Examples:**
```c++
cube_root(8);        // 2.0
cube_root(27);       // 3.0
cube_root(-8);       // -2.0 (cube root of negative is negative)
cube_root(1000);     // 10.0
```

**Real-world:** Volume calculations, finding side length from volume.

---

## Absolute Value and Sign

### Absolute Value

```c++
double absolute(double n);
```

Returns the absolute value |n| (always positive or zero).

**Examples:**
```c++
absolute(5.0);      // 5.0
absolute(-5.0);     // 5.0
absolute(0);        // 0.0
absolute(-3.14);    // 3.14
```

**Real-world:** Distance calculations, magnitude, error measurements.

---

### Sign

```c++
int sign(double n);
```

Returns the sign of a number:
- Returns -1 for negative numbers
- Returns 0 for zero
- Returns 1 for positive numbers

**Examples:**
```c++
sign(42.5);     // 1
sign(-17.3);    // -1
sign(0.0);      // 0
sign(-0.001);   // -1
```

**Real-world:** Direction indicators, profit/loss status, trend analysis.

---

## Remainders and Divisibility

### Remainder

```c++
int remainder(int a, int b);
```

Integer remainder of a ÷ b (modulo operation).

**Examples:**
```c++
remainder(10, 3);   // 1 (10 = 3×3 + 1)
remainder(17, 5);   // 2 (17 = 5×3 + 2)
remainder(20, 4);   // 0 (evenly divisible)
remainder(7, 10);   // 7 (dividend smaller than divisor)
```

**Real-world:** Clock arithmetic, cyclic patterns, checking divisibility.

---

### Is Divisible

```c++
bool is_divisible(int a, int b);
```

Checks if a is evenly divisible by b (remainder is 0).

**Examples:**
```c++
is_divisible(10, 2);     // true
is_divisible(15, 3);     // true
is_divisible(17, 5);     // false
is_divisible(100, 25);   // true
```

**Real-world:** Checking if items can be evenly distributed, validating constraints.

---

## Percentages

### Percent Of

```c++
double percent_of(double percent, double total);
```

Calculates what percent% of total equals.

**Formula:** result = (percent / 100) × total

**Examples:**
```c++
percent_of(20, 100);     // 20.0 (20% of 100)
percent_of(15, 200);     // 30.0 (15% of 200)
percent_of(50, 80);      // 40.0 (50% of 80)
percent_of(8.5, 150);    // 12.75 (8.5% of 150)
```

**Real-world:** Calculating tips, discounts, tax amounts, commissions.

---

### What Percent

```c++
double what_percent(double part, double total);
```

Finds what percent the part is of the total.

**Formula:** result = (part / total) × 100

**Examples:**
```c++
what_percent(25, 100);   // 25.0 (25 is 25% of 100)
what_percent(30, 150);   // 20.0 (30 is 20% of 150)
what_percent(45, 90);    // 50.0 (45 is 50% of 90)
what_percent(7, 35);     // 20.0 (7 is 20% of 35)
```

**Real-world:** Grade percentages, completion rates, market share analysis.

---

### Percent Increase

```c++
double percent_increase(double original, double newValue);
```

Calculates the percentage increase from original to newValue.

**Formula:** ((newValue - original) / original) × 100

**Examples:**
```c++
percent_increase(50, 75);    // 50.0 (increased by 50%)
percent_increase(100, 150);  // 50.0 (increased by 50%)
percent_increase(80, 100);   // 25.0 (increased by 25%)
percent_increase(200, 250);  // 25.0 (increased by 25%)
```

**Real-world:** Price increases, population growth, salary raises, profit margins.

---

### Percent Decrease

```c++
double percent_decrease(double original, double newValue);
```

Calculates the percentage decrease from original to newValue.

**Formula:** ((original - newValue) / original) × 100

**Examples:**
```c++
percent_decrease(100, 75);   // 25.0 (decreased by 25%)
percent_decrease(200, 150);  // 25.0 (decreased by 25%)
percent_decrease(80, 60);    // 25.0 (decreased by 25%)
percent_decrease(50, 25);    // 50.0 (decreased by 50%)
```

**Real-world:** Discounts, price reductions, depreciation, weight loss tracking.

---

## Averages and Statistics

### Average (Mean)

```c++
double average(const std::vector<double>& numbers);
```

Calculates the arithmetic mean (average) of a set of numbers.

**Formula:** sum of all numbers ÷ count of numbers

**Examples:**
```c++
std::vector<double> grades = {85, 90, 78, 92, 88};
average(grades);    // 86.6

std::vector<double> temps = {72.5, 68.0, 75.2, 71.8};
average(temps);     // 71.875
```

**Real-world:** Grade point average, average temperature, mean income.

---

### Sum

```c++
double sum(const std::vector<double>& numbers);
```

Calculates the total sum of all numbers in the vector.

**Examples:**
```c++
std::vector<double> prices = {10.5, 25.0, 8.75, 15.25};
sum(prices);    // 59.5

std::vector<double> scores = {100, 85, 90, 95};
sum(scores);    // 370.0
```

**Real-world:** Total sales, combined scores, aggregate values.

---

### Minimum

```c++
double minimum(const std::vector<double>& numbers);
```

Finds the smallest value in the vector.

**Examples:**
```c++
std::vector<double> temps = {72.5, 68.0, 75.2, 71.8};
minimum(temps);     // 68.0

std::vector<double> prices = {19.99, 15.50, 22.00, 12.99};
minimum(prices);    // 12.99
```

**Real-world:** Lowest price, minimum temperature, worst score.

---

### Maximum

```c++
double maximum(const std::vector<double>& numbers);
```

Finds the largest value in the vector.

**Examples:**
```c++
std::vector<double> temps = {72.5, 68.0, 75.2, 71.8};
maximum(temps);     // 75.2

std::vector<double> scores = {85, 92, 78, 95, 88};
maximum(scores);    // 95.0
```

**Real-world:** Highest score, peak temperature, maximum capacity.

---

### Range

```c++
double range(const std::vector<double>& numbers);
```

Calculates the difference between the maximum and minimum values.

**Formula:** max - min

**Examples:**
```c++
std::vector<double> temps = {68.0, 72.5, 75.2, 71.8};
range(temps);       // 7.2 (75.2 - 68.0)

std::vector<double> ages = {25, 35, 42, 28, 31};
range(ages);        // 17.0 (42 - 25)
```

**Real-world:** Temperature variation, price spread, age distribution.

---

### Median

```c++
double median(std::vector<double> numbers);
```

Finds the middle value when numbers are sorted. If there's an even count, returns the average of the two middle values.

**Note:** This function sorts the input vector.

**Examples:**
```c++
std::vector<double> odd = {3, 1, 4, 1, 5};
median(odd);        // 3.0 (middle of 1,1,3,4,5)

std::vector<double> even = {10, 20, 30, 40};
median(even);       // 25.0 (average of 20 and 30)
```

**Real-world:** Median income (resistant to outliers), middle test score.

---

## Fractions

### Add Fractions

```c++
double add_fractions(double num1, double den1, double num2, double den2);
```

Adds two fractions: (num1/den1) + (num2/den2).

**Examples:**
```c++
add_fractions(1, 2, 1, 3);       // 0.8333... (1/2 + 1/3 = 5/6)
add_fractions(2, 5, 3, 10);      // 0.7 (2/5 + 3/10 = 7/10)
add_fractions(1, 4, 1, 4);       // 0.5 (1/4 + 1/4 = 1/2)
```

**Real-world:** Recipe measurements, combining partial amounts.

---

### Subtract Fractions

```c++
double substract_fractions(double num1, double den1, double num2, double den2);
```

Subtracts two fractions: (num1/den1) - (num2/den2).

**Examples:**
```c++
substract_fractions(3, 4, 1, 2);  // 0.25 (3/4 - 1/2 = 1/4)
substract_fractions(5, 6, 1, 3);  // 0.5 (5/6 - 1/3 = 1/2)
```

**Real-world:** Measuring remaining quantities, calculating differences.

---

### Multiply Fractions

```c++
double multiply_fractions(double num1, double den1, double num2, double den2);
```

Multiplies two fractions: (num1/den1) × (num2/den2).

**Examples:**
```c++
multiply_fractions(2, 3, 3, 4);  // 0.5 (2/3 × 3/4 = 1/2)
multiply_fractions(1, 2, 1, 2);  // 0.25 (1/2 × 1/2 = 1/4)
```

**Real-world:** Scaling recipes, calculating portions.

---

### Divide Fractions

```c++
double divide_fractions(double num1, double den1, double num2, double den2);
```

Divides two fractions: (num1/den1) ÷ (num2/den2).

**Examples:**
```c++
divide_fractions(1, 2, 1, 4);    // 2.0 (1/2 ÷ 1/4 = 2)
divide_fractions(3, 4, 3, 8);    // 2.0 (3/4 ÷ 3/8 = 2)
```

**Real-world:** Dividing quantities, portion distribution.

---

## Rounding

### Round to Nearest

```c++
double round_to_nearest(double n);
```

Rounds to the nearest integer. Values at .5 round up.

**Examples:**
```c++
round_to_nearest(3.2);    // 3.0
round_to_nearest(3.7);    // 4.0
round_to_nearest(3.5);    // 4.0
round_to_nearest(-2.5);   // -2.0 or -3.0 (implementation dependent)
```

**Real-world:** Rounding prices, counting items, simplifying measurements.

---

### Round Up (Ceiling)

```c++
double round_up(double n);
```

Rounds up to the next integer (ceiling function).

**Examples:**
```c++
round_up(3.1);       // 4.0
round_up(3.9);       // 4.0
round_up(3.0);       // 3.0
round_up(-2.1);      // -2.0
```

**Real-world:** Calculating packages needed, minimum capacity, buffer allocation.

---

### Round Down (Floor)

```c++
double round_down(double n);
```

Rounds down to the previous integer (floor function).

**Examples:**
```c++
round_down(3.1);     // 3.0
round_down(3.9);     // 3.0
round_down(3.0);     // 3.0
round_down(-2.1);    // -3.0
```

**Real-world:** Complete sets, whole units available, truncating values.

---

### Round to Decimal Places

```c++
double round_to_decimal_places(double n, int places);
```

Rounds to a specified number of decimal places.

**Examples:**
```c++
round_to_decimal_places(3.14159, 2);   // 3.14
round_to_decimal_places(2.5678, 1);    // 2.6
round_to_decimal_places(100.567, 0);   // 101.0
round_to_decimal_places(1.2345, 3);    // 1.235
```

**Real-world:** Currency (2 decimal places), precision measurements, display formatting.

---

## Number Properties

### Is Even

```c++
bool is_even(int n);
```

Checks if a number is even (divisible by 2).

**Examples:**
```c++
is_even(4);      // true
is_even(7);      // false
is_even(0);      // true
is_even(-6);     // true
```

**Real-world:** Pairing items, determining patterns, scheduling rotations.

---

### Is Odd

```c++
bool is_odd(int n);
```

Checks if a number is odd (not divisible by 2).

**Examples:**
```c++
is_odd(5);       // true
is_odd(8);       // false
is_odd(1);       // true
is_odd(-3);      // true
```

**Real-world:** Alternating patterns, parity checks, game logic.

---

### Is Prime

```c++
bool is_prime(int n);
```

Tests whether a number is prime (only divisible by 1 and itself).

**Examples:**
```c++
is_prime(2);     // true (smallest prime)
is_prime(17);    // true
is_prime(20);    // false (divisible by 2, 4, 5, 10)
is_prime(1);     // false (1 is not prime by definition)
is_prime(29);    // true
```

**Real-world:** Cryptography, hash functions, mathematical research.

---

### Greatest Common Divisor (GCD)

```c++
int greatest_common_divisor(int a, int b);
```

Finds the largest number that divides both a and b evenly.

**Examples:**
```c++
greatest_common_divisor(48, 18);  // 6
greatest_common_divisor(100, 50); // 50
greatest_common_divisor(17, 19);  // 1 (coprime numbers)
greatest_common_divisor(24, 36);  // 12
```

**Real-world:** Simplifying fractions, tile arrangements, gear ratios.

---

### Least Common Multiple (LCM)

```c++
int least_common_multiple(int a, int b);
```

Finds the smallest positive number that is a multiple of both a and b.

**Examples:**
```c++
least_common_multiple(4, 6);      // 12
least_common_multiple(3, 5);      // 15
least_common_multiple(12, 18);    // 36
least_common_multiple(7, 14);     // 14
```

**Real-world:** Scheduling cycles, pattern repetition, synchronization problems.

---

## Geometry

### Distance 2D

```c++
double distance_2D(double x1, double y1, double x2, double y2);
```

Calculates the Euclidean distance between two points in 2D space.

**Formula:** √[(x₂-x₁)² + (y₂-y₁)²]

**Examples:**
```c++
distance_2D(0, 0, 3, 4);         // 5.0
distance_2D(1, 1, 4, 5);         // 5.0
distance_2D(-2, -3, 1, 1);       // 5.0
distance_2D(0, 0, 1, 1);         // 1.414... (√2)
```

**Real-world:** GPS distance, game coordinates, mapping applications.

---

### Pythagorean Theorem

```c++
double pythagorean(double a, double b);
```

Calculates the hypotenuse of a right triangle given the two legs.

**Formula:** c = √(a² + b²)

**Examples:**
```c++
pythagorean(3, 4);      // 5.0 (3-4-5 triangle)
pythagorean(5, 12);     // 13.0 (5-12-13 triangle)
pythagorean(1, 1);      // 1.414... (√2)
pythagorean(6, 8);      // 10.0
```

**Real-world:** Construction, navigation, diagonal measurements.

## Finance

### Simple Interest

```c++
double simple_interest(double principal, double rate, double time);
```

Calculates simple interest on a principal amount.

**Formula:** I = P × r × t

**Parameters:**
- principal: Initial amount
- rate: Interest rate (as decimal, e.g., 0.05 for 5%)
- time: Time period (usually in years)

**Examples:**
```c++
simple_interest(1000, 0.05, 2);      // 100.0 ($1000 at 5% for 2 years)
simple_interest(5000, 0.03, 1);      // 150.0 ($5000 at 3% for 1 year)
simple_interest(10000, 0.04, 3);     // 1200.0 ($10000 at 4% for 3 years)
```

**Real-world:** Loan interest, savings accounts, investment returns.

---

## Sequences

### Arithmetic Sequences

```c++
void sequence(uint_t first, uint_t diff, unsigned int terms,
                        std::vector<uint_t>& result);
uint_t sequence_sum(uint_t first, uint_t last, unsigned int terms);
uint_t nth_term(uint_t first, uint_t diff, unsigned int n);
```

**Examples:**
```c++
std::vector<uint_t> seq;
sequence(2, 3, 5, seq);  // {2, 5, 8, 11, 14}

sequence_sum(2, 14, 5);           // 40
nth_term(2, 3, 5);       // 14
```

**Real-world:** Savings, Taxi Fares, Salary.

## Complete Examples

### Example 1: Simple Calculator

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

---

### Example 2: Statistical Analysis

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>
#include <vector>

int main() {
    std::vector<double> grades = {85.5, 92.0, 78.5, 95.0, 88.0};

    std::cout << "Grade Statistics\n";
    std::cout << "================\n";
    std::cout << "Average: " << imeth::Arithmetic::average(grades) << "\n";
    std::cout << "Median: " << imeth::Arithmetic::median(grades) << "\n";
    std::cout << "Minimum: " << imeth::Arithmetic::minimum(grades) << "\n";
    std::cout << "Maximum: " << imeth::Arithmetic::maximum(grades) << "\n";
    std::cout << "Range: " << imeth::Arithmetic::range(grades) << "\n";

    return 0;
}
```

---

### Example 3: Number Theory

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    int a = 48, b = 18;

    std::cout << "Number Theory for " << a << " and " << b << "\n";
    std::cout << "GCD: " << imeth::Arithmetic::greatest_common_divisor(a, b) << "\n";
    std::cout << "LCM: " << imeth::Arithmetic::least_common_multiple(a, b) << "\n";

    std::cout << "\nPrime numbers from 1 to 20:\n";
    for (int i = 1; i <= 20; i++) {
        if (imeth::Arithmetic::is_prime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
```

---

### Example 4: Percentage Calculations

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    double original_price = 100.0;
    double sale_price = 75.0;

    double discount = imeth::Arithmetic::percent_of(20, original_price);
    double decrease = imeth::Arithmetic::percent_decrease(original_price, sale_price);

    std::cout << "Original Price: $" << original_price << "\n";
    std::cout << "20% discount: $" << discount << "\n";
    std::cout << "Sale Price: $" << sale_price << "\n";
    std::cout << "Percent saved: " << decrease << "%\n";

    return 0;
}
```

---

### Example 5: Geometry Calculations

```c++
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    // Calculate distance between two cities (coordinates)
    double city1_x = 0, city1_y = 0;
    double city2_x = 3, city2_y = 4;

    double distance = imeth::Arithmetic::distance_2D(city1_x, city1_y,
                                                     city2_x, city2_y);

    std::cout << "Distance between cities: " << distance << " km\n";

    // Calculate diagonal of a rectangle
    double width = 6, height = 8;
    double diagonal = imeth::Arithmetic::pythagorean(width, height);

    std::cout << "Rectangle diagonal: " << diagonal << "\n";

    return 0;
}
```

---

## Tips

- **Division by Zero**: Always check for zero before dividing
- **Integer vs Double**: Use appropriate types for your calculations
- **Rounding**: Choose the right rounding method for your use case
- **Prime Testing**: Large numbers may take longer to test
- **Floating Point**: Be aware of floating-point precision limitations
- **Vector Operations**: Ensure vectors are not empty before statistical calculations

---

## Quick Reference

| Operation Type | Function                               | Use Case               |
|----------------|----------------------------------------|------------------------|
| Basic math     | `add`, `subtract`, `multiply`, `divide` | Calculations           |
| Powers         | `power`, `square_root`, `cube_root`    | Exponents, roots       |
| Statistics     | `average`, `median`, `sum`             | Data analysis          |
| Percentages    | `percent_of`, `what_percent`           | Discounts, rates       |
| Rounding       | `round_to_nearest`, `round_up`, `round_down` | Display, precision     |
| Number theory  | `is_prime`, `greatest_common_divisor`  | Math problems          |
| Geometry       | `distance_2D`, `pythagorean`           | Coordinates, triangles |
| Finance        | `simple_interest`                      | Loans, investments     |
| Sequences      | `sequence`, `sequence_sum`, `nth_term` | Savings, salary        |

---

## Common Use Cases

### Shopping Calculations
```c++
double price = 50.0;
double taxRate = 0.08;  // 8% tax
double tax = imeth::Arithmetic::percent_of(taxRate * 100, price);
double total = imeth::Arithmetic::add(price, tax);
```

### Grade Calculator
```c++
std::vector<double> scores = {85, 90, 78, 92};
double avg = imeth::Arithmetic::average(scores);
double rounded = imeth::Arithmetic::round_to_nearest(avg);
```

### Distance Calculation
```c++
double dist = imeth::Arithmetic::distance_2D(x1, y1, x2, y2);
double rounded_dist = imeth::Arithmetic::round_to_decimal_places(dist, 2);
```

### Fraction Simplification
```c++
int num = 48, den = 18;
int gcd = imeth::Arithmetic::greatest_common_divisor(num, den);
int simplified_num = num / gcd;  // 8
int simplified_den = den / gcd;  // 3
// Result: 48/18 = 8/3
```
