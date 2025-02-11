class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> dp(nums.size(), ((1ll << 31) - 1));
        dp[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                dp[i + j] = std::min(dp[i + j], dp[i] + 1);
            }
        }

        return dp.back();
    }
};