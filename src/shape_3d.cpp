#include "../include/imeth/shape/3D.hpp"
#include <cmath>

namespace shape_3d {

Sphere::Sphere(double radius) : radius_(radius) {}

double Sphere::area() const {
    return 4 * M_PI * radius_ * radius_;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * radius_ * radius_ * radius_;
}

Cube::Cube(double side) : side_(side) {}

double Cube::area() const {
    return 6 * side_ * side_;
}

double Cube::volume() const {
    return side_ * side_ * side_;
}

Cylinder::Cylinder(double radius, double height)
    : radius_(radius), height_(height) {}

double Cylinder::area() const {
    return 2 * M_PI * radius_ * (radius_ + height_);
}

double Cylinder::volume() const {
    return M_PI * radius_ * radius_ * height_;
}

Cone::Cone(double radius, double height)
    : radius_(radius), height_(height) {}

double Cone::area() const {
    double slant_height = std::sqrt(radius_ * radius_ + height_ * height_);
    return M_PI * radius_ * (radius_ + slant_height);
}

double Cone::volume() const {
    return (1.0 / 3.0) * M_PI * radius_ * radius_ * height_;
}

Torus::Torus(double major_radius, double minor_radius)
    : major_radius_(major_radius), minor_radius_(minor_radius) {}

double Torus::area() const {
    return 4 * M_PI * M_PI * major_radius_ * minor_radius_;
}

double Torus::volume() const {
    return 2 * M_PI * M_PI * major_radius_ * minor_radius_ * minor_radius_;
}

} // namespace shape_3d
