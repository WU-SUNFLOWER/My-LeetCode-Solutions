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

#define IS_NULL(x) ((x) == nullptr)

class Solution {
public:
    int Search(TreeNode* node) {
        if (IS_NULL(node)) {
            return 0;
        }
        return std::max(Search(node->left), Search(node->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        return Search(root);
    }
};