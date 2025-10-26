#include <iostream>
#include <imeth/shape/2D.hpp>
#include <imeth/shape/3D.hpp>
#include <imeth/linear/linear.hpp>

int main() {
    shape_2d::Circle circle(5);
    shape_2d::Square square(4);
    shape_3d::Sphere sphere(3);
    shape_3d::Cube cube(2);

    std::cout << "=== SHAPE TESTS ===\n";
    std::cout << "Circle area: " << circle.area() << ", perimeter: " << circle.perimeter() << "\n";
    std::cout << "Square area: " << square.area() << ", perimeter: " << square.perimeter() << "\n";
    std::cout << "Sphere area: " << sphere.area() << ", volume: " << sphere.volume() << "\n";
    std::cout << "Cube area: " << cube.area() << ", volume: " << cube.volume() << "\n\n";

    std::cout << "=== LINEAR EQUATION TESTS ===\n";

    auto x1 = LinearEquation::solve_1v(2, 4);
    if (x1)
        std::cout << "SPL 1 Variable: x = " << *x1 << "\n";
    else
        std::cout << "SPL 1 Variable: No solution\n";

    auto xy = LinearEquation::solve_2v(2, 3, 8, 4, -2, 0);
    if (xy)
        std::cout << "SPL 2 Variables: x = " << xy->first << ", y = " << xy->second << "\n";
    else
        std::cout << "SPL 2 Variables: No solution\n";
}

// thank you gpt lmao
