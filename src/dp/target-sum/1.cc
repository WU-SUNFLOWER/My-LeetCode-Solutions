class Solution {
private:
    int ans_;

public:
    void DFS(int cur_index, std::vector<int>& nums, int cur_sum, int target) {
        if (cur_index == nums.size()) {
            ans_ += (cur_sum == target);
            return;
        }
        DFS(cur_index + 1, nums, cur_sum + nums[cur_index], target);
        DFS(cur_index + 1, nums, cur_sum - nums[cur_index], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        DFS(0, nums, 0, target);
        return ans_;
    }
};