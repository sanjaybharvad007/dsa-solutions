// arrays/max_subarray.hpp
// Maximum Subarray  (LeetCode #53 · Medium)
// -----------------------------------------
// Find the contiguous subarray with the largest sum; return that sum.
//
// APPROACH — Kadane's algorithm
// Keep a running sum. At each element decide: extend the current subarray, or
// start fresh here -> max(n, current + n). If the running sum goes negative it
// can only hurt what follows, so we drop it.
//
// Time:  O(n)      Space: O(1)
#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace dsa {

inline int max_subarray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("nums must be non-empty");
    }
    int current = nums[0];
    int best = nums[0];
    for (std::size_t i = 1; i < nums.size(); ++i) {
        current = std::max(nums[i], current + nums[i]);
        best = std::max(best, current);
    }
    return best;
}

}  // namespace dsa
