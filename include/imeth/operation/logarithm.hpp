#pragma once
#include <optional>

namespace imeth {
class Logarithm {
public:
  static std::optional<double> log(double base, double value);
  static std::optional<double> ln(double value);
  static std::optional<double> log10(double value);
  static std::optional<double> log2(double value);

  static std::optional<double> solve_exponential(double base, double value);
  static std::optional<double> change_base(double value, double old_base, double new_base);
};
} // namespace imeth
