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

#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int level_size = nodes.size();
            std::vector<int> current_level_values;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                current_level_values.push_back(node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        result.push_back(current_level_values);
        }
        return result;
    }
};
