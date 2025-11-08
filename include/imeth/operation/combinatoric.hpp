//
// Created by paijogoesblue on 11/5/25.
//

#ifndef IMETH_COMBINATORIC_H
#define IMETH_COMBINATORIC_H

#include <vector>
#include <array>

namespace imeth::Combinatorics {

    using uint_t = unsigned long long;

    uint_t factorial(uint_t n);
    uint_t combination(uint_t n, uint_t k);
    uint_t permutation(uint_t n, uint_t r);
    uint_t combination_with_repetition(uint_t n, uint_t r);
    uint_t permutation_with_repetition(uint_t n, const std::vector<uint_t>& repetitions);
    uint_t permutation_full_repetition(uint_t n, uint_t r);
    uint_t circular_permutation(uint_t n);
    uint_t permutation_with_restriction(uint_t n, uint_t fixed_positions);

    namespace Probability {

        class Dice {
        private:
            std::array<int, 6> numbers;

        public:
            Dice();
            double probability_of_number(int target) const;
            double probability_of_even() const;
            double probability_of_odd() const;
            double probability_greater_than(int limit) const;
            double probability_less_than(int limit) const;
            double probability_between(int min, int max) const;
            double probability_sum_two_dice(int target) const;
            double probability_sum_n_dice(int target, int n_dice) const;
            double probability_all_same(int target, int n_dice) const;
            static double probability_all_different(int n_dice) ;
        };

        class Coin {
        private:
            std::array<char, 2> sides;

        public:
            Coin();
            static double probability_of(char target) ;
            static double probability_consecutive(char target, unsigned int times) ;
            static double probability_at_least_one(char target, unsigned int times) ;
            static double probability_exactly_k(char target, unsigned int k, unsigned int n) ;
            static double probability_more_than_k(char target, unsigned int k, unsigned int n) ;
            static double probability_alternating(unsigned int n) ;
        };

        class MarbleBag {
        private:
            unsigned int red;
            unsigned int white;
            unsigned int blue;

        public:
            MarbleBag(unsigned int red_count, unsigned int white_count, unsigned int blue_count = 0);
            unsigned int total() const;
            double probability_single(char color) const;
            double probability_two_consecutive(char first, char second) const;
            double probability_two_with_replacement(char first, char second) const;
            double probability_all_same(char color, unsigned int draws) const;
            double probability_at_least_one(char color, unsigned int draws) const;
            double probability_exactly_k(char color, unsigned int k, unsigned int draws) const;
        };

        class Deck {
        private:
            unsigned int total_cards;
            unsigned int hearts;
            unsigned int diamonds;
            unsigned int clubs;
            unsigned int spades;

        public:
            Deck();
            static double probability_suit(char suit) ;
            static double probability_red() ;
            double probability_black() const;
            static double probability_face_card() ;
            static double probability_number_card() ;
            static double probability_ace() ;
            static double probability_specific_card(int rank) ;
            static double probability_two_same_suit() ;
            static double probability_pair() ;
            static double probability_straight_flush(unsigned int cards) ;
        };

        class Spinner {
        private:
            std::vector<int> sections;

        public:
            explicit Spinner(const std::vector<int>& section_values);
            double probability_of(int value) const;
            double probability_greater_than(int limit) const;
            double probability_even() const;
            double probability_odd() const;
            double expected_value() const;
        };

        class Lottery {
        private:
            unsigned int total_numbers;
            unsigned int numbers_drawn;

        public:
            Lottery(unsigned int total, unsigned int drawn);
            double probability_match_all() const;
            double probability_match_k(unsigned int k) const;
            double probability_match_at_least_k(unsigned int k) const;
        };

        namespace Functions {
            double binomial_probability(unsigned int n, unsigned int k, double p);
            double geometric_probability(unsigned int k, double p);
            double hypergeometric_probability(unsigned int N, unsigned int K, unsigned int n, unsigned int k);
            double complement_probability(double p);
            double union_probability(double p1, double p2, double p_both);
            double intersection_probability(double p1, double p2_given_1);
            double conditional_probability(double p_both, double p_condition);
            double total_probability(const std::vector<double>& event_probs, const std::vector<double>& conditional_probs);
            double bayes_theorem(double p_b_given_a, double p_a, double p_b);
            double expected_value(const std::vector<double>& values, const std::vector<double>& probabilities);
            double variance(const std::vector<double>& values, const std::vector<double>& probabilities);
            double standard_deviation(const std::vector<double>& values, const std::vector<double>& probabilities);
        }
    }

    namespace Counting {
        uint_t derangement(uint_t n);
        uint_t stirling_second_kind(uint_t n, uint_t k);
        uint_t catalan_number(uint_t n);
        uint_t bell_number(uint_t n);
        uint_t fibonacci(uint_t n);
        uint_t lucas_number(uint_t n);
        uint_t triangular_number(uint_t n);
        uint_t pentagonal_number(uint_t n);
        uint_t hexagonal_number(uint_t n);
        uint_t ways_to_climb_stairs(unsigned int n, const std::vector<unsigned int>& step_sizes);
        uint_t ways_to_make_change(unsigned int amount, const std::vector<unsigned int>& denominations);
        uint_t ways_to_partition(unsigned int n);
        uint_t ways_to_partition_into_k(unsigned int n, unsigned int k);
        std::vector<uint_t> pascal_row(unsigned int row);
    }

    namespace Sets {
        template<typename T>
        void generate_combinations(const std::vector<T>& items, unsigned int k,
                                   std::vector<std::vector<T>>& result);

        template<typename T>
        void generate_permutations(const std::vector<T>& items,
                                   std::vector<std::vector<T>>& result);

        template<typename T>
        void generate_subsets(const std::vector<T>& items,
                              std::vector<std::vector<T>>& result);

        template<typename T>
        bool is_subset(const std::vector<T>& subset, const std::vector<T>& set);

        template<typename T>
        void set_union(const std::vector<T>& set1, const std::vector<T>& set2,
                       std::vector<T>& result);

        template<typename T>
        void set_intersection(const std::vector<T>& set1, const std::vector<T>& set2,
                              std::vector<T>& result);

        template<typename T>
        void set_difference(const std::vector<T>& set1, const std::vector<T>& set2,
                            std::vector<T>& result);

        template<typename T>
        void symmetric_difference(const std::vector<T>& set1, const std::vector<T>& set2,
                                  std::vector<T>& result);

        template<typename T>
        void cartesian_product(const std::vector<T>& set1, const std::vector<T>& set2,
                               std::vector<std::pair<T, T>>& result);
    }

    namespace Sequences {
        void geometric_sequence(uint_t first, uint_t ratio, unsigned int terms,
                                std::vector<uint_t>& result);
        uint_t geometric_sum(uint_t first, uint_t ratio, unsigned int terms);
        uint_t nth_term_geometric(uint_t first, uint_t ratio, unsigned int n);
    }

    namespace Graphs {
        uint_t complete_graph_edges(unsigned int vertices);
        uint_t tree_edges(unsigned int vertices);
        uint_t bipartite_complete_edges(unsigned int set1_size, unsigned int set2_size);
        uint_t handshake_lemma(const std::vector<unsigned int>& degrees);
        bool is_graphical_sequence(std::vector<unsigned int> degrees);
        uint_t chromatic_polynomial_complete(unsigned int n, unsigned int k);
    }

}

#endif //IMETH_COMBINATORIC_H
