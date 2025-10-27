# IMETH

**I + METH** – Because I'm high on math equations like a guy high on meth.

A lightweight C++ math library for exploring computational mathematics while testing the limits of the author's C++ skills (and sanity).

## Features

- **Arithmetic Operations**: Basic arithmetic calculations
- **Linear Algebra**: Equation solving, matrix operations, and more
- **Shape Calculations**: 2D and 3D geometric operations
- **Base Conversions and Operations**: Convert and operate on numbers between different bases
- **Header-Only Design**: Maximum modularity, minimal overhead
- **Simple API**: Clean interfaces for complex math

## Installation

### Clone the Repository

```sh
git clone https://github.com/lordpaijo/imeth.cpp.git imeth
cd imeth
```

### Build with CMake
#### Linux/MacOS
```sh
mkdir build && cd build
cmake ..
make -j
sudo make install
```

#### Windows
Using Visual Studio:
```sh
mkdir build
cd build
cmake .. -G "Visual Studio 20 2022"
cmake --build . --config Release
cmake --install . --config Release
```
Or using mingw:
```sh
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j
mingw32-make install
```

### Manual Installation (Header-Only)
Since imeth is header-only, you can also manually copy the `include/imeth` directory to your project's include path:
```sh
cp -r include/imeth /path/to/your/project/include
```
Then include the library path in your compiler flags:
```sh
g++ -I/path/to/your/project/include your_code.cpp -o your_program
# or with clang++
clang++ -I/path/to/your/project/include your_code.cpp -o your_program
```

## Quick Start

### Basic Arithmetic Calculator
Here's a simple arithmetic calculator implementation using `<imeth/operation/arithmetic.hpp>`:
```cpp
#include <imeth/operation/arithmetic.hpp>
#include <iostream>

int main() {
    double a, b;
    char op;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter operation (e.g., 5 + 3): ";
    std::cin >> a >> op >> b;

    double result;
    switch(op) {
        case '+':
            result = imeth::Arithmetic::add(a, b);
            break;
        case '-':
            result = imeth::Arithmetic::subtract(a, b);
            break;
        case '*':
            result = imeth::Arithmetic::multiply(a, b);
            break;
        case '/':
            result = imeth::Arithmetic::divide(a, b);
            break;
        default:
            std::cout << "Invalid operator!\n";
            return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
```

### Linear Equation Solver (1 Variable)

Here's a simple example to solve equations of the form: `ax + b = 0` using `<imeth/linear/algebra.hpp>`:

```cpp
#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve: 2x + 4 = 0
    // Solution: x = -2
    auto solution = imeth::solve_1v(2, 4);

    if (solution) {
        std::cout << "Solution: x = " << *solution << "\n";
    } else {
        std::cout << "No solution exists\n";
    }

    return 0;
}
```

### Linear Equation Solver (2 Variables)

Here's a simple example to solve systems of the form
```
a₁x + b₁y = c₁
a₂x + b₂y = c₂
```
using `<imeth/linear/algebra.hpp>`:

```cpp
#include <imeth/linear/algebra.hpp>
#include <iostream>

int main() {
    // Solve:
    //   2x + 3y = 8
    //   4x - 2y = 0
    // Solution: x = 1, y = 2

    auto solution = imeth::solve_2v(2, 3, 8,    // First equation coefficients
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

## API Reference

Imeth is a modular, header-only library divided into namespaces:

```cpp
#include <imeth/linear/*.hpp>
#include <imeth/operation/*.hpp>
#include <imeth/shape/*.hpp>
#include <imeth/base/*.hpp>
```

The library is designed for maximum modularity – include only what you need.

## Contributing

Contributions are welcome! If you're also high on math (or just want to help), feel free to:

- Submit pull requests
- Report issues
- Suggest new features
- Improve documentation

The project is open to all mathematically-inclined minds.

## License

See the [LICENSE](https://github.com/lordpaijo/imeth.cpp/blob/main/LICENSE) file for details.

## Author's Note

This library is a personal exploration of C++ and computational mathematics. While the name is tongue-in-cheek, the math is serious. Expect active development as more features are added over time.

---

*Remember: Stay high on math, not meth.*
