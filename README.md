<div align="center">
<h1>imeth</h1>
<div>
    <a href="https://github.com/lordpaijo/imeth.cpp/actions/workflows/cmake-multi-platform.yml">
      <img src="https://img.shields.io/github/actions/workflow/status/lordpaijo/imeth.cpp/cmake-multi-platform.yml?branch=main&style=flat-square&logo=windows&label=windows" alt="windows-ci" />
    </a>
    <a href="https://github.com/lordpaijo/imeth.cpp/actions/workflows/cmake-multi-platform.yml">
      <img src="https://img.shields.io/github/actions/workflow/status/lordpaijo/imeth.cpp/cmake-multi-platform.yml?branch=main&style=flat-square&logo=linux&label=linux" alt="linux-ci" />
    </a>
    <a href="https://github.com/lordpaijo/imeth.cpp/actions/workflows/cmake-multi-platform.yml">
      <img src="https://img.shields.io/github/actions/workflow/status/lordpaijo/imeth.cpp/cmake-multi-platform.yml?branch=main&style=flat-square&logo=apple&label=macOS" alt="macos-ci" />
    </a>
    <a href="https://github.com/lordpaijo/imeth.cpp/releases">
      <img src="https://img.shields.io/github/release/lordpaijo/imeth.cpp.svg?style=flat-square" alt="Github All Releases" />
    </a>
</div>


<b>A lightweight C++ math library for exploring computational mathematics while testing the limits of the author's C++ skills (and sanity).</b><br/>
<i>**I + METH** – Because I'm high on math equations like a guy high on meth.</i><br/>

</div>

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
