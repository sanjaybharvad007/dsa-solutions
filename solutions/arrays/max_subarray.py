"""
Maximum Subarray  (LeetCode #53 · Medium)
-----------------------------------------
Find the contiguous subarray with the largest sum and return that sum.

APPROACH — Kadane's algorithm
Walk through the array keeping a running sum. At each element, decide: is it
better to EXTEND the current subarray, or START FRESH from this element? That
choice is `max(n, current + n)`. Track the best sum seen along the way.

INTUITION
If the running sum ever goes negative, it can only drag down whatever comes
next — so we drop it and start over from the current element.

Time:  O(n)   — single pass
Space: O(1)   — just two running variables
"""

from __future__ import annotations


def max_subarray(nums: list[int]) -> int:
    if not nums:
        raise ValueError("nums must be non-empty")

    current = best = nums[0]
    for n in nums[1:]:
        # Extend the existing subarray, or start a new one at n.
        current = max(n, current + n)
        best = max(best, current)
    return best
