#pragma once
#include <string>

namespace imeth {
namespace Binary {
    // Conversion
     std::string from_decimal(int decimal);
     int to_decimal(const std::string& binary);

    // Arithmetic operations
     std::string add(const std::string& a, const std::string& b);
     std::string subtract(const std::string& a, const std::string& b);
     std::string multiply(const std::string& a, const std::string& b);

    // Bitwise operations
     std::string bitwise_AND(const std::string& a, const std::string& b);
     std::string bitwise_OR(const std::string& a, const std::string& b);
     std::string bitwise_XOR(const std::string& a, const std::string& b);
     std::string bitwise_NOT(const std::string& binary);
     std::string left_shift(const std::string& binary, int positions);
     std::string right_shift(const std::string& binary, int positions);

    // Utility
     bool is_valid(const std::string& binary);
     std::string pad_left(const std::string& binary, size_t length);
     int count_ones(const std::string& binary);
     int count_zeros(const std::string& binary);
}; // namespace binary
} // namespace imeth
