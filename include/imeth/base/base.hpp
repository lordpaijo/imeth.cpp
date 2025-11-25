#pragma once
#include <string>

namespace imeth {
class Base {
public:
    // Convert FROM decimal TO any base (2-36)
    static std::string decimal_to_binary(int decimal);
    static std::string decimal_to_trinary(int decimal);
    static std::string decimal_to_octal(int decimal);
    static std::string decimal_to_hexadecimal(int decimal);
    static std::string decimal_to_base(int decimal, int base);

    // Convert FROM any base TO decimal
    static int binary_to_decimal(const std::string& binary);
    static int trinary_to_decimal(const std::string& trinary);
    static int octal_to_decimal(const std::string& octal);
    static int hexadecimal_to_decimal(const std::string& hex);
    static int base_to_decimal(const std::string& number, int base);

    // Direct conversion between bases (goes through decimal)
    static std::string convert(const std::string& number, int fromBase, int toBase);

    // Arithmetic operations in different bases
    static std::string add_in_base(const std::string& num1, const std::string& num2, int base);
    static std::string subtract_in_base(const std::string& num1, const std::string& num2, int base);
    static std::string multiply_in_base(const std::string& num1, const std::string& num2, int base);

    // Utility functions
    static bool is_valid_in_base(const std::string& number, int base);
    static std::string to_upper_case(const std::string& str);

private:
    static const std::string DIGITS;
    static char digit_to_char(int digit);
    static int char_to_digit(char c);
};
} // namespace imeth
