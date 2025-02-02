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

#define IS_NULL(x) (x == nullptr)

class Solution {
public:
    void Search(TreeNode* node) {
        if (IS_NULL(node)) {
            return;
        }
        std::swap(node->left, node->right);
        invertTree(node->left);
        invertTree(node->right);
    }

    TreeNode* invertTree(TreeNode* node) {
        Search(node);
        return node;
    }
};