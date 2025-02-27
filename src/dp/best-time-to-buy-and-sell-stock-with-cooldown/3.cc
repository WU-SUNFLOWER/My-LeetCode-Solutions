class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } 

        // dp[i][0] 第i天手上没有股票时，所能获得的最大利润
        // dp[i][1] 第i天手上持有股票时，所能获得的最大利润
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        // 第0天（手上还没有股票）：
        //      0.1 可以选择啥都不做
        //      0.2 可以选择买入股票
        // 第1天（手上可能已经有股票了）：
        // 1. 如果手头上没有股票
        //      1.1 啥都不做
        //      1.2 买入股票（状态：没有股票->有股票）
        // 2. 如果手头上已经有股票：
        //      2.1 啥都不做
        //      2.2 卖出股票（状态：有股票->没有股票）
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        dp[1][0] = std::max({ dp[0][0], dp[0][1] + prices[1] });  // 第一天结束时，没有股票
        dp[1][1] = std::max({ dp[0][1], dp[0][0] - prices[1] });  // 第一天结束时，有股票

        for (int i = 2; i < prices.size(); ++i) {
            // 没有股票：什么事情也不做，或者选择今天卖出股票
            dp[i][0] = std::max({ dp[i - 1][0], dp[i - 1][1] + prices[i] });
            // 有股票：什么事情也不做，或者选择买入股票
            dp[i][1] = std::max({ dp[i - 1][1], dp[i - 2][0] - prices[i] });
        }
        return dp[prices.size() - 1][0];
    }
};