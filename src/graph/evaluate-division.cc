class Solution {
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph_;
    std::unordered_map<std::string, bool> visited_;
    double ans_;

public:

    bool DFS(const std::string& cur, const std::string& target, double cur_value) {
        if (!graph_.contains(cur)) {
            return false;
        }

        visited_[cur] = true;

        if (cur == target) {
            ans_ = cur_value;
            return true;
        }

        auto nexts = graph_[cur];
        for (const auto& [next, edge_value] : nexts) {
            if (!visited_[next] && DFS(next, target, cur_value * edge_value)) {
                return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            auto equation = equations[i];
            std::string& from = equation[0];
            std::string& to = equation[1];
            double value = values[i];

            graph_[from].push_back({ to, value });
            graph_[to].push_back({ from, 1.0 / value });
        }

        std::vector<double> ans;
        for (const auto& query : queries) {
            const auto& from = query[0];
            const auto& to = query[1];
            visited_.clear();
            if (DFS(from, to, 1.0)) {
                ans.push_back(ans_);
            } else {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
};