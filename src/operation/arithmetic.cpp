#include "../include/imeth/operation/arithmetic.hpp"
#include <algorithm>
#include <stdexcept>

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
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double Arithmetic::squareRoot(double n) {
    if (n < 0) {
        throw std::invalid_argument("Cannot take square root of negative number");
    }
    auto z = n;
    for (int i = 0; i < 10; i++) { z = (z + n / z) / 2.0; }
    return z;
}

double Arithmetic::cubeRoot(double n) {
    if (n == 0) return 0;
    bool negative = n < 0;
    if (negative) n = -n;

    double x = n;
    double epsilon = 1e-10;

    while (true) {
        double x_next = (2.0 * x + n / (x * x)) / 3.0;
        if (absolute(x_next - x) < epsilon) break;

        x = x_next;
    }

    return negative ? -x : x;
}

// Absolute Value and Sign
double Arithmetic::absolute(double n) {
    return n < 0 ? -n : n;
}

int Arithmetic::absolute(int n) {
    return n < 0 ? -n : n;
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
    for (const double n : numbers) {
        total += n;
    }
    return total;
}

double Arithmetic::minimum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find minimum of empty list");
    }
    return *std::ranges::min_element(numbers);
}

double Arithmetic::maximum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find maximum of empty list");
    }
    return *std::ranges::max_element(numbers);
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
double Arithmetic::addFractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // Find common denominator and add
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 + newNum2) / commonDen;
}

double Arithmetic::subtractFractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 - newNum2) / commonDen;
}

double Arithmetic::multiplyFractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    return (num1 * num2) / (den1 * den2);
}

double Arithmetic::divideFractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0 || num2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero and cannot divide by zero");
    }
    return (num1 * den2) / (den1 * num2);
}

// Rounding
double Arithmetic::roundToNearest(double n) {
    if (n >= 0) {
        return static_cast<double>(static_cast<long long>(n + 0.5));
    } else {
        return static_cast<double>(static_cast<long long>(n - 0.5));
    }
    // this can give incorrect results... Do I have to wrap lround() from cmath here?????
}

double Arithmetic::roundUp(double n) {
    auto intPart = static_cast<long long>(n);
    if (n > 0 && n > static_cast<double>(intPart)) {
        return static_cast<double>(intPart + 1);
    }
    return static_cast<double>(intPart);
}

double Arithmetic::roundDown(double n) {
    auto intPart = static_cast<long long>(n);
    if (n < 0 && n < static_cast<double>(intPart)) {
        return static_cast<double>(intPart - 1);
    }
    return static_cast<double>(intPart);
}

double Arithmetic::roundToDecimalPlaces(double n, int places) {
    double multiplier = power(10.0, places);
    return roundToNearest(n * multiplier) / multiplier;
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
    a = absolute(a);
    b = absolute(b);

    while (b != 0) {
        const int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Arithmetic::leastCommonMultiple(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return absolute(a * b) / greatestCommonDivisor(a, b);
}

// Distance and Pythagorean
double Arithmetic::distance2D(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return squareRoot(dx * dx + dy * dy);
}

double Arithmetic::pythagorean(double a, double b) {
    return squareRoot(a * a + b * b);
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
} // namespace imeth
