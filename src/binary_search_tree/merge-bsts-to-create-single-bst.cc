constexpr size_t N = 5 * 10e4 + 1;

class Solution {
private:
    std::array<bool, N> is_sub_node_ = {false};
    std::array<TreeNode*, N> val_root_map_ = {nullptr};

public:
    int MergeTrees(TreeNode* root) {
        val_root_map_[root->val] = nullptr;
        int merged_cnt = 1;
        // 尝试拓展左子树
        if (root->left) {
            TreeNode* other_tree = val_root_map_[root->left->val];
            if (other_tree) {
                root->left = other_tree;
                merged_cnt += MergeTrees(root->left);
            }
        }

        // 尝试拓展右子树
        if (root->right) {
            TreeNode* other_tree = val_root_map_[root->right->val];
            if (other_tree) {
                root->right = other_tree;
                merged_cnt += MergeTrees(root->right);
            }
        }

        return merged_cnt;
    }

    bool IsValidBST(TreeNode* node, 
                    int low = std::numeric_limits<int>::min(),
                    int high = std::numeric_limits<int>::max()) {
        if (!node) return true;
        return low < node->val && 
               node->val < high &&
               IsValidBST(node->left, low, node->val) &&
               IsValidBST(node->right, node->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& roots) {
        // 初始化
        for (TreeNode* root : roots) {
            val_root_map_[root->val] = root;
            if (root->left) {
                // 同值节点只允许为"一个为子节点一个为根节点"的情况，
                // 不允许出现"两个都为子节点"的情况
                if (is_sub_node_[root->left->val]) return nullptr;
                is_sub_node_[root->left->val] = true;
            }
            if (root->right) {
                if (is_sub_node_[root->right->val]) return nullptr;
                is_sub_node_[root->right->val] = true;
            }
        }

        // 确定合成后的树的根节点
        TreeNode* merged_tree_root = nullptr;
        for (TreeNode* root : roots) {
            if (!is_sub_node_[root->val]) {
                if (merged_tree_root) return nullptr;
                merged_tree_root = root;
            }
        }

        if (!merged_tree_root) {
            return nullptr;
        }

        // 执行merge操作
        if (MergeTrees(merged_tree_root) != roots.size()) {
            return nullptr;
        }

        // 检测是不是合法的二叉搜索树
        if (!IsValidBST(merged_tree_root)) {
            return nullptr;
        }

        return merged_tree_root;
    }
};