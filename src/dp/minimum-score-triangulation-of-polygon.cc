#define INF (std::numeric_limits<int>::max())

class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        // dp[i][j]=min(dp[i][k] + dp[k][j] + v[i]*v[k]*v[j])
        std::vector<std::vector<uint32_t>> dp(n, std::vector<uint32_t>(n, INF));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = 0;
        }

        for (int len = 3; len <= n; ++len) {
            // len + i - 1 < n => i < n + 1 - len
            for (int i = 0; i < n + 1 - len; ++i) {
                // j - i + 1 = len => j = len + i - 1
                int j = len + i - 1;
                for (int k = i + 1; k <= j - 1; ++k) {
                    dp[i][j] = std::min(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};