class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] = std::max(dp[i - 1], prices[i] - i天之前的最低价);
        int n = prices.size();
        std::vector<int> dp(n, 0);
        int min_prices = prices[0];
        for (int i = 1; i < n; ++i) {
            min_prices = std::min(min_prices, prices[i]);
            dp[i] = std::max(dp[i - 1], prices[i] - min_prices);
        }
        return dp.back();
    }
};