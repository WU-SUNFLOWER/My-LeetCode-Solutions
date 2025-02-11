class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }

        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));
        dp[0][2] = -prices[0];

        // dp[i][0] 在第i天，手头上没有股票
        // dp[i][1] 在第i天或之前的某一天，卖出股票
        // dp[i][2] 在第i天或之前的某一天，买入股票
        for (int i = 1; i < len; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][2] + prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][0] - prices[i]);
        }

        return std::max({ dp[len - 1][0], dp[len - 1][1], dp[len - 1][2], 0 });
    }
};