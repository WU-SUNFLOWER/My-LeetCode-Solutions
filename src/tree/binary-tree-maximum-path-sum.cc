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
private:
    int max_path_price_ = (1ll << 31);
public:
    int MaxGain(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left_max_gain = std::max(MaxGain(node->left), 0);
        int right_max_gain = std::max(MaxGain(node->right), 0);

        int current_path_price = node->val + left_max_gain + right_max_gain;
        max_path_price_ = std::max(max_path_price_, current_path_price);

        return node->val + std::max(left_max_gain, right_max_gain);
    }

    int maxPathSum(TreeNode* root) {
        MaxGain(root);
        return max_path_price_;
    }
};