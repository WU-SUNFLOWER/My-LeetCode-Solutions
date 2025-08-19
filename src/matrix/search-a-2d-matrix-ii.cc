class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();

        int row = 0;
        int col = width - 1;
        while (row < height && 0 <= col) {
            if (target == matrix[row][col]) {
                return true;
            }
            else if (target < matrix[row][col]) {
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};