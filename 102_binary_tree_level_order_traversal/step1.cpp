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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::vector<TreeNode*> nodes = {root};  // current-level nodes.
        std::vector<TreeNode*> next_nodes;  // next-level nodes.

        while (!nodes.empty()) {
            std::vector<int> current_level_values;
            for (auto node : nodes) {
                current_level_values.push_back(node->val);
                if (node->left) next_nodes.push_back(node->left);
                if (node->right) next_nodes.push_back(node->right);
            }
            result.push_back(current_level_values);
            nodes = next_nodes;
            next_nodes.clear();
        }

        return result;
    }
};
