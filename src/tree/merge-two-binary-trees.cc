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
    TreeNode* Merge(TreeNode* node1, TreeNode* node2) {
        if (IS_NULL(node1) && IS_NULL(node2)) {
            return nullptr;
        }
        if (IS_NULL(node1) || IS_NULL(node2)) {
            if (!IS_NULL(node1)) {
                return node1;
            } else {
                return node2;
            }
        }
        TreeNode* new_node = new TreeNode(node1->val + node2->val);
        new_node->left = Merge(node1->left, node2->left);
        new_node->right = Merge(node1->right, node2->right);
        return new_node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return Merge(root1, root2);
    }
};