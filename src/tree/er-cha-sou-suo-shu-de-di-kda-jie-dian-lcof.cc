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
    std::vector<int> ordered_;
public:
    void Traversal(TreeNode* node) {
        if (!node) return;
        Traversal(node->left);
        ordered_.emplace_back(node->val);
        Traversal(node->right);
    }

    int findTargetNode(TreeNode* root, int cnt) {
        Traversal(root);
        return ordered_.at(ordered_.size() - cnt);
    }
};