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
class BSTIterator {
private:
    std::stack<TreeNode*> stack_;

public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != nullptr) {
            stack_.push(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        TreeNode* cur = stack_.top();
        int ret = cur->val;
        stack_.pop();

        cur = cur->right;
        while (cur != nullptr) {
            stack_.push(cur);
            cur = cur->left;
        }

        return ret;
    }
    
    bool hasNext() {
        return !stack_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */