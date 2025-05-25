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
    // 以node为根的树不包含1 => true
    // 以node为根的树包含1 => false
    bool Solve(TreeNode* node, TreeNode** link) {
        if (!node) return true;
        bool l_result = Solve(node->left, &node->left);
        bool r_result = Solve(node->right, &node->right);
        bool result = node->val == 0 && l_result && r_result;
        if (result) {
            *link = nullptr;
        }
        return result;
    }

    TreeNode* pruneTree(TreeNode* root) {
        Solve(root, &root);
        return root;
    }
};