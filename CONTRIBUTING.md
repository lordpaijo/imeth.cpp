# Contributing to imeth

🎉 **First off, thanks for taking the time to contribute!**
This guide will help you get started contributing to the project, whether you’re fixing a bug, adding a new math function, or improving documentation.

---

## 🧮 About the Project

<YourLibraryName> is a modern, header-only (or shared/static) C++ math library focused on **speed**, **correctness**, and **clean design**.
It aims to provide intuitive mathematical utilities built around standard C++20 (or newer) features and best practices.

---

## 🧰 Getting Started

### 1. Fork & Clone

```bash
git clone https://github.com/lordpaijo/imeth.cpp.git imeth
cd imeth
```

### 2. Build

Make sure you have:

* **CMake ≥ 3.15**
* **A C++20/23 compatible compiler**

Then build the project:

```bash
cmake -S . -B build
cmake --build build --config Release
```

To run tests (if available):

```bash
ctest --test-dir build
```

---

## 🧑‍💻 How to Contribute

### 🐛 Reporting Bugs

If you find a bug, please open an issue with:

* A clear title and description
* A minimal code example that reproduces the problem
* Expected vs actual behavior
* Your compiler and platform info

### ✨ Suggesting Features

Got an idea for a new function or optimization? Open an issue labeled **enhancement**.
Please describe:

* The math concept or algorithm
* Any references or papers (if applicable)
* Example usage and expected API design

### 🧩 Adding New Code

1. **Create a new branch**

   ```bash
   git checkout -b feature/your-feature-name
   ```
2. **Follow code style guidelines** (see below)
3. **Add tests** for your new code
4. **Document** your additions
5. **Submit a Pull Request**

---

## 🧷 Code Style Guidelines

* Follow **Modern C++** practices (RAII, `constexpr`, smart pointers, etc.)
* Use **`std::`** facilities over raw C-style constructs
* Prefer **`constexpr`**, **`noexcept`**, and **`[[nodiscard]]`** where applicable
* No dynamic allocations unless justified
* Keep functions small and self-contained
* Use consistent naming:

  * Functions: `snake_case`
  * Types/classes: `PascalCase`
  * Constants: `UPPER_CASE`

> ✏️ **Example**

```cpp
constexpr double add(double a, double b) noexcept {
    return a + b;
}
```

---

## 🧪 Testing

All functions must be covered by unit tests.
We use [Catch2](https://github.com/catchorg/Catch2) (or GoogleTest / doctest — specify yours here).

Example test:

```cpp
TEST_CASE("add() returns correct results") {
    REQUIRE(add(2, 3) == 5);
}
```

Run all tests with:

```bash
ctest --test-dir build
```

---

## 📖 Documentation

* All public APIs should have **Doxygen-style** comments:

```cpp
/// Computes the factorial of a number.
/// @param n Non-negative integer.
/// @return The factorial of n.
constexpr unsigned long long factorial(unsigned int n) noexcept;
```

* Update `README.md` or relevant docs when adding major features.

---

## 🧼 Commit Messages

Use clear, conventional commit messages:

```
feat: add vector dot product function
fix: correct floating-point comparison in sqrt_approx
docs: update math reference links
test: add benchmarks for matrix inverse
```

---

## 🧠 Code Review Checklist

Before submitting your PR:

* [ ] Code compiles with no warnings
* [ ] Tests pass
* [ ] Functions are `constexpr` where possible
* [ ] No unnecessary heap allocations
* [ ] Code is well-commented and documented

---

## 🫱🏼‍🫲🏽 Thank You!

Your contributions make <YourLibraryName> more robust, faster, and more fun to use.
Every math function counts — literally! 😄
