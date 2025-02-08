class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        // dp[i][j]: Can we select some numbers in { nums[0], nums[1], ..., nums[i] }
        // And let the sum of them to be j
        std::vector<std::vector<bool>> dp(nums.size(), std::vector<bool>(target + 1, false));

        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[nums.size() - 1][target];
    }
};