class Solution {
private:
    int64_t last_val_ = std::numeric_limits<int64_t>::min();

public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (!(last_val_ < root->val)) return false; 
        last_val_ = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};