#include "../include/imeth/operation/arithmetic.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <numbers>

namespace imeth {

// Basic Operations
double Arithmetic::add(double a, double b) {
    return a + b;
}

double Arithmetic::subtract(double a, double b) {
    return a - b;
}

double Arithmetic::multiply(double a, double b) {
    return a * b;
}

double Arithmetic::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return a / b;
}

// Power and Roots
double Arithmetic::power(double base, int exponent) {
    return std::pow(base, exponent);
}

double Arithmetic::squareRoot(double n) {
    if (n < 0) {
        throw std::invalid_argument("Cannot take square root of negative number");
    }
    return std::sqrt(n);
}

double Arithmetic::cubeRoot(double n) {
    return std::cbrt(n);
}

// Absolute Value and Sign
double Arithmetic::absolute(double n) {
    return std::abs(n);
}

int Arithmetic::sign(double n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

// Remainders and Divisibility
int Arithmetic::remainder(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot find remainder with divisor of zero");
    }
    return a % b;
}

bool Arithmetic::isDivisible(int a, int b) {
    if (b == 0) return false;
    return (a % b) == 0;
}

// Percentages
double Arithmetic::percentOf(double percent, double total) {
    return (percent / 100.0) * total;
}

double Arithmetic::whatPercent(double part, double total) {
    if (total == 0) {
        throw std::invalid_argument("Total cannot be zero");
    }
    return (part / total) * 100.0;
}

double Arithmetic::percentIncrease(double original, double newValue) {
    if (original == 0) {
        throw std::invalid_argument("Original value cannot be zero");
    }
    return ((newValue - original) / original) * 100.0;
}

double Arithmetic::percentDecrease(double original, double newValue) {
    if (original == 0) {
        throw std::invalid_argument("Original value cannot be zero");
    }
    return ((original - newValue) / original) * 100.0;
}

// Averages and Statistics
double Arithmetic::average(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find average of empty list");
    }
    return sum(numbers) / numbers.size();
}

double Arithmetic::sum(const std::vector<double>& numbers) {
    double total = 0;
    for (double n : numbers) {
        total += n;
    }
    return total;
}

double Arithmetic::minimum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find minimum of empty list");
    }
    return *std::min_element(numbers.begin(), numbers.end());
}

double Arithmetic::maximum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find maximum of empty list");
    }
    return *std::max_element(numbers.begin(), numbers.end());
}

double Arithmetic::range(const std::vector<double>& numbers) {
    return maximum(numbers) - minimum(numbers);
}

double Arithmetic::median(std::vector<double> numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find median of empty list");
    }

    std::sort(numbers.begin(), numbers.end());
    int size = numbers.size();

    if (size % 2 == 0) {
        // Even number of elements: average of two middle values
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        // Odd number of elements: middle value
        return numbers[size / 2];
    }
}

// Fractions
double Arithmetic::addFractions(double num1, double den1, double num2, double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // Find common denominator and add
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 + newNum2) / commonDen;
}

double Arithmetic::subtractFractions(double num1, double den1, double num2, double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 - newNum2) / commonDen;
}

double Arithmetic::multiplyFractions(double num1, double den1, double num2, double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    return (num1 * num2) / (den1 * den2);
}

double Arithmetic::divideFractions(double num1, double den1, double num2, double den2) {
    if (den1 == 0 || den2 == 0 || num2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero and cannot divide by zero");
    }
    // Flip second fraction and multiply
    return (num1 * den2) / (den1 * num2);
}

// Rounding
double Arithmetic::roundToNearest(double n) {
    return std::round(n);
}

double Arithmetic::roundUp(double n) {
    return std::ceil(n);
}

double Arithmetic::roundDown(double n) {
    return std::floor(n);
}

double Arithmetic::roundToDecimalPlaces(double n, int places) {
    double multiplier = std::pow(10.0, places);
    return std::round(n * multiplier) / multiplier;
}

// Number Properties
bool Arithmetic::isEven(int n) {
    return n % 2 == 0;
}

bool Arithmetic::isOdd(int n) {
    return n % 2 != 0;
}

bool Arithmetic::isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    // Check odd divisors up to square root
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int Arithmetic::greatestCommonDivisor(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Arithmetic::leastCommonMultiple(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a * b) / greatestCommonDivisor(a, b);
}

// Distance and Pythagorean
double Arithmetic::distance2D(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

double Arithmetic::pythagorean(double a, double b) {
    return std::sqrt(a * a + b * b);
}

// Temperature Conversions
double Arithmetic::celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double Arithmetic::fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Simple Interest
double Arithmetic::simpleInterest(double principal, double rate, double time) {
    return principal * (rate / 100.0) * time;
}

// Area Calculations
double Arithmetic::rectangleArea(double length, double width) {
    return length * width;
}

double Arithmetic::triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double Arithmetic::circleArea(double radius) {
    return std::numbers::pi * radius * radius;
}

// Perimeter Calculations
double Arithmetic::rectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double Arithmetic::trianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

double Arithmetic::circleCircumference(double radius) {
    return 2 * std::numbers::pi * radius;
}

} // namespace imeth
