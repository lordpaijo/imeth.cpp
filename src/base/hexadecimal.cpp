#include "../include/imeth/base/hexadecimal.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace imeth {

// Helper functions
int Hexadecimal::charToDigit(char c) {
    c = std::toupper(c);
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    throw std::invalid_argument("Invalid hexadecimal character");
}

char Hexadecimal::digitToChar(const int digit) {
    if (digit < 0 || digit > 15) {
        throw std::invalid_argument("Digit out of range");
    }
    if (digit < 10) {
        return '0' + digit;
    }
    return 'A' + (digit - 10);
}

// Conversion
std::string Hexadecimal::fromDecimal(int decimal) {
    if (decimal == 0) return "0";

    bool negative = decimal < 0;
    decimal = imeth::Arithmetic::absolute(decimal);

    std::string result = "";
    while (decimal > 0) {
        result = digitToChar(decimal % 16) + result;
        decimal /= 16;
    }

    if (negative) result = "-" + result;
    return result;
}

int Hexadecimal::toDecimal(const std::string& hex) {
    if (hex.empty()) {
        throw std::invalid_argument("Empty hexadecimal string");
    }

    bool negative = (hex[0] == '-');
    size_t start = negative ? 1 : 0;

    int result = 0;
    int power = 1;

    for (int i = hex.length() - 1; i >= static_cast<int>(start); --i) {
        int digit = charToDigit(hex[i]);
        result += digit * power;
        power *= 16;
    }

    return negative ? -result : result;
}

// Arithmetic operations
std::string Hexadecimal::add(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 + dec2);
}

std::string Hexadecimal::subtract(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 - dec2);
}

std::string Hexadecimal::multiply(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 * dec2);
}

// Utility
bool Hexadecimal::isValid(const std::string& hex) {
    if (hex.empty()) return false;

    size_t start = (hex[0] == '-') ? 1 : 0;
    for (size_t i = start; i < hex.length(); ++i) {
        char c = std::toupper(hex[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            return false;
        }
    }
    return true;
}

std::string Hexadecimal::toUpperCase(const std::string& hex) {
    std::string result = hex;
    std::ranges::transform(result, result.begin(), ::toupper);
    return result;
}

std::string Hexadecimal::toLowerCase(const std::string& hex) {
    std::string result = hex;
    std::ranges::transform(result, result.begin(), ::tolower);
    return result;
}

std::string Hexadecimal::padLeft(const std::string& hex, size_t length) {
    if (hex.length() >= length) return hex;
    return std::string(length - hex.length(), '0') + hex;
}

} // namespace imeth
