#include <imeth/operation/arithmetic.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::cout << "=== Data Statistics Calculator ===\n\n";

    // Get user input
    std::cout << "Enter numbers separated by spaces: ";
    std::string line;
    std::getline(std::cin, line);

    // Parse input into vector using C++20 ranges
    std::vector<double> data;
    std::istringstream iss(line);
    double num;
    while (iss >> num) {
        data.push_back(num);
    }

    if (data.empty()) {
        std::cout << "No data entered!\n";
        return 1;
    }

    // Calculate statistics using imeth
    double avg = imeth::Arithmetic::average(data);
    double total = imeth::Arithmetic::sum(data);
    double min = imeth::Arithmetic::minimum(data);
    double max = imeth::Arithmetic::maximum(data);
    double med = imeth::Arithmetic::median(data);
    double rng = imeth::Arithmetic::range(data);

    // Display original data
    std::cout << "\n--- Original Data ---\n";
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Sort data using STL C++20 (ascending)
    std::ranges::sort(data);

    std::cout << "\n--- Sorted Data (Ascending) ---\n";
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Display statistics
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Statistics ---\n";
    std::cout << "Count: " << data.size() << "\n";
    std::cout << "Sum: " << total << "\n";
    std::cout << "Average: " << avg << "\n";
    std::cout << "Median: " << med << "\n";
    std::cout << "Minimum: " << min << "\n";
    std::cout << "Maximum: " << max << "\n";
    std::cout << "Range: " << rng << "\n";

    // Filter values above average using C++20 ranges
    auto above_avg = data | std::views::filter([avg](double x) { return x > avg; });

    std::cout << "\n--- Values Above Average ---\n";
    for (const auto& val : above_avg) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Count even and odd integers using C++20 ranges
    auto even_count = std::ranges::count_if(data, [](double x) {
        return static_cast<int>(x) == x && imeth::Arithmetic::isEven(static_cast<int>(x));
    });

    std::cout << "\n--- Additional Info ---\n";
    std::cout << "Even integers: " << even_count << "\n";

    return 0;
}
