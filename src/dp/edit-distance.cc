class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) {
            return word2.size();
        }
        if (word2.size() == 0) {
            return word1.size();
        }

        // dp[i][j] —— 将word1中的前i个字符，变换到word2中的前j个字符，所需要的最小操作数
        // 改：dp[i][j] = dp[i - 1][j - 1] + 1
        // 增加：dp[i][j] = dp[i][j - 1] + 1
        // 删除：dp[i][j] = dp[i - 1][j] + 1

        std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                dp[i][j] = std::min({ dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1 });
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min({ dp[i][j], dp[i - 1][j - 1] });
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};