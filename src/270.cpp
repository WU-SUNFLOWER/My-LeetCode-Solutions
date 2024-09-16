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

#define isEqualDouble(x, y) (std::fabs((x) - (y)) < (double)(1e-9))

typedef std::pair<int, double> MyTuple;

class Solution {
public:
    MyTuple search(TreeNode* cur, double target) {
        double self_delta = std::fabs(cur->val - target);
        std::vector<MyTuple> results = {{cur->val, self_delta}};
        if (cur->left) {
            results.push_back(search(cur->left, target));
        }
        if (cur->right) {
            results.push_back(search(cur->right, target));
        }
        double res_delta = std::numeric_limits<double>::infinity();
        int res_val = -1;
        for (auto& result: results) {
            int cur_val = result.first;
            double cur_delta = result.second;
            if (
                cur_delta < res_delta || 
                isEqualDouble(cur_delta, res_delta) && cur_val < res_val
            ) {
                res_delta = cur_delta;
                res_val = cur_val;
            }
        }
        assert(res_val != -1);
        return {res_val, res_delta};
    }
    int closestValue(TreeNode* root, double target) {
        return search(root, target).first;
    }
};