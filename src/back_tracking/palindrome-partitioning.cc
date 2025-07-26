class Solution {
private:
    std::vector<std::string> slices_;
    std::vector<std::vector<std::string>> ans_;

public:
    bool Check(const std::string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start, --end;
        }
        return true;
    }

    void DFS(const std::string& s, int start_pos) {
        if (start_pos == s.size()) {
            ans_.emplace_back(slices_);
            return;
        }

        for (int end_pos = start_pos; end_pos < s.size(); ++end_pos) {
            if (Check(s, start_pos, end_pos)) {
                slices_.emplace_back(s.substr(start_pos, 
                                              end_pos - start_pos + 1));
                DFS(s, end_pos + 1);
                slices_.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        DFS(s, 0);
        return ans_;
    }
};