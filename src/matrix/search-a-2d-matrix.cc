class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();

#define GET_FROM_MATRIX(i) (matrix[(i) / width][(i) % width])

        int i = 0;
        int j = height * width;
        while (i < j) {
            int mid = (i + j) >> 1;
            if (GET_FROM_MATRIX(mid) == target) {
                return true;
            }
            if (GET_FROM_MATRIX(mid) < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }

        return false;
    }
};