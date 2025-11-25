#include "../include/imeth/operation/arithmetic.hpp"
#include <algorithm>
#include <stdexcept>

namespace imeth::Arithmetic {

// Basic Operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return a / b;
}

// Power and Roots
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double square_root(double n) {
    if (n < 0) {
        throw std::invalid_argument("Cannot take square root of negative number");
    }
    auto z = n;
    for (int i = 0; i < 10; i++) { z = (z + n / z) / 2.0; }
    return z;
}

double cube_root(double n) {
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
double absolute(double n) {
    return n < 0 ? -n : n;
}

int absolute(int n) {
    return n < 0 ? -n : n;
}

int sign(double n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

// Remainders and Divisibility
int remainder(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot find remainder with divisor of zero");
    }
    return a % b;
}

bool is_divisible(int a, int b) {
    if (b == 0) return false;
    return (a % b) == 0;
}

// Percentages
double percent_of(double percent, double total) {
    return (percent / 100.0) * total;
}

double what_percent(double part, double total) {
    if (total == 0) {
        throw std::invalid_argument("Total cannot be zero");
    }
    return (part / total) * 100.0;
}

double percent_increase(double original, double newValue) {
    if (original == 0) {
        throw std::invalid_argument("Original value cannot be zero");
    }
    return ((newValue - original) / original) * 100.0;
}

double percent_decrease(double original, double newValue) {
    if (original == 0) {
        throw std::invalid_argument("Original value cannot be zero");
    }
    return ((original - newValue) / original) * 100.0;
}

// Averages and Statistics
double average(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find average of empty list");
    }
    return sum(numbers) / numbers.size();
}

double sum(const std::vector<double>& numbers) {
    double total = 0;
    for (const double n : numbers) {
        total += n;
    }
    return total;
}

double minimum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find minimum of empty list");
    }
    return *std::ranges::min_element(numbers);
}

double maximum(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find maximum of empty list");
    }
    return *std::ranges::max_element(numbers);
}

double range(const std::vector<double>& numbers) {
    return maximum(numbers) - minimum(numbers);
}

double median(std::vector<double> numbers) {
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
double add_fractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    // Find common denominator and add
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 + newNum2) / commonDen;
}

double subtract_fractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    double commonDen = den1 * den2;
    double newNum1 = num1 * den2;
    double newNum2 = num2 * den1;
    return (newNum1 - newNum2) / commonDen;
}

double multiply_fractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    return (num1 * num2) / (den1 * den2);
}

double divide_fractions(const double num1, const double den1, const double num2, const double den2) {
    if (den1 == 0 || den2 == 0 || num2 == 0) {
        throw std::invalid_argument("Denominator cannot be zero and cannot divide by zero");
    }
    return (num1 * den2) / (den1 * num2);
}

// Rounding
double round_to_nearest(const double n) {
    if (n >= 0) {
        return static_cast<double>(static_cast<long long>(n + 0.5));
    } else {
        return static_cast<double>(static_cast<long long>(n - 0.5));
    }
    // this can give incorrect results... Do I have to wrap lround() from cmath here?????
}

double round_up(const double n) {
    const auto intPart = static_cast<long long>(n);
    if (n > 0 && n > static_cast<double>(intPart)) {
        return static_cast<double>(intPart + 1);
    }
    return static_cast<double>(intPart);
}

double round_down(const double n) {
    const auto intPart = static_cast<long long>(n);
    if (n < 0 && n < static_cast<double>(intPart)) {
        return static_cast<double>(intPart - 1);
    }
    return static_cast<double>(intPart);
}

double round_to_decimalPlaces(const double n, const int places) {
    const double multiplier = power(10.0, places);
    return round_to_nearest(n * multiplier) / multiplier;
}

// Number Properties
bool is_even(const int n) {
    return n % 2 == 0;
}

bool isOdd(const int n) {
    return n % 2 != 0;
}

bool is_prime(const int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    // Check odd divisors up to square root
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int greatest_common_divisor(int a, int b) {
    a = absolute(a);
    b = absolute(b);

    while (b != 0) {
        const int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int least_common_multiple(const int a, const int b) {
    if (a == 0 || b == 0) return 0;
    return absolute(a * b) / greatest_common_divisor(a, b);
}

// Distance and Pythagorean
double distance_2D(const double x1, const double y1, const double x2, const double y2) {
    const double dx = x2 - x1;
    const double dy = y2 - y1;
    return square_root(dx * dx + dy * dy);
}

double pythagorean(const double a, const double b) {
    return square_root(a * a + b * b);
}

// Simple Interest
double simple_interest(const double principal, const double rate, const double time) {
    return principal * (rate / 100.0) * time;
}

// Sequnces
void sequence(const uint_t first, const uint_t diff, unsigned int terms, std::vector<uint_t>& result) {
    result.clear();
    result.reserve(terms);
    for (unsigned int i = 0; i < terms; ++i) {
        result.push_back(first + i * diff);
    }
}

uint_t sequence_sum(const uint_t first, const uint_t last, const unsigned int terms) {
    return terms * (first + last) / 2;
}

uint_t nth_term(const uint_t first, const uint_t diff, const unsigned int n) {
    return first + (n - 1) * diff;
}

} // namespace imeth
