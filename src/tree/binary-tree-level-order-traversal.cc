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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans_vec;
        if (!root) {
            return ans_vec;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int num = q.size();
            std::vector<int> ans;
            while (num-- > 0) {
                TreeNode* cur_node = q.front();
                q.pop();

                ans.push_back(cur_node->val);
                if (cur_node->left != nullptr) q.push(cur_node->left);
                if (cur_node->right != nullptr) q.push(cur_node->right);
            }
            ans_vec.emplace_back(std::move(ans));
        }

        return ans_vec;
    }
};