//
// Created by paijogoesblue on 11/5/25.
//

#include "../include/imeth/operation/combinatoric.hpp"
#include "../include/imeth/operation/arithmetic.hpp"
#include <algorithm>
#include <numeric>

namespace imeth::combinatorics {
    uint64_t factorial(uint64_t n) {
        if (n > 20) {
            throw std::overflow_error("Factorial overflow: n too large");
        }
        uint64_t result = 1;
        for (uint64_t i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    uint64_t combination(uint64_t n, uint64_t k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;

        uint64_t result = 1;
        for (uint64_t i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    uint64_t permutation(uint64_t n, uint64_t r) {
        if (r > n) return 0;
        uint64_t result = 1;
        for (uint64_t i = 0; i < r; ++i) {
            result *= (n - i);
        }
        return result;
    }

    uint64_t combination_with_repetition(const uint64_t n, const uint64_t r) {
        return combination(n + r - 1, r);
    }

    uint64_t permutation_with_repetition(const uint64_t n, const std::vector<uint64_t>& repetitions) {
        uint64_t sum = std::accumulate(repetitions.begin(), repetitions.end(), 0ULL);
        if (sum != n) {
            throw std::invalid_argument("Sum of repetitions must equal n");
        }

        uint64_t result = factorial(n);
        for (uint64_t rep : repetitions) {
            result /= factorial(rep);
        }
        return result;
    }

    uint64_t permutation_full_repetition(const uint64_t n, const uint64_t r) {
        uint64_t result = 1;
        for (uint64_t i = 0; i < r; ++i) {
            result *= n;
        }
        return result;
    }

    namespace probability {

        // Dice implementation
        Dice::Dice() : numbers{1, 2, 3, 4, 5, 6} {}

        double Dice::probability_of_number(const int target) const {
            for (const int num : numbers) {
                if (num == target) return 1.0 / 6.0;
            }
            return 0.0;
        }

        double Dice::probability_of_even() {
            return 3.0 / 6.0;
        }

        double Dice::probability_of_odd() {
            return 3.0 / 6.0;
        }

        double Dice::probability_greater_than(const int limit) const {
            int count = 0;
            for (int num : numbers) {
                if (num > limit) ++count;
            }
            return static_cast<double>(count) / 6.0;
        }

        double Dice::probability_less_than(const int limit) const {
            int count = 0;
            for (int num : numbers) {
                if (num < limit) ++count;
            }
            return static_cast<double>(count) / 6.0;
        }

        double Dice::probability_between(const int min, const int max) const {
            int count = 0;
            for (int num : numbers) {
                if (num >= min && num <= max) ++count;
            }
            return static_cast<double>(count) / 6.0;
        }

        // Coin implementation
        Coin::Coin() : sides{'H', 'T'} {}

        double Coin::probability_of(char target) const {
            for (char side : sides) {
                if (side == target) return 0.5;
            }
            return 0.0;
        }

        double Coin::probability_consecutive(const uint32_t times) const {
            return Arithmetic::power(0.5, times);
        }

        double Coin::probability_at_least_one(const uint32_t times) const {
            return 1.0 - Arithmetic::power(0.5, times);
        }

        double Coin::probability_exactly_k(const uint32_t k, uint32_t n) const {
            return combination(n, k) * Arithmetic::power(0.5, n);
        }

        // MarbleBag implementation
        MarbleBag::MarbleBag(const uint32_t red_count, const uint32_t white_count)
            : red(red_count), white(white_count) {}

        uint32_t MarbleBag::total() const {
            return red + white;
        }

        double MarbleBag::probability_single(const char color) const {
            uint32_t t = total();
            if (t == 0) return 0.0;

            if (color == 'R' || color == 'r') {
                return static_cast<double>(red) / t;
            } else if (color == 'W' || color == 'w') {
                return static_cast<double>(white) / t;
            }
            return 0.0;
        }

        double MarbleBag::probability_two_consecutive(const char first, const char second) const {
            uint32_t t = total();
            if (t < 2) return 0.0;

            double p1 = probability_single(first);

            uint32_t remaining_first = (first == 'R' || first == 'r') ? red - 1 : white - 1;
            uint32_t remaining_second = (second == 'R' || second == 'r') ? red : white;
            if (first == second) remaining_second--;

            double p2 = static_cast<double>(remaining_second) / (t - 1);

            return p1 * p2;
        }

        double MarbleBag::probability_two_with_replacement(const char first, const char second) const {
            return probability_single(first) * probability_single(second);
        }

        double MarbleBag::probability_all_same(const char color, const uint32_t draws) const {
            uint32_t color_count = (color == 'R' || color == 'r') ? red : white;
            uint32_t t = total();

            if (draws > color_count) return 0.0;

            double prob = 1.0;
            for (uint32_t i = 0; i < draws; ++i) {
                prob *= static_cast<double>(color_count - i) / (t - i);
            }
            return prob;
        }

        // Deck implementation
        Deck::Deck() : total_cards(52), hearts(13), diamonds(13), clubs(13), spades(13) {}

        double Deck::probability_suit(char suit) {
            return 13.0 / 52.0;
        }

        double Deck::probability_red() {
            return 26.0 / 52.0;
        }

        double Deck::probability_black() {
            return 26.0 / 52.0;
        }

        double Deck::probability_face_card() {
            return 12.0 / 52.0; // 3 face cards per suit * 4 suits
        }

        double Deck::probability_number_card() {
            return 36.0 / 52.0; // 9 number cards per suit * 4 suits
        }

        namespace functions {
            double binomial_probability(const uint32_t n, const uint32_t k, const double p) {
                return combination(n, k) * Arithmetic::power(p, k) * Arithmetic::power(1.0 - p, n - k);
            }

            double geometric_probability(const uint32_t k, const double p) {
                return Arithmetic::power(1.0 - p, k - 1) * p;
            }

            double hypergeometric_probability(const uint32_t N, const uint32_t K, const uint32_t n, const uint32_t k) {
                return (static_cast<double>(combination(K, k)) * combination(N - K, n - k))
                       / combination(N, n);
            }

            double complement_probability(const double p) {
                return 1.0 - p;
            }

            double union_probability(const double p1, const double p2, const double p_both) {
                return p1 + p2 - p_both;
            }

            double intersection_probability(const double p1, const double p2_given_1) {
                return p1 * p2_given_1;
            }
        }
    }

    namespace counting {
        uint64_t derangement(const uint64_t n) {
            if (n == 0) return 1;
            if (n == 1) return 0;

            uint64_t d0 = 1, d1 = 0;
            for (uint64_t i = 2; i <= n; ++i) {
                uint64_t d_new = (i - 1) * (d0 + d1);
                d0 = d1;
                d1 = d_new;
            }
            return d1;
        }

        uint64_t stirling_second_kind(const uint64_t n, const uint64_t k) {
            if (n == 0 && k == 0) return 1;
            if (n == 0 || k == 0) return 0;
            if (k > n) return 0;
            if (k == 1 || k == n) return 1;

            std::vector<std::vector<uint64_t>> dp(n + 1, std::vector<uint64_t>(k + 1, 0));
            dp[0][0] = 1;

            for (uint64_t i = 1; i <= n; ++i) {
                for (uint64_t j = 1; j <= k && j <= i; ++j) {
                    dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            return dp[n][k];
        }

        uint64_t catalan_number(const uint64_t n) {
            if (n <= 1) return 1;
            return combination(2 * n, n) / (n + 1);
        }

        uint64_t bell_number(const uint64_t n) {
            std::vector<std::vector<uint64_t>> bell(n + 1, std::vector<uint64_t>(n + 1, 0));
            bell[0][0] = 1;

            for (uint64_t i = 1; i <= n; ++i) {
                bell[i][0] = bell[i - 1][i - 1];
                for (uint64_t j = 1; j <= i; ++j) {
                    bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
                }
            }
            return bell[n][0];
        }

        std::vector<std::vector<uint64_t>> pascal_triangle(const uint32_t rows) {
            std::vector<std::vector<uint64_t>> triangle(rows);

            for (uint32_t i = 0; i < rows; ++i) {
                triangle[i].resize(i + 1);
                triangle[i][0] = triangle[i][i] = 1;

                for (uint32_t j = 1; j < i; ++j) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
            }
            return triangle;
        }
    }

    namespace sets {
        template<typename T>
        std::vector<std::vector<T>> generate_combinations(const std::vector<T>& items, uint32_t k) {
            std::vector<std::vector<T>> result;
            uint32_t n = items.size();

            if (k > n || k == 0) return result;

            std::vector<bool> selector(n, false);
            std::fill(selector.begin(), selector.begin() + k, true);

            do {
                std::vector<T> combination;
                for (uint32_t i = 0; i < n; ++i) {
                    if (selector[i]) {
                        combination.push_back(items[i]);
                    }
                }
                result.push_back(combination);
            } while (std::prev_permutation(selector.begin(), selector.end()));

            return result;
        }

        template<typename T>
        std::vector<std::vector<T>> generate_permutations(const std::vector<T>& items) {
            std::vector<std::vector<T>> result;
            std::vector<T> perm = items;
            std::sort(perm.begin(), perm.end());

            do {
                result.push_back(perm);
            } while (std::next_permutation(perm.begin(), perm.end()));

            return result;
        }

        template<typename T>
        std::vector<std::vector<T>> generate_subsets(const std::vector<T>& items) {
            std::vector<std::vector<T>> result;
            uint32_t n = items.size();
            uint64_t total_subsets = 1ULL << n;

            for (uint64_t mask = 0; mask < total_subsets; ++mask) {
                std::vector<T> subset;
                for (uint32_t i = 0; i < n; ++i) {
                    if (mask & (1ULL << i)) {
                        subset.push_back(items[i]);
                    }
                }
                result.push_back(subset);
            }
            return result;
        }

        // Explicit template instantiations for common types
        template std::vector<std::vector<int>> generate_combinations(const std::vector<int>&, uint32_t);
        template std::vector<std::vector<int>> generate_permutations(const std::vector<int>&);
        template std::vector<std::vector<int>> generate_subsets(const std::vector<int>&);

        template std::vector<std::vector<double>> generate_combinations(const std::vector<double>&, uint32_t);
        template std::vector<std::vector<double>> generate_permutations(const std::vector<double>&);
        template std::vector<std::vector<double>> generate_subsets(const std::vector<double>&);

        template std::vector<std::vector<std::string>> generate_combinations(const std::vector<std::string>&, uint32_t);
        template std::vector<std::vector<std::string>> generate_permutations(const std::vector<std::string>&);
        template std::vector<std::vector<std::string>> generate_subsets(const std::vector<std::string>&);
    }

} // namespace imeth::combinatorics
