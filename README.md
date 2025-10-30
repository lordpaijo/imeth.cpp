# imeth

**I + METH** – Because I'm high on math equations like a guy high on meth.

A lightweight C++ math library for exploring computational mathematics while testing the limits of the author's C++ skills (and sanity).

## Features

- **Arithmetic Operations**: Basic arithmetic calculations
- **Linear Algebra**: Equation solving, matrix operations, and more
- **Shape Calculations**: 2D and 3D geometric operations
- **Base Conversions and Operations**: Convert and operate on numbers between different bases
- **Modular Design**: Clean, organized API with namespace separation
- **Simple API**: Clean interfaces for complex math

## Installation

### Clone the Repository

```sh
git clone https://github.com/lordpaijo/imeth.cpp.git imeth
cd imeth
```

### Build and Install with CMake

#### Linux/MacOS
```sh
mkdir build && cd build
cmake ..
make -j
sudo make install
```

This will install:
- Library: `/usr/local/lib/libimeth.a`
- Headers: `/usr/local/include/imeth/`
- CMake config: `/usr/local/lib/cmake/imeth/`

#### Windows
Using Visual Studio:
```sh
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
cmake --install . --config Release
```
Or using MinGW:
```sh
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j
mingw32-make install
```

## Usage

### Using with CMake (Recommended)

In your project's `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

# Find the installed imeth library
find_package(imeth REQUIRED)

add_executable(my_app main.cpp)

# Link against imeth
target_link_libraries(my_app PRIVATE imeth::imeth)
```

Then build:
```sh
cmake -B build
cmake --build build
```

### Using with Compiler Directly

After installation, compile your code with:

```sh
# Using g++
g++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program

# Using clang++
clang++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program
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
    auto solution = imeth::LinearAlgebra::solve_1v(2, 4);

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

### Shape Calculations

Calculate properties of geometric shapes:

```cpp
#include <imeth/geometry/2D.hpp>
#include <imeth/geometry/3D.hpp>
#include <iostream>

int main() {
    // 2D shapes
    imeth::Circle circle(5.0);
    std::cout << "Circle area: " << circle.area() << "\n";
    std::cout << "Circle perimeter: " << circle.perimeter() << "\n";

    // 3D shapes
    imeth::Sphere sphere(5.0);
    std::cout << "Sphere surface area: " << sphere.area() << "\n";
    std::cout << "Sphere volume: " << sphere.volume() << "\n";

    return 0;
}
```

## API Reference

Imeth is a modular library divided into namespaces and classes, which I prefer to call _categories_. Each *category* provides a set of functionalities related to a specific area of mathematics. Here's a simple table of the categories available in Imeth:

| Category | Description |
| --- | --- |
| `<imeth/linear>` | Linear equations and operations |
| `<imeth/operation>` | Bunch of general mathematical operations |
| `<imeth/geometry>` | Geometric shape calculations |
| `<imeth/base>` | Base conversions and operations |

Categories are there to represent `headers` fitting their functionalities. Each category is responsible for every `header` placed within its namespace. I'd like to call these `headers` as *chapters* since a category can consist of multiple chapters. You can see the usage of Imeth, its categories, and its chapters from the given examples [above](https://github.com/lordpaijo/imeth.cpp/blob/main/README.md#quick-start).

A clearer sight might look like this:
```cpp
#include <imeth/linear/algebra.hpp>             // Calling imeth's chapter algebra from the category linear
#include <imeth/linear/matrix.hpp>              // Calling imeth's chapter matrix from the category linear
#include <imeth/operation/arithmetic.hpp>       // Calling imeth's chapter arithmetic from the category operation
#include <imeth/geometry/2D.hpp>                // Calling imeth's chapter 2D from the category geometry
#include <imeth/geometry/3D.hpp>                // Calling imeth's chapter 3D from the category geometry
#include <imeth/base/base.hpp>                  // Calling imeth's chapter base from the category base
```

The library is designed for maximum modularity – include only what you need.

## Contributing

Contributions are welcome! If you're also high on math (or just want to help), feel free to:

- Submit pull requests
- Report issues
- Suggest new features
- Improve documentation

The project is open to all mathematically inclined minds.

## License

See the [LICENSE](https://github.com/lordpaijo/imeth.cpp/blob/main/LICENSE) file for details.

## Author's Note

This library is a personal exploration of C++ and computational mathematics. While the name is tongue-in-cheek, the math is serious. Expect active development as more features are added over time.

---

*Remember: Stay high on math, not meth.*
