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
    int PathSumWithFixedRoot(TreeNode* node, int target_sum) {
        if (node == nullptr) {
            return 0;
        }
        return (node->val == target_sum) + PathSumWithFixedRoot(node->left, target_sum - node->val) + PathSumWithFixedRoot(node->right, target_sum - node->val);
    }

    int pathSum(TreeNode* root, int target_sum) {
        if (!root) {
            return 0;
        }
        return PathSumWithFixedRoot(root, target_sum) + pathSum(root->left, target_sum) + pathSum(root->right, target_sum);
    }
};