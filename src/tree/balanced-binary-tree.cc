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
    bool Search(TreeNode* node, int& depth) {
        if (IS_NULL(node)) {
            depth = 0;
            return true;
        }

        int left_depth = -1;
        int right_depth = -1;
        bool flag = Search(node->left, left_depth);
        if (!flag) {
            return false;
        }
        flag = Search(node->right, right_depth);
        if (!flag) {
            return false;
        }

        depth = std::max(left_depth, right_depth) + 1;
        return std::abs(left_depth - right_depth) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        int total_depth = -1;
        return Search(root, total_depth);
    }
};