class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int k = 2;

        // dp[第i天][最多允许交易j次][手上是否有股票]
        std::vector<std::vector<std::vector<int>>> dp(days, std::vector<std::vector<int>>(k + 1, std::vector<int>(2, 0)));
        // 当j=0时，不可能产生交易
        for (int i = 0; i < days; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = -(1 << 30);
        }

        // 当j>=1，在第0天结束时
        for (int j = 1; j <= k; ++j) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for (int i = 1; i < days; ++i) {
            for (int j = 1; j <= k; ++j) {
                // 第i天结束时，手上没股票
                dp[i][j][0] = std::max({ dp[i - 1][j][0], dp[i - 1][j][1] + prices[i] });
                // 第i天结束时，手上有股票
                dp[i][j][1] = std::max({ dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i] });
            }
        }

        return dp[days - 1][k][0];
    }
};