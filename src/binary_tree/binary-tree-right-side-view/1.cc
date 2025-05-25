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
        if (!root) {
            return { };
        }

        std::queue<TreeNode*> q;
        q.push(root);

        int cur_layer_cnt = 0;
        int target_layer_cnt = 1;

        std::vector<int> cur_layer;
        std::vector<int> outs;

        bool has_child = false;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            cur_layer_cnt++;

            if (cur != nullptr) {
                cur_layer.push_back(cur->val);
                has_child = has_child || cur->left || cur->right;
                q.push(cur->left);
                q.push(cur->right);
            } else {
                q.push(nullptr);
                q.push(nullptr);
            }

            if (cur_layer_cnt == target_layer_cnt) {
                cur_layer_cnt = 0;
                target_layer_cnt *= 2;
                if (!cur_layer.empty()) {
                    outs.push_back(cur_layer.back());
                }
                cur_layer.clear();
                if (has_child) {
                    has_child = false;
                } else {
                    break;
                }
            }

        }

        if (!cur_layer.empty()) {
            outs.push_back(cur_layer.back());
        }

        return outs;
    }
};