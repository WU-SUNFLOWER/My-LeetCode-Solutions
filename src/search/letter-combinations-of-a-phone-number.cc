static const std::map<char, std::string> kDigitMap = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
};

class Solution {
private:
    std::vector<std::string> ans_vec_;

public:
    void DFS(const std::string& digits, int start, std::string& ans) {
        if (start == digits.size()) {
            ans_vec_.push_back(ans);
            return;
        }
        for (char ch : kDigitMap.at(digits[start])) {
            ans.push_back(ch);
            DFS(digits, start + 1, ans);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return { }; 
        }

        std::string str;
        DFS(digits, 0, str);
        return ans_vec_;
    }
};