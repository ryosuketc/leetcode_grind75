/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// return
# include <stack>

class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p->val;
        int q_val = q->val;
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            int node_val = node->val;
            if (p_val > node_val && q_val > node_val) {
                nodes.push(node->right);
                continue;
            }
            if (p_val < node_val && q_val < node_val) {
                nodes.push(node->left);
                continue;
            }
            return node;
        }
        // Unreachable
        return root;
    }
};


// unreachable
# include <stack>

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p->val;
        int q_val = q->val;
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            int node_val = node->val;
            if (p_val > node_val && q_val > node_val) {
                nodes.push(node->right);
                continue;
            }
            if (p_val < node_val && q_val < node_val) {
                nodes.push(node->left);
                continue;
            }
            return node;
        }
        std::unreachable();
    }
};


// 無限ループ
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p->val;
        int q_val = q->val;
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        while (true) {
            TreeNode* node = nodes.top();
            nodes.pop();
            int node_val = node->val;
            if (p_val > node_val && q_val > node_val) {
                nodes.push(node->right);
                continue;
            }
            if (p_val < node_val && q_val < node_val) {
                nodes.push(node->left);
                continue;
            }
            return node;
        }
    }
};
