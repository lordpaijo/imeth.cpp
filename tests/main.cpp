#include <iostream>
#include <imeth/shape/2D.hpp>
#include <imeth/shape/3D.hpp>
#include <imeth/linear/linear.hpp>

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

    auto x1 = imeth::solve_1v(2, 4);
    if (x1)
        std::cout << "Equation 1 Variable: x = " << *x1 << "\n";
    else
        std::cout << "Equation 1 Variable: No solution\n";

    auto xy = imeth::solve_2v(2, 3, 8, 4, -2, 0);
    if (xy)
        std::cout << "Equation 2 Variables: x = " << xy->first << ", y = " << xy->second << "\n";
    else
        std::cout << "Equation 2 Variables: No solution\n";
}

// thank you gpt lmao
