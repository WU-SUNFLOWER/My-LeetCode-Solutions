class Solution {
public:
    int Compute(const std::string& s, int l, int& r) {
        int sign = 1;
        // 记录正在读取的数字的值
        int num = 0;
        // 记录整个表达式的计算结果
        int ret = 0;

        for (int i = l; i < s.size(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else {
                // 当前数字读取结束，将其输出，并将计数器清空
                ret += sign * num;
                num = 0;
                
                if (s[i] == ' ') {
                    continue;
                } 
                else if (s[i] == '+') {
                    sign = 1;
                }
                else if (s[i] == '-') {
                    sign = -1;
                }
                else if (s[i] == '(') {
                    int r_parent_pos = -1;
                    ret += sign * Compute(s, i + 1, r_parent_pos);
                    i = r_parent_pos;
                }
                else if (s[i] == ')') {
                    r = i;
                    return ret;
                }
            }
        }

        return ret;
    }

    int calculate(string s) {
        int tmp = -1;
        return Compute("(" + s + ")", 0, tmp);
    }
};