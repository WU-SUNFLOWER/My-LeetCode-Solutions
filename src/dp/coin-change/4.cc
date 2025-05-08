#define INF (1 << 30)

class Solution {
private:
    std::vector<std::vector<int>> cache_;

public:
    int Solve(const std::vector<int>& coins, int len, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (len <= 0) {
            return INF;
        }

        int coin = coins[len - 1];
        
        if (cache_[len][amount] == -1) {
            if (amount - coin < 0) {
                cache_[len][amount] = Solve(coins, len - 1, amount);
            } else {
                cache_[len][amount] = 
                        std::min(Solve(coins, len - 1, amount),
                                 Solve(coins, len, amount - coin) + 1);            
            }
        }

        return cache_[len][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        cache_ = std::vector<std::vector<int>>(
                            coins.size() + 1,
                            std::vector<int>(amount + 1, -1));

        int ans = Solve(coins, coins.size(), amount);
        return ans < INF ? ans : -1;
    }
};