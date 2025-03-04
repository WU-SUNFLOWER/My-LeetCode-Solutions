class Solution {
private:
    std::vector<std::vector<int>> ans_vec_;
    int target_;

public:
    void Search(const std::vector<int>& nums, int idx, std::vector<int>& ans, int sum) {
        if (idx == nums.size()) {
            return;
        }
        
        // 不选择当前元素
        int tmp = idx + 1;
        while (tmp < nums.size() && nums[tmp] == nums[idx]) {
            ++tmp;
        }
        Search(nums, tmp, ans, sum);

        // 选择当前元素
        if (sum + nums[idx] == target_) {
            ans.push_back(nums[idx]);
            ans_vec_.emplace_back(ans);
            ans.pop_back();
        }
        else if (sum + nums[idx] < target_) {
            ans.push_back(nums[idx]);
            Search(nums, idx, ans, sum + nums[idx]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        target_ = target;
        std::vector<int> tmp;

        Search(candidates, 0, tmp, 0);

        return ans_vec_;
    }
};