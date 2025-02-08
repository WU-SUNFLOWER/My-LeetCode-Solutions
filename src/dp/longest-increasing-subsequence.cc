class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = std::max(dp[i], dp[j] + 1)
        int ans = 1;
        std::vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    ans = std::max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};