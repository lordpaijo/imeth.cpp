#include <iostream>
#include <imeth/geometry/2D.hpp>
#include <imeth/geometry/3D.hpp>
#include <imeth/linear/algebra.hpp>
#include <imeth/linear/matrix.hpp>
#include <imeth/operation/arithmetic.hpp>

int main() {
    imeth::Circle circle(5);
    imeth::Square square(4);
    imeth::Sphere sphere(3);
    imeth::Cube cube(2);

    std::cout << "=== SHAPE TESTS ===\n";
    std::cout << "Circle area: " << circle.area() << ", perimeter: " << circle.perimeter() << "\n";
    std::cout << "Square area: " << square.area() << ", perimeter: " << square.perimeter() << "\n";
    std::cout << "Sphere area: " << sphere.area() << ", volume: " << sphere.volume() << "\n";
    std::cout << "Cube area: " << cube.area() << ", volume: " << cube.volume() << "\n\n";

    std::cout << "=== LINEAR EQUATION TESTS ===\n";

    auto x1 = imeth::LinearAlgebra::solve_1v(2, 4);
    if (x1)
        std::cout << "Equation 1 Variable: x = " << *x1 << "\n";
    else
        std::cout << "Equation 1 Variable: No solution\n";

    auto xy = imeth::LinearAlgebra::solve_2v(2, 3, 8, 4, -2, 0);
    if (xy)
        std::cout << "Equation 2 Variables: x = " << xy->first << ", y = " << xy->second << "\n";
    else
        std::cout << "Equation 2 Variables: No solution\n";

    imeth::Matrix A{{2, 1}, {5, 7}};
    imeth::Vector b{11, 13};

    auto x = imeth::Solver::gaussian_elimination(A, b);

    std::cout << "Solution: ";
    for (size_t i = 0; i < x.size(); ++i)
        std::cout << x[i] << " ";
    std::cout << "\n\n";

    std::cout << "=== ARITHMETIC TESTS ===\n";

    // Basic operations
    std::cout << "10 + 5 = " << imeth::Arithmetic::add(10, 5) << "\n";
    std::cout << "10 * 5 = " << imeth::Arithmetic::multiply(10, 5) << "\n";
    std::cout << "2^5 = " << imeth::Arithmetic::power(2, 5) << "\n";
    std::cout << "Square root of 144 = " << imeth::Arithmetic::squareRoot(144) << "\n\n";

    // Percentages
    std::cout << "25% of 80 = " << imeth::Arithmetic::percentOf(25, 80) << "\n";
    std::cout << "20 is what % of 50? = " << imeth::Arithmetic::whatPercent(20, 50) << "%\n\n";

    // Statistics
    std::vector<double> grades = {85, 90, 78, 92, 88};
    std::cout << "Grades: 85, 90, 78, 92, 88\n";
    std::cout << "Average: " << imeth::Arithmetic::average(grades) << "\n";
    std::cout << "Median: " << imeth::Arithmetic::median(grades) << "\n";
    std::cout << "Highest: " << imeth::Arithmetic::maximum(grades) << "\n";
    std::cout << "Lowest: " << imeth::Arithmetic::minimum(grades) << "\n\n";

    // Number properties
    std::cout << "Is 17 prime? " << (imeth::Arithmetic::isPrime(17) ? "Yes" : "No") << "\n";
    std::cout << "Is 20 even? " << (imeth::Arithmetic::isEven(20) ? "Yes" : "No") << "\n";
    std::cout << "GCD of 48 and 18 = " << imeth::Arithmetic::greatestCommonDivisor(48, 18) << "\n\n";

    // Temperature
    std::cout << "25°C in Fahrenheit = " << imeth::Arithmetic::celsiusToFahrenheit(25) << "°F\n";

    // Quadratic equation
    auto result = imeth::QuadraticEquation::solve(1, -5, 6); // x² - 5x + 6 = 0
    if (std::holds_alternative<std::pair<double, double>>(result)) {
      auto [x1, x2] = std::get<std::pair<double, double>>(result);
      std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
}

// thank you gpt lmao
