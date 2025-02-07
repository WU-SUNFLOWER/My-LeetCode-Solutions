class Solution {
private:
    vector<vector<int>> ans_vec_;
public:
    void DFS(const std::vector<int>& nums, int cur_idx, std::vector<int>& ans) {
        if (cur_idx >= nums.size()) {
            ans_vec_.push_back(ans);
            return;
        }
        DFS(nums, cur_idx + 1, ans);

        ans.push_back(nums[cur_idx]);
        DFS(nums, cur_idx + 1, ans);
        ans.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> ans;
        DFS(nums, 0, ans);
        return ans_vec_;
    }
};