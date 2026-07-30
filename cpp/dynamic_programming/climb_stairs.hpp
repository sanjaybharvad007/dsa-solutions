// dynamic_programming/climb_stairs.hpp
// Climbing Stairs  (LeetCode #70 · Easy)
// --------------------------------------
// Steps of 1 or 2 at a time; count distinct ways to climb `n` stairs.
//
// APPROACH — bottom-up DP
// To reach step i you came from i-1 (a 1-step) or i-2 (a 2-step), so
// ways(i) = ways(i-1) + ways(i-2) — Fibonacci. Build up from base cases,
// keeping only the last two values.
//
// Time:  O(n)      Space: O(1)
#pragma once

#include <stdexcept>

namespace dsa {

inline long long climb_stairs(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n <= 2) return n;

    long long prev2 = 1;  // ways(1)
    long long prev1 = 2;  // ways(2)
    for (int i = 3; i <= n; ++i) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

}  // namespace dsa
