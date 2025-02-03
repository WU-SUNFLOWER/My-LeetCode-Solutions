class Solution {
public:

#define CHECK_STACK_TOP(ch, ch1, ch2) (stack.top() == ch1 && ch == ch2)

    bool isValid(string s) {
        std::stack<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            }
            else if (
                stack.size() > 0 && (
                    CHECK_STACK_TOP(ch, '(', ')')
                     || CHECK_STACK_TOP(ch, '[', ']')
                     || CHECK_STACK_TOP(ch, '{', '}'))
            ) {
                stack.pop();
            }
            else {
                return false;
            }
        }
        return stack.size() == 0;
    }
};