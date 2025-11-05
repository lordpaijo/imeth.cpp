#pragma once

namespace imeth {
class Shape2D {
public:
    Shape2D() = default;
    virtual ~Shape2D() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle final : public Shape2D {
public:
    Circle(const double radius) : radius_(radius) {}
    ~Circle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double radius_;
};

class Rectangle final : public Shape2D {
public:
    Rectangle(const double width, const double height) : width_(width), height_(height) {}
    ~Rectangle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double width_;
    double height_;
};

class Triangle final : public Shape2D {
public:
    Triangle(const double base, const double height) : base_(base), height_(height) {}
    ~Triangle() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double base_;
    double height_;
};

class Square final : public Shape2D {
public:
    explicit Square(const double side) : side_(side) {}
    ~Square() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Pentagon final : public Shape2D {
public:
    explicit Pentagon(const double side) : side_(side) {}
    ~Pentagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Hexagon final : public Shape2D {
public:
    explicit Hexagon(const double side) : side_(side) {}
    ~Hexagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};

class Octagon final : public Shape2D {
public:
    explicit Octagon(const double side) : side_(side) {}
    ~Octagon() override = default;

    double area() const override;
    double perimeter() const override;

private:
    double side_;
};
}
