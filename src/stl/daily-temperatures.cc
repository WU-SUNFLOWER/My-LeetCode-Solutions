class Solution {
public:
    std::vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stack;
        std::vector<int> answer(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty()) {
                int j = stack.top();
                if (temperatures[i] > temperatures[j]) {
                    answer[j] = i - j;
                    stack.pop();
                    continue;
                }
                break;
            }
            stack.push(i);
        }
        return answer;
    }
};