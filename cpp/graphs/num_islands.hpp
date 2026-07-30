// graphs/num_islands.hpp
// Number of Islands  (LeetCode #200 · Medium)
// -------------------------------------------
// Count islands in a grid of '1' (land) / '0' (water); land connects
// horizontally and vertically.
//
// APPROACH — DFS flood fill
// Scan every cell. On unvisited land, that's a new island: count it, then DFS
// out and sink every connected land cell to '0' so it's not counted again.
//
// Time:  O(rows * cols)      Space: O(rows * cols) worst-case recursion
#pragma once

#include <vector>

namespace dsa {

inline void sink(std::vector<std::vector<char>>& grid, int r, int c) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
        return;
    }
    grid[r][c] = '0';        // mark visited
    sink(grid, r + 1, c);    // explore 4 neighbors
    sink(grid, r - 1, c);
    sink(grid, r, c + 1);
    sink(grid, r, c - 1);
}

inline int num_islands(std::vector<std::vector<char>> grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int count = 0;
    for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
        for (int c = 0; c < static_cast<int>(grid[0].size()); ++c) {
            if (grid[r][c] == '1') {
                ++count;
                sink(grid, r, c);
            }
        }
    }
    return count;
}

}  // namespace dsa
