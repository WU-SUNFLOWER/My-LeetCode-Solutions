class Solution {
public:
    int GetWidth(const vector<int>& heights, int start) {
        int i = start;
        int j = start;
        while (0 <= i && heights[start] <= heights[i]) {
            --i;
        }
        while (j < heights.size() && heights[start] <= heights[j]) {
            ++j;
        }
        return (j - 1) - (i + 1) + 1;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (0 < i && heights[i - 1] == heights[i]) {
                continue;
            }
            int area = GetWidth(heights, i) * heights[i];
            ans = std::max(ans, area);
        }
        return ans;
    }
};