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
    int answer_ { 0 };
public:
    int Search(TreeNode* node) {
        if (IS_NULL(node)) {
            return 0;
        }

        int left_depth = Search(node->left);
        int right_depth = Search(node->right);

        answer_ = std::max(answer_, left_depth + right_depth);

        return std::max(left_depth, right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Search(root);
        return answer_;
    }
};