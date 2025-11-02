#include "../include/imeth/operation/logarithm.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <numbers>

constexpr double LN2 = std::numbers::ln2;
constexpr double LN10 = std::numbers::ln10;

double computeLn(double x) {
  if (x <= 0) return 0;

  int exponent = 0;
  while (x > 1.0) {
    x /= 2.0;
    exponent++;
  }
  while (x < 0.5) {
    x *= 2.0;
    exponent--;
  }

  double z = x - 1.0;
  double result = 0.0;
  double term = z;

  for (int n = 1; n <= 100; n++) {
    result += term / n;
    term *= -z;

    if (imeth::Arithmetic::absolute(term / n) < 1e-15) break;
  }
  return result + exponent * LN2;
}

namespace imeth {

  std::optional<double> Logarithm::log(const double base, const double value) {
    if (value <= 0 || base <= 0 || imeth::Arithmetic::absolute(base - 1.0) < 1e-10) {
      return std::nullopt;
    }
    return computeLn(value) / computeLn(base);
  }

  std::optional<double> Logarithm::ln(const double value) {
    if (value <= 0) {
      return std::nullopt;
    }
    return computeLn(value);
  }

  std::optional<double> Logarithm::log10(const double value) {
    if (value <= 0) {
      return std::nullopt;
    }
    return computeLn(value) / LN10;
  }

  std::optional<double> Logarithm::log2(const double value) {
    if (value <= 0) {
      return std::nullopt;
    }
    return computeLn(value) / LN2;
  }

  std::optional<double> Logarithm::solve_exponential(const double base, const double value) {
    return log(base, value);
  }

  std::optional<double> Logarithm::change_base(const double value, const double old_base, const double new_base) {
    if (value <= 0 || old_base <= 0 || new_base <= 0 ||
        imeth::Arithmetic::absolute(old_base - 1.0) < 1e-10 ||
        imeth::Arithmetic::absolute(new_base - 1.0) < 1e-10) {
      return std::nullopt;
        }

    const double log_old_value = computeLn(value) / computeLn(old_base);
    const double log_old_new = computeLn(new_base) / computeLn(old_base);

    return log_old_value / log_old_new;
  }
} // namespace imeth


// Author's comment: a lot of magic numbers here.