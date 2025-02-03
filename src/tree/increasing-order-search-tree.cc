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
    TreeNode* BuildNewTree(TreeNode* node) {
        TreeNode* new_left_tree = nullptr;
        TreeNode* new_right_tree = nullptr;

        if (node->left) {
            new_left_tree = BuildNewTree(node->left);
            node->left = nullptr;

            TreeNode* tail = new_left_tree;
            while (tail->right != nullptr) {
                tail = tail->right;
            }
            tail->right = node;
        }

        if (node->right) {
            new_right_tree = BuildNewTree(node->right);
            node->right = new_right_tree;
        }

        return new_left_tree ? new_left_tree : node;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        return BuildNewTree(root);
    }
};