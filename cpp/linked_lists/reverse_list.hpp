// linked_lists/reverse_list.hpp
// Reverse Linked List  (LeetCode #206 · Easy)
// -------------------------------------------
// Reverse a singly linked list, return the new head.
//
// APPROACH — iterative pointer reversal
// Walk once, flipping each node's `next` to point backward. Keep prev, curr,
// and a temp for curr->next so we don't lose the rest of the list.
//
// Time:  O(n)      Space: O(1)
#pragma once

#include <vector>

namespace dsa {

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int v, ListNode* n = nullptr) : val(v), next(n) {}
};

inline ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nxt = curr->next;  // remember the rest
        curr->next = prev;           // flip pointer backward
        prev = curr;                 // advance prev
        curr = nxt;                  // advance curr
    }
    return prev;  // new head
}

// --- helpers for tests ---
inline ListNode* from_vector(const std::vector<int>& vals) {
    ListNode* head = nullptr;
    for (auto it = vals.rbegin(); it != vals.rend(); ++it) {
        head = new ListNode(*it, head);
    }
    return head;
}

inline std::vector<int> to_vector(ListNode* head) {
    std::vector<int> out;
    while (head != nullptr) {
        out.push_back(head->val);
        head = head->next;
    }
    return out;
}

inline void free_list(ListNode* head) {
    while (head != nullptr) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

}  // namespace dsa
