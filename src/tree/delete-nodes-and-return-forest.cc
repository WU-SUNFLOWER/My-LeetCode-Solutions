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
    std::set<int> to_delete_set_;
    std::deque<TreeNode*> pending_trees_;
    std::vector<TreeNode*> answer_trees_;

public:
    void Search(TreeNode* node, TreeNode** parent_link) {
        if (IS_NULL(node)) {
            return;
        }

        if (to_delete_set_.count(node->val) > 0) {
            // remove this node from the tree which owns it.
            *parent_link = nullptr;
            
            // add this node's sub trees into pending_trees_.
            // and search these sub trees.
            if (!IS_NULL(node->left)) {
                pending_trees_.push_back(node->left);
                Search(node->left, &pending_trees_.back());
            }
            if (!IS_NULL(node->right)) {
                pending_trees_.push_back(node->right);
                Search(node->right, &pending_trees_.back());
            }

            // release this node.
            //delete node;
        } else {
            Search(node->left, &node->left);
            Search(node->right, &node->right);
        }
    }

    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
        // Initalize to_delete_set
        for (int num : to_delete) {
            to_delete_set_.insert(num);
        }

        // Add the entire tree to trees_
        pending_trees_.push_back(root);

        // Start search
        Search(root, &pending_trees_.back());

        // Filter the tree record which root is NULL.
        for (TreeNode* cur_root : pending_trees_) {
            if (!IS_NULL(cur_root)) {
                answer_trees_.push_back(cur_root);
            }
        }

        return answer_trees_;
    }
};