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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* first_node = nullptr;
        while (!queue.empty()) {
            int layer_node_num = queue.size();

            for (int i = 0; i < layer_node_num; ++i) {
                TreeNode* cur = queue.front();
                if (i == 0) {
                    first_node = cur;
                }
                queue.pop();
                if (cur->left) queue.push(cur->left);
                if (cur->right) queue.push(cur->right);
            }
        }
        return first_node->val;
    }
};