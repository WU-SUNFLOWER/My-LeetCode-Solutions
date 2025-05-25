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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> outs;

        if (!root) {
            return outs;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int last_val;
            int how_many_nodes_in_this_layer = q.size();
            while (how_many_nodes_in_this_layer-- > 0) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    last_val = node->val;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            outs.push_back(last_val);
        }

        return outs;
    }
};