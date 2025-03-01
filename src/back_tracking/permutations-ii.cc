class Solution {
private:
    std::unordered_set<int> used_;
    std::vector<std::vector<int>> ans_vec_;

public:
    void Search(const std::vector<int>& nums, std::vector<int>& ans) {
        if (nums.size() == ans.size()) {
            ans_vec_.emplace_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used_.contains(i) || 0 < i && nums[i - 1] == nums[i] && !used_.contains(i - 1)) {
                continue;
            }

            used_.insert(i);
            ans.emplace_back(nums[i]);
            Search(nums, ans);
            ans.pop_back();
            used_.erase(i);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> tmp;
        Search(nums, tmp);
        return ans_vec_;
    }
};