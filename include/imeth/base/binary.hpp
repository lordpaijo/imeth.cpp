#pragma once
#include <string>

namespace imeth {
namespace Binary {
    // Conversion
     std::string fromDecimal(int decimal);
     int toDecimal(const std::string& binary);

    // Arithmetic operations
     std::string add(const std::string& a, const std::string& b);
     std::string subtract(const std::string& a, const std::string& b);
     std::string multiply(const std::string& a, const std::string& b);

    // Bitwise operations
     std::string bitwiseAND(const std::string& a, const std::string& b);
     std::string bitwiseOR(const std::string& a, const std::string& b);
     std::string bitwiseXOR(const std::string& a, const std::string& b);
     std::string bitwiseNOT(const std::string& binary);
     std::string leftShift(const std::string& binary, int positions);
     std::string rightShift(const std::string& binary, int positions);

    // Utility
     bool isValid(const std::string& binary);
     std::string padLeft(const std::string& binary, size_t length);
     int countOnes(const std::string& binary);
     int countZeros(const std::string& binary);
}; // namespace binary
} // namespace imeth
