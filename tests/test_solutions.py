"""
Tests for every solution. Each problem has a few cases including edge cases.
Run all with:  python -m pytest -q
"""

from solutions.arrays.two_sum import two_sum
from solutions.arrays.max_subarray import max_subarray
from solutions.linked_lists.reverse_list import reverse_list, from_list, to_list
from solutions.trees.level_order import level_order, TreeNode
from solutions.dynamic_programming.climb_stairs import climb_stairs
from solutions.graphs.num_islands import num_islands


# ---- Two Sum ----
def test_two_sum():
    assert two_sum([2, 7, 11, 15], 9) == [0, 1]
    assert two_sum([3, 2, 4], 6) == [1, 2]
    assert two_sum([3, 3], 6) == [0, 1]


# ---- Max Subarray ----
def test_max_subarray():
    assert max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6  # [4,-1,2,1]
    assert max_subarray([1]) == 1
    assert max_subarray([-1, -2, -3]) == -1  # all negative


# ---- Reverse Linked List ----
def test_reverse_list():
    head = from_list([1, 2, 3, 4, 5])
    assert to_list(reverse_list(head)) == [5, 4, 3, 2, 1]
    assert to_list(reverse_list(from_list([]))) == []
    assert to_list(reverse_list(from_list([1]))) == [1]


# ---- Level Order Traversal ----
def test_level_order():
    #      3
    #     / \
    #    9  20
    #      /  \
    #     15   7
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    assert level_order(root) == [[3], [9, 20], [15, 7]]
    assert level_order(None) == []


# ---- Climbing Stairs ----
def test_climb_stairs():
    assert climb_stairs(2) == 2
    assert climb_stairs(3) == 3
    assert climb_stairs(5) == 8  # Fibonacci


# ---- Number of Islands ----
def test_num_islands():
    grid = [
        list("11110"),
        list("11010"),
        list("11000"),
        list("00000"),
    ]
    assert num_islands(grid) == 1

    grid2 = [
        list("11000"),
        list("11000"),
        list("00100"),
        list("00011"),
    ]
    assert num_islands(grid2) == 3
