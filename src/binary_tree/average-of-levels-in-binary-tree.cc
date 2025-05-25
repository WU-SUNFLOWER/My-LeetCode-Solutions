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

#define IS_NULL(x) (x == nullptr)

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        if (IS_NULL(root)) {
            return { 0.0f };
        }

        std::vector<double> answers;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            auto node_num = queue.size();
            double answer = 0.0f;

            for (auto i = 0; i < node_num; ++i) {
                TreeNode* cur_node = queue.front();
                answer += cur_node->val;
                
                if (!IS_NULL(cur_node->left)) {
                    queue.push(cur_node->left);
                }
                if (!IS_NULL(cur_node->right)) {
                    queue.push(cur_node->right);
                }

                queue.pop();
            }

            answers.push_back(answer / node_num);
        }

        return answers;
    }
};