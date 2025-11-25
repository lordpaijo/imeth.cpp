#include "../include/imeth/base/base.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace imeth {

const std::string Base::DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char Base::digit_to_char(int digit) {
    if (digit < 0 || digit >= 36) {
        throw std::invalid_argument("Digit out of range");
    }
    return DIGITS[digit];
}

int Base::char_to_digit(char c) {
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
std::string Base::decimal_to_base(int decimal, const int base) {
    if (base < 2 || base > 36) {
        throw std::invalid_argument("Base must be between 2 and 36");
    }

    if (decimal == 0) return "0";

    const bool negative = decimal < 0;
    decimal = imeth::Arithmetic::absolute(decimal);

    std::string result = "";
    while (decimal > 0) {
        int remainder = decimal % base;
        result = digit_to_char(remainder) + result;
        decimal /= base;
    }

    if (negative) result = "-" + result;
    return result;
}

std::string Base::decimal_to_binary(const int decimal) {
    return decimal_to_base(decimal, 2);
}

std::string Base::decimal_to_trinary(const int decimal) {
    return decimal_to_base(decimal, 3);
}

std::string Base::decimal_to_octal(const int decimal) {
    return decimal_to_base(decimal, 8);
}

std::string Base::decimal_to_hexadecimal(const int decimal) {
    return decimal_to_base(decimal, 16);
}

// Convert from any base to decimal
int Base::base_to_decimal(const std::string& number, int base) {
    if (base < 2 || base > 36) {
        throw std::invalid_argument("Base must be between 2 and 36");
    }

    if (number.empty()) {
        throw std::invalid_argument("Empty number string");
    }

    const bool negative = (number[0] == '-');
    size_t start = negative ? 1 : 0;

    int result = 0;
    int power = 1;

    // Process from right to left
    for (int i = number.length() - 1; i >= static_cast<int>(start); --i) {
        int digit = char_to_digit(number[i]);
        if (digit >= base) {
            throw std::invalid_argument("Invalid digit for base");
        }
        result += digit * power;
        power *= base;
    }

    return negative ? -result : result;
}

int Base::binary_to_decimal(const std::string& binary) {
    return base_to_decimal(binary, 2);
}

int Base::trinary_to_decimal(const std::string& trinary) {
    return base_to_decimal(trinary, 3);
}

int Base::octal_to_decimal(const std::string& octal) {
    return base_to_decimal(octal, 8);
}

int Base::hexadecimal_to_decimal(const std::string& hex) {
    return base_to_decimal(hex, 16);
}

// Direct conversion between bases
std::string Base::convert(const std::string& number, const int fromBase, const int toBase) {
    const int decimal = base_to_decimal(number, fromBase);
    return decimal_to_base(decimal, toBase);
}

// Arithmetic operations in different bases
std::string Base::add_in_base(const std::string& num1, const std::string& num2, const int base) {
    const int dec1 = base_to_decimal(num1, base);
    const int dec2 = base_to_decimal(num2, base);
    return decimal_to_base(dec1 + dec2, base);
}

std::string Base::subtract_in_base(const std::string& num1, const std::string& num2, const int base) {
    const int dec1 = base_to_decimal(num1, base);
    const int dec2 = base_to_decimal(num2, base);
    return decimal_to_base(dec1 - dec2, base);
}

std::string Base::multiply_in_base(const std::string& num1, const std::string& num2, const int base) {
    const int dec1 = base_to_decimal(num1, base);
    const int dec2 = base_to_decimal(num2, base);
    return decimal_to_base(dec1 * dec2, base);
}

// Utility functions
bool Base::is_valid_in_base(const std::string& number, const int base) {
    if (number.empty() || base < 2 || base > 36) {
        return false;
    }

    size_t start = (number[0] == '-') ? 1 : 0;

    for (size_t i = start; i < number.length(); ++i) {
        try {
            int digit = char_to_digit(number[i]);
            if (digit >= base) {
                return false;
            }
        } catch (...) {
            return false;
        }
    }

    return true;
}

std::string Base::to_upper_case(const std::string& str) {
    std::string result = str;
    std::ranges::transform(result, result.begin(), ::toupper);
    return result;
}

} // namespace imeth
