class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stack;

        int i = 0;  // pushed数组指针
        int j = 0;  // popped数组指针

        while (i < pushed.size()) {
            stack.push(pushed[i++]);
            // 检查当前栈顶元素是不是popped[j]
            while (!stack.empty() && stack.top() == popped[j]) {
                ++j;
                stack.pop();
            }
        }

        return j == popped.size();
    }
};