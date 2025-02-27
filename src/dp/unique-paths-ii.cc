class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;

        for (int i = 1; i < height; ++i) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
        }

        for (int j = 1; j < width; ++j) {
            dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j - 1];
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                // 如果当前位置有障碍物，则没有任何方法可以抵达
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp.back().back();
    }
};