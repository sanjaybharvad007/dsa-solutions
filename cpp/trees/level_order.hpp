// trees/level_order.hpp
// Binary Tree Level Order Traversal  (LeetCode #102 · Medium)
// -----------------------------------------------------------
// Return node values grouped by level, top to bottom.
//
// APPROACH — BFS with a queue
// Process level by level. Snapshot the queue size (that's the current level's
// node count), pop exactly that many, collect their values, and enqueue their
// children for the next level.
//
// Time:  O(n)      Space: O(n)
#pragma once

#include <queue>
#include <vector>

namespace dsa {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : val(v), left(l), right(r) {}
};

inline std::vector<std::vector<int>> level_order(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int level_size = static_cast<int>(q.size());  // snapshot this level
        std::vector<int> level;
        for (int i = 0; i < level_size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

inline void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

}  // namespace dsa
