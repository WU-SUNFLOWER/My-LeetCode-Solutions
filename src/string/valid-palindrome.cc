class Solution {
public:
    bool IsLetter(char ch) {
        return 'A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z' || '0' <= ch && ch <= '9';
    }

    char UpperToLower(char ch) {
        if ('A' <= ch && ch <= 'Z') {
            return ch - 'A' + 'a';
        }
        return ch;
    }

    bool Check(std::string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i, --j;
            } else {
                return false;
            }
        }
        return true;
    }

    std::string FlushString(std::string& s) {
        std::string ret;

        for (char ch : s) {
            if (IsLetter(ch)) {
                ch = UpperToLower(ch);
                ret.push_back(ch);
            }
        }

        return ret;
    }

    bool isPalindrome(string s) {
        std::string ss = FlushString(s);
        return Check(ss);
    }
};