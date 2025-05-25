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
    // <node_value, node_index_in_inorder_vector>
    std::unordered_map<int, int> inorder_index_;

public:
    TreeNode* BuildTree(const std::vector<int>& preorder, const std::vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left >= preorder_right || inorder_left >= inorder_right) {
            return nullptr;
        }

        int root_val = preorder[preorder_left];
        int root_index_in_inorder = inorder_index_[root_val];
        int left_children_size = root_index_in_inorder - inorder_left;

        TreeNode* node = new TreeNode(root_val);
        node->left = BuildTree(preorder, inorder, preorder_left + 1, preorder_left + 1 + left_children_size, inorder_left, root_index_in_inorder);
        node->right = BuildTree(preorder, inorder, preorder_left + 1 + left_children_size, preorder_right, root_index_in_inorder + 1, inorder_right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_index_[inorder[i]] = i;
        }
        return BuildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};