class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_len = 0;

        std::unordered_set<char> window;

        for (int i = 0; i < s.size(); ++i) {
            while (window.find(s[i]) != window.end()) {
                window.erase(s[left]);
                ++left;
            }
            window.insert(s[i]);
            max_len = std::max(max_len, i - left + 1);
        }

        return max_len;
    }
};