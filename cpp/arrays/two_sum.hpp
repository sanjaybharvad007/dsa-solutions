// arrays/two_sum.hpp
// Two Sum  (LeetCode #1 · Easy)
// -----------------------------
// Return the indices of the two numbers that add up to `target`.
//
// APPROACH — hash map, one pass
// For each number, check whether its complement (target - n) was already seen.
// std::unordered_map gives O(1) average lookups, turning the naive O(n^2)
// double loop into a single O(n) pass.
//
// Time:  O(n)      Space: O(n)
#pragma once

#include <unordered_map>
#include <vector>

namespace dsa {

inline std::vector<int> two_sum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;  // value -> index
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int complement = target - nums[i];
        auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[i]] = i;
    }
    return {};  // problem guarantees a solution
}

}  // namespace dsa
