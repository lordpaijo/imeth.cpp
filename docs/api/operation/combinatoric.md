# Combinatorics

The combinatorics chapter provides a comprehensive collection of functions for counting, probability calculations, and set operations. This module is essential for solving problems involving arrangements, selections, and probability.

```c++
#include <imeth/operation/combinatoric.hpp>
```

## Overview

Combinatorics is the mathematics of counting. This module helps you answer questions like:
- "How many ways can I arrange these items?"
- "What's the probability of rolling a specific number?"
- "How many different groups can I make?"

---

## Basic Combinatorics

### Factorial

```c++
uint_t factorial(uint_t n);
```

Calculates n! (n factorial) = n × (n-1) × (n-2) × ... × 2 × 1

**Examples:**
```c++
factorial(5);   // 120 (5 × 4 × 3 × 2 × 1)
factorial(3);   // 6
factorial(0);   // 1 (by definition)
factorial(10);  // 3,628,800
```

**Real-world:** Number of ways to arrange n items in a line.

---

### Combinations

```c++
uint_t combination(uint_t n, uint_t k);
```

Calculate C(n,k) or "n choose k" - selecting k items from n items where order doesn't matter.

**Formula:** C(n,k) = n! / (k! × (n-k)!)

**Examples:**
```c++
combination(5, 2);   // 10 (choosing 2 from 5)
combination(10, 3);  // 120
combination(52, 5);  // 2,598,960 (5-card poker hands)
```

**Real-world:**
- Selecting a team of 5 from 12 players
- Choosing 3 toppings from 8 options
- Lottery number selections

---

### Permutations

```c++
uint_t permutation(uint_t n, uint_t r);
```

Calculate P(n,r) - arranging r items from n items where order matters.

**Formula:** P(n,r) = n! / (n-r)!

**Examples:**
```c++
permutation(5, 2);   // 20 (arranging 2 from 5)
permutation(10, 3);  // 720
permutation(8, 8);   // 40,320 (all arrangements of 8 items)
```

**Real-world:**
- Arranging podium positions (1st, 2nd, 3rd)
- Password possibilities
- Race finishing orders

---

### Combinations with Repetition

```c++
uint_t combination_with_repetition(uint_t n, uint_t r);
```

Selecting r items from n types where items can be selected multiple times.

**Formula:** C(n+r-1, r)

**Examples:**
```c++
combination_with_repetition(3, 2);  // 6
// Choosing 2 fruits from {apple, banana, orange}
// Possibilities: AA, AB, AC, BB, BC, CC

combination_with_repetition(5, 3);  // 35
```

**Real-world:**
- Buying 5 donuts from 8 flavors (can pick same flavor multiple times)
- Distributing identical items into different boxes

---

### Permutations with Repetition

```c++
uint_t permutation_with_repetition(uint_t n, const std::vector<uint_t>& repetitions);
```

Arranging items where some items are identical.

**Formula:** n! / (n₁! × n₂! × ... × nₖ!)

**Examples:**
```c++
// Word "MISSISSIPPI" (1M, 4I, 4S, 2P)
std::vector<uint_t> letters = {1, 4, 4, 2};
permutation_with_repetition(11, letters);  // 34,650

// Word "BOOK" (1B, 2O, 1K)
std::vector<uint_t> book = {1, 2, 1};
permutation_with_repetition(4, book);  // 12
```

**Real-world:**
- Anagrams of words with repeated letters
- Arranging colored balls where some colors repeat

---

### Full Repetition Permutations

```c++
uint_t permutation_full_repetition(uint_t n, uint_t r);
```

Number of r-length sequences from n items with unlimited repetition.

**Formula:** n^r

**Examples:**
```c++
permutation_full_repetition(10, 4);  // 10,000 (4-digit PIN codes)
permutation_full_repetition(2, 8);   // 256 (8-bit binary numbers)
permutation_full_repetition(26, 3);  // 17,576 (3-letter combinations)
```

**Real-world:**
- Password combinations
- License plate possibilities
- Binary sequences

---

### Circular Permutations

```c++
uint_t circular_permutation(uint_t n);
```

Arranging n items in a circle (rotations are considered the same).

**Formula:** (n-1)!

**Examples:**
```c++
circular_permutation(5);  // 24 (arranging 5 people at a round table)
circular_permutation(4);  // 6
circular_permutation(6);  // 120
```

**Real-world:**
- Seating arrangements at a round table
- Necklace bead arrangements
- Round-robin tournament schedules

---

### Permutations with Restrictions

```c++
uint_t permutation_with_restriction(uint_t n, uint_t fixed_positions);
```

Arrangements where some positions are fixed.

**Examples:**
```c++
// 5 items where 2 positions are fixed
permutation_with_restriction(5, 2);  // 6

// Photo lineup where first and last must be specific people
permutation_with_restriction(8, 2);  // 720
```

**Real-world:**
- Arrangements where certain items must be in specific positions
- Queue arrangements with VIP positions reserved

---

## Probability Classes

### Dice

Simulate dice rolling probabilities.

```c++
Dice dice;
```

**Methods:**

```c++
double probability_of_number(int target) const;
double probability_of_even() const;
double probability_of_odd() const;
double probability_greater_than(int limit) const;
double probability_less_than(int limit) const;
double probability_between(int min, int max) const;
double probability_sum_two_dice(int target) const;
double probability_sum_n_dice(int target, int n_dice) const;
double probability_all_same(int target, int n_dice) const;
static double probability_all_different(int n_dice);
```

**Examples:**
```c++
Dice dice;

dice.probability_of_number(6);           // 0.1667 (1/6)
dice.probability_of_even();              // 0.5 (3/6)
dice.probability_greater_than(4);        // 0.3333 (2/6)
dice.probability_between(3, 5);          // 0.5 (3/6)

// Two dice
dice.probability_sum_two_dice(7);        // 0.1667 (highest probability sum)
dice.probability_sum_two_dice(12);       // 0.0278 (only 6+6)

// Multiple dice
dice.probability_all_same(6, 3);         // Probability of rolling three 6s
Dice::probability_all_different(3);      // All three dice show different numbers
```

---

### Coin

Simulate coin flip probabilities.

```c++
Coin coin;
```

**Methods:**

```c++
static double probability_of(char target);
static double probability_consecutive(char target, unsigned int times);
static double probability_at_least_one(char target, unsigned int times);
static double probability_exactly_k(char target, unsigned int k, unsigned int n);
static double probability_more_than_k(char target, unsigned int k, unsigned int n);
static double probability_alternating(unsigned int n);
```

**Examples:**
```c++
Coin::probability_of('H');                      // 0.5
Coin::probability_consecutive('H', 3);          // 0.125 (HHH)
Coin::probability_at_least_one('H', 5);         // 0.96875
Coin::probability_exactly_k('H', 3, 5);         // P(exactly 3 heads in 5 flips)
Coin::probability_more_than_k('H', 2, 5);       // P(more than 2 heads in 5 flips)
Coin::probability_alternating(4);               // P(HTHT or THTH)
```

---

### MarbleBag

Simulate drawing marbles from a bag.

```c++
MarbleBag(unsigned int red_count, unsigned int white_count, unsigned int blue_count = 0);
```

**Methods:**

```c++
unsigned int total() const;
double probability_single(char color) const;
double probability_two_consecutive(char first, char second) const;
double probability_two_with_replacement(char first, char second) const;
double probability_all_same(char color, unsigned int draws) const;
double probability_at_least_one(char color, unsigned int draws) const;
double probability_exactly_k(char color, unsigned int k, unsigned int draws) const;
```

**Examples:**
```c++
// Bag with 5 red, 3 white, 2 blue marbles
MarbleBag bag(5, 3, 2);

bag.total();                                    // 10
bag.probability_single('r');                    // 0.5 (5/10)
bag.probability_two_consecutive('r', 'w');      // Without replacement
bag.probability_two_with_replacement('r', 'w'); // With replacement
bag.probability_all_same('r', 3);               // Drawing 3 red in a row
bag.probability_exactly_k('r', 2, 3);           // Exactly 2 red in 3 draws
```

**Color codes:** 'r' = red, 'w' = white, 'b' = blue

---

### Deck

Standard 52-card deck probabilities.

```c++
Deck deck;
```

**Methods:**

```c++
static double probability_suit(char suit);
static double probability_red();
double probability_black() const;
static double probability_face_card();
static double probability_number_card();
static double probability_ace();
static double probability_specific_card(int rank);
static double probability_two_same_suit();
static double probability_pair();
static double probability_straight_flush(unsigned int cards);
```

**Examples:**
```c++
Deck::probability_suit('h');           // 0.25 (13/52 hearts)
Deck::probability_red();               // 0.5
Deck::probability_face_card();         // 0.231 (12/52: J, Q, K)
Deck::probability_ace();               // 0.077 (4/52)
Deck::probability_two_same_suit();     // Drawing 2 cards of same suit
Deck::probability_pair();              // Drawing a pair
```

**Suit codes:** 'h' = hearts, 'd' = diamonds, 'c' = clubs, 's' = spades

---

### Spinner

Simulate probability spinner or roulette wheel.

```c++
Spinner(const std::vector<int>& section_values);
```

**Methods:**

```c++
double probability_of(int value) const;
double probability_greater_than(int limit) const;
double probability_even() const;
double probability_odd() const;
double expected_value() const;
```

**Examples:**
```c++
// Spinner with sections: 1, 2, 3, 2, 4, 2
std::vector<int> sections = {1, 2, 3, 2, 4, 2};
Spinner spinner(sections);

spinner.probability_of(2);              // 0.5 (3 out of 6 sections)
spinner.probability_even();             // 0.667 (4/6: 2,2,4,2)
spinner.probability_greater_than(2);    // 0.333 (2/6: 3,4)
spinner.expected_value();               // Average value
```

---

### Lottery

Calculate lottery winning probabilities.

```c++
Lottery(unsigned int total_numbers, unsigned int numbers_drawn);
```

**Methods:**

```c++
double probability_match_all() const;
double probability_match_k(unsigned int k) const;
double probability_match_at_least_k(unsigned int k) const;
```

**Examples:**
```c++
// 6/49 lottery (pick 6 from 49)
Lottery lottery(49, 6);

lottery.probability_match_all();        // ~0.00000007 (1 in 13,983,816)
lottery.probability_match_k(3);         // Match exactly 3 numbers
lottery.probability_match_at_least_k(4);// Match 4 or more numbers
```

---

## Probability Functions

General probability calculation functions.

### Binomial Probability

```c++
double binomial_probability(unsigned int n, unsigned int k, double p);
```

Probability of exactly k successes in n trials with probability p.

**Examples:**
```c++
// Probability of 3 heads in 5 coin flips
binomial_probability(5, 3, 0.5);  // 0.3125

// Probability of 2 successes in 10 trials (30% success rate)
binomial_probability(10, 2, 0.3);
```

---

### Geometric Probability

```c++
double geometric_probability(unsigned int k, double p);
```

Probability that first success occurs on the k-th trial.

**Examples:**
```c++
// Probability first head appears on 3rd flip
geometric_probability(3, 0.5);  // 0.125
```

---

### Hypergeometric Probability

```c++
double hypergeometric_probability(unsigned int N, unsigned int K, 
                                  unsigned int n, unsigned int k);
```

Drawing without replacement from a finite population.

**Parameters:**
- N: Total population size
- K: Number of success states in population
- n: Number of draws
- k: Number of observed successes

---

### Basic Probability Operations

```c++
double complement_probability(double p);
double union_probability(double p1, double p2, double p_both);
double intersection_probability(double p1, double p2_given_1);
double conditional_probability(double p_both, double p_condition);
```

**Examples:**
```c++
complement_probability(0.3);              // 0.7 (1 - 0.3)
union_probability(0.4, 0.5, 0.2);        // P(A or B)
intersection_probability(0.6, 0.3);       // P(A and B)
conditional_probability(0.15, 0.3);       // P(A|B)
```

---

### Advanced Functions

```c++
double total_probability(const std::vector<double>& event_probs, 
                        const std::vector<double>& conditional_probs);
double bayes_theorem(double p_b_given_a, double p_a, double p_b);
double expected_value(const std::vector<double>& values, 
                     const std::vector<double>& probabilities);
double variance(const std::vector<double>& values, 
               const std::vector<double>& probabilities);
double standard_deviation(const std::vector<double>& values, 
                         const std::vector<double>& probabilities);
```

---

## Counting Functions

### Derangement

```c++
uint_t derangement(uint_t n);
```

Number of permutations where no element appears in its original position.

**Examples:**
```c++
derangement(3);  // 2 (arrangements where nothing is in original spot)
derangement(4);  // 9
```

**Real-world:** Secret Santa where nobody gets their own name.

---

### Stirling Numbers (Second Kind)

```c++
uint_t stirling_second_kind(uint_t n, uint_t k);
```

Ways to partition n objects into k non-empty subsets.

---

### Catalan Numbers

```c++
uint_t catalan_number(uint_t n);
```

Sequence appearing in many counting problems.

**Examples:**
```c++
catalan_number(3);  // 5
catalan_number(4);  // 14
```

**Real-world:**
- Valid parentheses combinations
- Binary tree structures
- Path counting problems

---

### Bell Numbers

```c++
uint_t bell_number(uint_t n);
```

Number of ways to partition a set of n elements.

---

### Number Sequences

```c++
uint_t fibonacci(uint_t n);
uint_t lucas_number(uint_t n);
uint_t triangular_number(uint_t n);
uint_t pentagonal_number(uint_t n);
uint_t hexagonal_number(uint_t n);
```

**Examples:**
```c++
fibonacci(10);          // 55 (Fibonacci sequence)
lucas_number(5);        // 11
triangular_number(5);   // 15 (1+2+3+4+5)
pentagonal_number(4);   // 22
hexagonal_number(3);    // 15
```

---

### Dynamic Programming Problems

```c++
uint_t ways_to_climb_stairs(unsigned int n, const std::vector<unsigned int>& step_sizes);
uint_t ways_to_make_change(unsigned int amount, const std::vector<unsigned int>& denominations);
uint_t ways_to_partition(unsigned int n);
uint_t ways_to_partition_into_k(unsigned int n, unsigned int k);
```

**Examples:**
```c++
// Climbing 5 stairs, can take 1 or 2 steps at a time
std::vector<unsigned int> steps = {1, 2};
ways_to_climb_stairs(5, steps);  // 8 ways

// Make 10 cents with {1, 5, 10} cent coins
std::vector<unsigned int> coins = {1, 5, 10};
ways_to_make_change(10, coins);  // 4 ways
```

---

### Pascal's Triangle

```c++
std::vector<uint_t> pascal_row(unsigned int row);
```

Returns the nth row of Pascal's triangle.

**Examples:**
```c++
pascal_row(0);  // {1}
pascal_row(1);  // {1, 1}
pascal_row(2);  // {1, 2, 1}
pascal_row(3);  // {1, 3, 3, 1}
pascal_row(4);  // {1, 4, 6, 4, 1}
```

---

## Set Operations

Template functions for working with sets.

### Generate Combinations

```c++
template<typename T>
void generate_combinations(const std::vector<T>& items, unsigned int k,
                          std::vector<std::vector<T>>& result);
```

**Examples:**
```c++
std::vector<int> items = {1, 2, 3, 4};
std::vector<std::vector<int>> result;
generate_combinations(items, 2, result);
// Result: {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}}
```

---

### Generate Permutations

```c++
template<typename T>
void generate_permutations(const std::vector<T>& items,
                          std::vector<std::vector<T>>& result);
```

---

### Generate Subsets

```c++
template<typename T>
void generate_subsets(const std::vector<T>& items,
                     std::vector<std::vector<T>>& result);
```

Generates all possible subsets (power set).

---

### Set Operations

```c++
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
```

---

## Sequences

### Arithmetic Sequences

```c++
void arithmetic_sequence(uint_t first, uint_t diff, unsigned int terms,
                        std::vector<uint_t>& result);
uint_t arithmetic_sum(uint_t first, uint_t last, unsigned int terms);
uint_t nth_term_arithmetic(uint_t first, uint_t diff, unsigned int n);
```

**Examples:**
```c++
std::vector<uint_t> seq;
arithmetic_sequence(2, 3, 5, seq);  // {2, 5, 8, 11, 14}

arithmetic_sum(2, 14, 5);           // 40
nth_term_arithmetic(2, 3, 5);       // 14
```

---

### Geometric Sequences

```c++
void geometric_sequence(uint_t first, uint_t ratio, unsigned int terms,
                       std::vector<uint_t>& result);
uint_t geometric_sum(uint_t first, uint_t ratio, unsigned int terms);
uint_t nth_term_geometric(uint_t first, uint_t ratio, unsigned int n);
```

**Examples:**
```c++
std::vector<uint_t> seq;
geometric_sequence(2, 3, 5, seq);   // {2, 6, 18, 54, 162}

geometric_sum(2, 3, 5);             // 242
nth_term_geometric(2, 3, 5);        // 162
```

---

## Graph Theory

### Graph Functions

```c++
uint_t complete_graph_edges(unsigned int vertices);
uint_t tree_edges(unsigned int vertices);
uint_t bipartite_complete_edges(unsigned int set1_size, unsigned int set2_size);
uint_t handshake_lemma(const std::vector<unsigned int>& degrees);
bool is_graphical_sequence(std::vector<unsigned int> degrees);
uint_t chromatic_polynomial_complete(unsigned int n, unsigned int k);
```

**Examples:**
```c++
complete_graph_edges(5);            // 10 (complete graph K5)
tree_edges(10);                     // 9 (tree with 10 vertices)
bipartite_complete_edges(3, 4);     // 12 (K3,4)
```

---

## Complete Example

```c++
#include <imeth/operation/combinatoric.hpp>
#include <iostream>

int main() {
    using namespace imeth::Combinatorics;
    
    // Basic combinatorics
    std::cout << "5! = " << factorial(5) << "\n";  // 120
    std::cout << "C(10,3) = " << combination(10, 3) << "\n";  // 120
    std::cout << "P(5,2) = " << permutation(5, 2) << "\n";  // 20
    
    // Probability with dice
    Probability::Dice dice;
    std::cout << "P(rolling 6) = " << dice.probability_of_number(6) << "\n";
    std::cout << "P(sum of 7 with 2 dice) = " 
              << dice.probability_sum_two_dice(7) << "\n";
    
    // Marble bag
    Probability::MarbleBag bag(5, 3, 2);  // 5 red, 3 white, 2 blue
    std::cout << "P(red marble) = " << bag.probability_single('r') << "\n";
    
    // Counting problems
    std::cout << "Fibonacci(10) = " << Counting::fibonacci(10) << "\n";
    std::cout << "5th Catalan number = " << Counting::catalan_number(5) << "\n";
    
    // Sequences
    std::vector<uint_t> arithmetic;
    Sequences::arithmetic_sequence(1, 3, 6, arithmetic);
    std::cout << "Arithmetic sequence: ";
    for (auto n : arithmetic) std::cout << n << " ";  // 1 4 7 10 13 16
    std::cout << "\n";
    
    return 0;
}
```

---

## Tips

- **Combinations vs Permutations**: If order matters, use permutations; if not, use combinations
- **With/Without Replacement**: Affects probability calculations significantly
- **Large Factorials**: Be aware of overflow with large numbers
- **Probability Range**: All probabilities are between 0 and 1
- **Set Operations**: Useful for working with groups and collections

---

## Quick Reference

| Problem Type | Function | Example |
|-------------|----------|---------|
| Choose k from n | `combination(n, k)` | Teams, lottery |
| Arrange k from n | `permutation(n, r)` | Races, passwords |
| Repeated choices | `combination_with_repetition` | Donuts, ice cream |
| Round table | `circular_permutation(n)` | Seating |
| Dice probability | `Dice::probability_*` | Games |
| Card probability | `Deck::probability_*` | Poker, blackjack |
| Stairs problem | `ways_to_climb_stairs` | DP problems |
| Make change | `ways_to_make_change` | Coin problems |