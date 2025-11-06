#include "../include/imeth/operation/combinatoric.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

namespace imeth::Combinatorics {

    uint_t factorial(uint_t n) {
        if (n == 0 || n == 1) return 1;
        uint_t result = 1;
        for (uint_t i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    uint_t combination(const uint_t n, uint_t k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;

        uint_t result = 1;
        for (uint_t i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    uint_t permutation(const uint_t n, const uint_t r) {
        if (r > n) {
            throw std::invalid_argument("r cannot be greater than n");
        }
        uint_t result = 1;
        for (uint_t i = 0; i < r; ++i) {
            result *= (n - i);
        }
        return result;
    }

    uint_t combination_with_repetition(const uint_t n, const uint_t r) {
        return combination(n + r - 1, r);
    }

    uint_t permutation_with_repetition(const uint_t n, const std::vector<uint_t>& repetitions) {
        const uint_t numerator = factorial(n);
        uint_t denominator = 1;
        for (uint_t rep : repetitions) {
            denominator *= factorial(rep);
        }
        return numerator / denominator;
    }

    uint_t permutation_full_repetition(const uint_t n, const uint_t r) {
        uint_t result = 1;
        for (uint_t i = 0; i < r; ++i) {
            result *= n;
        }
        return result;
    }

    uint_t circular_permutation(const uint_t n) {
        if (n == 0) return 0;
        return factorial(n - 1);
    }

    uint_t permutation_with_restriction(uint_t n, uint_t fixed_positions) {
        if (fixed_positions > n) return 0;
        return factorial(n - fixed_positions);
    }

    namespace Probability {

        Dice::Dice() : numbers{1, 2, 3, 4, 5, 6} {}

        double Dice::probability_of_number(const int target) const {
            for (int num : numbers) {
                if (num == target) return 1.0 / 6.0;
            }
            return 0.0;
        }

        double Dice::probability_of_even() const {
            return 0.5;
        }

        double Dice::probability_of_odd() const {
            return 0.5;
        }

        double Dice::probability_greater_than(const int limit) const {
            int count = 0;
            for (int num : numbers) {
                if (num > limit) count++;
            }
            return static_cast<double>(count) / 6.0;
        }

        double Dice::probability_less_than(int limit) const {
            int count = 0;
            for (int num : numbers) {
                if (num < limit) count++;
            }
            return static_cast<double>(count) / 6.0;
        }

        double Dice::probability_between(const int min, const int max) const {
            int count = 0;
            for (int num : numbers) {
                if (num >= min && num <= max) count++;
            }
            return static_cast<double>(count) / 6.0;
        }

        double Dice::probability_sum_two_dice(const int target) const {
            int count = 0;
            for (int d1 : numbers) {
                for (int d2 : numbers) {
                    if (d1 + d2 == target) count++;
                }
            }
            return static_cast<double>(count) / 36.0;
        }

        double Dice::probability_sum_n_dice(const int target, const int n_dice) const {
            if (n_dice <= 0) return 0.0;
            std::vector<int> dp(target + 1, 0);
            dp[0] = 1;

            for (int dice = 0; dice < n_dice; ++dice) {
                std::vector<int> new_dp(target + 1, 0);
                for (int sum = 0; sum <= target; ++sum) {
                    if (dp[sum] > 0) {
                        for (int face : numbers) {
                            if (sum + face <= target) {
                                new_dp[sum + face] += dp[sum];
                            }
                        }
                    }
                }
                dp = std::move(new_dp);
            }

            int total = 1;
            for (int i = 0; i < n_dice; ++i) {
                total *= 6;
            }
            return static_cast<double>(dp[target]) / total;
        }

        double Dice::probability_all_same(const int target, const int n_dice) const {
            bool valid = false;
            for (int num : numbers) {
                if (num == target) {
                    valid = true;
                    break;
                }
            }
            if (!valid) return 0.0;
            return std::pow(1.0 / 6.0, n_dice);
        }

        double Dice::probability_all_different(const int n_dice) const {
            if (n_dice > 6) return 0.0;
            double prob = 1.0;
            for (int i = 0; i < n_dice; ++i) {
                prob *= (6.0 - i) / 6.0;
            }
            return prob;
        }

        Coin::Coin() : sides{'H', 'T'} {}

        double Coin::probability_of(const char target) const {
            return (target == 'H' || target == 'T') ? 0.5 : 0.0;
        }

        double Coin::probability_consecutive(const char target, const unsigned int times) const {
            if (target != 'H' && target != 'T') return 0.0;
            return std::pow(0.5, times);
        }

        double Coin::probability_at_least_one(const char target, const unsigned int times) const {
            if (target != 'H' && target != 'T') return 0.0;
            return 1.0 - std::pow(0.5, times);
        }

        double Coin::probability_exactly_k(const char target, const unsigned int k, const unsigned int n) const {
            if (k > n || (target != 'H' && target != 'T')) return 0.0;
            uint_t ways = combination(n, k);
            return ways * std::pow(0.5, n);
        }

        double Coin::probability_more_than_k(const char target, const unsigned int k, const unsigned int n) const {
            double prob = 0.0;
            for (unsigned int i = k + 1; i <= n; ++i) {
                prob += probability_exactly_k(target, i, n);
            }
            return prob;
        }

        double Coin::probability_alternating(const unsigned int n) const {
            if (n == 0) return 0.0;
            if (n == 1) return 1.0;
            return 2.0 / std::pow(2.0, n);
        }

        MarbleBag::MarbleBag(const unsigned int red_count, const unsigned int white_count, const unsigned int blue_count)
            : red(red_count), white(white_count), blue(blue_count) {}

        unsigned int MarbleBag::total() const {
            return red + white + blue;
        }

        double MarbleBag::probability_single(const char color) const {
            unsigned int t = total();
            if (t == 0) return 0.0;

            switch (color) {
                case 'R': return static_cast<double>(red) / t;
                case 'W': return static_cast<double>(white) / t;
                case 'B': return static_cast<double>(blue) / t;
                default: return 0.0;
            }
        }

        double MarbleBag::probability_two_consecutive(const char first, const char second) const {
            unsigned int t = total();
            if (t < 2) return 0.0;

            unsigned int first_count = 0, second_count = 0;

            switch (first) {
                case 'R': first_count = red; break;
                case 'W': first_count = white; break;
                case 'B': first_count = blue; break;
                default: return 0.0;
            }

            if (first == second) {
                second_count = first_count > 0 ? first_count - 1 : 0;
            } else {
                switch (second) {
                    case 'R': second_count = red; break;
                    case 'W': second_count = white; break;
                    case 'B': second_count = blue; break;
                    default: return 0.0;
                }
            }

            return (static_cast<double>(first_count) / t) *
                   (static_cast<double>(second_count) / (t - 1));
        }

        double MarbleBag::probability_two_with_replacement(const char first, const char second) const {
            return probability_single(first) * probability_single(second);
        }

        double MarbleBag::probability_all_same(const char color, const unsigned int draws) const {
            unsigned int t = total();
            unsigned int color_count = 0;

            switch (color) {
                case 'R': color_count = red; break;
                case 'W': color_count = white; break;
                case 'B': color_count = blue; break;
                default: return 0.0;
            }

            if (draws > color_count) return 0.0;

            double prob = 1.0;
            for (unsigned int i = 0; i < draws; ++i) {
                prob *= static_cast<double>(color_count - i) / (t - i);
            }
            return prob;
        }

        double MarbleBag::probability_at_least_one(const char color, const unsigned int draws) const {
            unsigned int t = total();
            unsigned int other_count = t;

            switch (color) {
                case 'R': other_count = white + blue; break;
                case 'W': other_count = red + blue; break;
                case 'B': other_count = red + white; break;
                default: return 0.0;
            }

            if (draws > t) return 1.0;
            if (other_count == 0) return 1.0;

            double prob_none = 1.0;
            for (unsigned int i = 0; i < draws; ++i) {
                if (i >= other_count) return 1.0;
                prob_none *= static_cast<double>(other_count - i) / (t - i);
            }
            return 1.0 - prob_none;
        }

        double MarbleBag::probability_exactly_k(const char color, const unsigned int k, const unsigned int draws) const {
            unsigned int color_count = 0;
            unsigned int other_count = 0;
            unsigned int t = total();

            switch (color) {
                case 'R':
                    color_count = red;
                    other_count = white + blue;
                    break;
                case 'W':
                    color_count = white;
                    other_count = red + blue;
                    break;
                case 'B':
                    color_count = blue;
                    other_count = red + white;
                    break;
                default: return 0.0;
            }

            if (k > draws || k > color_count || (draws - k) > other_count) return 0.0;

            uint_t ways = combination(color_count, k) * combination(other_count, draws - k);
            uint_t total_ways = combination(t, draws);

            return static_cast<double>(ways) / total_ways;
        }

        Deck::Deck()
            : total_cards(52), hearts(13), diamonds(13), clubs(13), spades(13) {}

        double Deck::probability_suit(const char suit) {
            switch (suit) {
                case 'H': return 13.0 / 52.0;
                case 'D': return 13.0 / 52.0;
                case 'C': return 13.0 / 52.0;
                case 'S': return 13.0 / 52.0;
                default: return 0.0;
            }
        }

        double Deck::probability_red() {
            return 26.0 / 52.0;
        }

        double Deck::probability_black() const {
            return 26.0 / 52.0;
        }

        double Deck::probability_face_card() {
            return 12.0 / 52.0;
        }

        double Deck::probability_number_card() {
            return 36.0 / 52.0;
        }

        double Deck::probability_ace() {
            return 4.0 / 52.0;
        }

        double Deck::probability_specific_card(const int rank) {
            if (rank < 1 || rank > 13) return 0.0;
            return 1.0 / 52.0;
        }

        double Deck::probability_two_same_suit() {
            return (13.0 / 52.0) * (12.0 / 51.0) * 4;
        }

        double Deck::probability_pair() {
            return (4.0 / 52.0) * (3.0 / 51.0) * 13;
        }

        double Deck::probability_straight_flush(const unsigned int cards) {
            if (cards > 13) return 0.0;
            uint_t straights = 13 - cards + 1;
            uint_t ways = straights * 4;
            uint_t total = combination(52, cards);
            return static_cast<double>(ways) / total;
        }

        Spinner::Spinner(const std::vector<int>& section_values) : sections(section_values) {}

        double Spinner::probability_of(int value) const {
            if (sections.empty()) return 0.0;
            int count = static_cast<int>(std::count(sections.begin(), sections.end(), value));
            return static_cast<double>(count) / sections.size();
        }

        double Spinner::probability_greater_than(int limit) const {
            if (sections.empty()) return 0.0;
            int count = 0;
            for (int val : sections) {
                if (val > limit) count++;
            }
            return static_cast<double>(count) / sections.size();
        }

        double Spinner::probability_even() const {
            if (sections.empty()) return 0.0;
            int count = 0;
            for (int val : sections) {
                if (val % 2 == 0) count++;
            }
            return static_cast<double>(count) / sections.size();
        }

        double Spinner::probability_odd() const {
            if (sections.empty()) return 0.0;
            int count = 0;
            for (int val : sections) {
                if (val % 2 != 0) count++;
            }
            return static_cast<double>(count) / sections.size();
        }

        double Spinner::expected_value() const {
            if (sections.empty()) return 0.0;
            double sum = std::accumulate(sections.begin(), sections.end(), 0.0);
            return sum / sections.size();
        }

        Lottery::Lottery(const unsigned int total, const unsigned int drawn)
            : total_numbers(total), numbers_drawn(drawn) {}

        double Lottery::probability_match_all() const {
            return 1.0 / combination(total_numbers, numbers_drawn);
        }

        double Lottery::probability_match_k(const unsigned int k) const {
            if (k > numbers_drawn) return 0.0;
            uint_t ways = combination(numbers_drawn, k) *
                          combination(total_numbers - numbers_drawn, numbers_drawn - k);
            uint_t total = combination(total_numbers, numbers_drawn);
            return static_cast<double>(ways) / total;
        }

        double Lottery::probability_match_at_least_k(unsigned int k) const {
            double prob = 0.0;
            for (unsigned int i = k; i <= numbers_drawn; ++i) {
                prob += probability_match_k(i);
            }
            return prob;
        }

        namespace Functions {
            double binomial_probability(unsigned int n, unsigned int k, double p) {
                uint_t ways = combination(n, k);
                return ways * std::pow(p, k) * std::pow(1.0 - p, n - k);
            }

            double geometric_probability(unsigned int k, double p) {
                return std::pow(1.0 - p, k - 1) * p;
            }

            double hypergeometric_probability(const unsigned int N, const unsigned int K, const unsigned int n, const unsigned int k) {
                if (k > K || (n - k) > (N - K)) return 0.0;
                const uint_t favorable = combination(K, k) * combination(N - K, n - k);
                const uint_t total = combination(N, n);
                return static_cast<double>(favorable) / total;
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

            double conditional_probability(const double p_both, const double p_condition) {
                if (p_condition == 0.0) return 0.0;
                return p_both / p_condition;
            }

            double total_probability(const std::vector<double>& event_probs, const std::vector<double>& conditional_probs) {
                double result = 0.0;
                size_t size = std::min(event_probs.size(), conditional_probs.size());
                for (size_t i = 0; i < size; ++i) {
                    result += event_probs[i] * conditional_probs[i];
                }
                return result;
            }

            double bayes_theorem(const double p_b_given_a, const double p_a, const double p_b) {
                if (p_b == 0.0) return 0.0;
                return (p_b_given_a * p_a) / p_b;
            }

            double expected_value(const std::vector<double>& values, const std::vector<double>& probabilities) {
                double result = 0.0;
                size_t size = std::min(values.size(), probabilities.size());
                for (size_t i = 0; i < size; ++i) {
                    result += values[i] * probabilities[i];
                }
                return result;
            }

            double variance(const std::vector<double>& values, const std::vector<double>& probabilities) {
                double ev = expected_value(values, probabilities);
                double result = 0.0;
                size_t size = std::min(values.size(), probabilities.size());
                for (size_t i = 0; i < size; ++i) {
                    result += probabilities[i] * std::pow(values[i] - ev, 2);
                }
                return result;
            }

            double standard_deviation(const std::vector<double>& values, const std::vector<double>& probabilities) {
                return std::sqrt(variance(values, probabilities));
            }
        }
    }

    namespace Counting {
        uint_t derangement(const uint_t n) {
            if (n == 0) return 1;
            if (n == 1) return 0;

            uint_t prev2 = 1, prev1 = 0, curr = 0;
            for (uint_t i = 2; i <= n; ++i) {
                curr = (i - 1) * (prev1 + prev2);
                prev2 = prev1;
                prev1 = curr;
            }
            return curr;
        }

        uint_t stirling_second_kind(const uint_t n, const uint_t k) {
            if (n == 0 && k == 0) return 1;
            if (n == 0 || k == 0 || k > n) return 0;
            if (k == 1 || k == n) return 1;

            std::vector<std::vector<uint_t>> dp(n + 1, std::vector<uint_t>(k + 1, 0));
            dp[0][0] = 1;

            for (uint_t i = 1; i <= n; ++i) {
                for (uint_t j = 1; j <= k && j <= i; ++j) {
                    dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            return dp[n][k];
        }

        uint_t catalan_number(const uint_t n) {
            if (n <= 1) return 1;
            std::vector<uint_t> catalan(n + 1, 0);
            catalan[0] = catalan[1] = 1;

            for (uint_t i = 2; i <= n; ++i) {
                for (uint_t j = 0; j < i; ++j) {
                    catalan[i] += catalan[j] * catalan[i - 1 - j];
                }
            }
            return catalan[n];
        }

        uint_t bell_number(const uint_t n) {
            std::vector<uint_t> bell(n + 1);
            bell[0] = 1;

            for (uint_t i = 1; i <= n; ++i) {
                std::vector<uint_t> new_bell(n + 1);
                new_bell[0] = bell[i - 1];

                for (uint_t j = 1; j <= n; ++j) {
                    new_bell[j] = new_bell[j - 1] + bell[j - 1];
                }
                bell = std::move(new_bell);
            }
            return bell[0];
        }

        uint_t fibonacci(const uint_t n) {
            if (n == 0) return 0;
            if (n == 1) return 1;

            uint_t prev = 0, curr = 1;
            for (uint_t i = 2; i <= n; ++i) {
                uint_t next = prev + curr;
                prev = curr;
                curr = next;
            }
            return curr;
        }

        uint_t lucas_number(const uint_t n) {
            if (n == 0) return 2;
            if (n == 1) return 1;

            uint_t prev = 2, curr = 1;
            for (uint_t i = 2; i <= n; ++i) {
                uint_t next = prev + curr;
                prev = curr;
                curr = next;
            }
            return curr;
        }

        uint_t triangular_number(const uint_t n) {
            return n * (n + 1) / 2;
        }

        uint_t pentagonal_number(const uint_t n) {
            return n * (3 * n - 1) / 2;
        }

        uint_t hexagonal_number(const uint_t n) {
            return n * (2 * n - 1);
        }

        uint_t ways_to_climb_stairs(unsigned int n, const std::vector<unsigned int>& step_sizes) {
            std::vector<uint_t> dp(n + 1, 0);
            dp[0] = 1;

            for (unsigned int i = 1; i <= n; ++i) {
                for (unsigned int step : step_sizes) {
                    if (i >= step) {
                        dp[i] += dp[i - step];
                    }
                }
            }
            return dp[n];
        }

        uint_t ways_to_make_change(unsigned int amount, const std::vector<unsigned int>& denominations) {
            std::vector<uint_t> dp(amount + 1, 0);
            dp[0] = 1;

            for (unsigned int coin : denominations) {
                for (unsigned int i = coin; i <= amount; ++i) {
                    dp[i] += dp[i - coin];
                }
            }
            return dp[amount];
        }

        uint_t ways_to_partition(unsigned int n) {
            std::vector<uint_t> p(n + 1, 0);
            p[0] = 1;

            for (unsigned int k = 1; k <= n; ++k) {
                for (unsigned int i = k; i <= n; ++i) {
                    p[i] += p[i - k];
                }
            }
            return p[n];
        }

        uint_t ways_to_partition_into_k(unsigned int n, unsigned int k) {
            if (k > n || k == 0) return 0;
            if (k == 1 || k == n) return 1;

            std::vector<uint_t> prev(n + 1, 0), curr(n + 1, 0);
            prev[0] = 1;

            for (unsigned int j = 1; j <= k; ++j) {
                std::fill(curr.begin(), curr.end(), 0);
                for (unsigned int i = j; i <= n; ++i) {
                    curr[i] = prev[i - 1] + curr[i - j];
                }
                prev = curr;
            }
            return curr[n];
        }

        std::vector<uint_t> pascal_row(unsigned int row) {
            std::vector<uint_t> result(row + 1);
            for (unsigned int i = 0; i <= row; ++i) {
                result[i] = combination(row, i);
            }
            return result;
        }
    }

    namespace Sets {
        template<typename T>
        void generate_combinations(const std::vector<T>& items, unsigned int k,
                                   std::vector<std::vector<T>>& result) {
            result.clear();
            unsigned int n = items.size();

            if (k > n || k == 0) return;

            std::vector<bool> selector(n, false);
            std::fill(selector.begin(), selector.begin() + k, true);

            do {
                std::vector<T> combination;
                combination.reserve(k);
                for (unsigned int i = 0; i < n; ++i) {
                    if (selector[i]) {
                        combination.push_back(items[i]);
                    }
                }
                result.push_back(std::move(combination));
            } while (std::prev_permutation(selector.begin(), selector.end()));
        }

        template<typename T>
        void generate_permutations(const std::vector<T>& items,
                                   std::vector<std::vector<T>>& result) {
            result.clear();
            std::vector<T> perm = items;
            std::sort(perm.begin(), perm.end());

            do {
                result.push_back(perm);
            } while (std::next_permutation(perm.begin(), perm.end()));
        }

        template<typename T>
        void generate_subsets(const std::vector<T>& items,
                              std::vector<std::vector<T>>& result) {
            result.clear();
            unsigned int n = items.size();
            unsigned int total = 1U << n;

            for (unsigned int mask = 0; mask < total; ++mask) {
                std::vector<T> subset;
                for (unsigned int i = 0; i < n; ++i) {
                    if (mask & (1U << i)) {
                        subset.push_back(items[i]);
                    }
                }
                result.push_back(std::move(subset));
            }
        }

        template<typename T>
        bool is_subset(const std::vector<T>& subset, const std::vector<T>& set) {
            std::set<T> set_elements(set.begin(), set.end());
            for (const T& elem : subset) {
                if (set_elements.find(elem) == set_elements.end()) {
                    return false;
                }
            }
            return true;
        }

        template<typename T>
        void set_union(const std::vector<T>& set1, const std::vector<T>& set2,
                       std::vector<T>& result) {
            std::set<T> result_set(set1.begin(), set1.end());
            result_set.insert(set2.begin(), set2.end());
            result.assign(result_set.begin(), result_set.end());
        }

        template<typename T>
        void set_intersection(const std::vector<T>& set1, const std::vector<T>& set2,
                              std::vector<T>& result) {
            std::set<T> s1(set1.begin(), set1.end());
            std::set<T> s2(set2.begin(), set2.end());
            result.clear();
            std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                  std::back_inserter(result));
        }

        template<typename T>
        void set_difference(const std::vector<T>& set1, const std::vector<T>& set2,
                            std::vector<T>& result) {
            std::set<T> s1(set1.begin(), set1.end());
            std::set<T> s2(set2.begin(), set2.end());
            result.clear();
            std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                std::back_inserter(result));
        }

        template<typename T>
        void symmetric_difference(const std::vector<T>& set1, const std::vector<T>& set2,
                                  std::vector<T>& result) {
            std::set<T> s1(set1.begin(), set1.end());
            std::set<T> s2(set2.begin(), set2.end());
            result.clear();
            std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                          std::back_inserter(result));
        }

        template<typename T>
        void cartesian_product(const std::vector<T>& set1, const std::vector<T>& set2,
                               std::vector<std::pair<T, T>>& result) {
            result.clear();
            result.reserve(set1.size() * set2.size());
            for (const T& elem1 : set1) {
                for (const T& elem2 : set2) {
                    result.emplace_back(elem1, elem2);
                }
            }
        }

        template void generate_combinations(const std::vector<int>&, unsigned int, std::vector<std::vector<int>>&);
        template void generate_permutations(const std::vector<int>&, std::vector<std::vector<int>>&);
        template void generate_subsets(const std::vector<int>&, std::vector<std::vector<int>>&);
        template bool is_subset(const std::vector<int>&, const std::vector<int>&);
        template void set_union(const std::vector<int>&, const std::vector<int>&, std::vector<int>&);
        template void set_intersection(const std::vector<int>&, const std::vector<int>&, std::vector<int>&);
        template void set_difference(const std::vector<int>&, const std::vector<int>&, std::vector<int>&);
        template void symmetric_difference(const std::vector<int>&, const std::vector<int>&, std::vector<int>&);
        template void cartesian_product(const std::vector<int>&, const std::vector<int>&, std::vector<std::pair<int, int>>&);

        template void generate_combinations(const std::vector<std::string>&, unsigned int, std::vector<std::vector<std::string>>&);
        template void generate_permutations(const std::vector<std::string>&, std::vector<std::vector<std::string>>&);
        template void generate_subsets(const std::vector<std::string>&, std::vector<std::vector<std::string>>&);
        template bool is_subset(const std::vector<std::string>&, const std::vector<std::string>&);
        template void set_union(const std::vector<std::string>&, const std::vector<std::string>&, std::vector<std::string>&);
        template void set_intersection(const std::vector<std::string>&, const std::vector<std::string>&, std::vector<std::string>&);
        template void set_difference(const std::vector<std::string>&, const std::vector<std::string>&, std::vector<std::string>&);
        template void symmetric_difference(const std::vector<std::string>&, const std::vector<std::string>&, std::vector<std::string>&);
        template void cartesian_product(const std::vector<std::string>&, const std::vector<std::string>&, std::vector<std::pair<std::string, std::string>>&);
    }

    namespace Sequences {
        void arithmetic_sequence(uint_t first, uint_t diff, unsigned int terms,
                                 std::vector<uint_t>& result) {
            result.clear();
            result.reserve(terms);
            for (unsigned int i = 0; i < terms; ++i) {
                result.push_back(first + i * diff);
            }
        }

        void geometric_sequence(uint_t first, uint_t ratio, unsigned int terms,
                                std::vector<uint_t>& result) {
            result.clear();
            result.reserve(terms);
            uint_t current = first;
            for (unsigned int i = 0; i < terms; ++i) {
                result.push_back(current);
                current *= ratio;
            }
        }

        uint_t arithmetic_sum(uint_t first, uint_t last, unsigned int terms) {
            return terms * (first + last) / 2;
        }

        uint_t geometric_sum(uint_t first, uint_t ratio, unsigned int terms) {
            if (ratio == 1) return first * terms;
            uint_t power = 1;
            for (unsigned int i = 0; i < terms; ++i) {
                power *= ratio;
            }
            return first * (power - 1) / (ratio - 1);
        }

        uint_t nth_term_arithmetic(uint_t first, uint_t diff, unsigned int n) {
            return first + (n - 1) * diff;
        }

        uint_t nth_term_geometric(uint_t first, uint_t ratio, unsigned int n) {
            uint_t result = first;
            for (unsigned int i = 1; i < n; ++i) {
                result *= ratio;
            }
            return result;
        }
    }

    namespace Graphs {
        uint_t complete_graph_edges(unsigned int vertices) {
            return combination(vertices, 2);
        }

        uint_t tree_edges(unsigned int vertices) {
            return vertices > 0 ? vertices - 1 : 0;
        }

        uint_t bipartite_complete_edges(unsigned int set1_size, unsigned int set2_size) {
            return set1_size * set2_size;
        }

        uint_t handshake_lemma(const std::vector<unsigned int>& degrees) {
            uint_t sum = std::accumulate(degrees.begin(), degrees.end(), 0ULL);
            return sum / 2;
        }

        bool is_graphical_sequence(std::vector<unsigned int> degrees) {
            while (true) {
                std::sort(degrees.rbegin(), degrees.rend());

                if (degrees[0] == 0) return true;

                unsigned int v = degrees[0];
                degrees.erase(degrees.begin());

                if (v > degrees.size()) return false;

                for (unsigned int i = 0; i < v; ++i) {
                    if (degrees[i] == 0) return false;
                    degrees[i]--;
                }
            }
        }

        uint_t chromatic_polynomial_complete(unsigned int n, unsigned int k) {
            if (k < n) return 0;
            uint_t result = 1;
            for (unsigned int i = 0; i < n; ++i) {
                result *= (k - i);
            }
            return result;
        }
    }
}
