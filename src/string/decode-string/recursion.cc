class Solution {
public:
    bool IsDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }

    std::string DFS(const std::string& s, int low, int high) {
        std::string output;

        int i = low;
        int time = 0;
        int balance = 0;
        int start = -1;
        while (i < high) {
            char ch = s[i];
            if (IsDigit(ch) && balance == 0) {
                time = time * 10 + (ch - '0');
                ++i;
            }
            else if (ch == '[') {
                ++balance;
                ++i;
                if (balance == 1) {
                    start = i;
                }
            }
            else if (ch == ']') {
                --balance;
                if (balance == 0) {
                    std::string sub = DFS(s, start, i);
                    while (time > 0) {
                        output += sub;
                        --time;
                    }
                    time = 0;
                }
                ++i;
            }
            else if (balance == 0) {
                output.push_back(ch);
                ++i;
            }
            else {
                ++i;
            }
        }

        return output;
    }

    std::string decodeString(std::string s) {
        return DFS(s, 0, s.size());
    }
};