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
class Solution {
private:
    std::vector<int> inordered_;

    std::stack<TreeNode*> stack_;

    std::set<TreeNode*> record_;

public:
    bool IsLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    vector<int> inorderTraversal(TreeNode* root) {

        if (!root) {
            return inordered_;
        }

        stack_.push(root);

        while (!stack_.empty()) {
            TreeNode* cur = stack_.top();
            stack_.pop();
            
            if (IsLeafNode(cur) || record_.count(cur) > 0) {
                inordered_.push_back(cur->val);
                continue;                
            }

            if (cur->right) stack_.push(cur->right);
            stack_.push(cur);
            record_.insert(cur);
            if (cur->left) stack_.push(cur->left);
        }

        return inordered_;
    }
};