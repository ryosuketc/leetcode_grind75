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
private:
    int diameter;

    int LongestPath(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }
        int left_path = LongestPath(node->left);
        int right_path = LongestPath(node->right);
        diameter = std::max(diameter, left_path + right_path + 2);
        return std::max(left_path, right_path) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        LongestPath(root);
        return diameter;
    }
};


class Solution2 {
private:
    int diameter;

    int LongestPath(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_path = LongestPath(node->left);
        int right_path = LongestPath(node->right);
        diameter = std::max(diameter, left_path + right_path);
        return std::max(left_path, right_path) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        LongestPath(root);
        return diameter;
    }
};
