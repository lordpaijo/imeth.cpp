#include "../include/imeth/base.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace imeth {

const std::string Base::DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char Base::digitToChar(int digit) {
    if (digit < 0 || digit >= 36) {
        throw std::invalid_argument("Digit out of range");
    }
    return DIGITS[digit];
}

int Base::charToDigit(char c) {
    c = std::toupper(c);
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    throw std::invalid_argument("Invalid character in number");
}

// Convert decimal to any base
std::string Base::decimalToBase(int decimal, int base) {
    if (base < 2 || base > 36) {
        throw std::invalid_argument("Base must be between 2 and 36");
    }

    if (decimal == 0) return "0";

    bool negative = decimal < 0;
    decimal = abs(decimal);

    std::string result = "";
    while (decimal > 0) {
        int remainder = decimal % base;
        result = digitToChar(remainder) + result;
        decimal /= base;
    }

    if (negative) result = "-" + result;
    return result;
}

std::string Base::decimalToBinary(int decimal) {
    return decimalToBase(decimal, 2);
}

std::string Base::decimalToTrinary(int decimal) {
    return decimalToBase(decimal, 3);
}

std::string Base::decimalToOctal(int decimal) {
    return decimalToBase(decimal, 8);
}

std::string Base::decimalToHexadecimal(int decimal) {
    return decimalToBase(decimal, 16);
}

// Convert from any base to decimal
int Base::baseToDecimal(const std::string& number, int base) {
    if (base < 2 || base > 36) {
        throw std::invalid_argument("Base must be between 2 and 36");
    }

    if (number.empty()) {
        throw std::invalid_argument("Empty number string");
    }

    bool negative = (number[0] == '-');
    size_t start = negative ? 1 : 0;

    int result = 0;
    int power = 1;

    // Process from right to left
    for (int i = number.length() - 1; i >= (int)start; --i) {
        int digit = charToDigit(number[i]);
        if (digit >= base) {
            throw std::invalid_argument("Invalid digit for base");
        }
        result += digit * power;
        power *= base;
    }

    return negative ? -result : result;
}

int Base::binaryToDecimal(const std::string& binary) {
    return baseToDecimal(binary, 2);
}

int Base::trinaryToDecimal(const std::string& trinary) {
    return baseToDecimal(trinary, 3);
}

int Base::octalToDecimal(const std::string& octal) {
    return baseToDecimal(octal, 8);
}

int Base::hexadecimalToDecimal(const std::string& hex) {
    return baseToDecimal(hex, 16);
}

// Direct conversion between bases
std::string Base::convert(const std::string& number, int fromBase, int toBase) {
    int decimal = baseToDecimal(number, fromBase);
    return decimalToBase(decimal, toBase);
}

// Arithmetic operations in different bases
std::string Base::addInBase(const std::string& num1, const std::string& num2, int base) {
    int dec1 = baseToDecimal(num1, base);
    int dec2 = baseToDecimal(num2, base);
    return decimalToBase(dec1 + dec2, base);
}

std::string Base::subtractInBase(const std::string& num1, const std::string& num2, int base) {
    int dec1 = baseToDecimal(num1, base);
    int dec2 = baseToDecimal(num2, base);
    return decimalToBase(dec1 - dec2, base);
}

std::string Base::multiplyInBase(const std::string& num1, const std::string& num2, int base) {
    int dec1 = baseToDecimal(num1, base);
    int dec2 = baseToDecimal(num2, base);
    return decimalToBase(dec1 * dec2, base);
}

// Utility functions
bool Base::isValidInBase(const std::string& number, int base) {
    if (number.empty() || base < 2 || base > 36) {
        return false;
    }

    size_t start = (number[0] == '-') ? 1 : 0;

    for (size_t i = start; i < number.length(); ++i) {
        try {
            int digit = charToDigit(number[i]);
            if (digit >= base) {
                return false;
            }
        } catch (...) {
            return false;
        }
    }

    return true;
}

std::string Base::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

} // namespace imeth
