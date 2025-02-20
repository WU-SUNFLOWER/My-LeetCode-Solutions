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
private:
    bool Check(TreeNode* p_node, TreeNode* q_node) {
        if (IS_NULL(p_node) || IS_NULL(q_node)) {
            if (!(IS_NULL(p_node) && IS_NULL(q_node))) {
                return false;
            } else {
                return true;
            }
        }
        if (p_node->val != q_node->val) {
            return false;
        }
        return Check(p_node->left, q_node->left) && Check(p_node->right, q_node->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return Check(p, q);
    }
};