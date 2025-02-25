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
    int count_ = 0;
    int flag = false;
    int ans_ = -1;

public:
    void Search(TreeNode* node, int k) {
        if (flag) return;
        if (!node) return;
        
        Search(node->left, k);
        if (++count_ == k) {
            ans_ = node->val;
            flag = true;
            return;
        }
        Search(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        Search(root, k);
        return ans_;
    }
};