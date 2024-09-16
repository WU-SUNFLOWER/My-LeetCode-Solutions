class Solution {
public:
    int countLetters(string s) {
        int len = s.length();
        int sum = 0;
        int i, j;
        for (i = 0; i < len;) {
            for (j = i + 1; j < len; ++j) {
                if (s[i] != s[j]) {
                    break;
                }
            }
            sum += (1 + j - i) * (j - i) / 2;
            i = j;
        }
        return sum;
    }
};