class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        // dp[第几天][已完成几笔交易][现在手上有无股票]
        std::vector<std::vector<std::vector<int>>> dp(days, std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));

        // 第0天结束时
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = dp[0][1][1] = -(1 << 30);

        for (int i = 1; i < days; ++i) {
            // 第i天，手上没有股票，目前还没完成任何交易
            dp[i][0][0] = dp[i - 1][0][0];
            // 第i天，手上持有股票，目前还没完成任何交易
            dp[i][0][1] = std::max({ dp[i - 1][0][1], dp[i - 1][0][0] - prices[i] });
            // 第i天，手上没有股票，已完成一笔交易（之前股票已经被卖出过一次了）
            dp[i][1][0] = std::max({ dp[i - 1][1][0], dp[i - 1][0][1] + prices[i] });
            // 第i天，手上持有股票，已完成一笔交易
            dp[i][1][1] = std::max({ dp[i - 1][1][1], dp[i - 1][1][0] - prices[i] });
            // 第i天，手上没有股票，已完成两笔交易
            dp[i][2][0] = std::max({ dp[i - 1][2][0], dp[i - 1][1][1] + prices[i] });
        }

        return std::max({ dp[days - 1][0][0], dp[days - 1][1][0], dp[days - 1][2][0] });
    }
};