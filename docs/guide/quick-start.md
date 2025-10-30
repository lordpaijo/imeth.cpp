# Quick Start

You can start building an app using imeth by including a _category_ and its _chapter_ in your code like this:

```c++
#include <imeth/linear/algebra.hpp>
```

Then start using the methods imported from the header like this:

```c++
int main() {
    // Solve: 2x + 4 = 0
    // Solution: x = -2
    auto solution = imeth::LinearAlgebra::solve_1v(2, 4);

    if (solution) {
        std::cout << "Solution: x = " << *solution << "\n";
    } else {
        std::cout << "No solution exists\n";
    }

    return 0;
}
```

## Example: Solving a System of Linear Equations

Let's make a program to solve linear equation of two variables using imeth:

```c++
#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve:
    //   2x + 3y = 8
    //   4x - 2y = 0
    // Solution: x = 1, y = 2

    auto solution = imeth::LinearAlgebra::solve_2v(2, 3, 8,    // First equation coefficients
                                                   4, -2, 0);  // Second equation coefficients

    if (solution) {
        std::cout << "Solution: x = " << solution->first
                  << ", y = " << solution->second << "\n";
    } else {
        std::cout << "No unique solution exists\n";
    }

    return 0;
}
```

Here, I call the library `imeth`, then the category `linear`, and then the chapter `algebra.hpp`.

What I'm really doing is, I'm importing the methods from the algebra chapter (header file, `algebra.hpp`) from the linear category (`linear/`) of the
imeth library (`imeth/`).
