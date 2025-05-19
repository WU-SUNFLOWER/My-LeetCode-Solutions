// dp[node] 以当前节点为根节点的子树，【至少】需要安装多少个摄像头？
// dp[node][0] 给节点node安装摄像头
// dp[node][1] 当前节点不安装摄像头，父节点安装
// dp[node][2] 当前节点不安装摄像头，父节点未安装（也就是说至少有一个孩子安装）

// dp[node][0]=min(dp[node.left][0], dp[node.left][1], dp[node.left][2]) + 
//             min(dp[node.right][0], dp[node.right][1], dp[node.right][2]) +
//             1
//
// dp[node][1]=min(dp[node.left][0], dp[node.left][2]) +
//             min(dp[node.right][0], dp[node.right][2])
//
// dp[node][2]=min(dp[node.left][0]+dp[node.right][0], 
//                 dp[node.left][0]+dp[node.right][2],
//                 dp[node.left][2]+dp[node.right][0])

class Solution {
private:
    std::vector<std::unordered_map<TreeNode*, int>> dp;

public:
    int64_t Solve(TreeNode* node, int state) {
        static std::vector<int> null_node_ret = {std::numeric_limits<int>::max(), 0, 0};
        if (!node) {
            return null_node_ret[state];
        }

        if (dp[state].contains(node)) {
            return dp[state][node]; 
        }

        int64_t result;
        switch (state) {
            case 0:
                result = (std::min({Solve(node->left, 0), Solve(node->left, 1), Solve(node->left, 2)}) +
                          std::min({Solve(node->right, 0), Solve(node->right, 1), Solve(node->right, 2)}) +
                          1);
                break;
            case 1:
                result = (std::min(Solve(node->left, 0), Solve(node->left, 2)) +
                          std::min(Solve(node->right, 0), Solve(node->right, 2)));
                break;
            case 2:
                result = std::min({Solve(node->left, 0) + Solve(node->right, 0),
                                   Solve(node->left, 2) + Solve(node->right, 0),
                                   Solve(node->left, 0) + Solve(node->right, 2)});
                break;
            default:
                assert(0);
        }

        dp[state][node] = result;
        return result;
    }

    int minCameraCover(TreeNode* root) {
        dp.resize(3);
        return std::min(Solve(root, 0), Solve(root, 2));
    }
};
