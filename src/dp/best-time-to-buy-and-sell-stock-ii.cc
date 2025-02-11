class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] 在第i天或之前的某一天买入
        // dp[i][1] 在第i天或之前的某一天卖出

        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max({ dp[i - 1][0], dp[i - 1][1] - prices[i] });
            dp[i][1] = std::max({ dp[i - 1][1], dp[i - 1][0] + prices[i] });
        }

        return std::max({ dp[prices.size() - 1][0], dp[prices.size() - 1][1], 0});
    }
};