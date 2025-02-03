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

#define IS_NULL(node) (node == nullptr)
#define IS_LEFT_NODE_OF(node, parent) (node == parent->left)
#define IS_RIGHT_NODE_OF(node, parent) (node == parent->right)

class Solution {
public:
    void PrintError(const char* msg) {
        std::cerr << msg << std::endl;
        exit(-1);
    }

    TreeNode* GetSuccessor(TreeNode* node, TreeNode**& successor_parent_link) {
        successor_parent_link = &node->right;
        TreeNode* successor = node->right;
        
        if (IS_NULL(successor)) {
            PrintError("can't find successor!");
        }

        while (successor->left) {
            successor_parent_link = &successor->left;
            successor = successor->left;
        }

        return successor;
    }
    
    TreeNode* SearchNode(int target_val, TreeNode* node, TreeNode**& parent_link) {
        while (node != nullptr) {
            if (target_val == node->val) {
                return node;
            }

            if (target_val < node->val) {
                parent_link = &node->left;
                node = node->left;
            } else {
                parent_link = &node->right;
                node = node->right;
            }
        }
        return nullptr;
    }

    void RemoveNode(TreeNode* target, TreeNode** target_parent_link) {
        if (IS_NULL(target->left) || IS_NULL(target->right)) {
            if (IS_NULL(target->left)) {
                *target_parent_link = target->right;
            } else {
                *target_parent_link = target->left;
            }
            return;
        }

        TreeNode** successor_parent_link;
        TreeNode* successor = GetSuccessor(target, successor_parent_link);

        if (!IS_NULL(successor->left)) {
            PrintError("illegal successor");
        }

        successor->left = target->left;
        *target_parent_link = successor;

        if (!IS_RIGHT_NODE_OF(successor, target)) {
            *successor_parent_link = successor->right;
            successor->right = target->right;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** target_parent_link = &root;
        TreeNode* target = SearchNode(key, root, target_parent_link);

        if (IS_NULL(target)) {
            return root;
        }

        RemoveNode(target, target_parent_link);
        delete target;

        return root;
    }
};