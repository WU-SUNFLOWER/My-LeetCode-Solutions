#define MY_MAX (1 << 30)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][j]  使用第0~i种硬币，组合成总金额j，最少的硬币个数
        std::vector<std::vector<int>> dp(
                                coins.size(),
                                std::vector<int>(
                                        amount + 1, 
                                        MY_MAX));
        
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= amount; ++j) {
            if (0 <= j - coins[0]) {
                dp[0][j] = dp[0][j - coins[0]] + 1;
            }
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (0 <= j - coins[i]) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - coins[i]] + 1);
                }
            }
        }

        int ans = dp[coins.size() - 1][amount];
        return ans >= MY_MAX ? -1 : ans; 
    }
};