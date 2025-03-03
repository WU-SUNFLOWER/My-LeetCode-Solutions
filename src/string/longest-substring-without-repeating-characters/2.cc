class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        std::unordered_map<char, int> window = { { s[0], 1 } };

        int win_left = 0;
        int win_right = 1;
        int ans = 1;

        while (win_right < s.size()) {
            ans = std::max(ans, win_right - win_left);

            char ch = s[win_right];
            if (window[ch] > 0) {
                --window[s[win_left]];
                ++win_left;
            } else {
                ++window[ch];
                ++win_right;
            }
        }
        ans = std::max(ans, win_right - win_left);

        return ans;
    }
};