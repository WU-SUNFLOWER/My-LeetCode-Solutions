/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
    void ComputeSearchPath(TreeNode* node, TreeNode* target, std::deque<TreeNode*>& path) {
        while (node != target) {
            path.push_front(node);
            if (target->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        path.push_front(node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::deque<TreeNode*> path1;
        std::deque<TreeNode*> path2;

        ComputeSearchPath(root, p, path1);
        ComputeSearchPath(root, q, path2);

        for (int i = 0; i < path1.size(); ++i) {
            for (int j = 0; j < path2.size(); ++j) {
                if (path1[i] == path2[j]) {
                    return path1[i];
                }
            }
        }

        return nullptr;
    }
};