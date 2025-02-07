class Solution {
private:
    std::vector<std::vector<int>> ans_vec_;

public:
    void Search(const std::vector<int>& candidates, int start, int target, std::vector<int>& ans) {
        if (start == candidates.size() || target == 0) {
            if (target == 0) {
                ans_vec_.push_back(ans);
            }
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                ans.push_back(candidates[i]);
                Search(candidates, i, target - candidates[i], ans);
                ans.pop_back();
            }
            //Search(candidates, i + 1, target, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> ans;
        Search(candidates, 0, target, ans);
        return ans_vec_;
    }
};