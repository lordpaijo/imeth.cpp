#pragma once
#include <string>

namespace imeth {
class Base {
public:
    // Convert FROM decimal TO any base (2-36)
    static std::string decimalToBinary(int decimal);
    static std::string decimalToTrinary(int decimal);
    static std::string decimalToOctal(int decimal);
    static std::string decimalToHexadecimal(int decimal);
    static std::string decimalToBase(int decimal, int base);

    // Convert FROM any base TO decimal
    static int binaryToDecimal(const std::string& binary);
    static int trinaryToDecimal(const std::string& trinary);
    static int octalToDecimal(const std::string& octal);
    static int hexadecimalToDecimal(const std::string& hex);
    static int baseToDecimal(const std::string& number, int base);

    // Direct conversion between bases (goes through decimal)
    static std::string convert(const std::string& number, int fromBase, int toBase);

    // Arithmetic operations in different bases
    static std::string addInBase(const std::string& num1, const std::string& num2, int base);
    static std::string subtractInBase(const std::string& num1, const std::string& num2, int base);
    static std::string multiplyInBase(const std::string& num1, const std::string& num2, int base);

    // Utility functions
    static bool isValidInBase(const std::string& number, int base);
    static std::string toUpperCase(const std::string& str);

private:
    static const std::string DIGITS;
    static char digitToChar(int digit);
    static int charToDigit(char c);
};
} // namespace imeth
