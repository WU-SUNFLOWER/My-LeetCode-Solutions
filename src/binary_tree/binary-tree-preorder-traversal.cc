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

class Solution {
 private:
    std::vector<int> answer_;
    std::stack<TreeNode*> stack_;

 public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack_.push(root);
        while (!stack_.empty()) {
            TreeNode* node = stack_.top();
            stack_.pop();

            if (IS_NULL(node)) {
                continue;
            }

            answer_.push_back(node->val);
            stack_.push(node->right);
            stack_.push(node->left);
        }
        return answer_;
    }
};