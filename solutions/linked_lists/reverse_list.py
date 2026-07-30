"""
Reverse Linked List  (LeetCode #206 · Easy)
-------------------------------------------
Reverse a singly linked list and return the new head.

APPROACH — iterative pointer reversal
Walk the list once, flipping each node's `next` pointer to point backward.
Keep three references: `prev` (already-reversed part), `curr` (node we're on),
and a temp for `curr.next` so we don't lose the rest of the list.

Time:  O(n)   — visit each node once
Space: O(1)   — in-place, only a few pointers
"""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: "Optional[ListNode]" = None):
        self.val = val
        self.next = next


def reverse_list(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr is not None:
        nxt = curr.next    # remember the rest of the list
        curr.next = prev   # flip the pointer backward
        prev = curr        # advance prev
        curr = nxt         # advance curr
    return prev            # prev is the new head


# --- small helpers so tests can build/inspect lists easily ---
def from_list(values: list[int]) -> Optional[ListNode]:
    head = None
    for v in reversed(values):
        head = ListNode(v, head)
    return head


def to_list(head: Optional[ListNode]) -> list[int]:
    out = []
    while head is not None:
        out.append(head.val)
        head = head.next
    return out
