//
// Created by paijogoesblue on 11/5/25.
//

#ifndef IMETH_COMBINATORIC_H
#define IMETH_COMBINATORIC_H

#include <vector>
#include <array>
#include <cstdint>

namespace imeth::Combinatorics {

    uint64_t factorial(uint64_t n);
    uint64_t combination(uint64_t n, uint64_t k);
    uint64_t permutation(uint64_t n, uint64_t r);
    uint64_t combination_with_repetition(uint64_t n, uint64_t r);
    uint64_t permutation_with_repetition(uint64_t n, const std::vector<uint64_t>& repetitions);
    uint64_t permutation_full_repetition(uint64_t n, uint64_t r);

    namespace Probability {

        class Dice {
        private:
            std::array<int, 6> numbers;

        public:
            Dice();
            double probability_of_number(int target) const;
            static double probability_of_even() ;
            static double probability_of_odd() ;
            double probability_greater_than(int limit) const;
            double probability_less_than(int limit) const;
            double probability_between(int min, int max) const;
        };

        class Coin {
        private:
            std::array<char, 2> sides;

        public:
            Coin();
            double probability_of(char target) const;
            double probability_consecutive(uint32_t times) const;
            double probability_at_least_one(uint32_t times) const;
            double probability_exactly_k(uint32_t k, uint32_t n) const;
        };

        class MarbleBag {
        private:
            uint32_t red;
            uint32_t white;

        public:
            MarbleBag(uint32_t red_count, uint32_t white_count);
            uint32_t total() const;
            double probability_single(char color) const;
            double probability_two_consecutive(char first, char second) const;
            double probability_two_with_replacement(char first, char second) const;
            double probability_all_same(char color, uint32_t draws) const;
        };

        class Deck {
        private:
            uint32_t total_cards;
            uint32_t hearts;
            uint32_t diamonds;
            uint32_t clubs;
            uint32_t spades;

        public:
            Deck();
            static double probability_suit(char suit) ;
            static double probability_red() ;
            static double probability_black() ;
            static double probability_face_card() ;
            static double probability_number_card() ;
        };

        namespace Functions {
            double binomial_probability(uint32_t n, uint32_t k, double p);
            double geometric_probability(uint32_t k, double p);
            double hypergeometric_probability(uint32_t N, uint32_t K, uint32_t n, uint32_t k);
            double complement_probability(double p);
            double union_probability(double p1, double p2, double p_both);
            double intersection_probability(double p1, double p2_given_1);
        }
    }

    namespace Counting {
        uint64_t derangement(uint64_t n);
        uint64_t stirling_second_kind(uint64_t n, uint64_t k);
        uint64_t catalan_number(uint64_t n);
        uint64_t bell_number(uint64_t n);
        std::vector<std::vector<uint64_t>> pascal_triangle(uint32_t rows);
    }

    namespace Sets {
        template<typename T>
        std::vector<std::vector<T>> generate_combinations(const std::vector<T>& items, uint32_t k);

        template<typename T>
        std::vector<std::vector<T>> generate_permutations(const std::vector<T>& items);

        template<typename T>
        std::vector<std::vector<T>> generate_subsets(const std::vector<T>& items);
    }

} // namespace imeth::combinatorics


#endif //IMETH_COMBINATORIC_H