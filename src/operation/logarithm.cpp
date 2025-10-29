#include "../include/imeth/operation/logarithm.hpp"
#include <cmath>

namespace imeth {

std::optional<double> Logarithm::log(double base, double value) {
  if (value <= 0 || base <= 0 || std::abs(base - 1.0) < 1e-10) {
    return std::nullopt;
  }
  return std::log(value) / std::log(base);
}

std::optional<double> Logarithm::ln(double value) {
  if (value <= 0) {
    return std::nullopt;
  }
  return std::log(value);
}

std::optional<double> Logarithm::log10(double value) {
  if (value <= 0) {
    return std::nullopt;
  }
  return std::log10(value);
}

std::optional<double> Logarithm::log2(double value) {
  if (value <= 0) {
    return std::nullopt;
  }
  return std::log2(value);
}

std::optional<double> Logarithm::solve_exponential(double base, double value) {
  return log(base, value);
}

std::optional<double> Logarithm::change_base(double value, double old_base, double new_base) {
  // Validate inputs
  if (value <= 0 || old_base <= 0 || new_base <= 0 ||
      std::abs(old_base - 1.0) < 1e-10 || std::abs(new_base - 1.0) < 1e-10) {
    return std::nullopt;
  }
  double log_old_value = std::log(value) / std::log(old_base);
  double log_old_new = std::log(new_base) / std::log(old_base);

  return log_old_value / log_old_new;
}

} // namespace imeth
