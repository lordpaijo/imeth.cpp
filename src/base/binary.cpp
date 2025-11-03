#include "../include/imeth/base/binary.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <stdexcept>

namespace imeth {

// Conversion
std::string Binary::fromDecimal(int decimal) {
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

int Binary::toDecimal(const std::string& binary) {
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
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 + dec2);
}

std::string Binary::subtract(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 - dec2);
}

std::string Binary::multiply(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 * dec2);
}

// Bitwise operations
std::string Binary::bitwiseAND(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 & dec2);
}

std::string Binary::bitwiseOR(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 | dec2);
}

std::string Binary::bitwiseXOR(const std::string& a, const std::string& b) {
    const int dec1 = toDecimal(a);
    const int dec2 = toDecimal(b);
    return fromDecimal(dec1 ^ dec2);
}

std::string Binary::bitwiseNOT(const std::string& binary) {
    // For simplicity, flip all bits in the string
    std::string result = binary;
    for (char& c : result) {
        if (c == '0') c = '1';
        else if (c == '1') c = '0';
    }
    return result;
}

std::string Binary::leftShift(const std::string& binary, int positions) {
    const int decimal = toDecimal(binary);
    return fromDecimal(decimal << positions);
}

std::string Binary::rightShift(const std::string& binary, int positions) {
    int decimal = toDecimal(binary);
    return fromDecimal(decimal >> positions);
}

// Utility
bool Binary::isValid(const std::string& binary) {
    if (binary.empty()) return false;

    size_t start = (binary[0] == '-') ? 1 : 0;
    for (size_t i = start; i < binary.length(); ++i) {
        if (binary[i] != '0' && binary[i] != '1') {
            return false;
        }
    }
    return true;
}

std::string Binary::padLeft(const std::string& binary, size_t length) {
    if (binary.length() >= length) return binary;
    return std::string(length - binary.length(), '0') + binary;
}

int Binary::countOnes(const std::string& binary) {
    int count = 0;
    for (const char c : binary) {
        if (c == '1') count++;
    }
    return count;
}

int Binary::countZeros(const std::string& binary) {
    int count = 0;
    for (const char c : binary) {
        if (c == '0') count++;
    }
    return count;
}

} // namespace imeth
