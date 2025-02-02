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

    bool CheckSymmetric(std::vector<TreeNode*>& nodes) {
        auto size = nodes.size();
        for (auto i = 0; i < size / 2; ++i) {
            TreeNode* l_node = nodes[i];
            TreeNode* r_node = nodes[size - i - 1];

            // If at least one node is NULL?
            if (IS_NULL(l_node) || IS_NULL(r_node)) {
                // If one node is NULL and another isn't NULL?
                if (!IS_NULL(l_node) || !IS_NULL(r_node)) {
                    return false;
                } 
                // If both nodes are NULL?
                else {
                    continue;
                }
            }

            // Normal situation!
            if (l_node->val != r_node->val) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        std::vector<TreeNode*> layer;
        layer.push_back(root);

        while (true) {
            std::vector<TreeNode*> next_layer;

            // Is node order symmetric in this layer?
            if (!CheckSymmetric(layer)) {
                return false;
            }

            // Push the nodes' children into the next layer
            bool has_normal_node = false;
            for (TreeNode* node : layer) {
                if (IS_NULL(node)) {
                    next_layer.push_back(nullptr);
                    next_layer.push_back(nullptr);
                    continue;
                }
                has_normal_node = true;
                next_layer.push_back(node->left);
                next_layer.push_back(node->right);
            }

            // Have we already traversal the entire tree?
            if (!has_normal_node) {
                return true;
            }

            // Update layer
            layer = std::move(next_layer);
        }

        return true;
    }
};