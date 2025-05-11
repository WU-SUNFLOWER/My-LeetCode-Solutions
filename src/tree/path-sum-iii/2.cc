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
    int ans_ = 0;
    int target_ = 0;
    std::unordered_map<int64_t, int> prefix_sum_map_;

public:
    void Solve(TreeNode* node, int64_t prefix_sum) {
        if (!node) return;

        prefix_sum_map_[prefix_sum] += 1;

        // prefix_sum[node] - prefix_sum[ancestor] + node->val == target_
        // prefix_sum[ancestor] == prefix_sum[node] + node->val - target_
        int64_t ancestor_prefix_sum = prefix_sum + node->val - target_;
        if (prefix_sum_map_.contains(ancestor_prefix_sum)) {
            ans_ += prefix_sum_map_[ancestor_prefix_sum];
        }

        Solve(node->left, prefix_sum + node->val);
        Solve(node->right, prefix_sum + node->val);

        if (--prefix_sum_map_[prefix_sum] == 0) {
            prefix_sum_map_.erase(prefix_sum);
        }
    }

    int pathSum(TreeNode* root, int target_sum) {
        target_ = target_sum;
        Solve(root, 0);
        return ans_;
    }
};