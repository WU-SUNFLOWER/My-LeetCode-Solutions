class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int total = matrix.size();
        
        for (int n = total, j = 0; n > 1; n -= 2, ++j) {
            for (int i = 0; i < n - 1; ++i) {
                int temp = matrix[j][i + j];
                matrix[j][i + j] = matrix[n - 1 - i + j][j];
                matrix[n - 1 - i + j][j] = matrix[n - 1 + j][n - 1 - i + j];
                matrix[n - 1 + j][n - 1 - i + j] = matrix[i + j][n - 1 + j];
                matrix[i + j][n - 1 + j] = temp;
            }
        }
    }
};