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
    std::vector<int> path_;
    std::vector<std::vector<int>> paths_;
public:
    void Solve(TreeNode* node, int target_sum) {
        if (!node) {
            return;
        }
        path_.emplace_back(node->val);
        // 叶子节点
        if (!node->left && !node->right) {
            if (target_sum - node->val == 0) {
                paths_.emplace_back(path_);
            }
            return;
        }
        // 非叶子节点
        if (node->left) {
            Solve(node->left, target_sum - node->val);
            path_.pop_back();
        }
        if (node->right) {
            Solve(node->right, target_sum - node->val);
            path_.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        Solve(root, targetSum);
        return paths_;
    }
};