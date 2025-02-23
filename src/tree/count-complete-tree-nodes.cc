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
    int countLevel(TreeNode* node) {
        int level = 0;
        while (node != nullptr) {
            ++level;
            node = node->left;
        }
        return level;
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_level = countLevel(root->left);
        int right_level = countLevel(root->right);

        // 如果可以判定左子树一定是满二叉树
        if (left_level == right_level) {
            return 1 + ((1 << left_level) - 1) + countNodes(root->right);
        }
        // 如果可以判定右子树一定是满二叉树
        else {
            return 1 + ((1 << right_level) - 1) + countNodes(root->left);
        }
    }
};