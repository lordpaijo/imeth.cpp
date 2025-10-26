#include "../include/imeth/shape/2D.hpp"
#include <cmath>

namespace shape_2d {
double Circle::area() const {
    return M_PI * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius_;
}

double Rectangle::area() const {
    return width_ * height_;
}

double Rectangle::perimeter() const {
    return 2 * (width_ + height_);
}

double Triangle::area() const {
    return 0.5 * base_ * height_;
}

double Triangle::perimeter() const {
    double side = std::sqrt((base_ / 2) * (base_ / 2) + height_ * height_);
    return base_ + 2 * side;
}

double Square::area() const {
    return side_ * side_;
}

double Square::perimeter() const {
    return 4 * side_;
}

double Pentagon::area() const {
    return 0.25 * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * side_ * side_;
}

double Pentagon::perimeter() const {
    return 5 * side_;
}

double Hexagon::area() const {
    return (3 * std::sqrt(3) / 2) * side_ * side_;
}

double Hexagon::perimeter() const {
    return 6 * side_;
}

double Octagon::area() const {
    return 2 * (1 + std::sqrt(2)) * side_ * side_;
}

double Octagon::perimeter() const {
    return 8 * side_;
}
} // namespace shape_2d
