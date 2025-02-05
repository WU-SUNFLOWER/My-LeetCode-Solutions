class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        int ans = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};