class Solution {
  private:
    TreeNode* last_node_{nullptr};

  public:
    void Visit(TreeNode* node) {
        if (!node) return;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        if (last_node_) {
            last_node_->right = node;
        }
        node->left = node->right = nullptr;
        last_node_ = node;

        Visit(left);
        Visit(right);
    }

    void flatten(TreeNode* root) {
        Visit(root);
    }
};