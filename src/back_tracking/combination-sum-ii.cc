class Solution {
private:
    std::vector<std::vector<int>> ans_vec_;
    int target_;

public:
    void Search(const std::vector<int>& nums, int idx, std::vector<int>& ans, int sum) {
        if (idx == nums.size()) {
            return;
        }

        // 对每个数字，都有选择和不选择两种情况
        
        // 不选择
        // 如果不选择x，则同时亦不能选择x'
        // 否则会出现"选x不选x'"和"不选x选x'"两种重复的情况
        int tmp = idx + 1;
        while (tmp < nums.size() && nums[tmp] == nums[idx]) {
            ++tmp;
        }
        Search(nums, tmp, ans, sum);

        // 选择
        ans.push_back(nums[idx]);
        if (sum + nums[idx] == target_) {
            ans_vec_.emplace_back(ans);
        }
        // 剪枝：如果当前数纳入计算之后超出了目标，就没有向下搜索的必要了
        else if (sum + nums[idx] < target_) {
            Search(nums, idx + 1, ans, sum + nums[idx]);
        }
        ans.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        target_ = target;

        std::sort(candidates.begin(), candidates.end());
        std::vector<int> tmp;
        Search(candidates, 0, tmp, 0);
        return ans_vec_;
    }
};