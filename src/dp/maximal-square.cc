class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int max_side = 0;

        std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));

        for (int i = 0; i < height; ++i) {
            if (matrix[i][0] == '1') {
                max_side = dp[i][0] = 1;
            }
        }
        for (int j = 0; j < width; ++j) {
            if (matrix[0][j] == '1') {
                max_side = dp[0][j] = 1;
            }
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
                    max_side = std::max(max_side, dp[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};