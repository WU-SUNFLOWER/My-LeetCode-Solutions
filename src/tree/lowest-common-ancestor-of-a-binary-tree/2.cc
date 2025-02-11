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
private:
    std::unordered_map<TreeNode*, TreeNode*> parent_;
    bool is_p_found_ = false;
    bool is_q_found_ = false;

public:
    void DFS(TreeNode* cur, TreeNode* cur_parent, TreeNode* p, TreeNode* q) {
        if (!cur || (is_p_found_ && is_q_found_)) {
            return;
        }
        parent_[cur] = cur_parent;
        if (cur == p) {
            is_p_found_ = true;
        } else if (cur == q) {
            is_q_found_ = true;
        }
        DFS(cur->left, cur, p, q);
        DFS(cur->right, cur, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root, nullptr, p, q);

        std::unordered_set<TreeNode*> visited;

        for (TreeNode* p_parent = p; p_parent; p_parent = parent_[p_parent]) {
            visited.insert(p_parent);
        }

        for (TreeNode* q_parent = q; q_parent; q_parent = parent_[q_parent]) {
            if (visited.contains(q_parent)) return q_parent; 
        }

        return nullptr;
    }
};