class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> pending;
        std::vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!pending.empty() && temperatures[i] > temperatures[pending.top()]) {
                ans[pending.top()] = i - pending.top();
                pending.pop();
            }
            pending.push(i);
        }
        return ans;
    }
};