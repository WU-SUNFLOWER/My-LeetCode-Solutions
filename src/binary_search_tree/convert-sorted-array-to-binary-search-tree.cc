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
    TreeNode* BuildTree(const std::vector<int>& vec, int start, int end) {
        if (!(start < end)) {
            return nullptr;
        }
        int mid = (start + end) >> 1;
        TreeNode* new_node = new TreeNode(vec[mid]);
        new_node->left = BuildTree(vec, start, mid);
        new_node->right = BuildTree(vec, mid + 1, end);
        return new_node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size());
    }
};