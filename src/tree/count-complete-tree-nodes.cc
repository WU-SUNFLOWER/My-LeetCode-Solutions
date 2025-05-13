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
public:
    int ComputeTreeMaxDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            ++depth;
            root = root->left;
        }
        return depth;
    }

    int countNodes(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int node_id = 1;
        // 访问到叶子节点时，退出循环
        while (node->left || node->right) {
            int left_depth = ComputeTreeMaxDepth(node->left);
            int right_depth = ComputeTreeMaxDepth(node->right);
            // 如果左右深度一直，往右走
            // 如果左边的深度比右边大，往左走
            if (left_depth == right_depth) {
                node = node->right;
                node_id = 2 * node_id + 1;
            } else {
                node = node->left;
                node_id = 2 * node_id;
            }
        }
        return node_id;
    }
};