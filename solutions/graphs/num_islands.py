"""
Number of Islands  (LeetCode #200 · Medium)
-------------------------------------------
Given a 2D grid of '1' (land) and '0' (water), count the islands. An island is
land connected horizontally or vertically.

APPROACH — depth-first search / flood fill
Scan every cell. When we hit unvisited land, that's a new island: increment the
count, then DFS out from it, sinking every connected land cell to '0' so we
don't count it again.

WHY IT WORKS
Each DFS "floods" one entire island in one go, marking it visited. So the
number of times we START a DFS equals the number of islands.

Time:  O(rows * cols)   — each cell visited once
Space: O(rows * cols)   — worst-case recursion depth (all land)
"""

from __future__ import annotations


def num_islands(grid: list[list[str]]) -> int:
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])

    def sink(r: int, c: int) -> None:
        # Out of bounds or water -> stop.
        if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] != "1":
            return
        grid[r][c] = "0"          # mark visited
        sink(r + 1, c)            # explore 4 neighbors
        sink(r - 1, c)
        sink(r, c + 1)
        sink(r, c - 1)

    count = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                sink(r, c)
    return count
