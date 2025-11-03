#include "../include/imeth/geometry/3D.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <cmath>
#include <numbers>

namespace imeth {

Sphere::Sphere(const double radius) : radius_(radius) {}

double Sphere::area() const {
    return 4 * std::numbers::pi * radius_ * radius_;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * std::numbers::pi * radius_ * radius_ * radius_;
}

Cube::Cube(const double side) : side_(side) {}

double Cube::area() const {
    return 6 * side_ * side_;
}

double Cube::volume() const {
    return side_ * side_ * side_;
}

Cylinder::Cylinder(const double radius, const double height)
    : radius_(radius), height_(height) {}

double Cylinder::area() const {
    return 2 * std::numbers::pi * radius_ * (radius_ + height_);
}

double Cylinder::volume() const {
    return std::numbers::pi * radius_ * radius_ * height_;
}

Cone::Cone(const double radius, const double height)
    : radius_(radius), height_(height) {}

double Cone::area() const {
    double slant_height = imeth::Arithmetic::squareRoot(radius_ * radius_ + height_ * height_);
    return std::numbers::pi * radius_ * (radius_ + slant_height);
}

double Cone::volume() const {
    return (1.0 / 3.0) * std::numbers::pi * radius_ * radius_ * height_;
}

Torus::Torus(const double major_radius, const double minor_radius)
    : major_radius_(major_radius), minor_radius_(minor_radius) {}

double Torus::area() const {
    return 4 * std::numbers::pi * std::numbers::pi * major_radius_ * minor_radius_;
}

double Torus::volume() const {
    return 2 * std::numbers::pi * std::numbers::pi * major_radius_ * minor_radius_ * minor_radius_;
}

} // namespace imeth
