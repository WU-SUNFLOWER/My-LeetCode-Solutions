class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int len = s.size();
        std::vector<std::vector<bool>> dp(len, 
                                          std::vector<bool>(len, false));

        int ans_len = 0;
        int ans_l = 0;
        for (int r = 0; r < len; ++r) {
            for (int l = 0; l <= r; ++l) {
                // 判断区间[l, r]是不是字串
                if (s[l] == s[r] && (r - l < 2 || dp[r - 1][l + 1])) {
                    dp[r][l] = true;
                    if (ans_len < r - l + 1) {
                        ans_len = r - l + 1;
                        ans_l = l;
                    }
                }
            }
        }

        return s.substr(ans_l, ans_len);
    }
};