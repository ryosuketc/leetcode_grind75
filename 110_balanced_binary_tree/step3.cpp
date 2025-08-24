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

 # include <utility>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return GetHeightAndBalanced(root).second;
    }
private:
    std::pair<int, bool> GetHeightAndBalanced(TreeNode* node) {
        if (node == nullptr) {
            return std::make_pair(0, true);
        }
        auto [left_height, left_balanced] = GetHeightAndBalanced(node->left);
        auto [right_height, right_balanced] = GetHeightAndBalanced(node->right);
        int height = std::max(left_height, right_height) + 1;
        bool height_balanced = std::abs(left_height - right_height) <= 1;
        bool balanced = height_balanced && left_balanced && right_balanced;
        return std::make_pair(height, balanced);
    }
};
