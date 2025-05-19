class Solution {
private:
    int n_;
    std::string values_;
    std::vector<std::vector<int>> children_;
    int longest_path_ = 1;
    std::vector<int> dp_;

public:
    int Solve(int node) {
        // 无条件访问一遍自己的所有子节点，并初始化它们的dp_
        // 并挑出由子树贡献的最优的子路径，与自己组合成新的子路径
        int longest_path_from_me = 1;
        for (int child : children_[node]) {
            dp_[child] = Solve(child);
            if (values_[child] != values_[node]) {
                longest_path_ = std::max(longest_path_, dp_[child] + 1);
                longest_path_from_me = 
                    std::max(longest_path_from_me, dp_[child] + 1);
            }
        }

        // 尝试两两组合当前节点全部的子节点
        // 看看能不能以当前节点为中心，节点i、j为两翼，组合出更优的路径
        for (int i = 0; i < children_[node].size(); ++i) {
            int child_1 = children_[node][i];
            if (values_[child_1] == values_[node]) {
                continue;
            }
            for (int j = i + 1; j < children_[node].size(); ++j) {
                int child_2 = children_[node][j];
                if (values_[child_2] == values_[node]) {
                    continue;
                }
                longest_path_ = std::max(longest_path_,
                                         dp_[child_1] + dp_[child_2] + 1);
            }
        }

        return longest_path_from_me;
    }

    int longestPath(std::vector<int>& parents, std::string s) {
        n_ = parents.size();
        values_ = std::move(s);

        // children[i] 节点i的子节点有哪些
        children_.resize(n_);
        dp_.resize(n_);
        for (int i = 0; i < n_; ++i) {
            if (parents[i] == -1) continue;
            children_[parents[i]].emplace_back(i);
        }

        Solve(0);

        return longest_path_;
    }
};