class Solution {
private:
    std::unordered_set<std::string> visited_;
    std::string start_;
    std::string end_;

    int ans_ = std::numeric_limits<int>::max();

public:
    bool IsVaildNext(const std::string& a, const std::string& b) {
        int cnt = 0;
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++cnt;
            }
            if (cnt > 1) return false;
        }
        return true;
    }

    void Search(const std::string& cur, int steps, std::vector<std::string>& banks) {
        if (cur == end_) {
            ans_ = std::min(ans_, steps);
            return;
        }
        if (visited_.size() == banks.size()) {
            return;
        }
        for (const std::string& next : banks) {
            if (!visited_.contains(next) && IsVaildNext(cur, next)) {
                visited_.insert(next);
                Search(next, steps + 1, banks);
                visited_.erase(next);
            }
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& banks) {
        start_ = std::move(startGene);
        end_ = std::move(endGene);

        Search(start_, 0, banks);

        return ans_ == std::numeric_limits<int>::max() ? -1 : ans_;
    }
};