class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // left[i] 在柱子i左侧，第一根高度比height[i]小的柱子（自左向右，维护一个单调上升的栈）
        std::vector<int> left(n, -1);
        // right[i] 在柱子i右侧，第一根高度比height[i]小的柱子（自右向左，维护一个单调上升的栈）
        std::vector<int> right(n, n);

        std::stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }

        s = std::stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int area = (right[i] - left[i] - 1) * heights[i];
            ans = std::max(ans, area);
        }
        return ans;
    }
};