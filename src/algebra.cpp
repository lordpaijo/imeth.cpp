#include "../include/imeth/linear/algebra.hpp"

namespace imeth {

std::optional<double> solve_1v(double a, double b) {
  if (a == 0.0) return std::nullopt;
  return -b / a;
}

std::optional<std::pair<double, double>> solve_2v(
  double a1, double b1, double c1,
  double a2, double b2, double c2
) {
  double new_b1, new_b2, new_c1, new_c2;

  if (a1 == a2) {
    new_b1 = b1;
    new_b2 = b2;
    new_c1 = c1;
    new_c2 = c2;
  } else {
    new_b1 = b1 * a2;
    new_b2 = b2 * a1;
    new_c1 = c1 * a2;
    new_c2 = c2 * a1;
  }

  double b3, c3;
  if (a1 < 0.0 || a2 < 0.0) {
    b3 = new_b1 + new_b2;
    c3 = new_c1 + new_c2;
  } else {
    b3 = new_b1 - new_b2;
    c3 = new_c1 - new_c2;
  }

  if (b3 == 0.0 || a2 == 0.0) return std::nullopt;

  double y = c3 / b3;
  double x = (c2 - (b2 * y)) / a2;

  return std::make_pair(x, y);
}

} // namespace linear
