class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> s;
        std::vector<int> ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        return ans;
    }
};