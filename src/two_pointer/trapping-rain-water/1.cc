class Solution {
public:
    int trap(vector<int>& heights) {
        int left_max = -1;
        int right_max = -1;
        int left = 0;
        int right = heights.size() - 1;

        int ans = 0;
        while (left < right) {
            left_max = std::max(left_max, heights[left]);
            right_max = std::max(right_max, heights[right]);

            if (heights[left] <= heights[right]) {
                ans += left_max - heights[left];
                ++left;
            } else {
                ans += right_max - heights[right];
                --right;
            }
        }

        return ans;
    }
};