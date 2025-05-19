class Solution {
private:
    int n_;
    std::string values_;
    std::vector<std::vector<int>> children_;
    int longest_path_ = 1;

public:
    int Solve(int node) {
        int x = 0;
        for (int child : children_[node]) {
            int y = Solve(child);
            if (values_[child] != values_[node]) {
                longest_path_ = std::max(longest_path_, x + y + 1);
                x = std::max(x, y);                
            }
        }
        return x + 1;
    }

    int longestPath(std::vector<int>& parents, std::string s) {
        n_ = parents.size();
        values_ = std::move(s);

        // children[i] 节点i的子节点有哪些
        children_.resize(n_);
        for (int i = 0; i < n_; ++i) {
            if (parents[i] == -1) continue;
            children_[parents[i]].emplace_back(i);
        }

        Solve(0);

        return longest_path_;
    }
};