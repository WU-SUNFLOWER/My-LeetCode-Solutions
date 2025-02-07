class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        std::vector<std::vector<int>> helper(height, std::vector<int>(width, 0));

        for (int j = 0; j < width; ++j) {
            helper[0][j] = matrix[0][j] == '1';
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    helper[i][j] = helper[i - 1][j] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (helper[i][j] > 0) {
                    int k = j - 1;
                    int cnt = 1;
                    while (0 <= k && helper[i][k] >= helper[i][j]) {
                        ++cnt;
                        --k;
                    }
                    k = j + 1;
                    while (k < width && helper[i][k] >= helper[i][j]) {
                        ++cnt;
                        ++k;
                    }
                    ans = std::max(ans, helper[i][j] * cnt);
                }
            }
        }

        return ans;
    }
};