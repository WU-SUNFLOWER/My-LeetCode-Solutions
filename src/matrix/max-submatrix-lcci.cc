class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();

        std::vector<std::vector<int>> pro_sum(height, std::vector<int>(width, 0));
        for (int i = 0; i < width; ++i) {
            pro_sum[0][i] = matrix[0][i];
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                pro_sum[i][j] = pro_sum[i - 1][j] + matrix[i][j];
            }
        }

        int ans_sum = std::numeric_limits<int>::min();
        int ans_r_1, ans_c_1;  // 答案矩阵左上角
        int ans_r_2, ans_c_2;  // 答案矩阵右下角
        for (int r_begin = 0; r_begin < height; ++r_begin) {
            for (int r_end = r_begin; r_end < height; ++r_end) {
                // 将矩阵中的第r_begin到第r_end行，压缩成一维数组
                std::vector<int> row(width, 0);
                for (int c = 0; c < width; ++c) {
                    if (r_begin >= 1) {
                        row[c] = pro_sum[r_end][c] - pro_sum[r_begin - 1][c];
                    } else {
                        row[c] = pro_sum[r_end][c];
                    }
                }

                // 一维数组最大子数组问题
                int sum = row[0];
                int c_1 = 0, c_2 = 0;

                if (sum > ans_sum) {
                    ans_sum = sum;
                    ans_r_1 = r_begin;
                    ans_r_2 = r_end;
                    ans_c_1 = c_1;
                    ans_c_2 = c_2;
                }

                for (int c = 1; c < width; ++c) {
                    if (sum + row[c] > row[c]) {
                        sum = sum + row[c];
                        c_2 = c;
                    } else {
                        sum = row[c];
                        c_1 = c_2 = c;
                    }
                    if (sum > ans_sum) {
                        ans_sum = sum;
                        ans_r_1 = r_begin;
                        ans_r_2 = r_end;
                        ans_c_1 = c_1;
                        ans_c_2 = c_2;
                    }
                }
            }
        }

        return { ans_r_1, ans_c_1, ans_r_2, ans_c_2 };
    }
};