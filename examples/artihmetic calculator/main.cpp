#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    double a, b;
    char op;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter operation (e.g., 5 + 3): ";
    std::cin >> a >> op >> b;

    double result;
    switch(op) {
        case '+':
            result = imeth::Arithmetic::add(a, b);
            break;
        case '-':
            result = imeth::Arithmetic::subtract(a, b);
            break;
        case '*':
            result = imeth::Arithmetic::multiply(a, b);
            break;
        case '/':
            result = imeth::Arithmetic::divide(a, b);
            break;
        default:
            std::cout << "Invalid operator!\n";
            return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
