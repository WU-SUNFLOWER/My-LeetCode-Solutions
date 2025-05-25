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
    std::unordered_map<int, int> inorder_val_pos_map_;

public:
    TreeNode* BuildNode(const std::vector<int>& inorder, const std::vector<int>& postorder, 
                        int inorder_start, int inorder_end, 
                        int postorder_start, int postorder_end) 
    {
        if (inorder_start >= inorder_end || postorder_start >= postorder_end) {
            return nullptr;
        }

        // 从后序序列中取出当前节点的值，并创建当前节点
        int cur_val = postorder[postorder_end - 1];
        TreeNode* cur_node = new TreeNode(cur_val);

        // 确定当前节点在中序遍历中的位置
        int inorder_idx = inorder_val_pos_map_[cur_val];
        // 于是乎我们知道在当前节点的左子树中有inorder_idx - inorder_start个节点
        // 因此可以进一步确定当前节点的右子树中有多少个节点
        int how_many_nodes_in_left = inorder_idx - inorder_start;

        cur_node->left = BuildNode(inorder, postorder, inorder_start, inorder_idx, postorder_start, postorder_start + how_many_nodes_in_left);
        cur_node->right = BuildNode(inorder, postorder, inorder_idx + 1, inorder_end, postorder_start + how_many_nodes_in_left, postorder_end - 1);

        return cur_node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_val_pos_map_[inorder[i]] = i;
        }
        return BuildNode(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};