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
class SolutionWA {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return std::abs(getMaxHeight(root->left) - getMaxHeight(root->right)) <= 1;
    }
private:
    int getMaxHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(getMaxHeight(node->left), getMaxHeight(node->right));
    }
};


class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return (std::abs(getMaxHeight(root->left) - getMaxHeight(root->right)) <= 1
                && isBalanced(root->left) && isBalanced(root->right));
    }
private:
    int getMaxHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(getMaxHeight(node->left), getMaxHeight(node->right));
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        bool heightBalanced = std::abs(left_height - right_height) <= 1;
        return heightBalanced && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
};
