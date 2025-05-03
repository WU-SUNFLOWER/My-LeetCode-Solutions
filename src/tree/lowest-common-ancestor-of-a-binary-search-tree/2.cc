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
    static bool InRange(int l, int r, int x) {
        return l <= x && x <= r;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (InRange(p->val, q->val, root->val) || InRange(q->val, p->val, root->val)) {
            return root;
        }
        assert(p->val < root->val && q->val < root->val || p->val > root->val && q->val > root->val);
        if (p->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};