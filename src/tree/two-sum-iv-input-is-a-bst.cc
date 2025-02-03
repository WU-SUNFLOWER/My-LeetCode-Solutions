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
    std::vector<int> values_;

 public:
    void Search(TreeNode* node) {
        if (node == nullptr) return;
        Search(node->left);
        values_.push_back(node->val);
        Search(node->right);
    }

    bool findTarget(TreeNode* root, int k) {
        Search(root);
        for (int i = 0; i < values_.size(); ++i) {
            for (int j = i + 1; j < values_.size(); ++j) {
                if (values_[i] + values_[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
};