class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        
        if (len1 + len2 != s3.size()) {
            return false;
        }

        std::vector<std::vector<bool>> dp(len1 + 1, std::vector<bool>(len2 + 1, false));

#define GET_CHAR(str, which) (str[which - 1])

        // 空串和空串组合，可以得到空串
        dp[0][0] = true;

        // 只取一个字符串的前若干个字符，另一个字符串取空串
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] = GET_CHAR(s1, i) == GET_CHAR(s3, i) && dp[i - 1][0];
        }

        for (int j = 1; j <= len2; ++j) {
            dp[0][j] = GET_CHAR(s2, j) == GET_CHAR(s3, j) && dp[0][j - 1];
        }

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = GET_CHAR(s1, i) == GET_CHAR(s3, i + j) && dp[i - 1][j] || 
                           GET_CHAR(s2, j) == GET_CHAR(s3, i + j) && dp[i][j - 1];
            }
        }

#undef GET_CHAR

        return dp[len1][len2];
    }
};