# imeth

**I + METH** – Because I'm high on math equations like a guy high on meth.

A lightweight C++ math library for exploring computational mathematics while testing the limits of the author's C++ skills (and sanity).

## Features

- **Arithmetic Operations**: Basic arithmetic calculations
- **Linear Algebra**: Equation solving, matrix operations, and more
- **Shape Calculations**: 2D and 3D geometric operations
- **Base Conversions and Operations**: Convert and operate on numbers between different bases
- **Modular Design**: Clean, organized API with namespace separation

## Quick Start

### Installation
```sh
git clone https://github.com/lordpaijo/imeth.cpp.git imeth
cd imeth
mkdir build && cd build
cmake ..
make -j
sudo make install
```

### Basic Usage
```cpp
#include <imeth/operation/arithmetic.hpp>
#include <imeth/linear/algebra.hpp>

int main() {
    // Simple arithmetic
    double result = imeth::Arithmetic::add(5, 3);

    // Solve linear equation: 2x + 4 = 0
    auto solution = imeth::LinearAlgebra::solve_1v(2, 4);

    return 0;
}
```

## Documentation

For complete installation instructions, API reference, usage examples, and more, visit the [full documentation](https://lordpaijo.github.io/imeth.cpp/).

## Contributing

Contributions are welcome! Submit pull requests, report issues, or suggest new features.

## License

See the [LICENSE](https://github.com/lordpaijo/imeth.cpp/blob/main/LICENSE) file for details.

---

*Remember: Stay high on math, not meth.*
