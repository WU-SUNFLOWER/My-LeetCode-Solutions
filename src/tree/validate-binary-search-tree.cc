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
    std::vector<int> middle_ordered_;
public:
    void MiddleTraverse(TreeNode* node) {
        if (!node) return;
        MiddleTraverse(node->left);
        middle_ordered_.push_back(node->val);
        MiddleTraverse(node->right);
    }

    bool isValidBST(TreeNode* root) {
        MiddleTraverse(root);
        if (middle_ordered_.size() > 1) {
            for (int i = 1; i < middle_ordered_.size(); ++i) {
                if (!(middle_ordered_[i - 1] < middle_ordered_[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};