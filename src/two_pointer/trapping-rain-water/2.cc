class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> max_in_left(height.size(), 0);
        std::vector<int> max_in_right(height.size(), 0);

        for (int i = 1; i < height.size(); ++i) {
            max_in_left[i] = std::max(max_in_left[i - 1], height[i - 1]);
        }

        for (int i = height.size() - 2; i >= 0 ; --i) {
            max_in_right[i] = std::max(max_in_right[i + 1], height[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            int delta = std::min(max_in_left[i], max_in_right[i]) - height[i];
            if (delta > 0) {
                ans += delta;
            }
        }

        return ans;
    }
};