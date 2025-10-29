#include <imeth/geometry/2D.hpp>
#include <imeth/geometry/3D.hpp>
#include <iostream>

int main() {
    // 2D shapes
    imeth::Circle circle(5.0);
    std::cout << "Circle area: " << circle.area() << "\n";
    std::cout << "Circle perimeter: " << circle.perimeter() << "\n";

    // 3D shapes
    imeth::Sphere sphere(5.0);
    std::cout << "Sphere surface area: " << sphere.area() << "\n";
    std::cout << "Sphere volume: " << sphere.volume() << "\n";

    return 0;
}
