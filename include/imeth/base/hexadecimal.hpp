#pragma once
#include <string>

namespace imeth {
class Hexadecimal {
public:
    // Conversion
    static std::string from_decimal(int decimal);
    static int to_decimal(const std::string& hex);

    // Arithmetic operations
    static std::string add(const std::string& a, const std::string& b);
    static std::string subtract(const std::string& a, const std::string& b);
    static std::string multiply(const std::string& a, const std::string& b);

    // Utility
    static bool is_valid(const std::string& hex);
    static std::string to_upper_case(const std::string& hex);
    static std::string to_lower_case(const std::string& hex);
    static std::string pad_left(const std::string& hex, size_t length);

private:
    static int char_to_digit(char c);
    static char digit_to_char(int digit);
};
} // namespace imeth
