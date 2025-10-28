#pragma once
#include <vector>

namespace imeth {
class Arithmetic {
public:
    // Basic Operations
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);

    // Power and Roots
    static double power(double base, int exponent);
    static double squareRoot(double n);
    static double cubeRoot(double n);

    // Absolute Value and Sign
    static double absolute(double n);
    static int sign(double n); // Returns -1, 0, or 1

    // Remainders and Divisibility
    static int remainder(int a, int b);
    static bool isDivisible(int a, int b);

    // Percentages
    static double percentOf(double percent, double total);
    static double whatPercent(double part, double total);
    static double percentIncrease(double original, double newValue);
    static double percentDecrease(double original, double newValue);

    // Averages and Statistics
    static double average(const std::vector<double>& numbers);
    static double sum(const std::vector<double>& numbers);
    static double minimum(const std::vector<double>& numbers);
    static double maximum(const std::vector<double>& numbers);
    static double range(const std::vector<double>& numbers);
    static double median(std::vector<double> numbers); // Note: not const because we sort

    // Fractions (simplified as doubles)
    static double addFractions(double num1, double den1, double num2, double den2);
    static double subtractFractions(double num1, double den1, double num2, double den2);
    static double multiplyFractions(double num1, double den1, double num2, double den2);
    static double divideFractions(double num1, double den1, double num2, double den2);

    // Rounding
    static double roundToNearest(double n);
    static double roundUp(double n);
    static double roundDown(double n);
    static double roundToDecimalPlaces(double n, int places);

    // Number Properties
    static bool isEven(int n);
    static bool isOdd(int n);
    static bool isPrime(int n);
    static int greatestCommonDivisor(int a, int b);
    static int leastCommonMultiple(int a, int b);

    // Distance and Pythagorean
    static double distance2D(double x1, double y1, double x2, double y2);
    static double pythagorean(double a, double b); // Returns hypotenuse c

    // Temperature Conversions
    static double celsiusToFahrenheit(double celsius);
    static double fahrenheitToCelsius(double fahrenheit);

    // Simple Interest
    static double simpleInterest(double principal, double rate, double time);
};
} // namespace imeth
