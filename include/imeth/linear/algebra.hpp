#pragma once
#include <optional>
#include <utility>
#include <variant>

namespace imeth {

class LinearAlgebra {
public:
  static std::optional<double> solve_1v(double a, double b);

  static std::optional<std::pair<double, double>> solve_2v(
    double a1, double b1, double c1,
    double a2, double b2, double c2
  );
}; // class LinearAlgebra

class QuadraticEquation {
public:
  using Solution = std::variant<std::monostate, double, std::pair<double, double>>;
  static Solution solve(double a, double b, double c);
}; // class QuadraticEquation

} // namespace imeth
