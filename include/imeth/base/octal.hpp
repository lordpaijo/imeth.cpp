#pragma once
#include <string>

namespace imeth {
namespace Octal {
    // Conversion
    static std::string fromDecimal(int decimal);
    static int toDecimal(const std::string& octal);

    // Arithmetic operations
    static std::string add(const std::string& a, const std::string& b);
    static std::string subtract(const std::string& a, const std::string& b);
    static std::string multiply(const std::string& a, const std::string& b);

    // Utility
    static bool isValid(const std::string& octal);
    static std::string padLeft(const std::string& octal, size_t length);
}; // namespace octal
} // namespace imeth
