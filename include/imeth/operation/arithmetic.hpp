#pragma once
#include <vector>

namespace imeth {
namespace Arithmetic {
    using uint_t = unsigned long long;

    // Basic Operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double modulo(double a, double b);

    // Power and Roots
    double power(double base, int exponent);
    double square_root(double n);
    double cube_root(double n);

    // Absolute Value and Sign
    double absolute(double n);
    int absolute(int n); // don't mind me
    int sign(double n); // Returns -1, 0, or 1

    // Remainders and Divisibility
    int remainder(int a, int b);
    bool is_divisible(int a, int b);

    // Percentages
    double percent_of(double percent, double total);
    double what_percent(double part, double total);
    double percent_increase(double original, double newValue);
    double percent_decrease(double original, double newValue);

    // Averages and Statistics
    double average(const std::vector<double>& numbers);
    double sum(const std::vector<double>& numbers);
    double minimum(const std::vector<double>& numbers);
    double maximum(const std::vector<double>& numbers);
    double range(const std::vector<double>& numbers);
    double median(std::vector<double> numbers); // Note: not const because we sort

    // Fractions (simplified as doubles)
    double add_fractions(double num1, double den1, double num2, double den2);
    double subtract_fractions(double num1, double den1, double num2, double den2);
    double multiply_fractions(double num1, double den1, double num2, double den2);
    double divide_fractions(double num1, double den1, double num2, double den2);

    // Rounding
    double round_to_nearest(double n);
    double round_up(double n);
    double round_down(double n);
    double round_to_decimalPlaces(double n, int places);

    // Number Properties
    bool is_even(int n);
    bool is_odd(int n);
    bool is_prime(int n);
    int greatest_common_divisor(int a, int b);
    int least_common_multiple(int a, int b);

    // Distance and Pythagorean
    double distance_2D(double x1, double y1, double x2, double y2);
    double pythagorean(double a, double b); // Returns hypotenuse c

    // Simple Interest
    double simple_interest(double principal, double rate, double time);

    // Sequences
    void sequence(uint_t first, uint_t diff, unsigned int terms,
                                std::vector<uint_t>& result);
    uint_t sequence_sum(uint_t first, uint_t last, unsigned int terms);
    uint_t nth_term(uint_t first, uint_t diff, unsigned int n);
}; // namespace arithmetic
} // namespace imeth
