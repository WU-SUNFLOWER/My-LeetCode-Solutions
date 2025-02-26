class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        int width = triangle.back().size();

        std::vector<std::vector<int>> dp(height, std::vector<int>(width, std::numeric_limits<int>::max()));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < height; ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = std::min({ dp[i][j], dp[i - 1][j] + triangle[i][j], dp[i - 1][j - 1] + triangle[i][j] });
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        // 计算最终答案
        int ans = std::numeric_limits<int>::max();
        for (int path : dp.back()) {
            ans = std::min(ans, path);
        }

        return ans;
    }
};