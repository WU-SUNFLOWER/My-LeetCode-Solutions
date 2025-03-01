class Solution {
private:
    std::vector<std::string> ans_vec_;
public:
    bool IsNumber(char ch) {
        return '0' <= ch && ch <= '9';
    }

    bool IsUpperLetter(char ch) {
        return 'A' <= ch && ch <= 'Z';
    }

    void Solve(const std::string& original_str, std::string& ans_str) {
        if (ans_str.size() == original_str.size()) {
            ans_vec_.emplace_back(ans_str);
            return;
        }

        int idx = ans_str.size();
        char ch = original_str[idx];
        if (IsNumber(ch)) {
            ans_str.push_back(ch);
            Solve(original_str, ans_str);
            ans_str.pop_back();
        } else {
            char lower = IsUpperLetter(ch) ? (ch - 'A' + 'a') : ch;
            char upper = IsUpperLetter(ch) ? ch : (ch - 'a' + 'A');

            ans_str.push_back(lower);
            Solve(original_str, ans_str);
            ans_str.pop_back();

            ans_str.push_back(upper);
            Solve(original_str, ans_str);
            ans_str.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        std::string tmp;
        Solve(s, tmp);
        return ans_vec_;
    }
};