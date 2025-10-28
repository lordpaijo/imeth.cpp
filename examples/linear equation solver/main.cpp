#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve: 2x + 4 = 0
    // Solution: x = -2
    auto solution = imeth::LinearAlgebra::solve_1v(2, 4);

    if (solution) {
        std::cout << "Solution: x = " << *solution << "\n";
    } else {
        std::cout << "No solution exists\n";
    }

    // Solve:
    //   2x + 3y = 8
    //   4x - 2y = 0
    // Solution: x = 1, y = 2

    auto solution2 = imeth::LinearAlgebra::solve_2v(
        2, 3, 8,    // First equation coefficients
        4, -2, 0);  // Second equation coefficients

    if (solution2) {
        std::cout << "Solution: x = " << solution2->first
                  << ", y = " << solution2->second << "\n";
    } else {
        std::cout << "No unique solution exists\n";
    }

    return 0;
}
