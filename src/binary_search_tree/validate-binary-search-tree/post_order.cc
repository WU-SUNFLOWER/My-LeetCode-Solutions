class Solution {
private:
    bool ans_ = true;

public:
    std::pair<int64_t, int64_t> Solve(TreeNode* node) {
        if (!node) {
            return {std::numeric_limits<int64_t>::max(),
                    std::numeric_limits<int64_t>::min()};
        }

        auto [l_min, l_max] = Solve(node->left);
        auto [r_min, r_max] = Solve(node->right);

        if (!(l_max < node->val && node->val < r_min)) {
            ans_ = false;
        }

        return {std::min({l_min, r_min, (int64_t)node->val}), 
                std::max({l_max, r_max, (int64_t)node->val})};
    }

    bool isValidBST(TreeNode* root) {
        Solve(root);
        return ans_;
    }
};