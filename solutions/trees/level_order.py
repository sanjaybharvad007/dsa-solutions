"""
Binary Tree Level Order Traversal  (LeetCode #102 · Medium)
-----------------------------------------------------------
Return the node values grouped by level, top to bottom.

APPROACH — breadth-first search with a queue
Process the tree level by level. For each level, record how many nodes are in
the queue right now (that's the level's size), then pop exactly that many,
collecting their values and enqueuing their children for the next level.

WHY BFS
Levels map naturally onto BFS: a queue always holds one "frontier" of the tree
at a time. The size-snapshot trick is what lets us know where one level ends.

Time:  O(n)   — each node enqueued/dequeued once
Space: O(n)   — the queue holds up to a full level
"""

from __future__ import annotations

from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val: int = 0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def level_order(root: Optional[TreeNode]) -> list[list[int]]:
    if root is None:
        return []

    result: list[list[int]] = []
    queue = deque([root])
    while queue:
        level_size = len(queue)          # snapshot: nodes in THIS level
        level_vals = []
        for _ in range(level_size):
            node = queue.popleft()
            level_vals.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        result.append(level_vals)
    return result
