class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> bucket;
        for (char ch : s) {
            ++bucket[ch];
        }

        int ans = 0;
        for (auto& [ch, cnt] : bucket) {
            ans += (cnt / 2) * 2;
            cnt = cnt % 2;
        }

        for (auto& [ch, cnt] : bucket) {
            if (cnt > 0) {
                ans++;
                break;
            }
        }

        return ans;
    }
};