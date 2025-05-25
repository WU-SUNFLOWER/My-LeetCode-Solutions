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
    void BuildNewTree(TreeNode* node_in_old_tree, TreeNode** parent_link_in_new_tree, int low, int high) {
        if (IS_NULL(node_in_old_tree)) {
            return;
        }
        if (node_in_old_tree->val < low) {
            BuildNewTree(node_in_old_tree->right, parent_link_in_new_tree, low, high);
        }
        else if (node_in_old_tree->val > high) {
            BuildNewTree(node_in_old_tree->left, parent_link_in_new_tree, low, high);
        }
        else {
            TreeNode* new_node = new TreeNode(node_in_old_tree->val);
            *parent_link_in_new_tree = new_node;
            BuildNewTree(node_in_old_tree->left, &new_node->left, low, high);
            BuildNewTree(node_in_old_tree->right, &new_node->right, low, high);
        }
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* new_root = nullptr;
        BuildNewTree(root, &new_root, low, high);
        return new_root;
    }
};