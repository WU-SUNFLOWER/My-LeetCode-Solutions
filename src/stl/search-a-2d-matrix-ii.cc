class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        if (height <= 0) {
            return false;
        }

        int width = matrix[0].size();
        int i = 0;
        int j = width - 1;
        while (0 <= i && i < height && 0 <= j && j < width) {
            if (target == matrix[i][j]) {
                return true;
            }
            if (target < matrix[i][j]) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};