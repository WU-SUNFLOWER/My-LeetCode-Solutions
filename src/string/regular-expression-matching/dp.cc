class Solution {
  public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();

        std::vector<std::vector<bool>> dp(s_len + 1, 
                                          std::vector<bool>(p_len + 1, false));
        dp[0][0] = true;
 
        for (int j = 1; j <= p_len; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            for (int j = 1; j <= p_len; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];  // 匹配0个
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];  // 匹配至少1个
                    }
                }
            }
        }

        return dp.back().back();
    }
};