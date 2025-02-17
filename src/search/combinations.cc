class Solution {
private:
    std::vector<std::vector<int>> ans_;
    
public:
    void Search(std::vector<int>& vec, int cur, int n, int k) {
        if (cur > n) {
            if (vec.size() == k) {
                ans_.emplace_back(vec);
            }
            return;
        }

        if (vec.size() + (n - cur + 1) < k) {
            return;
        }

        // 选取cur
        vec.push_back(cur);
        Search(vec, cur + 1, n, k);
        vec.pop_back();

        // 不选取cur
        Search(vec, cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<int> vec;
        Search(vec, 1, n, k);
        return ans_;
    }
};