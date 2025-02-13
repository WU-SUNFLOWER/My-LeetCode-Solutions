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
    int ans_ = 1 << 31;
public:
    int ComputeMaxGain(TreeNode* cur) {
        if (!cur) {
            return 0;
        }

        int max_gain_left = ComputeMaxGain(cur->left);
        int max_gain_right = ComputeMaxGain(cur->right);

        ans_ = std::max({ ans_, max_gain_left + max_gain_right + cur->val });

        return std::max({ max_gain_left + cur->val, max_gain_right + cur->val, cur->val, 0 });
    }

    int maxPathSum(TreeNode* root) {
        ComputeMaxGain(root);
        return ans_;
    }
};