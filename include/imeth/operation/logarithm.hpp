#pragma once
#include <optional>

namespace imeth {
namespace Logarithm {
   std::optional<double> log(double base, double value);
   std::optional<double> ln(double value);
   std::optional<double> log10(double value);
   std::optional<double> log2(double value);

   std::optional<double> solve_exponential(double base, double value);
   std::optional<double> change_base(double value, double old_base, double new_base);
}; // namespace Logarithm
} // namespace imeth
