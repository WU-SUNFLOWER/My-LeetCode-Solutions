class Solution {
public:
    int uniquePaths(int height, int width) {
        std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i < height; ++i) {
            dp[i][0] = dp[i - 1][0];
        }
        for (int j = 1; j < width; ++j) {
            dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[height - 1][width - 1];
    }
};