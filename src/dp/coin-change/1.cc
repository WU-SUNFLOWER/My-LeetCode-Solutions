class Solution {

#define MAX ((1ll << 30))

public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, MAX);

        for (int coin : coins) {
            if (coin < amount + 1) {
                dp[coin] = 1;
            }
        }
        dp[0] = 0; 

        // dp[i] = std::min(dp[i - coin1], dp[i - coin2]...) + 1
        for (int i = 0; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp.back() == MAX ? -1 : dp.back();
    }
};