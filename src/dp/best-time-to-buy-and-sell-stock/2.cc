class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = ((1ll << 31) - 1);
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            min_price = std::min(min_price, prices[i]);
            ans = std::max(ans, prices[i] - min_price);
        }
        return ans;
    }
};