class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // 0 今天持有股票（昨天就持有股票了，或者今天刚刚买入股票）
            // 1 今天卖出了股票
            // 2 今天没有持有股票（即之前某天已经卖出了股票）
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
        }

        return std::max({ dp[prices.size() - 1][1], dp[prices.size() - 1][2] });
    }
};