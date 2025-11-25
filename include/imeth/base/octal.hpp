#pragma once
#include <string>

namespace imeth {
namespace Octal {
    // Conversion
    static std::string from_decimal(int decimal);
    static int to_decimal(const std::string& octal);

    // Arithmetic operations
    static std::string add(const std::string& a, const std::string& b);
    static std::string subtract(const std::string& a, const std::string& b);
    static std::string multiply(const std::string& a, const std::string& b);

    // Utility
    static bool is_valid(const std::string& octal);
    static std::string pad_left(const std::string& octal, size_t length);
}; // namespace octal
} // namespace imeth
