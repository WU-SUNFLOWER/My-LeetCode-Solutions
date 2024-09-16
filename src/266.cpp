class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::map<char, int> count;
        for (char ch: s) {
            if (count.find(ch) == count.end()) {
                count[ch] = 1;
            } else {
                count[ch] += 1; 
            }
        }
        int oddCount = 0;
        for (const auto& pair: count) {
            if (pair.second % 2 == 1) {
                ++oddCount;
            }
            if (oddCount > 1) {
                return false;
            }
        }
        return true;
    }
};