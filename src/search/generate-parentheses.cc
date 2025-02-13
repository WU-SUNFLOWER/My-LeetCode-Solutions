class Solution {
private:
    std::vector<std::string> ans_vec_;
public:
    void Search(std::string& str, int balance, int n) {
        // 情况1：所有balance都消耗光了，且n也用光了
        if (balance == 0 && n == 0) {
            ans_vec_.push_back(str);
            return;
        }
        // 情况2：消耗balance
        if (balance > 0) {
            str.push_back(')');
            Search(str, balance - 1, n);
            str.pop_back();
        }
        // 情况3：继续创建balance
        if (n > 0) {
            str.push_back('(');
            Search(str, balance + 1, n - 1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        std::string str;
        Search(str, 0, n);
        return ans_vec_;
    }
};