// tests/test_solutions.cpp
// A small, dependency-free test harness (no external framework needed).
#include <iostream>
#include <string>
#include <vector>

#include "arrays/two_sum.hpp"
#include "arrays/max_subarray.hpp"
#include "linked_lists/reverse_list.hpp"
#include "trees/level_order.hpp"
#include "dynamic_programming/climb_stairs.hpp"
#include "graphs/num_islands.hpp"

namespace {
int tests_run = 0;
int tests_passed = 0;

void check(bool cond, const std::string& name) {
    ++tests_run;
    if (cond) {
        ++tests_passed;
        std::cout << "  [PASS] " << name << "\n";
    } else {
        std::cout << "  [FAIL] " << name << "\n";
    }
}
}  // namespace

int main() {
    using namespace dsa;
    std::cout << "Running C++ DSA tests...\n";

    // Two Sum
    check(two_sum({2, 7, 11, 15}, 9) == std::vector<int>({0, 1}), "two_sum basic");
    check(two_sum({3, 3}, 6) == std::vector<int>({0, 1}), "two_sum duplicates");

    // Max Subarray
    check(max_subarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6, "max_subarray mixed");
    check(max_subarray({-1, -2, -3}) == -1, "max_subarray all negative");

    // Reverse Linked List
    {
        ListNode* head = from_vector({1, 2, 3, 4, 5});
        ListNode* rev = reverse_list(head);
        check(to_vector(rev) == std::vector<int>({5, 4, 3, 2, 1}), "reverse_list");
        free_list(rev);
    }

    // Level Order Traversal
    {
        TreeNode* root = new TreeNode(3, new TreeNode(9),
                                      new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        auto levels = level_order(root);
        bool ok = levels.size() == 3 &&
                  levels[0] == std::vector<int>({3}) &&
                  levels[1] == std::vector<int>({9, 20}) &&
                  levels[2] == std::vector<int>({15, 7});
        check(ok, "level_order");
        free_tree(root);
    }

    // Climbing Stairs
    check(climb_stairs(5) == 8, "climb_stairs fib");
    check(climb_stairs(2) == 2, "climb_stairs base");

    // Number of Islands
    {
        std::vector<std::vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        check(num_islands(grid) == 3, "num_islands");
    }

    std::cout << "\n" << tests_passed << "/" << tests_run << " tests passed\n";
    return (tests_passed == tests_run) ? 0 : 1;
}
