class Solution {
private:
    int ans_ = 0;

public:
    // <树中节点的最小值, 树中节点的最大值, 整棵树的节点和>
    std::tuple<int, int, int> Solve(TreeNode* root) {
        if (!root) {
            return {std::numeric_limits<int>::max(),
                    std::numeric_limits<int>::min(),
                    0};
        }

        auto [l_min, l_max, l_sum] = Solve(root->left);
        auto [r_min, r_max, r_sum] = Solve(root->right);

        if (!(l_max < root->val && root->val < r_min)) {
            return {std::numeric_limits<int>::min(),
                    std::numeric_limits<int>::max(),
                    0};
        }

        auto sum = root->val + l_sum + r_sum;
        ans_ = std::max(ans_, sum);
        return {std::min(l_min, root->val), 
                std::max(r_max, root->val), 
                sum};
    }

    int maxSumBST(TreeNode* root) {
        Solve(root);
        return ans_;
    }
};