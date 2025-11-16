/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <stack>
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> node_and_depth;
        node_and_depth.push(std::make_pair(root, 1));
        int max_depth = 0;
        while (!node_and_depth.empty()) {
            auto [node, depth] = node_and_depth.top();
            node_and_depth.pop();
            if (!node) {
                continue;
            }
            max_depth = std::max(max_depth, depth);
            node_and_depth.push(std::make_pair(node->left, depth + 1));
            node_and_depth.push(std::make_pair(node->right, depth + 1));
        }
        return max_depth;
    }
};
