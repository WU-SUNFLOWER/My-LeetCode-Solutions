#define MY_MAX (std::numeric_limits<int>::max())

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][j]  使用第0~i种硬币，组合成总金额j，最少的硬币个数
        std::vector<std::vector<int>> dp(
                                coins.size(),
                                std::vector<int>(
                                        amount + 1, 
                                        MY_MAX));
        
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= amount; ++j) {
            if (j >= coins[0] && j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                int left_amount = j;
                int coin_cnt = 1;
                while (0 <= left_amount - coins[i]) {
                    int sub_question_ans = dp[i - 1][left_amount - coins[i]];
                    if (sub_question_ans != MY_MAX) {
                        dp[i][j] = std::min(dp[i][j], 
                                            sub_question_ans + coin_cnt);
                    }
                    left_amount -= coins[i];
                    ++coin_cnt;
                }
            }
        }

        int ans = dp[coins.size() - 1][amount];
        return ans == MY_MAX ? -1 : ans; 
    }
};