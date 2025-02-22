class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        int ans = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= right) {
                right = std::min(right, points[i][1]);
            } else {
                ++ans;
                right = points[i][1];
            }
        }

        return ans;
    }
};