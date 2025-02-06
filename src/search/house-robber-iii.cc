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
    std::unordered_map<TreeNode*, int> robbed_cache_;
    std::unordered_map<TreeNode*, int> no_robbed_cache_;

public:
    int DFS(TreeNode* cur_node, bool is_parent_robbed) {
        if (!cur_node) {
            return 0;
        }
        // 1. 当前节点可以被偷，也可以被不偷
        if (!is_parent_robbed) {
            if (robbed_cache_.contains(cur_node)) {
                return robbed_cache_[cur_node];
            }

            int left_robbed = DFS(cur_node->left, true);
            int right_robbed = DFS(cur_node->right, true);

            int left_no_robbed = DFS(cur_node->left, false);
            int right_no_robbed = DFS(cur_node->right, false);

            robbed_cache_[cur_node] = std::max(left_robbed + right_robbed + cur_node->val, left_no_robbed + right_no_robbed);

            return robbed_cache_[cur_node];
        }
        // 2. 当前节点不能被偷
        else {
            if (no_robbed_cache_.contains(cur_node)) {
                return no_robbed_cache_[cur_node];
            }

            int left_no_robbed = DFS(cur_node->left, false);
            int right_no_robbed = DFS(cur_node->right, false);

            no_robbed_cache_[cur_node] = left_no_robbed + right_no_robbed;

            return no_robbed_cache_[cur_node];
        }
    }

    int rob(TreeNode* root) {
        if (!root) return 0;
        return DFS(root, false);
    }
};