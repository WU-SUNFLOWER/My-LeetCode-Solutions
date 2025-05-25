class Solution {
private:
    int m_;  // 矩阵高度
    int n_; // 矩阵宽度

public:
    int SolveRow(const std::vector<int>& heights) {
        // left[i] 柱子i左侧第一个高度比它小的柱子是谁
        //（从左向右遍历，维护单调递增栈）
        std::vector<int> left(n_, -1);
        // right[i] 柱子i右侧第一个高度比它小的柱子是谁
        // （从右向左遍历，维护单调递增栈）
        std::vector<int> right(n_, n_);

        std::stack<int> st;
        for (int i = 0; i < n_; ++i) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = std::stack<int>();
        for (int i = n_ - 1; 0 <= i; --i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n_; ++i) {
            int area = (right[i] - left[i] - 1) * heights[i];
            ans = std::max(ans, area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        m_ = matrix.size();  // 矩阵高度
        n_ = matrix[0].size(); // 矩阵宽度

        std::vector<int> heights(n_, 0);
        int ans = 0;
        for (int i = 0; i < m_; ++i) {
            // 刷新当前行柱子的高度信息
            for (int j = 0; j < n_; ++j) {
                heights[j] = matrix[i][j] == '1' ? (heights[j] + 1) : 0;
            }
            // 84. 柱状图中最大的矩形
            // https://leetcode.cn/problems/largest-rectangle-in-histogram/
            ans = std::max(ans, SolveRow(heights));
        }
        return ans;
    }
};