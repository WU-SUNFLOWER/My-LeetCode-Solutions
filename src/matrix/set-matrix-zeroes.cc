class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<int> target_rows;
        std::unordered_set<int> target_cols;

        int height = matrix.size();
        if (height <= 0) return;
        int width = matrix[0].size();

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (matrix[row][col] == 0) {
                    target_cols.insert(col);
                    target_rows.insert(row);
                }
            }
        }

        for (int row = 0; row < height; ++row) {
            for (int col : target_cols) {
                matrix[row][col] = 0;
            }
        }

        for (int col = 0; col < width; ++col) {
            for (int row : target_rows) {
                matrix[row][col] = 0;
            }
        }
    }
};