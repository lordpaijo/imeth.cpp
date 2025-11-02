#pragma once
#include <optional>
#include <utility>
#include <variant>

namespace imeth {
namespace LinearAlgebra {
   std::optional<double> solve_1v(double a, double b);

   std::optional<std::pair<double, double>> solve_2v(
    double a1, double b1, double c1,
    double a2, double b2, double c2
  );
}; // namespace LinearAlgebra
namespace QuadraticEquation {
  using Solution = std::variant<std::monostate, double, std::pair<double, double>>;
   Solution solve(double a, double b, double c);
}; // namespace QuadraticEquation
} // namespace imeth
