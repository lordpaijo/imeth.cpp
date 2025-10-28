#include <imeth/base/base.hpp>
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Base Converter ===\n\n";

    std::string input;
    std::cout << "Enter a decimal number: ";
    std::getline(std::cin, input);

    int decimal = std::stoi(input);

    std::cout << "\nDecimal: " << decimal << "\n";
    std::cout << "Binary: " << imeth::Base::decimalToBinary(decimal) << "\n";
    std::cout << "Octal: " << imeth::Base::decimalToOctal(decimal) << "\n";
    std::cout << "Hexadecimal: " << imeth::Base::decimalToHexadecimal(decimal) << "\n";

    return 0;
}
