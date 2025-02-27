class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();

        if (days <= 1) return 0;

        std::vector<std::vector<std::vector<int>>> dp(days, std::vector<std::vector<int>>(k + 1, std::vector<int>(2, 0)));
        
        // 限制交易次数为0时，交易不可能发生
        for (int i = 0; i < days; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = -(1 << 30);
        }
        // 限制交易次数大于等于1，在第0天结束时
        for (int j = 1; j <= k; ++j) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for (int i = 1; i < days; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = std::max({ dp[i - 1][j][0], dp[i - 1][j][1] + prices[i] });
                dp[i][j][1] = std::max({ dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i] });
            }
        }

        return dp[days - 1][k][0];
    }
};