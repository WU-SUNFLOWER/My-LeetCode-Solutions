class Solution {
private:
    int ans_ = 0;

public:
    // <树中节点的最小值, 树中节点的最大值, 整棵树的节点和, 是否为二叉搜索树>
    std::tuple<int, int, int, bool> Solve(TreeNode* root) {
        if (!root) {
            return {std::numeric_limits<int>::max(),
                    std::numeric_limits<int>::min(),
                    0, true};
        }

        auto [l_min, l_max, l_sum, l_flag] = Solve(root->left);
        auto [r_min, r_max, r_sum, r_flag] = Solve(root->right);
        auto sum = root->val + l_sum + r_sum;
        bool flag = false;
        if (l_flag && r_flag && 
            l_max < root->val && 
            root->val < r_min) 
        {
            flag = true;
            ans_ = std::max(ans_, sum);
        }
        return {std::min(l_min, root->val), 
                std::max(r_max, root->val), 
                sum, flag};
    }

    int maxSumBST(TreeNode* root) {
        Solve(root);
        return ans_;
    }
};