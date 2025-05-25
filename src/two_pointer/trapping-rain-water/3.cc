class Solution {
public:
    int trap(vector<int>& height) {
        // 存下标
        std::stack<int> pending;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!pending.empty() && height[i] > height[pending.top()]) {
                int pending_i = pending.top();
                pending.pop();
                if (pending.empty()) {
                    break;
                }
                int delta_height = std::min(height[i], height[pending.top()]) - height[pending_i];
                ans += delta_height * (i - pending.top() - 1);
            }
            pending.push(i);
        }
        return ans;
    }
};