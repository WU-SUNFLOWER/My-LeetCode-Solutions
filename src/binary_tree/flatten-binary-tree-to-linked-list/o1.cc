class Solution {
  public:
    void flatten(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                pre = curr->left;
                // 寻找左子树中的最靠右的那个节点，
                // 它就是我们要找的pre
                while (pre->right) {
                    pre = pre->right;
                }
                // 利用pre穿针引线
                pre->right = curr->right;
                // 调整树的结构
                curr->right = curr->left;
                curr->left = nullptr;  
            }
            // 更新curr
            curr = curr->right;
        }
    }
};