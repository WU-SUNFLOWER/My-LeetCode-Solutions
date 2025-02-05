class Solution {
private:
    int min_cut_time_ = (1ll << 31) - 1;
    std::vector<std::string> solutions_;
    std::unordered_set<std::string> visited_;

public:
    bool IsValidString(const std::string& str) {
        int balance = 0;
        for (char ch : str) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }

    void DFS(std::string& cur_str, int cur_idx, int cut_time) {
        if (cur_idx >= cur_str.size()) {
            if (IsValidString(cur_str) && !visited_.contains(cur_str)) {
                if (cut_time < min_cut_time_) {
                    min_cut_time_ = cut_time;
                    solutions_.clear();
                }
                visited_.insert(cur_str);
                solutions_.emplace_back(cur_str);
            }
            return;
        }
        char ch = cur_str[cur_idx];
        if (ch != '(' && ch != ')') {
            DFS(cur_str, cur_idx + 1, cut_time);
            return;
        }
        if (cut_time + 1 <= min_cut_time_) {
            cur_str.erase(cur_idx, 1);
            DFS(cur_str, cur_idx, cut_time + 1);
            cur_str.insert(cur_idx, 1, ch);
        }
        DFS(cur_str, cur_idx + 1, cut_time);
    }

    std::vector<string> removeInvalidParentheses(std::string s) {
        DFS(s, 0, 0);
        return solutions_;
    }
};