# IMETH
Imeth, or I ❤️ meth, is a simple math library written in C++. It's goal is to test author's skills in C++ and to provide a simple library for math operations. And yes, the author is high on meth.
## Installation
### Getting the source
Clone the repository using git:
```sh
$ git clone https://github.com/lordpaijo/imeth.cpp.git imeth
```
### Building the library
Build the library using CMake:
```sh
$ cd imeth
$ mkdir build
$ cd build
$ cmake ..
$ make -j
```
### Installing
Install the library using CMake:
```sh
$ sudo make install
```

## Usage
### API
Currently there has been only shorthand amount of APIs available. Likely it's due to the author being a lazy freak, who's high on meth.
```cpp
#include <imeth/shape/2D.hpp>
#include <imeth/shape/3D.hpp>
#include <imeth/linear/linear.hpp>
```
Imeth itself is just a big chunk of library with tons of modularity. Which you will likely never see it included just by its name (even in the future), since it doesn't have any implementation either. It's just a blob of bunch of headers that you can include in your project.
Unless someone wants to change this by however they want, it's likely that this will stay forever.
### Example
Here's a simple example of the APIs usage:
```cpp
int main() {
    shape_2d::Circle circle(5);
    shape_2d::Square square(4);
    shape_3d::Sphere sphere(3);
    shape_3d::Cube cube(2);

    std::cout << "=== SHAPE TESTS ===\n";
    std::cout << "Circle area: " << circle.area() << ", perimeter: " << circle.perimeter() << "\n";
    std::cout << "Square area: " << square.area() << ", perimeter: " << square.perimeter() << "\n";
    std::cout << "Sphere area: " << sphere.area() << ", volume: " << sphere.volume() << "\n";
    std::cout << "Cube area: " << cube.area() << ", volume: " << cube.volume() << "\n\n";

    std::cout << "=== LINEAR EQUATION TESTS ===\n";

    auto x1 = LinearEquation::solve_1v(2, 4);
    if (x1)
        std::cout << "Equation 1 Variable: x = " << *x1 << "\n";
    else
        std::cout << "Equation 1 Variable: No solution\n";

    auto xy = LinearEquation::solve_2v(2, 3, 8, 4, -2, 0);
    if (xy)
        std::cout << "Equation 2 Variables: x = " << xy->first << ", y = " << xy->second << "\n";
    else
        std::cout << "Equation 2 Variables: No solution\n";
}
```
The author doesn't believe that this is a good example of how to use the library. But the author is not God The Almighty so he just doesn't care about whatever his AI wrote for him.
## Contributing
The game is open for everyone. Any dirty hands and brains can contribute to the project by submitting pull requests or reporting issues. The author knows that he's not the only one who is high on meth, someone else is too...


So please, consider on contributing.
