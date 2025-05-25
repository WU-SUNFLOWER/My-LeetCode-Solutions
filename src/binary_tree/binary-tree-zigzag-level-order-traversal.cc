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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode*> q;
        q.push(root);

        int flag = true;
        std::vector<std::vector<int>> ans;
        while (!q.empty()) {
            int cur_layer_size = q.size();
            std::vector<int> tmp;
            while (cur_layer_size-- > 0) {
                TreeNode* node = q.front();
                q.pop();

                if (flag) {
                    tmp.push_back(node->val);
                } else {
                    //tmp.push_front(node->val);
                    tmp.insert(tmp.begin(), node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            flag = !flag;
            ans.emplace_back(std::move(tmp));
        }
        return ans;
    }
};