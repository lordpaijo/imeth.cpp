#include "../include/imeth/base/octal.hpp"
#include <stdexcept>

namespace imeth {

// Conversion
std::string Octal::fromDecimal(int decimal) {
    if (decimal == 0) return "0";

    bool negative = decimal < 0;
    decimal = abs(decimal);

    std::string result = "";
    while (decimal > 0) {
        result = std::to_string(decimal % 8) + result;
        decimal /= 8;
    }

    if (negative) result = "-" + result;
    return result;
}

int Octal::toDecimal(const std::string& octal) {
    if (octal.empty()) {
        throw std::invalid_argument("Empty octal string");
    }

    bool negative = (octal[0] == '-');
    size_t start = negative ? 1 : 0;

    int result = 0;
    int power = 1;

    for (int i = octal.length() - 1; i >= (int)start; --i) {
        int digit = octal[i] - '0';
        if (digit < 0 || digit > 7) {
            throw std::invalid_argument("Invalid octal digit");
        }
        result += digit * power;
        power *= 8;
    }

    return negative ? -result : result;
}

// Arithmetic operations
std::string Octal::add(const std::string& a, const std::string& b) {
    int dec1 = toDecimal(a);
    int dec2 = toDecimal(b);
    return fromDecimal(dec1 + dec2);
}

std::string Octal::subtract(const std::string& a, const std::string& b) {
    int dec1 = toDecimal(a);
    int dec2 = toDecimal(b);
    return fromDecimal(dec1 - dec2);
}

std::string Octal::multiply(const std::string& a, const std::string& b) {
    int dec1 = toDecimal(a);
    int dec2 = toDecimal(b);
    return fromDecimal(dec1 * dec2);
}

// Utility
bool Octal::isValid(const std::string& octal) {
    if (octal.empty()) return false;

    size_t start = (octal[0] == '-') ? 1 : 0;
    for (size_t i = start; i < octal.length(); ++i) {
        if (octal[i] < '0' || octal[i] > '7') {
            return false;
        }
    }
    return true;
}

std::string Octal::padLeft(const std::string& octal, size_t length) {
    if (octal.length() >= length) return octal;
    return std::string(length - octal.length(), '0') + octal;
}

} // namespace imeth
