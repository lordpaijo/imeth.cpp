#pragma once

namespace imeth {
class Shape2D {
public:
    Shape2D() = default;
    virtual ~Shape2D() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle : public Shape2D {
public:
    Circle(double radius) : radius_(radius) {}
    ~Circle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double radius_;
};

class Rectangle : public Shape2D {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    ~Rectangle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double width_;
    double height_;
};

class Triangle : public Shape2D {
public:
    Triangle(double base, double height) : base_(base), height_(height) {}
    ~Triangle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double base_;
    double height_;
};

class Square : public Shape2D {
public:
    Square(double side) : side_(side) {}
    ~Square() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Pentagon : public Shape2D {
public:
    Pentagon(double side) : side_(side) {}
    ~Pentagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Hexagon : public Shape2D {
public:
    Hexagon(double side) : side_(side) {}
    ~Hexagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Octagon : public Shape2D {
public:
    Octagon(double side) : side_(side) {}
    ~Octagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};
}
