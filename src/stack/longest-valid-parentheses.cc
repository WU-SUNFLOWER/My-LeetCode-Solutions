class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        // dp[i] 以s[i]结尾的最长有效子串的长度是多少？
        std::vector<int> dp(n, 0);
        std::stack<int> st;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
                dp[i] = 0;
            } 
            // 消费掉st当中的'('
            else if (!st.empty()) {
                // 我们可以考虑这个例子："()(())"
                // 从中可知要同时加上dp[st.top() - 1]和dp[i - 1]，答案才完整
                if (0 <= st.top() - 1) {
                    dp[i] = dp[st.top() - 1] + dp[i - 1] + 2;
                } else {
                    dp[i] = dp[i - 1] + 2;
                }
                st.pop();
            }
            else {
                dp[i] = 0;
            }
            ans = std::max(ans, dp[i]);
        }

        return ans;
    }
};