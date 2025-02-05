class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            // 1. 偷窃当前房屋
            // 2. 不偷窃当前房屋
            dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
};