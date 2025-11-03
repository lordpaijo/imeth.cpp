#pragma once
#include <vector>

namespace imeth {
namespace Arithmetic {
    // Basic Operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double modulo(double a, double b);

    // Power and Roots
    double power(double base, int exponent);
    double squareRoot(double n);
    double cubeRoot(double n);

    // Absolute Value and Sign
    double absolute(double n);
    int absolute(int n); // don't mind me
    int sign(double n); // Returns -1, 0, or 1

    // Remainders and Divisibility
    int remainder(int a, int b);
    bool isDivisible(int a, int b);

    // Percentages
    double percentOf(double percent, double total);
    double whatPercent(double part, double total);
    double percentIncrease(double original, double newValue);
    double percentDecrease(double original, double newValue);

    // Averages and Statistics
    double average(const std::vector<double>& numbers);
    double sum(const std::vector<double>& numbers);
    double minimum(const std::vector<double>& numbers);
    double maximum(const std::vector<double>& numbers);
    double range(const std::vector<double>& numbers);
    double median(std::vector<double> numbers); // Note: not const because we sort

    // Fractions (simplified as doubles)
    double addFractions(double num1, double den1, double num2, double den2);
    double subtractFractions(double num1, double den1, double num2, double den2);
    double multiplyFractions(double num1, double den1, double num2, double den2);
    double divideFractions(double num1, double den1, double num2, double den2);

    // Rounding
    double roundToNearest(double n);
    double roundUp(double n);
    double roundDown(double n);
    double roundToDecimalPlaces(double n, int places);

    // Number Properties
    bool isEven(int n);
    bool isOdd(int n);
    bool isPrime(int n);
    int greatestCommonDivisor(int a, int b);
    int leastCommonMultiple(int a, int b);

    // Distance and Pythagorean
    double distance2D(double x1, double y1, double x2, double y2);
    double pythagorean(double a, double b); // Returns hypotenuse c

    // Temperature Conversions
    double celsiusToFahrenheit(double celsius);
    double fahrenheitToCelsius(double fahrenheit);

    // Simple Interest
    double simpleInterest(double principal, double rate, double time);
}; // namespace arithmetic
} // namespace imeth
