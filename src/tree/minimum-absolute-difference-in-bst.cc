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
 private:
    std::vector<int> middle_ordered_;

 public:
    void MiddleOrderTraverse(TreeNode* node) {
        if (!IS_NULL(node->left)) MiddleOrderTraverse(node->left);
        middle_ordered_.push_back(node->val);
        if (!IS_NULL(node->right)) MiddleOrderTraverse(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        MiddleOrderTraverse(root);

        int answer = (1ll << 31) - 1;
        for (int i = 1; i < middle_ordered_.size(); ++i) {
            answer = std::min(answer, std::abs(middle_ordered_[i] - middle_ordered_[i - 1]));
        }

        return answer;
    }
};