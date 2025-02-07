class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);

        // dp[i] = std::max(dp[i - 1], i + nums[i]);
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = i == 0 ? nums[0] : std::max(dp[i - 1], i + nums[i]);
            if (dp[i] >= nums.size() - 1) {
                return true;
            }
            if (dp[i] == i) {
                return false;
            }
        }
        return true;
    }
};