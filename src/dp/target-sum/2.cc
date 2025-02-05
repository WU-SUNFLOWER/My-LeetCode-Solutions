class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dp[i][sum]
        // dp[i][sum] = dp[i - 1][sum - nums[i]] + dp[i - 1][sum + nums[i]]

        int base = 0;
        for (int num : nums) {
            base += num;
        }

        if (!(-base <= target && target <= base)) {
            return 0;
        }

        int height = nums.size() + 1;
        int width = 2 * base + 1;
        // int dp[height][width];
        std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
        dp[0][base] = 1;

#define GET_NUM(i) (nums[i - 1])

        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // Case1: sum += GET_SUM(i)
                if (0 <= j - GET_NUM(i)) {
                    dp[i][j] += dp[i - 1][j - GET_NUM(i)];
                }
                // Case2: sum -= GET_SUM(i)
                if (j + GET_NUM(i) < width) {
                    dp[i][j] += dp[i - 1][j + GET_NUM(i)];
                }
            }
        }

        return dp[height - 1][base + target];
    }
};