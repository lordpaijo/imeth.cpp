#pragma once
#include <string>

namespace imeth {
class Binary {
public:
    // Conversion
    static std::string fromDecimal(int decimal);
    static int toDecimal(const std::string& binary);

    // Arithmetic operations
    static std::string add(const std::string& a, const std::string& b);
    static std::string subtract(const std::string& a, const std::string& b);
    static std::string multiply(const std::string& a, const std::string& b);

    // Bitwise operations
    static std::string bitwiseAND(const std::string& a, const std::string& b);
    static std::string bitwiseOR(const std::string& a, const std::string& b);
    static std::string bitwiseXOR(const std::string& a, const std::string& b);
    static std::string bitwiseNOT(const std::string& binary);
    static std::string leftShift(const std::string& binary, int positions);
    static std::string rightShift(const std::string& binary, int positions);

    // Utility
    static bool isValid(const std::string& binary);
    static std::string padLeft(const std::string& binary, size_t length);
    static int countOnes(const std::string& binary);
    static int countZeros(const std::string& binary);
};
} // namespace imeth
