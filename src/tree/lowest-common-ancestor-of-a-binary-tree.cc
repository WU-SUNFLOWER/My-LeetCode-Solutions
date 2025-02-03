/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define IS_NULL(x) (x == nullptr)

class Solution {
 public:
    void PrintError(const std::string& msg) {
        std::cerr << msg << std::endl;
    }

    bool ComputeSearchPath(TreeNode* node, TreeNode* target, std::deque<TreeNode*>& tmp_path, std::deque<TreeNode*>& correct_path) {
        tmp_path.push_back(node);
        if (node == target) {
            correct_path = std::move(tmp_path);
            return true;
        } else {
            if (!IS_NULL(node->left) && ComputeSearchPath(node->left, target, tmp_path, correct_path)) {
                return true;
            }

            // clear the tmp_path
            while (tmp_path.back() != node) {
                tmp_path.pop_back();
            }

            if (!IS_NULL(node->right) && ComputeSearchPath(node->right, target, tmp_path, correct_path)) {
                return true;
            }
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::deque<TreeNode*> path1;
        std::deque<TreeNode*> path2;
        std::deque<TreeNode*> tmp_path;

        if (!ComputeSearchPath(root, p, tmp_path, path1)) {
            PrintError("can't find node p");
        }
        if (path1.back() != p) {
            PrintError("illegal path of node p");
        }

        tmp_path.clear();

        if (!ComputeSearchPath(root, q, tmp_path, path2)) {
            PrintError("can't find node q");
        }

        if (path2.back() != q) {
            PrintError("illegal path of node q");
        }

        for (auto iter1 = path1.rbegin(); iter1 != path1.rend(); ++iter1) {
            for (auto iter2 = path2.rbegin(); iter2 != path2.rend(); ++iter2) {
                if (*iter1 == *iter2) {
                    return *iter1;
                }
            }
        }

        return nullptr;
    }
};