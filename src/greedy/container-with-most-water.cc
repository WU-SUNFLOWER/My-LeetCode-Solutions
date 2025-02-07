class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = std::max(ans, (j - i) * std::min(height[i], height[j]));

            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};