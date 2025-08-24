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

 // pair を返す
class Solution1 {
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
        int is_balanced = left_balanced && right_balanced && height_balanced;
        return std::make_pair(height, is_balanced);
    }
};

// 参照をもらって書き込む
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced;
        GetHeight(root, balanced);
        return balanced;
    }
private:
    int GetHeight(TreeNode* node, bool& balanced) {
        if (node == nullptr) {
            balanced = true;
            return 0;
        }
        bool left_balanced;
        bool right_balanced;
        int left_height = GetHeight(node->left, left_balanced);
        int right_height = GetHeight(node->right, right_balanced);
        int height = std::max(left_height, right_height) + 1;
        bool height_balanced = std::abs(left_height - right_height) <= 1;
        balanced = left_balanced && right_balanced && height_balanced;
        return height;
    }
};

// ポインタをもらって書き込む
class Solution3 {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced;
        GetHeight(root, &balanced);
        return balanced;
    }
private:
    int GetHeight(TreeNode* node, bool* balanced) {
        if (node == nullptr) {
            *balanced = true;
            return 0;
        }
        bool left_balanced;
        bool right_balanced;
        int left_height = GetHeight(node->left, &left_balanced);
        int right_height = GetHeight(node->right, &right_balanced);
        int height = std::max(left_height, right_height) + 1;
        bool height_balanced = std::abs(left_height - right_height) <= 1;
        *balanced = left_balanced && right_balanced && height_balanced;
        return height;
    }
};

// class で返す

class HeightAndBalancedInfo {
public:
    int height_;
    bool balanced_;

    HeightAndBalancedInfo(int height, bool balanced) : height_(height), balanced_(balanced) {};
};

class Solution4 {
public:
    bool isBalanced(TreeNode* root) {
        return GetHeightAndBalanced(root).balanced_;
    }
private:
    HeightAndBalancedInfo GetHeightAndBalanced(TreeNode* node) {
        if (node == nullptr) {
            return HeightAndBalancedInfo(0, true);
        }
        HeightAndBalancedInfo left_info = GetHeightAndBalanced(node->left);
        HeightAndBalancedInfo right_info = GetHeightAndBalanced(node->right);
        int left_height = left_info.height_;
        int right_height = right_info.height_;
        int height = std::max(left_height, right_height) + 1;
        bool height_balanced = std::abs(left_height - right_height) <= 1;
        bool left_balanced = left_info.balanced_;
        bool right_balanced = right_info.balanced_;
        int is_balanced = left_balanced && right_balanced && height_balanced;
        return HeightAndBalancedInfo(height, is_balanced);
    }
};

