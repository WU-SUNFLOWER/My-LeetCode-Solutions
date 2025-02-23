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
    int Search(TreeNode* node, int base) {
        if (!node->left && !node->right) {
            return base * 10 + node->val;
        }

        int sum = 0;
        if (node->left) {
            sum += Search(node->left, base * 10 + node->val);
        }
        if (node->right) {
            sum += Search(node->right, base * 10 + node->val);
        }
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return Search(root, 0);
    }
};