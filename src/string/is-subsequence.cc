class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 判断 s 是否为 t 的子序列
        // t大s小
        if (!(s.size() <= t.size())) {
            return false;
        }

        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return i == s.size();
    }
};