class Solution {
public:
    bool IsOperator(std::string& str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> my_stack;
        for (auto& token : tokens) {
            if (IsOperator(token)) {
                int right = std::stoi(my_stack.top());
                my_stack.pop();
                int left = std::stoi(my_stack.top());
                my_stack.pop();
                int result = 0;
                if (token == "+") {
                    result = left + right;
                }
                else if (token == "-") {
                    result = left - right;
                }
                else if (token == "*") {
                    result = left * right;
                }
                else if (token == "/") {
                    result = left / right;
                }
                my_stack.push(std::to_string(result));
            } else {
                my_stack.push(std::move(token));
            }
        }

        return std::stoi(my_stack.top());
    }
};