class Solution {
public:
    std::pair<int, int> Expand(const std::string& s, int i, int j) {
        while (0 <= i && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return { i + 1, j - 1 };
    }

    std::string longestPalindrome(std::string s) {
        int ans_left = 0;
        int ans_right = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left_1, right_1] = Expand(s, i, i);
            auto [left_2, right_2] = Expand(s, i, i + 1);
            if (right_1 - left_1 > ans_right - ans_left) {
                ans_left = left_1;
                ans_right = right_1;
            }
            if (right_2 - left_2 > ans_right - ans_left) {
                ans_left = left_2;
                ans_right = right_2;
            }
        }
        return s.substr(ans_left, ans_right - ans_left + 1);
    }
};