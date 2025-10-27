#pragma once
#include <string>

namespace imeth {
class Hexadecimal {
public:
    // Conversion
    static std::string fromDecimal(int decimal);
    static int toDecimal(const std::string& hex);

    // Arithmetic operations
    static std::string add(const std::string& a, const std::string& b);
    static std::string subtract(const std::string& a, const std::string& b);
    static std::string multiply(const std::string& a, const std::string& b);

    // Utility
    static bool isValid(const std::string& hex);
    static std::string toUpperCase(const std::string& hex);
    static std::string toLowerCase(const std::string& hex);
    static std::string padLeft(const std::string& hex, size_t length);

private:
    static int charToDigit(char c);
    static char digitToChar(int digit);
};
} // namespace imeth
