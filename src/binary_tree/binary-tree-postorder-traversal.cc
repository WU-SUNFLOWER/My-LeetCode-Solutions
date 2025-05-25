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

#define IS_NULL(x) (x == nullptr)
#define IS_LEAF_NODE(node) (IS_NULL(node->left) && IS_NULL(node->right))

class Solution {
private:
    std::stack<TreeNode*> stack_;
    std::set<TreeNode*> record_;
    std::vector<int> post_ordered_;

public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if (IS_NULL(root)) {
            return post_ordered_;
        }

        stack_.push(root);
        while (!stack_.empty()) {
            TreeNode* cur = stack_.top();
            stack_.pop();

            if (IS_LEAF_NODE(cur) || record_.count(cur) > 0) {
                post_ordered_.push_back(cur->val);
                continue;
            }

            record_.insert(cur);
            stack_.push(cur);
            if (!IS_NULL(cur->right)) stack_.push(cur->right);
            if (!IS_NULL(cur->left)) stack_.push(cur->left);
        }

        return post_ordered_;
    }
};