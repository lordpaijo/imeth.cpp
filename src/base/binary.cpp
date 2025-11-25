#include "../include/imeth/base/binary.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <stdexcept>

namespace imeth {

// Conversion
std::string Binary::from_decimal(int decimal) {
    if (decimal == 0) return "0";

    const bool negative = decimal < 0;
    decimal = imeth::Arithmetic::absolute(decimal);

    std::string result = "";
    while (decimal > 0) {
        result = (decimal % 2 == 0 ? "0" : "1") + result;
        decimal /= 2;
    }

    if (negative) result = "-" + result;
    return result;
}

int Binary::to_decimal(const std::string& binary) {
    if (binary.empty()) {
        throw std::invalid_argument("Empty binary string");
    }

    const bool negative = (binary[0] == '-');
    size_t start = negative ? 1 : 0;

    int result = 0;
    int power = 1;

    for (int i = binary.length() - 1; i >= (int)start; --i) {
        if (binary[i] == '1') {
            result += power;
        } else if (binary[i] != '0') {
            throw std::invalid_argument("Invalid binary digit");
        }
        power *= 2;
    }

    return negative ? -result : result;
}

// Arithmetic operations
std::string Binary::add(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 + dec2);
}

std::string Binary::subtract(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 - dec2);
}

std::string Binary::multiply(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 * dec2);
}

// Bitwise operations
std::string Binary::bitwise_AND(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 & dec2);
}

std::string Binary::bitwise_OR(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 | dec2);
}

std::string Binary::bitwise_XOR(const std::string& a, const std::string& b) {
    const int dec1 = to_decimal(a);
    const int dec2 = to_decimal(b);
    return from_decimal(dec1 ^ dec2);
}

std::string Binary::bitwise_NOT(const std::string& binary) {
    // For simplicity, flip all bits in the string
    std::string result = binary;
    for (char& c : result) {
        if (c == '0') c = '1';
        else if (c == '1') c = '0';
    }
    return result;
}

std::string Binary::left_shift(const std::string& binary, int positions) {
    const int decimal = to_decimal(binary);
    return from_decimal(decimal << positions);
}

std::string Binary::right_shift(const std::string& binary, int positions) {
    int decimal = to_decimal(binary);
    return from_decimal(decimal >> positions);
}

// Utility
bool Binary::is_valid(const std::string& binary) {
    if (binary.empty()) return false;

    size_t start = (binary[0] == '-') ? 1 : 0;
    for (size_t i = start; i < binary.length(); ++i) {
        if (binary[i] != '0' && binary[i] != '1') {
            return false;
        }
    }
    return true;
}

std::string Binary::pad_left(const std::string& binary, size_t length) {
    if (binary.length() >= length) return binary;
    return std::string(length - binary.length(), '0') + binary;
}

int Binary::count_ones(const std::string& binary) {
    int count = 0;
    for (const char c : binary) {
        if (c == '1') count++;
    }
    return count;
}

int Binary::count_zeros(const std::string& binary) {
    int count = 0;
    for (const char c : binary) {
        if (c == '0') count++;
    }
    return count;
}

} // namespace imeth
