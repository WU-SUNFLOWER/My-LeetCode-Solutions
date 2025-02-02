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
#define IS_LEAF_NODE(n) (IS_NULL(n->left) && IS_NULL(n->right))

class Solution {
public:
    int Sum(TreeNode* node, TreeNode* parent) {
        if (IS_NULL(node)) {
            return 0;
        }
        if (IS_LEAF_NODE(node) && parent && node == parent->left) {
            return node->val;
        }
        return Sum(node->left, node) + Sum(node->right, node);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return Sum(root, nullptr);
    }
};