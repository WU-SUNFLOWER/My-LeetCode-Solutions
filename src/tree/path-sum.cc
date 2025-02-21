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
public:
    bool Search(TreeNode* node, int sum, int target) {
        // 碰到叶子节点
        if (!node->left && !node->right) {
            return node->val + sum == target;
        }
        // 碰到普通节点
        if (node->left && Search(node->left, node->val + sum, target)) {
            return true;
        }
        if (node->right && Search(node->right, node->val + sum, target)) {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return root ? Search(root, 0, targetSum) : false;
    }
};