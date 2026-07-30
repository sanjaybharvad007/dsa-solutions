"""
Two Sum  (LeetCode #1 · Easy)
-----------------------------
Given an array of integers `nums` and a target, return the indices of the two
numbers that add up to target.

APPROACH — hash map (one pass)
Store each number's index as we go. For each number `n`, check whether
`target - n` (its "complement") has already been seen. If so, we're done.

WHY IT'S GOOD
The brute force is two nested loops: O(n^2). By trading space for time — a hash
map giving O(1) lookups — we solve it in a single pass.

Time:  O(n)   — one pass over the array
Space: O(n)   — the hash map can hold up to n entries
"""

from __future__ import annotations


def two_sum(nums: list[int], target: int) -> list[int]:
    seen: dict[int, int] = {}  # value -> index
    for i, n in enumerate(nums):
        complement = target - n
        if complement in seen:
            return [seen[complement], i]
        seen[n] = i
    return []  # problem guarantees a solution, but be safe
