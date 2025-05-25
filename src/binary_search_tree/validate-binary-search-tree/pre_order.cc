class Solution {
public:
    // node->val必须在(low, high)区间范围内
    bool Solve(TreeNode* node, int64_t low, int64_t high) {
        if (!node) {
            return true;
        }
        return low < node->val &&
               node->val < high &&
               Solve(node->left, low, node->val) &&
               Solve(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return Solve(root, 
                     std::numeric_limits<int64_t>::min(),
                     std::numeric_limits<int64_t>::max());
    }
};