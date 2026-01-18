class Solution {
public:
    bool IsMatchImpl(const std::string& s, const std::string& p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }

        bool has_quantifier = j + 1 < p.size() && (p[j + 1] == '*' || p[j + 1] == '?');
        if (!has_quantifier) {
            if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                return IsMatchImpl(s, p, i + 1, j + 1);
            } else {
                return false;
            }
        } else if (p[j + 1] == '*') {
            // 匹配0个
            bool choice0 = IsMatchImpl(s, p, i, j + 2);
            if (choice0) return true;
            // 匹配1个
            bool choice1 = i < s.size() && (s[i] == p[j] || p[j] == '.') && IsMatchImpl(s, p, i + 1, j);
            return choice1;
        } else if (p[j + 1] == '?') {
            // TODO
        }
        return false;
    }

    bool isMatch(string s, string p) {
        return IsMatchImpl(s, p, 0, 0);
    }
};