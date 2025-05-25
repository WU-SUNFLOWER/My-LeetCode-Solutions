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

// std::pair<TreeNode pointer, TreeNode parent link>
using RecordStruct = std::pair<TreeNode*, TreeNode**>;

class Solution {
 private:
    std::vector<RecordStruct> records_;

 public:
    void Search(TreeNode* node, TreeNode** parent_link, int low, int high) {
        if (IS_NULL(node)) {
            return;
        }

        std::cout << "find node=" 
                  << node->val 
                  << ", low=" 
                  << low 
                  << ", high=" 
                  << high
                  << std::endl;

        if (!(low <= node->val && node->val <= high)) {
            records_.push_back({ node, parent_link });
            Search(node->left, &node->left, low, high);
            Search(node->right, &node->right, low, high);
        } else {
            Search(node->left, &node->left, low, node->val);
            Search(node->right, &node->right, node->val, high);
        }
    }

    void Fix() {
        if (records_.size() != 2) {
            return;
        }

        RecordStruct record1 = records_[0];
        RecordStruct record2 = records_[1];
        TreeNode* node1 = record1.first;
        TreeNode* node2 = record2.first;
        TreeNode** parent_link_1 = record1.second;
        TreeNode** parent_link_2 = record2.second;

        std::cout << "-----------------" << std::endl;
        std::cout << "node1=" << node1->val << std::endl;
        std::cout << "node2=" << node2->val << std::endl;


        std::swap(parent_link_1, parent_link_2);
        std::swap(node1->left, node2->left);
        std::swap(node1->right, node2->right);

    }

    void recoverTree(TreeNode* root) {
        if (IS_NULL(root)) {
            return;
        }

        int low = 1ll << 31;
        int high = (1ll << 31) - 1;
        Search(root, &root, low, high);
        Fix();
    }
};