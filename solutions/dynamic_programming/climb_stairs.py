"""
Climbing Stairs  (LeetCode #70 · Easy, but the gateway to DP)
-------------------------------------------------------------
You climb a staircase of `n` steps, taking 1 or 2 steps at a time. How many
distinct ways can you reach the top?

APPROACH — dynamic programming (bottom-up)
To reach step `i`, you arrived either from step `i-1` (a 1-step) or step `i-2`
(a 2-step). So ways(i) = ways(i-1) + ways(i-2) — it's the Fibonacci sequence.

We build up from the base cases instead of recursing, which avoids
recomputing the same subproblems (the whole point of DP).

Time:  O(n)   — one loop
Space: O(1)   — we only keep the last two values
"""

from __future__ import annotations


def climb_stairs(n: int) -> int:
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 2:
        return n

    # ways to reach the two previous steps
    prev2, prev1 = 1, 2  # ways(1)=1, ways(2)=2
    for _ in range(3, n + 1):
        prev2, prev1 = prev1, prev1 + prev2
    return prev1
