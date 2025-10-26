#pragma once
#include <optional>
#include <utility>

namespace LinearEquation {

std::optional<double> solve_1v(double a, double b);

std::optional<std::pair<double, double>> solve_2v(
  double a1, double b1, double c1,
  double a2, double b2, double c2
);

} // namespace linear
