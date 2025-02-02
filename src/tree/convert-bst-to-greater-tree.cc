/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#define IS_NULL(x) (x == nullptr)

class Solution {
private:
    std::vector<int> middle_ordered_;
    std::vector<int> sum_;
    std::map<int, int> values_in_new_tree_;

public:
    void MiddleOrderTraverse(TreeNode* node) {
        if (IS_NULL(node))
            return;
        MiddleOrderTraverse(node->left);
        middle_ordered_.push_back(node->val);
        MiddleOrderTraverse(node->right);
    }

    TreeNode* CreateNewTree(TreeNode* old_tree_node) {
        if (IS_NULL(old_tree_node)) {
            return nullptr;
        }

        int val = values_in_new_tree_[old_tree_node->val];
        TreeNode* new_tree_node = new TreeNode(val);

        new_tree_node->left = CreateNewTree(old_tree_node->left);
        new_tree_node->right = CreateNewTree(old_tree_node->right);

        return new_tree_node;
    }

    TreeNode* convertBST(TreeNode* root) {
        // Get the middle ordered values.
        MiddleOrderTraverse(root);
        // Compute sum_ and values_in_new_tree_.
        sum_ = middle_ordered_;
        for (int i = sum_.size() - 1; i >= 0; --i) {
            if (i < sum_.size() - 1) {
                sum_[i] = sum_[i] + sum_[i + 1];
            }
            values_in_new_tree_[middle_ordered_[i]] = sum_[i];
        }
        // Create new tree.
        return CreateNewTree(root);
    }
};