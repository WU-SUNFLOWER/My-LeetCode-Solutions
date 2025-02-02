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
    TreeNode* sub_root_;
public:
    bool Check(TreeNode* node, TreeNode* sub_node) {
        if (IS_NULL(node) || IS_NULL(sub_node)) {
            return IS_NULL(node) && IS_NULL(sub_node);
        }
        if (node->val == sub_node->val) {
            return Check(node->left, sub_node->left) && Check(node->right, sub_node->right);
        }
        return false;
    }

    bool Search(TreeNode* node) {
        if (Check(node, sub_root_)) {
            return true;
        }
        if (!IS_NULL(node)) {
            if (Search(node->left) || Search(node->right)) {
                return true;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sub_root_ = subRoot;
        return Search(root);
    }
};